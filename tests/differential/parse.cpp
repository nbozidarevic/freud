// Differential parser (C++ reference) for the Rust migration.
// Behavior frozen: dumps the parse tree as a single-line S-expression
// (see SPEC.md). The Rust core must match it byte-for-byte until the C++
// implementation is retired (see decision 0005).
// Usage: parsedump FILE (exit 1 on tokenize/parse error).
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct ParseError {
  int line, col;
  string msg;
  ParseError(int line, int col, const string& msg)
      : line(line), col(col), msg(msg) {}
  string str() const {
    ostringstream out;
    out << line << ":" << col << ": error: " << msg;
    return out.str();
  }
};

enum TokType {
  T_END, T_IDENT, T_INT, T_CHAR, T_STRING,
  T_KW_INT, T_KW_CHAR, T_KW_SHORT, T_KW_VOID,
  T_KW_IF, T_KW_ELSE, T_KW_SWITCH, T_KW_CASE, T_KW_DEFAULT,
  T_KW_WHILE, T_KW_FOR, T_KW_BREAK, T_KW_CONTINUE, T_KW_RETURN,
  T_LPAREN, T_RPAREN, T_LBRACE, T_RBRACE, T_LBRACKET, T_RBRACKET,
  T_SEMI, T_COMMA, T_COLON, T_QUESTION,
  T_ASSIGN, T_EQ, T_NE, T_LT, T_LE, T_GT, T_GE,
  T_PLUS, T_MINUS, T_STAR, T_SLASH, T_PERCENT,
  T_PLUSPLUS, T_MINUSMINUS, T_ANDAND, T_OROR, T_BANG, T_AMP,
  T_BAR, T_CARET, T_TILDE, T_DOT,
  T_PLUS_A, T_MINUS_A, T_STAR_A, T_SLASH_A, T_PERCENT_A,
  T_SHL, T_SHR, T_ARROW
};

struct Tok {
  TokType t;
  string text;
  int line, col;
  long ival;
  Tok(TokType t, const string& text, int line, int col, long ival = 0)
      : t(t), text(text), line(line), col(col), ival(ival) {}
  string desc() const {
    if (t == T_END) return "end of file";
    return "'" + text + "'";
  }
};

static map<string, TokType> keywords() {
  map<string, TokType> k;
  k["int"] = T_KW_INT; k["char"] = T_KW_CHAR; k["short"] = T_KW_SHORT;
  k["void"] = T_KW_VOID; k["if"] = T_KW_IF; k["else"] = T_KW_ELSE;
  k["switch"] = T_KW_SWITCH; k["case"] = T_KW_CASE;
  k["default"] = T_KW_DEFAULT; k["while"] = T_KW_WHILE;
  k["for"] = T_KW_FOR; k["break"] = T_KW_BREAK;
  k["continue"] = T_KW_CONTINUE; k["return"] = T_KW_RETURN;
  return k;
}

static map<string, TokType> twoChars() {
  map<string, TokType> m;
  m["=="] = T_EQ; m["!="] = T_NE; m["<="] = T_LE; m[">="] = T_GE;
  m["++"] = T_PLUSPLUS; m["--"] = T_MINUSMINUS;
  m["&&"] = T_ANDAND; m["||"] = T_OROR;
  m["+="] = T_PLUS_A; m["-="] = T_MINUS_A; m["*="] = T_STAR_A;
  m["/="] = T_SLASH_A; m["%="] = T_PERCENT_A;
  m["<<"] = T_SHL; m[">>"] = T_SHR; m["->"] = T_ARROW;
  return m;
}

static map<char, TokType> oneChars() {
  map<char, TokType> m;
  m['('] = T_LPAREN; m[')'] = T_RPAREN;
  m['{'] = T_LBRACE; m['}'] = T_RBRACE;
  m['['] = T_LBRACKET; m[']'] = T_RBRACKET;
  m[';'] = T_SEMI; m[','] = T_COMMA; m[':'] = T_COLON;
  m['?'] = T_QUESTION; m['+'] = T_PLUS; m['-'] = T_MINUS;
  m['*'] = T_STAR; m['/'] = T_SLASH; m['%'] = T_PERCENT;
  m['<'] = T_LT; m['>'] = T_GT; m['!'] = T_BANG; m['&'] = T_AMP;
  m['|'] = T_BAR; m['^'] = T_CARET; m['~'] = T_TILDE;
  m['='] = T_ASSIGN; m['.'] = T_DOT;
  return m;
}

