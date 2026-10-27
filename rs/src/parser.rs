//! Recursive-descent parser for the freud C subset.
//!
//! Mirrors `tests/differential/parse.cpp` routine-for-routine: same
//! accepted language, same tree shapes (see `tests/differential/SPEC.md`),
//! same error messages and positions.

use crate::ast::*;
use crate::token::{Kind, Tok, TokenError, tokenize};

/// Parse failure: 1-based position plus the reference message.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct ParseError {
    pub line: usize,
    pub col: usize,
    pub msg: String,
}

impl std::fmt::Display for ParseError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}:{}: error: {}", self.line, self.col, self.msg)
    }
}

impl std::error::Error for ParseError {}

/// Tokenize and parse `src` into a translation unit.
pub fn parse(src: &[u8]) -> Result<TranslationUnit, ParseError> {
    let toks = tokenize(src).map_err(|e: TokenError| ParseError {
        line: e.line,
        col: e.col,
        msg: e.msg,
    })?;
    let mut p = Parser::new(&toks);
    let tu = p.parse_translation_unit()?;
    p.check_end()?;
    Ok(tu)
}

const TYPE_KWS: [&[u8]; 4] = [b"int", b"char", b"short", b"void"];
const ASSIGN_OPS: [&[u8]; 6] = [b"=", b"+=", b"-=", b"*=", b"/=", b"%="];
const EQUALITY_OPS: [&[u8]; 2] = [b"==", b"!="];
const RELATIONAL_OPS: [&[u8]; 4] = [b"<", b">", b"<=", b">="];
const ADDITIVE_OPS: [&[u8]; 2] = [b"+", b"-"];
const MULTIPLICATIVE_OPS: [&[u8]; 3] = [b"*", b"/", b"%"];
const UNARY_OPS: [&[u8]; 4] = [b"!", b"&", b"++", b"--"];

fn is_op_in(text: &[u8], ops: &[&[u8]]) -> bool {
    ops.iter().any(|op| *op == text)
}

fn desc(t: &Tok) -> String {
    if t.kind == Kind::End {
        "end of file".to_string()
    } else {
        format!("'{}'", String::from_utf8_lossy(&t.text))
    }
}

fn is_lvalue(e: &Expr) -> bool {
    match e {
        Expr::Ident(_) => true,
        Expr::Paren(inner) => is_lvalue(inner),
        _ => false,
    }
}

struct Parser<'a> {
    t: &'a [Tok],
    p: usize,
}

impl<'a> Parser<'a> {
    fn new(t: &'a [Tok]) -> Self {
        Parser { t, p: 0 }
    }

    fn peek_at(&self, k: isize) -> &Tok {
        let j = (self.p as isize + k).max(0) as usize;
        self.t.get(j).unwrap_or_else(|| self.t.last().unwrap())
    }

    fn peek(&self) -> &Tok {
        self.peek_at(0)
    }

    fn at_end(&self) -> bool {
        self.peek().kind == Kind::End
    }

    fn at_kw(&self, w: &[u8]) -> bool {
        let t = self.peek();
        t.kind == Kind::Kw && t.text.as_slice() == w
    }

    fn at_punct(&self, w: &[u8]) -> bool {
        let t = self.peek();
        t.kind == Kind::Punct && t.text.as_slice() == w
    }

    fn at_ident(&self) -> bool {
        self.peek().kind == Kind::Ident
    }

    fn at_punct_op(&self, ops: &[&[u8]]) -> bool {
        let t = self.peek();
        t.kind == Kind::Punct && is_op_in(&t.text, ops)
    }

    fn is_type_tok(&self) -> bool {
        let t = self.peek();
        t.kind == Kind::Kw && is_op_in(&t.text, &TYPE_KWS)
    }

    fn next_tok(&mut self) -> Tok {
        let t = self.peek().clone();
        self.p += 1;
        t
    }

    fn err(&self, line: usize, col: usize, msg: String) -> ParseError {
        ParseError { line, col, msg }
    }

    fn fail<T>(&self, msg: String) -> Result<T, ParseError> {
        let t = self.peek().clone();
        Err(self.err(t.line, t.col, msg))
    }

    fn expect_punct(&mut self, w: &[u8], what: &str) -> Result<Tok, ParseError> {
        if self.at_punct(w) {
            Ok(self.next_tok())
        } else {
            let t = self.peek().clone();
            Err(self.err(
                t.line,
                t.col,
                format!("expected {}, found {}", what, desc(&t)),
            ))
        }
    }

