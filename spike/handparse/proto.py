#!/usr/bin/env python3
"""Executable design prototype for a hand-written C-subset parser (spike).

Validates structure only: tokenizes, parses, counts nodes. The C++ port in
parser.cpp mirrors this file routine-for-routine; behavior verified here
runs on CI there. Usage: proto.py <file...> (exit 1 on any parse failure).
"""

import sys

class ParseError(Exception):
    def __init__(self, line, col, msg):
        super().__init__(f"{line}:{col}: error: {msg}")
        self.line, self.col, self.msg = line, col, msg

KEYWORDS = {
    "int": "INT", "char": "CHAR", "short": "SHORT", "void": "VOID",
    "if": "IF", "else": "ELSE", "switch": "SWITCH", "case": "CASE",
    "default": "DEFAULT", "while": "WHILE", "for": "FOR",
    "break": "BREAK", "continue": "CONTINUE", "return": "RETURN",
}

TWO_CHAR = {
    "==": "EQ", "!=": "NE", "<=": "LE", ">=": "GE", "++": "PLUSPLUS",
    "--": "MINUSMINUS", "&&": "ANDAND", "||": "OROR", "+=": "PLUS_A",
    "-=": "MINUS_A", "*=": "STAR_A", "/=": "SLASH_A", "%=": "PERCENT_A",
    "<<": "SHL", ">>": "SHR", "->": "ARROW",
}

ONE_CHAR = {
    "(": "LPAREN", ")": "RPAREN", "{": "LBRACE", "}": "RBRACE",
    "[": "LBRACKET", "]": "RBRACKET", ";": "SEMI", ",": "COMMA",
    ":": "COLON", "?": "QUESTION", "+": "PLUS", "-": "MINUS",
    "*": "STAR", "/": "SLASH", "%": "PERCENT", "<": "LT", ">": "GT",
    "!": "BANG", "&": "AMP", "|": "BAR", "^": "CARET", "~": "TILDE",
    "=": "ASSIGN", ".": "DOT",
}

ESCAPES = {"n": "\n", "t": "\t", "r": "\r", "0": "\0",
           "\\": "\\", "'": "'", '"': '"', "a": "\a", "b": "\b"}

class Tok:
    def __init__(self, t, text, line, col, ival=0):
        self.t, self.text, self.line, self.col, self.ival = \
            t, text, line, col, ival
    def desc(self):
        if self.t == "END":
            return "end of file"
        if self.t in ("IDENT", "INT", "CHAR", "STRING"):
            return f"{self.text!r}"
        return f"{self.text!r}"

def tokenize(src):
    toks = []
    i, line, col, n = 0, 1, 1, len(src)

    def err(msg):
        raise ParseError(line, col, msg)

    while i < n:
        c = src[i]
        if c in " \t\r":
            i += 1
            col += 1
        elif c == "\n":
            i += 1
            line += 1
            col = 1
        elif c == "/" and i + 1 < n and src[i + 1] == "/":
            while i < n and src[i] != "\n":
                i += 1
        elif c == "/" and i + 1 < n and src[i + 1] == "*":
            i += 2
            col += 2
            closed = False
            while i < n:
                if src[i] == "*" and i + 1 < n and src[i + 1] == "/":
                    i += 2
                    col += 2
                    closed = True
                    break
                if src[i] == "\n":
                    line += 1
                    col = 1
                else:
                    col += 1
                i += 1
            if not closed:
                err("unterminated block comment")
        elif c == "#":
            while i < n and src[i] != "\n":
                i += 1
        elif c.isdigit():
            j = i
            while j < n and src[j].isdigit():
                j += 1
            text = src[i:j]
            toks.append(Tok("INT", text, line, col, int(text)))
            col += j - i
            i = j
        elif c.isalpha() or c == "_":
            j = i
            while j < n and (src[j].isalnum() or src[j] == "_"):
                j += 1
            text = src[i:j]
            toks.append(Tok(KEYWORDS.get(text, "IDENT"), text, line, col))
            col += j - i
            i = j
        elif c == "'":
            j = i + 1
            val = None
            if j < n and src[j] == "\\":
                if j + 1 >= n or src[j + 1] not in ESCAPES:
                    err("bad escape in character literal")
                val = ESCAPES[src[j + 1]]
                j += 2
            elif j < n and src[j] not in "'\n":
                val = src[j]
                j += 1
            else:
                err("bad character literal")
            if j >= n or src[j] != "'":
                err("unterminated character literal")
            j += 1
            toks.append(Tok("CHAR", src[i:j], line, col, ord(val)))
            col += j - i
            i = j
        elif c == '"':
            j = i + 1
            parts = []
            while True:
                if j >= n or src[j] == "\n":
                    err("unterminated string literal")
                if src[j] == '"':
                    break
                if src[j] == "\\":
                    if j + 1 >= n or src[j + 1] not in ESCAPES:
                        err("bad escape in string literal")
                    parts.append(ESCAPES[src[j + 1]])
                    j += 2
                else:
                    parts.append(src[j])
                    j += 1
            j += 1
            toks.append(Tok("STRING", "".join(parts), line, col))
            col += j - i
            i = j
        elif src[i:i + 2] in TWO_CHAR:
            toks.append(Tok(TWO_CHAR[src[i:i + 2]], src[i:i + 2], line, col))
            i += 2
            col += 2
        elif c in ONE_CHAR:
            toks.append(Tok(ONE_CHAR[c], c, line, col))
            i += 1
            col += 1
        else:
            err(f"unexpected character {c!r}")
    toks.append(Tok("END", "", line, col))
    return toks