static int escapeVal(char c, int line, int col) {
  switch (c) {
    case 'n': return '\n'; case 't': return '\t'; case 'r': return '\r';
    case '0': return '\0'; case '\\': return '\\'; case '\'': return '\'';
    case '"': return '"'; case 'a': return '\a'; case 'b': return '\b';
    default: break;
  }
  throw ParseError(line, col, "bad escape in literal");
}

vector<Tok> tokenize(const string& src) {
  static map<string, TokType> kw = keywords();
  static map<string, TokType> two = twoChars();
  static map<char, TokType> one = oneChars();
  vector<Tok> toks;
  size_t i = 0, n = src.size();
  int line = 1, col = 1;
  while (i < n) {
    char c = src[i];
    if (c == ' ' || c == '\t' || c == '\r') { ++i; ++col; }
    else if (c == '\n') { ++i; ++line; col = 1; }
    else if (c == '/' && i + 1 < n && src[i + 1] == '/') {
      while (i < n && src[i] != '\n') ++i;
    } else if (c == '/' && i + 1 < n && src[i + 1] == '*') {
      i += 2; col += 2;
      bool closed = false;
      while (i < n) {
        if (src[i] == '*' && i + 1 < n && src[i + 1] == '/') {
          i += 2; col += 2; closed = true; break;
        }
        if (src[i] == '\n') { ++line; col = 1; } else { ++col; }
        ++i;
      }
      if (!closed) throw ParseError(line, col, "unterminated block comment");
    } else if (c == '#') {
      while (i < n && src[i] != '\n') ++i;
    } else if (isdigit((unsigned char)c)) {
      size_t j = i;
      while (j < n && isdigit((unsigned char)src[j])) ++j;
      string text = src.substr(i, j - i);
      toks.push_back(Tok(T_INT, text, line, col, atol(text.c_str())));
      col += (int)(j - i); i = j;
    } else if (isalpha((unsigned char)c) || c == '_') {
      size_t j = i;
      while (j < n && (isalnum((unsigned char)src[j]) || src[j] == '_')) ++j;
      string text = src.substr(i, j - i);
      TokType t = T_IDENT;
      if (kw.count(text)) t = kw[text];
      toks.push_back(Tok(t, text, line, col));
      col += (int)(j - i); i = j;
    } else if (c == '\'') {
      size_t j = i + 1;
      int val = -1;
      if (j < n && src[j] == '\\') {
        if (j + 1 >= n) throw ParseError(line, col, "bad character literal");
        val = escapeVal(src[j + 1], line, (int)(col + j - i));
        j += 2;
      } else if (j < n && src[j] != '\'' && src[j] != '\n') {
        val = src[j];
        ++j;
      } else {
        throw ParseError(line, col, "bad character literal");
      }
      if (j >= n || src[j] != '\'')
        throw ParseError(line, col, "unterminated character literal");
      ++j;
      toks.push_back(Tok(T_CHAR, src.substr(i, j - i), line, col, val));
      col += (int)(j - i); i = j;
    } else if (c == '"') {
      size_t j = i + 1;
      string parts;
      while (true) {
        if (j >= n || src[j] == '\n')
          throw ParseError(line, col, "unterminated string literal");
        if (src[j] == '"') break;
        if (src[j] == '\\') {
          if (j + 1 >= n)
            throw ParseError(line, col, "bad escape in string literal");
          parts += (char)escapeVal(src[j + 1], line, (int)(col + j - i));
          j += 2;
        } else {
          parts += src[j];
          ++j;
        }
      }
      ++j;
      toks.push_back(Tok(T_STRING, parts, line, col));
      col += (int)(j - i); i = j;
    } else if (i + 1 < n && two.count(src.substr(i, 2))) {
      string text = src.substr(i, 2);
      toks.push_back(Tok(two[text], text, line, col));
      i += 2; col += 2;
    } else if (one.count(c)) {
      toks.push_back(Tok(one[c], string(1, c), line, col));
      ++i; ++col;
    } else {
      throw ParseError(line, col, string("unexpected character '") + c + "'");
    }
  }
  toks.push_back(Tok(T_END, "", line, col));
  return toks;
}