    fn expect_kw(&mut self, w: &[u8], what: &str) -> Result<Tok, ParseError> {
        if self.at_kw(w) {
            Ok(self.next_tok())
        } else {
            let t = self.peek().clone();
            Err(self.err(
                t.line,
                t.col,
                format!("expected {}, found {}", what, desc(&t)),
            ))
        }
    }

    fn expect_ident(&mut self, what: &str) -> Result<Tok, ParseError> {
        if self.at_ident() {
            Ok(self.next_tok())
        } else {
            let t = self.peek().clone();
            Err(self.err(
                t.line,
                t.col,
                format!("expected {}, found {}", what, desc(&t)),
            ))
        }
    }

    fn check_end(&self) -> Result<(), ParseError> {
        if !self.at_end() {
            let t = self.peek().clone();
            return Err(self.err(
                t.line,
                t.col,
                format!("unexpected trailing {}", desc(&t)),
            ));
        }
        Ok(())
    }

    fn parse_translation_unit(&mut self) -> Result<TranslationUnit, ParseError> {
        let mut items = Vec::new();
        while !self.at_end() {
            if self.at_punct(b";") {
                self.next_tok();
                continue;
            }
            items.push(self.parse_external()?);
        }
        Ok(TranslationUnit(items))
    }

    fn parse_external(&mut self) -> Result<External, ParseError> {
        if self.is_type_tok() || (self.at_ident() && self.peek_at(1).kind == Kind::Ident)
        {
            let mark = self.p;
            let spec = self.next_tok().text;
            if self.at_ident() {
                let name = self.next_tok().text;
                if self.at_punct(b"(") {
                    return Ok(External::FuncDef(self.parse_funcdef(spec, name)?));
                }
            }
            self.p = mark;
            return Ok(External::Decl(self.parse_declaration()?));
        }
        self.fail("expected declaration or function definition".to_string())
    }

    fn parse_funcdef(&mut self, _spec: Vec<u8>, name: Vec<u8>) -> Result<FuncDef, ParseError> {
        self.expect_punct(b"(", "'('")?;
        if !self.at_punct(b")") {
            if self.at_kw(b"void") {
                self.next_tok();
            } else {
                loop {
                    if !self.is_type_tok() {
                        return self.fail("expected parameter type".to_string());
                    }
                    self.next_tok();
                    self.expect_ident("parameter name")?;
                    if !self.at_punct(b",") {
                        break;
                    }
                    self.next_tok();
                }
            }
        }
        self.expect_punct(b")", "')'")?;
        let body = self.parse_compound()?;
        Ok(FuncDef { name, body })
    }

    fn parse_declaration(&mut self) -> Result<Decl, ParseError> {
        let spec = if self.is_type_tok() || self.at_ident() {
            self.next_tok().text
        } else {
            return self.fail("expected type name".to_string());
        };
        let init = if !self.at_punct(b";") {
            Some(self.parse_init_declarator()?)
        } else {
            None
        };
        self.expect_punct(b";", "';'")?;
        Ok(Decl { spec, init })
    }

    fn parse_init_declarator(&mut self) -> Result<InitDecl, ParseError> {
        let name = self.expect_ident("declarator name")?.text;
        let init = if self.at_punct(b"=") {
            self.next_tok();
            Some(self.parse_assignment()?)
        } else {
            None
        };
        Ok(InitDecl { name, init })
    }

    fn parse_statement(&mut self) -> Result<Stmt, ParseError> {
        if self.at_punct(b"{") {
            return Ok(Stmt::Compound(self.parse_compound()?));
        }
        if self.at_kw(b"if") || self.at_kw(b"switch") {
            return self.parse_selection();
        }
        if self.at_kw(b"while") || self.at_kw(b"for") {
            return self.parse_iteration();
        }
        if self.at_kw(b"break") || self.at_kw(b"continue") || self.at_kw(b"return") {
            return self.parse_jump();
        }
        if self.at_kw(b"case")
            || self.at_kw(b"default")
            || (self.at_ident() && self.peek_at(1).kind == Kind::Punct && self.peek_at(1).text == b":")
        {
            return self.parse_labeled();
        }
        if self.at_punct(b";") {
            self.next_tok();
            return Ok(Stmt::Empty);
        }
        let e = self.parse_expression()?;
        self.expect_punct(b";", "';'")?;
        Ok(Stmt::Expr(e))
    }

