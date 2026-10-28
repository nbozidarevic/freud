//! Brainfuck code formatter (`BrainfuckFormatter`).
//!
//! Ported from the retired C++ `BrainfuckFormatter` (see git history):
//! - Pretty mode groups consecutive same-class commands (`<>`, `,.`,
//!   `+-`) onto one indented line; `[` and `]` always start a line,
//!   with `]` dedented first. Two spaces per depth level.
//! - Minify mode strips everything but the eight commands.
//! - Both modes end output with a single trailing newline — even for
//!   empty input, since the C++ `endl` is unconditional.
//! - Non-command bytes are ignored, exactly like `BrainfuckReader`.
//!
//! `depth` is signed: a stray `]` drives it negative and subsequent
//! indents print nothing until `[`s recover it, exactly like C++.

use std::io::Write;

/// Format `code` (raw bytes; non-commands ignored) to `output`.
pub fn format<W: Write>(code: &[u8], output: &mut W, minify: bool) {
    let cmds: Vec<u8> = code
        .iter()
        .copied()
        .filter(|b| matches!(b, b'<' | b'>' | b'+' | b'-' | b',' | b'.' | b'[' | b']'))
        .collect();
    if minify {
        for c in &cmds {
            let _ = output.write_all(&[*c]);
        }
        let _ = output.write_all(b"\n");
        return;
    }
    let mut depth: i32 = 0;
    let mut prev: Option<u8> = None;
    for &cmd in &cmds {
        let should_indent = match cmd {
            b'<' | b'>' => !matches!(prev, Some(b'<') | Some(b'>')),
            b',' | b'.' => !matches!(prev, Some(b',') | Some(b'.')),
            b'+' | b'-' => !matches!(prev, Some(b'+') | Some(b'-')),
            b'[' => true,
            b']' => {
                depth -= 1;
                true
            }
            _ => false, // unreachable: filtered above
        };
        if should_indent {
            if prev.is_some() {
                let _ = output.write_all(b"\n");
            }
            for _ in 0..depth {
                let _ = output.write_all(b"  ");
            }
        }
        if cmd == b'[' {
            depth += 1;
        }
        let _ = output.write_all(&[cmd]);
        prev = Some(cmd);
    }
    let _ = output.write_all(b"\n");
}

#[cfg(test)]
mod tests {
    use super::*;

    fn fmt(code: &str, minify: bool) -> String {
        let mut out = Vec::new();
        format(code.as_bytes(), &mut out, minify);
        String::from_utf8(out).unwrap()
    }

    #[test]
    fn pretty_groups_and_indents() {
        assert_eq!(fmt("[+-]", false), "[\n  +-\n]\n");
    }

    #[test]
    fn pretty_class_breaks() {
        assert_eq!(fmt(">>.,<<", false), ">>\n.,\n<<\n");
    }

    #[test]
    fn pretty_nested() {
        assert_eq!(fmt("[[]]", false), "[\n  [\n  ]\n]\n");
    }

    #[test]
    fn pretty_ignores_non_commands() {
        assert_eq!(fmt("a+b.", false), "+\n.\n");
    }

    #[test]
    fn pretty_stray_close_goes_negative() {
        assert_eq!(fmt("]][[", false), "]\n]\n[\n[\n");
    }

    #[test]
    fn pretty_empty_is_newline() {
        assert_eq!(fmt("", false), "\n");
        assert_eq!(fmt("no commands here", false), "\n");
    }

    #[test]
    fn minify_strips_and_ends_newline() {
        assert_eq!(fmt("[+-]\n junk\t", true), "[+-]\n");
    }

    #[test]
    fn minify_empty_is_newline() {
        assert_eq!(fmt("", true), "\n");
    }
}
