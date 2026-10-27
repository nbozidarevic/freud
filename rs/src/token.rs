//! Tokenizer for the freud C subset.
//!
//! Mirrors `tests/differential/tokdump.cpp` token-for-token: same token
//! boundaries, same 1-based line/col tracking (including the `//` and `#`
//! "columns go stale until newline" quirk), same cooked string contents,
//! same error messages.

/// Token kinds. [`Kind::dump_name`] gives the differential-dump label.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Kind {
    Kw,
    Ident,
    Int,
    Char,
    String,
    Punct,
    End,
}

impl Kind {
    /// Differential-dump label (`kw`, `ident`, `int`, `char`, `string`,
    /// `punct`, `end`).
    pub fn dump_name(self) -> &'static str {
        match self {
            Kind::Kw => "kw",
            Kind::Ident => "ident",
            Kind::Int => "int",
            Kind::Char => "char",
            Kind::String => "string",
            Kind::Punct => "punct",
            Kind::End => "end",
        }
    }
}

/// A lexical token: kind, text bytes, 1-based start position.
///
/// Text is the raw source slice, except strings, which are cooked
/// (escapes processed, quotes stripped) — exactly like the C++ reference.
/// `raw` preserves the string's inner source text (escapes unprocessed,
/// quotes stripped) for `printf`/`scanf` fidelity; it is `None` for every
/// other token kind.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Tok {
    pub kind: Kind,
    pub text: Vec<u8>,
    pub raw: Option<Vec<u8>>,
    pub line: usize,
    pub col: usize,
}

/// Tokenizer failure: 1-based position plus the reference message.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct TokenError {
    pub line: usize,
    pub col: usize,
    pub msg: String,
}

impl std::fmt::Display for TokenError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}:{}: error: {}", self.line, self.col, self.msg)
    }
}

impl std::error::Error for TokenError {}

/// Tokenize `src` into the subset token stream, ending with [`Kind::End`].
pub fn tokenize(src: &[u8]) -> Result<Vec<Tok>, TokenError> {
    Cursor::new(src).run()
}

/// Escape token text for the `LINE:COL KIND TEXT` dump format.
pub fn escape_into(out: &mut Vec<u8>, text: &[u8]) {
    for &b in text {
        match b {
            b'\\' => out.extend_from_slice(b"\\\\"),
            b'\n' => out.extend_from_slice(b"\\n"),
            b'\t' => out.extend_from_slice(b"\\t"),
            b'\r' => out.extend_from_slice(b"\\r"),
            0 => out.extend_from_slice(b"\\0"),
            _ => out.push(b),
        }
    }
}

fn escape_val(c: u8) -> Option<u8> {
    match c {
        b'n' => Some(b'\n'),
        b't' => Some(b'\t'),
        b'r' => Some(b'\r'),
        b'0' => Some(0),
        b'\\' => Some(b'\\'),
        b'\'' => Some(b'\''),
        b'"' => Some(b'"'),
        b'a' => Some(7),
        b'b' => Some(8),
        _ => None,
    }
}

const KEYWORDS: [&[u8]; 14] = [
    b"int", b"char", b"short", b"void", b"if", b"else", b"switch", b"case",
    b"default", b"while", b"for", b"break", b"continue", b"return",
];

fn is_keyword(word: &[u8]) -> bool {
    KEYWORDS.iter().any(|k| *k == word)
}

fn is_two_char(a: u8, b: u8) -> bool {
    matches!(
        (a, b),
        (b'=', b'=')
            | (b'!', b'=')
            | (b'<', b'=')
            | (b'>', b'=')
            | (b'+', b'+')
            | (b'-', b'-')
            | (b'&', b'&')
            | (b'|', b'|')
            | (b'+', b'=')
            | (b'-', b'=')
            | (b'*', b'=')
            | (b'/', b'=')
            | (b'%', b'=')
            | (b'<', b'<')
            | (b'>', b'>')
            | (b'-', b'>')
    )
}

fn is_one_char(c: u8) -> bool {
    matches!(
        c,
        b'(' | b')'
            | b'{'
            | b'}'
            | b'['
            | b']'
            | b';'
            | b','
            | b':'
            | b'?'
            | b'+'
            | b'-'
            | b'*'
            | b'/'
            | b'%'
            | b'<'
            | b'>'
            | b'!'
            | b'&'
            | b'|'
            | b'^'
            | b'~'
            | b'='
            | b'.'
    )
}