    fn parse_compound(&mut self) -> Result<Block, ParseError> {
        self.expect_punct(b"{", "'{'")?;
        let mut items = Vec::new();
        while !self.at_punct(b"}") {
            if self.at_end() {
                return self.fail("expected '}'".to_string());
            }
            items.push(self.parse_block_item()?);
        }
        self.next_tok();
        Ok(Block(items))
    }

    fn parse_block_item(&mut self) -> Result<BlockItem, ParseError> {
        if self.is_type_tok() || (self.at_ident() && self.peek_at(1).kind == Kind::Ident) {
            Ok(BlockItem::Decl(self.parse_declaration()?))
        } else {
            Ok(BlockItem::Stmt(self.parse_statement()?))
        }
    }

    fn parse_selection(&mut self) -> Result<Stmt, ParseError> {
        if self.at_kw(b"if") {
            self.next_tok();
            self.expect_punct(b"(", "'('")?;
            let c = self.parse_expression()?;
            self.expect_punct(b")", "')'")?;
            let t = self.parse_statement()?;
            if self.at_kw(b"else") {
                self.next_tok();
                let e = self.parse_statement()?;
                return Ok(Stmt::If {
                    cond: c,
                    then: Box::new(t),
                    els: Some(Box::new(e)),
                });
            }
            return Ok(Stmt::If {
                cond: c,
                then: Box::new(t),
                els: None,
            });
        }
        self.expect_kw(b"switch", "'switch'")?;
        self.expect_punct(b"(", "'('")?;
        let c = self.parse_expression()?;
        self.expect_punct(b")", "')'")?;
        let b = self.parse_statement()?;
        Ok(Stmt::Switch {
            expr: c,
            body: Box::new(b),
        })
    }

    fn parse_iteration(&mut self) -> Result<Stmt, ParseError> {
        if self.at_kw(b"while") {
            self.next_tok();
            self.expect_punct(b"(", "'('")?;
            let c = self.parse_expression()?;
            self.expect_punct(b")", "')'")?;
            let b = self.parse_statement()?;
            return Ok(Stmt::While {
                cond: c,
                body: Box::new(b),
            });
        }
        self.expect_kw(b"for", "'for'")?;
        self.expect_punct(b"(", "'('")?;
        let init = if self.is_type_tok() {
            ForInit::Decl(self.parse_for_declaration()?)
        } else if self.at_punct(b";") {
            ForInit::Empty
        } else {
            ForInit::Expr(self.parse_expression()?)
        };
        self.expect_punct(b";", "';'")?;
        let cond = if !self.at_punct(b";") {
            Some(self.parse_expression()?)
        } else {
            None
        };
        self.expect_punct(b";", "';'")?;
        let incr = if !self.at_punct(b")") {
            Some(self.parse_expression()?)
        } else {
            None
        };
        self.expect_punct(b")", "')'")?;
        let body = self.parse_statement()?;
        Ok(Stmt::For {
            init,
            cond,
            incr,
            body: Box::new(body),
        })
    }

    fn parse_for_declaration(&mut self) -> Result<ForDecl, ParseError> {
        let spec = self.next_tok().text;
        if self.at_ident() {
            let name = self.next_tok().text;
            if self.at_punct(b"=") {
                self.next_tok();
                let init = self.parse_assignment()?;
                return Ok(ForDecl {
                    spec,
                    name: Some(name),
                    init: Some(init),
                });
            }
            return Ok(ForDecl {
                spec,
                name: Some(name),
                init: None,
            });
        }
        Ok(ForDecl {
            spec,
            name: None,
            init: None,
        })
    }

    fn parse_jump(&mut self) -> Result<Stmt, ParseError> {
        let kw = self.next_tok().text;
        if kw == b"return" && !self.at_punct(b";") {
            let e = self.parse_expression()?;
            self.expect_punct(b";", "';'")?;
            return Ok(Stmt::Return(Some(e)));
        }
        self.expect_punct(b";", "';'")?;
        if kw == b"return" {
            Ok(Stmt::Return(None))
        } else if kw == b"break" {
            Ok(Stmt::Break)
        } else {
            Ok(Stmt::Continue)
        }
    }

    fn parse_labeled(&mut self) -> Result<Stmt, ParseError> {
        if self.at_kw(b"case") {
            self.next_tok();
            let label = self.parse_assignment()?;
            self.expect_punct(b":", "':'")?;
            let b = self.parse_statement()?;
            return Ok(Stmt::Case {
                label,
                body: Box::new(b),
            });
        }
        if self.at_kw(b"default") {
            self.next_tok();
            self.expect_punct(b":", "':'")?;
            let b = self.parse_statement()?;
            return Ok(Stmt::Default {
                body: Box::new(b),
            });
        }
        let name = self.expect_ident("label name")?.text;
        self.expect_punct(b":", "':'")?;
        let b = self.parse_statement()?;
        Ok(Stmt::GotoLabel {
            name,
            body: Box::new(b),
        })
    }
}