struct Node {
  string kind, text;
  vector<Node*> kids;
  Node(const string& kind, const string& text = "") : kind(kind), text(text) {}
  ~Node() { for (size_t i = 0; i < kids.size(); ++i) delete kids[i]; }
};

class Parser {
 public:
  long funcs, decls, stmts, exprs, nodes;
  explicit Parser(const vector<Tok>& toks) : t(toks), p(0) {
    funcs = decls = stmts = exprs = nodes = 0;
  }
  Node* parseTranslationUnit();
  void checkEnd() {
    if (!at(T_END)) {
      const Tok& t = peek();
      throw ParseError(t.line, t.col, "unexpected trailing " + t.desc());
    }
  }
 private:
  const vector<Tok>& t;
  size_t p;
  Node* node(const string& kind, const string& text = "") {
    ++nodes;
    return new Node(kind, text);
  }
  const Tok& peek(int k = 0) const {
    size_t j = p + k;
    if (j >= t.size()) j = t.size() - 1;
    return t[j];
  }
  bool at(TokType a) const { return peek().t == a; }
  template <typename... Ts>
  bool at(TokType a, Ts... rest) const {
    return peek().t == a || at(rest...);
  }
  bool at() const { return false; }
  Tok next() { return t[p++]; }
  Tok expect(TokType want, const string& what) {
    if (at(want)) return next();
    const Tok& tok = peek();
    throw ParseError(tok.line, tok.col,
                     "expected " + what + ", found " + tok.desc());
  }
  void fail(const string& msg) {
    const Tok& tok = peek();
    throw ParseError(tok.line, tok.col, msg);
  }
  bool isTypeTok() const {
    return at(T_KW_INT, T_KW_CHAR, T_KW_SHORT, T_KW_VOID);
  }
  Node* parseExternal();
  Node* parseFuncdef(const string& spectext, const string& name);
  Node* parseDeclaration();
  Node* parseInitDeclarator();
  Node* parseStatement();
  Node* parseCompound();
  Node* parseBlockItem();
  Node* parseSelection();
  Node* parseIteration();
  Node* parseForDeclaration();
  Node* parseJump();
  Node* parseLabeled();
  Node* parseExpression();
  Node* parseAssignment();
  bool isLvalue(Node* n);
  Node* parseLogicalOr();
  Node* parseLogicalAnd();
  Node* parseEquality();
  Node* parseRelational();
  Node* parseAdditive();
  Node* parseMultiplicative();
  Node* parseUnary();
  Node* parsePostfix();
  Node* parsePrimary();
};

Node* Parser::parseTranslationUnit() {
  Node* tu = node("tu");
  while (!at(T_END)) {
    if (at(T_SEMI)) { next(); continue; }
    tu->kids.push_back(parseExternal());
  }
  return tu;
}

Node* Parser::parseExternal() {
  if (isTypeTok() || (at(T_IDENT) && peek(1).t == T_IDENT)) {
    size_t mark = p;
    string spectext = next().text;
    if (at(T_IDENT)) {
      string name = next().text;
      if (at(T_LPAREN)) return parseFuncdef(spectext, name);
    }
    p = mark;
    return parseDeclaration();
  }
  fail("expected declaration or function definition");
  return NULL;
}

