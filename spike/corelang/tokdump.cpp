// Differential tokenizer (C++ baseline) for the core-language spike.
// Tokenizer extracted from spike/handparse/parser.cpp; dumps one
// `LINE:COL KIND TEXT` line per token (TEXT escaped, `end` has no TEXT).
// Usage: tokdump FILE (exit 1 on tokenize error).
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

static string kindOf(TokType t) {
  switch (t) {
    case T_END: return "end";
    case T_IDENT: return "ident";
    case T_INT: return "int";
    case T_CHAR: return "char";
    case T_STRING: return "string";
    default: break;
  }
  if (t >= T_KW_INT && t <= T_KW_RETURN) return "kw";
  return "punct";
}

int main(int argc, char** argv) {
  if (argc != 2) {
    cerr << "usage: tokdump FILE" << endl;
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
    for (size_t i = 0; i < toks.size(); ++i) {
      const Tok& t = toks[i];
      cout << t.line << ":" << t.col << " " << kindOf(t.t);
      if (t.t != T_END) cout << " " << escapeText(t.text);
      cout << "\n";
    }
  } catch (const ParseError& e) {
    cerr << argv[1] << ":" << e.str() << endl;
    return 1;
  }
  return 0;
}