TYPE_TOKENS = ("INT", "CHAR", "SHORT", "VOID")
ASSIGN_OPS = ("ASSIGN", "PLUS_A", "MINUS_A", "STAR_A", "SLASH_A",
              "PERCENT_A")


class Node:
    def __init__(self, kind, text="", kids=()):
        self.kind, self.text, self.kids = kind, text, list(kids)


class Parser:
    def __init__(self, toks):
        self.t, self.p = toks, 0
        self.funcs = self.decls = self.stmts = self.exprs = 0
        self.nodes = 0

    def node(self, kind, text="", kids=()):
        self.nodes += 1
        return Node(kind, text, kids)

    def peek(self, k=0):
        return self.t[min(self.p + k, len(self.t) - 1)]

    def at(self, *ts):
        return self.peek().t in ts

    def next(self):
        t = self.peek()
        self.p += 1
        return t

    def expect(self, t, what):
        if self.at(t):
            return self.next()
        p = self.peek()
        raise ParseError(p.line, p.col,
                         f"expected {what}, found {p.desc()}")

    def fail(self, msg):
        p = self.peek()
        raise ParseError(p.line, p.col, msg)

    # ---- top level ----
    def parse_translation_unit(self):
        items = []
        while not self.at("END"):
            if self.at("SEMI"):
                self.next()
                continue
            items.append(self.parse_external())
        return self.node("tu", kids=items)

    def parse_external(self):
        # funcdef or declaration: [spec] ident ...
        if self.at(*TYPE_TOKENS) or \
                (self.at("IDENT") and self.peek(1).t == "IDENT"):
            mark = self.p
            spectext = self.next().text
            if self.at("IDENT"):
                name = self.next().text
                if self.at("LPAREN"):
                    return self.parse_funcdef(spectext, name)
            self.p = mark
            return self.parse_declaration()
        self.fail("expected declaration or function definition")

    def parse_funcdef(self, spectext, name):
        self.funcs += 1
        self.expect("LPAREN", "'('")
        params = []
        if not self.at("RPAREN"):
            if self.at("VOID"):
                self.next()
            else:
                while True:
                    if not self.at(*TYPE_TOKENS):
                        self.fail("expected parameter type")
                    ptype = self.next().text
                    pname = self.expect("IDENT", "parameter name").text
                    params.append((ptype, pname))
                    if not self.at("COMMA"):
                        break
                    self.next()
        self.expect("RPAREN", "')'")
        body = self.parse_compound()
        return self.node("funcdef", name, [body])

    # ---- declarations ----
    def parse_declaration(self):
        if self.at(*TYPE_TOKENS):
            spectext = self.next().text
        elif self.at("IDENT"):
            spectext = self.next().text  # typedef name
        else:
            self.fail("expected type name")
        kids = []
        if not self.at("SEMI"):
            kids.append(self.parse_init_declarator())
        self.expect("SEMI", "';'")
        self.decls += 1
        return self.node("decl", spectext, kids)

    def parse_init_declarator(self):
        name = self.expect("IDENT", "declarator name").text
        if self.at("ASSIGN"):
            self.next()
            init = self.parse_assignment()
            return self.node("initdecl", name, [init])
        return self.node("initdecl", name)

    # ---- statements ----
    def parse_statement(self):
        self.stmts += 1
        if self.at("LBRACE"):
            return self.parse_compound()
        if self.at("IF", "SWITCH"):
            return self.parse_selection()
        if self.at("WHILE", "FOR"):
            return self.parse_iteration()
        if self.at("BREAK", "CONTINUE", "RETURN"):
            return self.parse_jump()
        if self.at("CASE", "DEFAULT") or \
                (self.at("IDENT") and self.peek(1).t == "COLON"):
            return self.parse_labeled()
        if self.at("SEMI"):
            self.next()
            return self.node("empty")
        e = self.parse_expression()
        self.expect("SEMI", "';'")
        return self.node("exprstmt", kids=[e])

    def parse_compound(self):
        self.expect("LBRACE", "'{'")
        items = []
        while not self.at("RBRACE"):
            if self.at("END"):
                self.fail("expected '}'")
            items.append(self.parse_block_item())
        self.next()
        return self.node("compound", kids=items)

    def parse_block_item(self):
        if self.at(*TYPE_TOKENS) or \
                (self.at("IDENT") and self.peek(1).t == "IDENT"):
            return self.parse_declaration()
        return self.parse_statement()

    def parse_selection(self):
        if self.at("IF"):
            self.next()
            self.expect("LPAREN", "'('")
            c = self.parse_expression()
            self.expect("RPAREN", "')'")
            t = self.parse_statement()
            if self.at("ELSE"):
                self.next()
                e = self.parse_statement()
                return self.node("ifelse", kids=[c, t, e])
            return self.node("if", kids=[c, t])
        self.expect("SWITCH", "'switch'")
        self.expect("LPAREN", "'('")
        c = self.parse_expression()
        self.expect("RPAREN", "')'")
        b = self.parse_statement()
        return self.node("switch", kids=[c, b])

    def parse_iteration(self):
        if self.at("WHILE"):
            self.next()
            self.expect("LPAREN", "'('")
            c = self.parse_expression()
            self.expect("RPAREN", "')'")
            b = self.parse_statement()
            return self.node("while", kids=[c, b])
        self.expect("FOR", "'for'")
        self.expect("LPAREN", "'('")
        if self.at(*TYPE_TOKENS):
            init = self.parse_for_declaration()
        elif self.at("SEMI"):
            init = self.node("empty-init")
        else:
            init = self.parse_expression()
        self.expect("SEMI", "';'")
        cond = self.parse_expression() if not self.at("SEMI") else None
        self.expect("SEMI", "';'")
        update = self.parse_expression() if not self.at("RPAREN") else None
        self.expect("RPAREN", "')'")
        b = self.parse_statement()
        kids = [init] + ([cond] if cond else []) + \
            ([update] if update else []) + [b]
        return self.node("for", kids=kids)

    def parse_for_declaration(self):
        spectext = self.next().text
        if self.at("IDENT"):
            name = self.next().text
            if self.at("ASSIGN"):
                self.next()
                init = self.parse_assignment()
                return self.node("fordecl", f"{spectext} {name}", [init])
            return self.node("fordecl", f"{spectext} {name}")
        return self.node("fordecl", spectext)

    def parse_jump(self):
        kw = self.next().text
        if kw == "return" and not self.at("SEMI"):
            e = self.parse_expression()
            self.expect("SEMI", "';'")
            return self.node("return", kids=[e])
        self.expect("SEMI", "';'")
        return self.node(kw)

    def parse_labeled(self):
        if self.at("CASE"):
            self.next()
            label = self.parse_assignment()
            self.expect("COLON", "':'")
            b = self.parse_statement()
            return self.node("case", kids=[label, b])
        if self.at("DEFAULT"):
            self.next()
            self.expect("COLON", "':'")
            b = self.parse_statement()
            return self.node("default", kids=[b])
        name = self.expect("IDENT", "label name").text
        self.expect("COLON", "':'")
        b = self.parse_statement()
        return self.node("goto-label", kids=[b])

    # ---- expressions (precedence ladder) ----
    def parse_expression(self):
        first = self.parse_assignment()
        if not self.at("COMMA"):
            return first
        rest = [first]
        while self.at("COMMA"):
            self.next()
            rest.append(self.parse_assignment())
        return self.node("comma", kids=rest)

    def parse_assignment(self):
        self.exprs += 1
        lhs = self.parse_logical_or()
        if self.at(*ASSIGN_OPS):
            op = self.next().text
            if lhs.kind != "ident" and not (
                    lhs.kind == "paren" and lhs.kids and
                    self.is_lvalue(lhs.kids[0])):
                p = self.peek(-1)
                raise ParseError(p.line, p.col,
                                 "invalid lvalue in assignment")
            rhs = self.parse_assignment()
            return self.node("assign", op, [lhs, rhs])
        return lhs

    def is_lvalue(self, n):
        if n.kind == "ident":
            return True
        return n.kind == "paren" and bool(n.kids) and \
            self.is_lvalue(n.kids[0])

    def left_assoc(self, ops, sub):
        node = sub()
        while self.at(*ops):
            op = self.next().text
            rhs = sub()
            node = self.node("binop", op, [node, rhs])
        return node

    def parse_logical_or(self):
        return self.left_assoc(("OROR",), self.parse_logical_and)

    def parse_logical_and(self):
        return self.left_assoc(("ANDAND",), self.parse_equality)

    def parse_equality(self):
        return self.left_assoc(("EQ", "NE"), self.parse_relational)

    def parse_relational(self):
        return self.left_assoc(("LT", "GT", "LE", "GE"),
                               self.parse_additive)

    def parse_additive(self):
        return self.left_assoc(("PLUS", "MINUS"),
                               self.parse_multiplicative)

    def parse_multiplicative(self):
        return self.left_assoc(("STAR", "SLASH", "PERCENT"),
                               self.parse_unary)

    def parse_unary(self):
        if self.at("BANG", "AMP", "PLUSPLUS", "MINUSMINUS"):
            op = self.next().text
            return self.node("unary", op, [self.parse_unary()])
        return self.parse_postfix()

    def parse_postfix(self):
        node = self.parse_primary()
        while True:
            if self.at("PLUSPLUS", "MINUSMINUS"):
                node = self.node("postfix", self.next().text, [node])
            elif self.at("LPAREN"):
                self.next()
                args = []
                if not self.at("RPAREN"):
                    args.append(self.parse_assignment())
                    while self.at("COMMA"):
                        self.next()
                        args.append(self.parse_assignment())
                self.expect("RPAREN", "')'")
                node = self.node("call", kids=[node] + args)
            else:
                return node

    def parse_primary(self):
        if self.at("INT"):
            t = self.next()
            return self.node("int", t.text)
        if self.at("CHAR"):
            t = self.next()
            return self.node("char", t.text)
        if self.at("IDENT"):
            t = self.next()
            return self.node("ident", t.text)
        if self.at("STRING"):
            parts = []
            while self.at("STRING"):
                parts.append(self.next().text)
            return self.node("string", "".join(parts))
        if self.at("LPAREN"):
            self.next()
            e = self.parse_expression()
            self.expect("RPAREN", "')'")
            return self.node("paren", kids=[e])
        self.fail(f"expected expression, found {self.peek().desc()}")


def parse_file(path):
    with open(path) as f:
        src = f.read()
    toks = tokenize(src)
    p = Parser(toks)
    tree = p.parse_translation_unit()
    if not p.at("END"):
        t = p.peek()
        raise ParseError(t.line, t.col,
                         f"unexpected trailing {t.desc()}")
    return p


def main(argv):
    failed = False
    for path in argv[1:]:
        try:
            p = parse_file(path)
            print(f"OK {path} funcs={p.funcs} decls={p.decls} "
                  f"stmts={p.stmts} exprs={p.exprs} nodes={p.nodes}")
        except ParseError as e:
            print(f"{path}:{e}", file=sys.stderr)
            failed = True
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