Node* Parser::parseFuncdef(const string& spectext, const string& name) {
  ++funcs;
  (void)spectext;
  expect(T_LPAREN, "'('");
  if (!at(T_RPAREN)) {
    if (at(T_KW_VOID)) {
      next();
    } else {
      while (true) {
        if (!isTypeTok()) fail("expected parameter type");
        next();
        expect(T_IDENT, "parameter name");
        if (!at(T_COMMA)) break;
        next();
      }
    }
  }
  expect(T_RPAREN, "')'");
  Node* body = parseCompound();
  Node* fn = node("funcdef", name);
  fn->kids.push_back(body);
  return fn;
}

Node* Parser::parseDeclaration() {
  string spectext;
  if (isTypeTok() || at(T_IDENT)) {
    spectext = next().text;
  } else {
    fail("expected type name");
  }
  Node* decl = node("decl", spectext);
  if (!at(T_SEMI)) decl->kids.push_back(parseInitDeclarator());
  expect(T_SEMI, "';'");
  ++decls;
  return decl;
}

Node* Parser::parseInitDeclarator() {
  string name = expect(T_IDENT, "declarator name").text;
  Node* d = node("initdecl", name);
  if (at(T_ASSIGN)) {
    next();
    d->kids.push_back(parseAssignment());
  }
  return d;
}

Node* Parser::parseStatement() {
  ++stmts;
  if (at(T_LBRACE)) return parseCompound();
  if (at(T_KW_IF, T_KW_SWITCH)) return parseSelection();
  if (at(T_KW_WHILE, T_KW_FOR)) return parseIteration();
  if (at(T_KW_BREAK, T_KW_CONTINUE, T_KW_RETURN)) return parseJump();
  if (at(T_KW_CASE, T_KW_DEFAULT) ||
      (at(T_IDENT) && peek(1).t == T_COLON))
    return parseLabeled();
  if (at(T_SEMI)) { next(); return node("empty"); }
  Node* e = parseExpression();
  expect(T_SEMI, "';'");
  Node* s = node("exprstmt");
  s->kids.push_back(e);
  return s;
}

Node* Parser::parseCompound() {
  expect(T_LBRACE, "'{'");
  Node* c = node("compound");
  while (!at(T_RBRACE)) {
    if (at(T_END)) fail("expected '}'");
    c->kids.push_back(parseBlockItem());
  }
  next();
  return c;
}

Node* Parser::parseBlockItem() {
  if (isTypeTok() || (at(T_IDENT) && peek(1).t == T_IDENT))
    return parseDeclaration();
  return parseStatement();
}

Node* Parser::parseSelection() {
  if (at(T_KW_IF)) {
    next();
    expect(T_LPAREN, "'('");
    Node* c = parseExpression();
    expect(T_RPAREN, "')'");
    Node* t = parseStatement();
    if (at(T_KW_ELSE)) {
      next();
      Node* e = parseStatement();
      Node* n = node("ifelse");
      n->kids.push_back(c); n->kids.push_back(t); n->kids.push_back(e);
      return n;
    }
    Node* n = node("if");
    n->kids.push_back(c); n->kids.push_back(t);
    return n;
  }
  expect(T_KW_SWITCH, "'switch'");
  expect(T_LPAREN, "'('");
  Node* c = parseExpression();
  expect(T_RPAREN, "')'");
  Node* b = parseStatement();
  Node* n = node("switch");
  n->kids.push_back(c); n->kids.push_back(b);
  return n;
}

Node* Parser::parseIteration() {
  if (at(T_KW_WHILE)) {
    next();
    expect(T_LPAREN, "'('");
    Node* c = parseExpression();
    expect(T_RPAREN, "')'");
    Node* b = parseStatement();
    Node* n = node("while");
    n->kids.push_back(c); n->kids.push_back(b);
    return n;
  }
  expect(T_KW_FOR, "'for'");
  expect(T_LPAREN, "'('");
  Node* n = node("for");
  if (isTypeTok()) {
    n->kids.push_back(parseForDeclaration());
  } else if (at(T_SEMI)) {
    n->kids.push_back(node("empty-init"));
  } else {
    n->kids.push_back(parseExpression());
  }
  expect(T_SEMI, "';'");
  if (!at(T_SEMI)) n->kids.push_back(parseExpression());
  expect(T_SEMI, "';'");
  if (!at(T_RPAREN)) n->kids.push_back(parseExpression());
  expect(T_RPAREN, "')'");
  n->kids.push_back(parseStatement());
  return n;
}