impl<'a> Parser<'a> {
    fn parse_expression(&mut self) -> Result<Expr, ParseError> {
        let first = self.parse_assignment()?;
        if !self.at_punct(b",") {
            return Ok(first);
        }
        let mut kids = vec![first];
        while self.at_punct(b",") {
            self.next_tok();
            kids.push(self.parse_assignment()?);
        }
        Ok(Expr::Comma(kids))
    }

    fn parse_assignment(&mut self) -> Result<Expr, ParseError> {
        let lhs = self.parse_logical_or()?;
        let t = self.peek().clone();
        if t.kind == Kind::Punct && is_op_in(&t.text, &ASSIGN_OPS) {
            self.next_tok();
            if !is_lvalue(&lhs) {
                return Err(self.err(t.line, t.col, "invalid lvalue in assignment".to_string()));
            }
            let rhs = self.parse_assignment()?;
            return Ok(Expr::Assign {
                op: t.text,
                lhs: Box::new(lhs),
                rhs: Box::new(rhs),
            });
        }
        Ok(lhs)
    }

    fn parse_logical_or(&mut self) -> Result<Expr, ParseError> {
        let mut n = self.parse_logical_and()?;
        while self.at_punct(b"||") {
            let op = self.next_tok().text;
            let rhs = self.parse_logical_and()?;
            n = Expr::BinOp {
                op,
                l: Box::new(n),
                r: Box::new(rhs),
            };
        }
        Ok(n)
    }

    fn parse_logical_and(&mut self) -> Result<Expr, ParseError> {
        let mut n = self.parse_equality()?;
        while self.at_punct(b"&&") {
            let op = self.next_tok().text;
            let rhs = self.parse_equality()?;
            n = Expr::BinOp {
                op,
                l: Box::new(n),
                r: Box::new(rhs),
            };
        }
        Ok(n)
    }

    fn parse_equality(&mut self) -> Result<Expr, ParseError> {
        let mut n = self.parse_relational()?;
        while self.at_punct_op(&EQUALITY_OPS) {
            let op = self.next_tok().text;
            let rhs = self.parse_relational()?;
            n = Expr::BinOp {
                op,
                l: Box::new(n),
                r: Box::new(rhs),
            };
        }
        Ok(n)
    }

    fn parse_relational(&mut self) -> Result<Expr, ParseError> {
        let mut n = self.parse_additive()?;
        while self.at_punct_op(&RELATIONAL_OPS) {
            let op = self.next_tok().text;
            let rhs = self.parse_additive()?;
            n = Expr::BinOp {
                op,
                l: Box::new(n),
                r: Box::new(rhs),
            };
        }
        Ok(n)
    }

    fn parse_additive(&mut self) -> Result<Expr, ParseError> {
        let mut n = self.parse_multiplicative()?;
        while self.at_punct_op(&ADDITIVE_OPS) {
            let op = self.next_tok().text;
            let rhs = self.parse_multiplicative()?;
            n = Expr::BinOp {
                op,
                l: Box::new(n),
                r: Box::new(rhs),
            };
        }
        Ok(n)
    }

    fn parse_multiplicative(&mut self) -> Result<Expr, ParseError> {
        let mut n = self.parse_unary()?;
        while self.at_punct_op(&MULTIPLICATIVE_OPS) {
            let op = self.next_tok().text;
            let rhs = self.parse_unary()?;
            n = Expr::BinOp {
                op,
                l: Box::new(n),
                r: Box::new(rhs),
            };
        }
        Ok(n)
    }

    fn parse_unary(&mut self) -> Result<Expr, ParseError> {
        let t = self.peek().clone();
        if t.kind == Kind::Punct && is_op_in(&t.text, &UNARY_OPS) {
            self.next_tok();
            let e = self.parse_unary()?;
            return Ok(Expr::Unary {
                op: t.text,
                e: Box::new(e),
            });
        }
        self.parse_postfix()
    }