struct Cursor<'a> {
    src: &'a [u8],
    i: usize,
    line: usize,
    col: usize,
}

impl<'a> Cursor<'a> {
    fn new(src: &'a [u8]) -> Self {
        Cursor {
            src,
            i: 0,
            line: 1,
            col: 1,
        }
    }

    fn err(&self, line: usize, col: usize, msg: String) -> TokenError {
        TokenError { line, col, msg }
    }

    fn run(mut self) -> Result<Vec<Tok>, TokenError> {
        let mut toks: Vec<Tok> = Vec::new();
        let n = self.src.len();
        while self.i < n {
            let c = self.src[self.i];
            if c == b' ' || c == b'\t' || c == b'\r' {
                self.i += 1;
                self.col += 1;
            } else if c == b'\n' {
                self.i += 1;
                self.line += 1;
                self.col = 1;
            } else if c == b'/' && self.i + 1 < n && self.src[self.i + 1] == b'/' {
                while self.i < n && self.src[self.i] != b'\n' {
                    self.i += 1;
                }
            } else if c == b'/' && self.i + 1 < n && self.src[self.i + 1] == b'*' {
                self.i += 2;
                self.col += 2;
                let mut closed = false;
                while self.i < n {
                    if self.src[self.i] == b'*'
                        && self.i + 1 < n
                        && self.src[self.i + 1] == b'/'
                    {
                        self.i += 2;
                        self.col += 2;
                        closed = true;
                        break;
                    }
                    if self.src[self.i] == b'\n' {
                        self.line += 1;
                        self.col = 1;
                    } else {
                        self.col += 1;
                    }
                    self.i += 1;
                }
                if !closed {
                    return Err(self.err(
                        self.line,
                        self.col,
                        "unterminated block comment".to_string(),
                    ));
                }
            } else if c == b'#' {
                while self.i < n && self.src[self.i] != b'\n' {
                    self.i += 1;
                }
            } else if c.is_ascii_digit() {
                let j0 = self.i;
                while self.i < n && self.src[self.i].is_ascii_digit() {
                    self.i += 1;
                }
                toks.push(Tok {
                    kind: Kind::Int,
                    text: self.src[j0..self.i].to_vec(),
                    raw: None,
                    line: self.line,
                    col: self.col,
                });
                self.col += self.i - j0;
            } else if c.is_ascii_alphabetic() || c == b'_' {
                let j0 = self.i;
                while self.i < n
                    && (self.src[self.i].is_ascii_alphanumeric() || self.src[self.i] == b'_')
                {
                    self.i += 1;
                }
                let word = &self.src[j0..self.i];
                let kind = if is_keyword(word) {
                    Kind::Kw
                } else {
                    Kind::Ident
                };
                toks.push(Tok {
                    kind,
                    text: word.to_vec(),
                    raw: None,
                    line: self.line,
                    col: self.col,
                });
                self.col += self.i - j0;
            } else if c == b'\'' {
                let mut j = self.i + 1;
                if j < n && self.src[j] == b'\\' {
                    if j + 1 >= n {
                        return Err(self.err(
                            self.line,
                            self.col,
                            "bad character literal".to_string(),
                        ));
                    }
                    let ec = self.col + (j - self.i);
                    match escape_val(self.src[j + 1]) {
                        Some(_) => {}
                        None => {
                            return Err(self.err(
                                self.line,
                                ec,
                                "bad escape in literal".to_string(),
                            ))
                        }
                    }
                    j += 2;
                } else if j < n && self.src[j] != b'\'' && self.src[j] != b'\n' {
                    j += 1;
                } else {
                    return Err(self.err(
                        self.line,
                        self.col,
                        "bad character literal".to_string(),
                    ));
                }
                if j >= n || self.src[j] != b'\'' {
                    return Err(self.err(
                        self.line,
                        self.col,
                        "unterminated character literal".to_string(),
                    ));
                }
                j += 1;
                toks.push(Tok {
                    kind: Kind::Char,
                    text: self.src[self.i..j].to_vec(),
                    raw: None,
                    line: self.line,
                    col: self.col,
                });
                self.col += j - self.i;
                self.i = j;
            } else if c == b'"' {
                let mut j = self.i + 1;
                let mut parts: Vec<u8> = Vec::new();
                loop {
                    if j >= n || self.src[j] == b'\n' {
                        return Err(self.err(
                            self.line,
                            self.col,
                            "unterminated string literal".to_string(),
                        ));
                    }
                    if self.src[j] == b'"' {
                        break;
                    }
                    if self.src[j] == b'\\' {
                        if j + 1 >= n {
                            return Err(self.err(
                                self.line,
                                self.col,
                                "bad escape in string literal".to_string(),
                            ));
                        }
                        let ec = self.col + (j - self.i);
                        match escape_val(self.src[j + 1]) {
                            Some(v) => parts.push(v),
                            None => {
                                return Err(self.err(
                                    self.line,
                                    ec,
                                    "bad escape in literal".to_string(),
                                ))
                            }
                        }
                        j += 2;
                    } else {
                        parts.push(self.src[j]);
                        j += 1;
                    }
                }
                j += 1;
                toks.push(Tok {
                    kind: Kind::String,
                    text: parts,
                    // Inner source text: quotes at i and j-1 are stripped.
                    raw: Some(self.src[self.i + 1..j - 1].to_vec()),
                    line: self.line,
                    col: self.col,
                });
                self.col += j - self.i;
                self.i = j;
            } else if self.i + 1 < n && is_two_char(self.src[self.i], self.src[self.i + 1]) {
                toks.push(Tok {
                    kind: Kind::Punct,
                    text: self.src[self.i..self.i + 2].to_vec(),
                    raw: None,
                    line: self.line,
                    col: self.col,
                });
                self.i += 2;
                self.col += 2;
            } else if is_one_char(c) {
                toks.push(Tok {
                    kind: Kind::Punct,
                    text: vec![c],
                    raw: None,
                    line: self.line,
                    col: self.col,
                });
                self.i += 1;
                self.col += 1;
            } else {
                return Err(self.err(
                    self.line,
                    self.col,
                    format!("unexpected character '{}'", c as char),
                ));
            }
        }
        toks.push(Tok {
            kind: Kind::End,
            text: Vec::new(),
            raw: None,
            line: self.line,
            col: self.col,
        });
        Ok(toks)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn toks(src: &[u8]) -> Vec<Tok> {
        tokenize(src).expect("tokenize failed")
    }

    fn kinds(src: &[u8]) -> Vec<Kind> {
        toks(src).iter().map(|t| t.kind).collect()
    }

    fn texts(src: &[u8]) -> Vec<String> {
        toks(src)
            .iter()
            .map(|t| String::from_utf8_lossy(&t.text).into_owned())
            .collect()
    }

    fn assert_kinds(src: &[u8], want: &[Kind]) {
        assert_eq!(kinds(src), want);
    }

    fn assert_texts(src: &[u8], want: &[&str]) {
        let got = texts(src);
        assert_eq!(got.len(), want.len(), "token count");
        for (g, w) in got.iter().zip(want.iter()) {
            assert_eq!(g, w);
        }
    }

    #[test]
    fn empty_yields_end_only() {
        let t = toks(b"");
        assert_eq!(t.len(), 1);
        assert_eq!(t[0].kind, Kind::End);
        assert_eq!((t[0].line, t[0].col), (1, 1));
    }

    #[test]
    fn declaration() {
        let t = toks(b"int x = 42;");
        assert_kinds(
            b"int x = 42;",
            &[
                Kind::Kw,
                Kind::Ident,
                Kind::Punct,
                Kind::Int,
                Kind::Punct,
                Kind::End,
            ],
        );
        assert_eq!(t[0].text, b"int");
        assert_eq!(t[1].text, b"x");
        assert_eq!(t[3].text, b"42");
        assert_eq!((t[3].line, t[3].col), (1, 9));
        assert_eq!((t[5].line, t[5].col), (1, 12));
    }

    #[test]
    fn keywords_vs_idents() {
        assert_kinds(
            b"if iffy while3 return",
            &[Kind::Kw, Kind::Ident, Kind::Ident, Kind::Kw, Kind::End],
        );
        let t = toks(b"if iffy while3 return");
        assert_eq!(t[1].text, b"iffy");
        assert_eq!(t[2].text, b"while3");
    }

    #[test]
    fn all_two_char_operators() {
        assert_texts(
            b"a==b!=c<=d>=e++f--g&&h||i+=j-=k*=l/=m%=n<<o>>p->q;",
            &[
                "a", "==", "b", "!=", "c", "<=", "d", ">=", "e", "++", "f", "--",
                "g", "&&", "h", "||", "i", "+=", "j", "-=", "k", "*=", "l",
                "/=", "m", "%=", "n", "<<", "o", ">>", "p", "->", "q", ";", "",
            ],
        );
    }

    #[test]
    fn strings_are_cooked() {
        let t = toks(br#""a\nb\t\"q\"\\""#);
        assert_eq!(t[0].kind, Kind::String);
        assert_eq!((t[0].line, t[0].col), (1, 1));
        assert_eq!(t[0].text, b"a\nb\t\"q\"\\");
    }

    #[test]
    fn strings_carry_raw_text() {
        let t = toks(br#""a\nb""#);
        assert_eq!(t[0].kind, Kind::String);
        assert_eq!(t[0].text, b"a\nb");
        assert_eq!(t[0].raw, Some(b"a\\nb".to_vec()));
        let t = toks(b"42");
        assert_eq!(t[0].raw, None);
    }

    #[test]
    fn chars_keep_raw_slice() {
        assert_texts(b"'x' '\\n'", &["'x'", "'\\n'", ""]);
        let t = toks(b"'x' '\\n'");
        assert_eq!(t[0].kind, Kind::Char);
        assert_eq!(t[1].kind, Kind::Char);
    }

    #[test]
    fn comments_and_hash_lines_skipped() {
        let src = b"int a; // trailing\n# define X\n/* multi\nline */ b=c;";
        assert_kinds(
            src,
            &[
                Kind::Kw,
                Kind::Ident,
                Kind::Punct,
                Kind::Ident,
                Kind::Punct,
                Kind::Ident,
                Kind::Punct,
                Kind::End,
            ],
        );
        let t = toks(src);
        assert_eq!((t[3].line, t[3].col), (4, 9));
        assert_eq!(t[3].text, b"b");
    }

    #[test]
    fn positions_across_lines() {
        let t = toks(b"a\nbb\n;");
        assert_eq!((t[0].line, t[0].col), (1, 1));
        assert_eq!((t[1].line, t[1].col), (2, 1));
        assert_eq!((t[2].line, t[2].col), (3, 1));
        assert_eq!((t[3].line, t[3].col), (3, 2));
    }

    #[test]
    fn no_floats_int_dot_int() {
        // Pins the reference quirk: `3.14` is int, dot, int.
        assert_texts(b"3.14", &["3", ".", "14", ""]);
        assert_kinds(b"3.14", &[Kind::Int, Kind::Punct, Kind::Int, Kind::End]);
    }

    #[test]
    fn escape_into_covers_controls() {
        let mut out = Vec::new();
        escape_into(&mut out, b"a\nb\\c\x00d\t\re");
        assert_eq!(out, b"a\\nb\\\\c\\0d\\t\\re");
    }

    #[test]
    fn error_unterminated_string() {
        assert_eq!(
            tokenize(b"\"abc"),
            Err(TokenError {
                line: 1,
                col: 1,
                msg: "unterminated string literal".to_string(),
            })
        );
    }

    #[test]
    fn error_bad_escape_points_at_backslash() {
        assert_eq!(
            tokenize(b"\"a\\qb\""),
            Err(TokenError {
                line: 1,
                col: 3,
                msg: "bad escape in literal".to_string(),
            })
        );
    }

    #[test]
    fn error_unexpected_character() {
        assert_eq!(
            tokenize(b"int $;"),
            Err(TokenError {
                line: 1,
                col: 5,
                msg: "unexpected character '$'".to_string(),
            })
        );
    }

    #[test]
    fn error_unterminated_block_comment() {
        assert_eq!(
            tokenize(b"/* x"),
            Err(TokenError {
                line: 1,
                col: 5,
                msg: "unterminated block comment".to_string(),
            })
        );
    }

    #[test]
    fn error_bad_character_literal() {
        assert_eq!(
            tokenize(b"''"),
            Err(TokenError {
                line: 1,
                col: 1,
                msg: "bad character literal".to_string(),
            })
        );
    }
}