Node* Parser::parseForDeclaration() {
  string spectext = next().text;
  if (at(T_IDENT)) {
    string name = next().text;
    if (at(T_ASSIGN)) {
      next();
      Node* init = parseAssignment();
      Node* d = node("fordecl", spectext + " " + name);
      d->kids.push_back(init);
      return d;
    }
    return node("fordecl", spectext + " " + name);
  }
  return node("fordecl", spectext);
}

Node* Parser::parseJump() {
  string kw = next().text;
  if (kw == "return" && !at(T_SEMI)) {
    Node* e = parseExpression();
    expect(T_SEMI, "';'");
    Node* n = node("return");
    n->kids.push_back(e);
    return n;
  }
  expect(T_SEMI, "';'");
  return node(kw);
}

Node* Parser::parseLabeled() {
  if (at(T_KW_CASE)) {
    next();
    Node* label = parseAssignment();
    expect(T_COLON, "':'");
    Node* b = parseStatement();
    Node* n = node("case");
    n->kids.push_back(label); n->kids.push_back(b);
    return n;
  }
  if (at(T_KW_DEFAULT)) {
    next();
    expect(T_COLON, "':'");
    Node* b = parseStatement();
    Node* n = node("default");
    n->kids.push_back(b);
    return n;
  }
  string name = expect(T_IDENT, "label name").text;
  expect(T_COLON, "':'");
  Node* b = parseStatement();
  Node* n = node("goto-label", name);
  n->kids.push_back(b);
  return n;
}

bool Parser::isLvalue(Node* n) {
  if (n->kind == "ident") return true;
  return n->kind == "paren" && !n->kids.empty() && isLvalue(n->kids[0]);
}

Node* Parser::parseExpression() {
  Node* first = parseAssignment();
  if (!at(T_COMMA)) return first;
  Node* c = node("comma");
  c->kids.push_back(first);
  while (at(T_COMMA)) {
    next();
    c->kids.push_back(parseAssignment());
  }
  return c;
}

Node* Parser::parseAssignment() {
  ++exprs;
  Node* lhs = parseLogicalOr();
  if (at(T_ASSIGN, T_PLUS_A, T_MINUS_A, T_STAR_A, T_SLASH_A,
         T_PERCENT_A)) {
    string op = next().text;
    if (!isLvalue(lhs)) {
      const Tok& tok = peek(-1);
      throw ParseError(tok.line, tok.col, "invalid lvalue in assignment");
    }
    Node* rhs = parseAssignment();
    Node* n = node("assign", op);
    n->kids.push_back(lhs); n->kids.push_back(rhs);
    return n;
  }
  return lhs;
}

Node* Parser::parseLogicalOr() {
  Node* n = parseLogicalAnd();
  while (at(T_OROR)) {
    string op = next().text;
    Node* rhs = parseLogicalAnd();
    Node* b = node("binop", op);
    b->kids.push_back(n); b->kids.push_back(rhs);
    n = b;
  }
  return n;
}

Node* Parser::parseLogicalAnd() {
  Node* n = parseEquality();
  while (at(T_ANDAND)) {
    string op = next().text;
    Node* rhs = parseEquality();
    Node* b = node("binop", op);
    b->kids.push_back(n); b->kids.push_back(rhs);
    n = b;
  }
  return n;
}

Node* Parser::parseEquality() {
  Node* n = parseRelational();
  while (at(T_EQ, T_NE)) {
    string op = next().text;
    Node* rhs = parseRelational();
    Node* b = node("binop", op);
    b->kids.push_back(n); b->kids.push_back(rhs);
    n = b;
  }
  return n;
}

