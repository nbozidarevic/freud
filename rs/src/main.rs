// Differential tokenizer (Rust core) for the C++ migration.
// Mirrors tests/differential/tokdump.cpp byte-for-byte on stdout:
// one `LINE:COL KIND TEXT` line per token, TEXT escaped.
use std::env;
use std::fs;
use std::io::Write;
use std::process::exit;

struct Tok {
    kind: &'static str,
    text: Vec<u8>,
    line: usize,
    col: usize,
}

fn fail(file: &str, line: usize, col: usize, msg: impl std::fmt::Display) -> ! {
    eprintln!("{}:{}:{}: error: {}", file, line, col, msg);
    exit(1);
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

fn tokenize(file: &str, src: &[u8]) -> Vec<Tok> {
    let mut toks: Vec<Tok> = Vec::new();
    let n = src.len();
    let mut i = 0usize;
    let mut line = 1usize;
    let mut col = 1usize;
    while i < n {
        let c = src[i];
        if c == b' ' || c == b'\t' || c == b'\r' {
            i += 1;
            col += 1;
        } else if c == b'\n' {
            i += 1;
            line += 1;
            col = 1;
        } else if c == b'/' && i + 1 < n && src[i + 1] == b'/' {
            while i < n && src[i] != b'\n' {
                i += 1;
            }
        } else if c == b'/' && i + 1 < n && src[i + 1] == b'*' {
            i += 2;
            col += 2;
            let mut closed = false;
            while i < n {
                if src[i] == b'*' && i + 1 < n && src[i + 1] == b'/' {
                    i += 2;
                    col += 2;
                    closed = true;
                    break;
                }
                if src[i] == b'\n' {
                    line += 1;
                    col = 1;
                } else {
                    col += 1;
                }
                i += 1;
            }
            if !closed {
                fail(file, line, col, "unterminated block comment");
            }
        } else if c == b'#' {
            while i < n && src[i] != b'\n' {
                i += 1;
            }
        } else if c.is_ascii_digit() {
            let j0 = i;
            while i < n && src[i].is_ascii_digit() {
                i += 1;
            }
            toks.push(Tok {
                kind: "int",
                text: src[j0..i].to_vec(),
                line,
                col,
            });
            col += i - j0;
        } else if c.is_ascii_alphabetic() || c == b'_' {
            let j0 = i;
            while i < n && (src[i].is_ascii_alphanumeric() || src[i] == b'_') {
                i += 1;
            }
            let word = &src[j0..i];
            let kind = if is_keyword(word) { "kw" } else { "ident" };
            toks.push(Tok {
                kind,
                text: word.to_vec(),
                line,
                col,
            });
            col += i - j0;
        } else if c == b'\'' {
            let mut j = i + 1;
            if j < n && src[j] == b'\\' {
                if j + 1 >= n {
                    fail(file, line, col, "bad character literal");
                }
                let ec = col + (j - i);
                match escape_val(src[j + 1]) {
                    Some(_) => {}
                    None => fail(file, line, ec, "bad escape in literal"),
                }
                j += 2;
            } else if j < n && src[j] != b'\'' && src[j] != b'\n' {
                j += 1;
            } else {
                fail(file, line, col, "bad character literal");
            }
            if j >= n || src[j] != b'\'' {
                fail(file, line, col, "unterminated character literal");
            }
            j += 1;
            toks.push(Tok {
                kind: "char",
                text: src[i..j].to_vec(),
                line,
                col,
            });
            col += j - i;
            i = j;
        } else if c == b'"' {
            let mut j = i + 1;
            let mut parts: Vec<u8> = Vec::new();
            loop {
                if j >= n || src[j] == b'\n' {
                    fail(file, line, col, "unterminated string literal");
                }
                if src[j] == b'"' {
                    break;
                }
                if src[j] == b'\\' {
                    if j + 1 >= n {
                        fail(file, line, col, "bad escape in string literal");
                    }
                    let ec = col + (j - i);
                    match escape_val(src[j + 1]) {
                        Some(v) => parts.push(v),
                        None => fail(file, line, ec, "bad escape in literal"),
                    }
                    j += 2;
                } else {
                    parts.push(src[j]);
                    j += 1;
                }
            }
            j += 1;
            toks.push(Tok {
                kind: "string",
                text: parts,
                line,
                col,
            });
            col += j - i;
            i = j;
        } else if i + 1 < n && is_two_char(src[i], src[i + 1]) {
            toks.push(Tok {
                kind: "punct",
                text: src[i..i + 2].to_vec(),
                line,
                col,
            });
            i += 2;
            col += 2;
        } else if is_one_char(c) {
            toks.push(Tok {
                kind: "punct",
                text: vec![c],
                line,
                col,
            });
            i += 1;
            col += 1;
        } else {
            fail(file, line, col, format!("unexpected character '{}'", c as char));
        }
    }
    toks.push(Tok {
        kind: "end",
        text: Vec::new(),
        line,
        col,
    });
    toks
}

fn escape_into(out: &mut Vec<u8>, text: &[u8]) {
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

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        eprintln!("usage: tokdump FILE");
        exit(2);
    }
    let src = match fs::read(&args[1]) {
        Ok(b) => b,
        Err(_) => {
            eprintln!("{}: cannot open file", args[1]);
            exit(2);
        }
    };
    let toks = tokenize(&args[1], &src);
    let mut out: Vec<u8> = Vec::new();
    for t in &toks {
        out.extend_from_slice(format!("{}:{} {}", t.line, t.col, t.kind).as_bytes());
        if t.kind != "end" {
            out.push(b' ');
            escape_into(&mut out, &t.text);
        }
        out.push(b'\n');
    }
    std::io::stdout().write_all(&out).unwrap();
}