    fn parse_postfix(&mut self) -> Result<Expr, ParseError> {
        let mut n = self.parse_primary()?;
        loop {
            if self.at_punct(b"++") || self.at_punct(b"--") {
                let op = self.next_tok().text;
                n = Expr::Postfix {
                    op,
                    e: Box::new(n),
                };
            } else if self.at_punct(b"(") {
                self.next_tok();
                let mut args = Vec::new();
                if !self.at_punct(b")") {
                    args.push(self.parse_assignment()?);
                    while self.at_punct(b",") {
                        self.next_tok();
                        args.push(self.parse_assignment()?);
                    }
                }
                self.expect_punct(b")", "')'")?;
                n = Expr::Call {
                    callee: Box::new(n),
                    args,
                };
            } else {
                return Ok(n);
            }
        }
    }

    fn parse_primary(&mut self) -> Result<Expr, ParseError> {
        let t = self.peek().clone();
        match t.kind {
            Kind::Int => {
                self.next_tok();
                Ok(Expr::Int(t.text))
            }
            Kind::Char => {
                self.next_tok();
                Ok(Expr::Char(t.text))
            }
            Kind::Ident => {
                self.next_tok();
                Ok(Expr::Ident(t.text))
            }
            Kind::String => {
                let mut parts = Vec::new();
                while self.peek().kind == Kind::String {
                    parts.extend_from_slice(&self.next_tok().text);
                }
                Ok(Expr::StringLit(parts))
            }
            _ => {
                if self.at_punct(b"(") {
                    self.next_tok();
                    let e = self.parse_expression()?;
                    self.expect_punct(b")", "')'")?;
                    return Ok(Expr::Paren(Box::new(e)));
                }
                let t = self.peek().clone();
                Err(self.err(
                    t.line,
                    t.col,
                    format!("expected expression, found {}", desc(&t)),
                ))
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::ast::dump_tu;

    fn sexp(src: &str) -> String {
        let tu = parse(src.as_bytes()).expect("parse failed");
        let mut out = Vec::new();
        dump_tu(&tu, &mut out);
        String::from_utf8(out).expect("non-utf8 dump")
    }

    fn assert_sexp(src: &str, want: &str) {
        assert_eq!(sexp(src), want);
    }

    fn assert_err(src: &str, line: usize, col: usize, msg: &str) {
        match parse(src.as_bytes()) {
            Err(e) => {
                assert_eq!(e.line, line);
                assert_eq!(e.col, col);
                assert_eq!(e.msg, msg);
            }
            Ok(_) => panic!("expected parse error for {:?}", src),
        }
    }

    #[test]
    fn minimal_main() {
        assert_sexp(
            "int main() { return 0; }",
            "(tu (funcdef main (compound (return (int 0)))))",
        );
    }

    #[test]
    fn declarator_init_has_no_assign_node() {
        assert_sexp(
            "int x = 1 + 2 * 3;",
            "(tu (decl int (initdecl x (binop + (int 1) (binop * (int 2) (int 3))))))",
        );
    }

    #[test]
    fn assignment_is_right_associative() {
        assert_sexp(
            "int f() { a = b = 1; }",
            "(tu (funcdef f (compound (exprstmt (assign = (ident a) (assign = (ident b) (int 1)))))))",
        );
    }

    #[test]
    fn dangling_else_binds_inner() {
        assert_sexp(
            "int f() { if (a) if (b) c(); else d(); }",
            "(tu (funcdef f (compound (if (ident a) (ifelse (ident b) (exprstmt (call (ident c))) (exprstmt (call (ident d))))))))",
        );
    }

    #[test]
    fn while_loop() {
        assert_sexp(
            "int f() { while (i) i = i + 1; }",
            "(tu (funcdef f (compound (while (ident i) (exprstmt (assign = (ident i) (binop + (ident i) (int 1))))))))",
        );
    }

    #[test]
    fn for_empty_clauses() {
        assert_sexp(
            "int f() { for (;;) ; }",
            "(tu (funcdef f (compound (for (empty-init) (empty)))))",
        );
    }

    #[test]
    fn for_full_clauses() {
        assert_sexp(
            "int f() { for (i = 0; i < 3; i++) x(); }",
            "(tu (funcdef f (compound (for (assign = (ident i) (int 0)) (binop < (ident i) (int 3)) (postfix ++ (ident i)) (exprstmt (call (ident x)))))))",
        );
    }

    #[test]
    fn for_declaration_init() {
        assert_sexp(
            "int f() { for (int i = 0; i < 1; i++) ; }",
            "(tu (funcdef f (compound (for (fordecl int i (int 0)) (binop < (ident i) (int 1)) (postfix ++ (ident i)) (empty)))))",
        );
    }

    #[test]
    fn switch_case_break_default() {
        assert_sexp(
            "int f() { switch (x) { case 1: y(); break; default: z(); } }",
            "(tu (funcdef f (compound (switch (ident x) (compound (case (int 1) (exprstmt (call (ident y)))) (break) (default (exprstmt (call (ident z)))))))))",
        );
    }

    #[test]
    fn call_arguments() {
        assert_sexp(
            "int f() { g(a, b + 1); }",
            "(tu (funcdef f (compound (exprstmt (call (ident g) (ident a) (binop + (ident b) (int 1)))))))",
        );
    }

    #[test]
    fn comma_expression() {
        assert_sexp(
            "int f() { a = 1, b = 2; }",
            "(tu (funcdef f (compound (exprstmt (comma (assign = (ident a) (int 1)) (assign = (ident b) (int 2)))))))",
        );
    }

    #[test]
    fn parens_are_kept() {
        assert_sexp(
            "int f() { x = (a + b) * c; }",
            "(tu (funcdef f (compound (exprstmt (assign = (ident x) (binop * (paren (binop + (ident a) (ident b))) (ident c)))))))",
        );
    }

    #[test]
    fn unary_and_postfix_operators() {
        assert_sexp(
            "int f() { x = !a; y = &b; i++; --j; }",
            "(tu (funcdef f (compound (exprstmt (assign = (ident x) (unary ! (ident a)))) (exprstmt (assign = (ident y) (unary & (ident b)))) (exprstmt (postfix ++ (ident i))) (exprstmt (unary -- (ident j))))))",
        );
    }

    #[test]
    fn adjacent_strings_paste() {
        assert_sexp(
            "int f() { s(\"a\" \"b\"); }",
            "(tu (funcdef f (compound (exprstmt (call (ident s) (string ab))))))",
        );
    }

    #[test]
    fn logic_precedence() {
        assert_sexp(
            "int f() { x = a || b && !c; }",
            "(tu (funcdef f (compound (exprstmt (assign = (ident x) (binop || (ident a) (binop && (ident b) (unary ! (ident c)))))))))",
        );
    }

    #[test]
    fn goto_label() {
        assert_sexp(
            "int f() { lab: x = 1; }",
            "(tu (funcdef f (compound (goto-label lab (exprstmt (assign = (ident x) (int 1)))))))",
        );
    }

    #[test]
    fn decls_with_and_without_init() {
        assert_sexp("int g;\nint;", "(tu (decl int (initdecl g)) (decl int))");
    }

    #[test]
    fn chars_dump_raw_with_escaping() {
        assert_sexp(
            "int f() { c = 'x'; d = '\\n'; }",
            "(tu (funcdef f (compound (exprstmt (assign = (ident c) (char 'x'))) (exprstmt (assign = (ident d) (char '\\\\n'))))))",
        );
    }

    #[test]
    fn string_escapes_dump_escaped() {
        assert_sexp(
            "int f() { s(\"a\\nb\"); }",
            "(tu (funcdef f (compound (exprstmt (call (ident s) (string a\\nb))))))",
        );
    }

    #[test]
    fn params_consumed_not_kept() {
        assert_sexp(
            "int add(int a, int b) { return a; }",
            "(tu (funcdef add (compound (return (ident a)))))",
        );
        assert_sexp(
            "int f(void) { return 0; }",
            "(tu (funcdef f (compound (return (int 0)))))",
        );
    }

    #[test]
    fn break_continue_bare_return() {
        assert_sexp(
            "int f() { while (1) { break; continue; } return; }",
            "(tu (funcdef f (compound (while (int 1) (compound (break) (continue))) (return)))))",
        );
    }

    #[test]
    fn nested_empty_compound() {
        assert_sexp("int f() { {} }", "(tu (funcdef f (compound (compound))))");
    }

    #[test]
    fn error_bad_lvalue_points_at_operator() {
        assert_err("int f() { 1 = 2; }", 1, 13, "invalid lvalue in assignment");
    }

    #[test]
    fn error_expected_declaration() {
        assert_err(
            "int x; }",
            1,
            8,
            "expected declaration or function definition",
        );
    }

    #[test]
    fn error_missing_semicolon() {
        assert_err("int f() { x = 1 }", 1, 17, "expected ';', found '}'");
    }

    #[test]
    fn error_expected_expression() {
        assert_err("int f() { x = ; }", 1, 15, "expected expression, found ';'");
    }
}