Node* Parser::parseRelational() {
  Node* n = parseAdditive();
  while (at(T_LT, T_GT, T_LE, T_GE)) {
    string op = next().text;
    Node* rhs = parseAdditive();
    Node* b = node("binop", op);
    b->kids.push_back(n); b->kids.push_back(rhs);
    n = b;
  }
  return n;
}

Node* Parser::parseAdditive() {
  Node* n = parseMultiplicative();
  while (at(T_PLUS, T_MINUS)) {
    string op = next().text;
    Node* rhs = parseMultiplicative();
    Node* b = node("binop", op);
    b->kids.push_back(n); b->kids.push_back(rhs);
    n = b;
  }
  return n;
}

Node* Parser::parseMultiplicative() {
  Node* n = parseUnary();
  while (at(T_STAR, T_SLASH, T_PERCENT)) {
    string op = next().text;
    Node* rhs = parseUnary();
    Node* b = node("binop", op);
    b->kids.push_back(n); b->kids.push_back(rhs);
    n = b;
  }
  return n;
}

Node* Parser::parseUnary() {
  if (at(T_BANG, T_AMP, T_PLUSPLUS, T_MINUSMINUS)) {
    string op = next().text;
    Node* n = node("unary", op);
    n->kids.push_back(parseUnary());
    return n;
  }
  return parsePostfix();
}

Node* Parser::parsePostfix() {
  Node* n = parsePrimary();
  while (true) {
    if (at(T_PLUSPLUS, T_MINUSMINUS)) {
      Node* p = node("postfix", next().text);
      p->kids.push_back(n);
      n = p;
    } else if (at(T_LPAREN)) {
      next();
      Node* c = node("call");
      c->kids.push_back(n);
      if (!at(T_RPAREN)) {
        c->kids.push_back(parseAssignment());
        while (at(T_COMMA)) {
          next();
          c->kids.push_back(parseAssignment());
        }
      }
      expect(T_RPAREN, "')'");
      n = c;
    } else {
      return n;
    }
  }
}

Node* Parser::parsePrimary() {
  if (at(T_INT)) {
    Tok t = next();
    return node("int", t.text);
  }
  if (at(T_CHAR)) {
    Tok t = next();
    return node("char", t.text);
  }
  if (at(T_IDENT)) {
    Tok t = next();
    return node("ident", t.text);
  }
  if (at(T_STRING)) {
    string parts;
    while (at(T_STRING)) parts += next().text;
    return node("string", parts);
  }
  if (at(T_LPAREN)) {
    next();
    Node* e = parseExpression();
    expect(T_RPAREN, "')'");
    Node* n = node("paren");
    n->kids.push_back(e);
    return n;
  }
  fail("expected expression, found " + peek().desc());
  return NULL;
}

static string escapeText(const string& s) {
  string out;
  for (size_t i = 0; i < s.size(); ++i) {
    char c = s[i];
    if (c == '\\') out += "\\\\";
    else if (c == '\n') out += "\\n";
    else if (c == '\t') out += "\\t";
    else if (c == '\r') out += "\\r";
    else if (c == '\0') out += "\\0";
    else out += c;
  }
  return out;
}

static void dumpTree(ostream& out, Node* n) {
  out << "(" << n->kind;
  if (!n->text.empty()) out << " " << escapeText(n->text);
  for (size_t i = 0; i < n->kids.size(); ++i) {
    out << " ";
    dumpTree(out, n->kids[i]);
  }
  out << ")";
}

int main(int argc, char** argv) {
  if (argc != 2) {
    cerr << "usage: parsedump FILE" << endl;
    return 2;
  }
  ifstream in(argv[1]);
  if (!in) {
    cerr << argv[1] << ": cannot open file" << endl;
    return 2;
  }
  ostringstream buf;
  buf << in.rdbuf();
  try {
    vector<Tok> toks = tokenize(buf.str());
    Parser p(toks);
    Node* tree = p.parseTranslationUnit();
    p.checkEnd();
    dumpTree(cout, tree);
    cout << "\n";
    delete tree;
  } catch (const ParseError& e) {
    cerr << argv[1] << ":" << e.str() << endl;
    return 1;
  }
  return 0;
}
