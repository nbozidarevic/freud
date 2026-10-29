//! Brainfuck program runner (`BrainfuckRunner` + `BrainfuckReader`).
//!
//! Ported from the retired C++ `BrainfuckRunner` semantics:
//! - `u8` wrapping tape, 1024 cells, origin at 512, same growth rules
//!   (prepend on the left, `2*index+1` resize on the right).
//! - `,` reads one byte and leaves the cell unchanged on EOF (pinned).
//! - Non-command bytes are ignored, exactly like `BrainfuckReader`.
//! - Unbalanced brackets report the C++ messages verbatim.
//! - A precomputed jump table makes `[` skips and `]` jumps O(1); a
//!   depth counter (incremented on `[`, decremented on `]`, including
//!   re-executions) replaces the loop stack, with identical error
//!   behavior: unmatched `]` errors at runtime in execution order, so
//!   partial output precedes the error exactly as before.
//! - Input/output are buffered (`BufReader`/`BufWriter`): `,`/`.` cost
//!   one buffer touch, not one syscall, per byte. Byte order and EOF
//!   semantics are unchanged, and output is flushed before returning.
//!
//! Deliberate deviation: C++ spins forever when a zero-cell `[` has no
//! matching `]` (it keeps reading `NONE` past EOF). This port reports
//! `unclosed '['` instead — a hang has no observable output to match,
//! so no differential can distinguish them except by timeout.

use std::io::{BufReader, BufWriter, Read, Write};

/// `]` with no matching `[` (`BrainfuckRunner` message, verbatim).
pub const ERR_UNEXPECTED_CLOSE: &str = "Unbalanced Brainfuck code: unexpected ']'";
/// `[` never closed (`BrainfuckRunner` message, verbatim).
pub const ERR_UNCLOSED_OPEN: &str = "Unbalanced Brainfuck code: unclosed '['";

const TAPE_INIT: usize = 1024;
const ORIGIN_INIT: i64 = 512;

/// Tape index for `pointer`, growing the tape like `BrainfuckRunner::cell`.
fn cell_index(tape: &mut Vec<u8>, origin: &mut i64, pointer: i64) -> usize {
    let index = pointer + *origin;
    if index < 0 {
        let need = (-index) as usize;
        tape.splice(0..0, std::iter::repeat(0).take(need));
        *origin += -index;
        0
    } else if (index as usize) >= tape.len() {
        tape.resize((index as usize) * 2 + 1, 0);
        index as usize
    } else {
        index as usize
    }
}

/// Execute `code` (raw bytes; non-commands ignored), reading input and
/// writing output as the program runs.
///
/// Input is read one byte per `,` (streaming, like `istream::get`): on
/// EOF — or any read failure — the cell is left unchanged.
pub fn run<R: Read, W: Write>(
    code: &[u8],
    input: &mut R,
    output: &mut W,
) -> Result<(), &'static str> {
    let cmds: Vec<u8> = code
        .iter()
        .copied()
        .filter(|b| matches!(b, b'<' | b'>' | b'+' | b'-' | b',' | b'.' | b'[' | b']'))
        .collect();
    // Jump table: matching bracket for each `[`/`]`, `usize::MAX` when
    // unmatched. Built without failing: unmatched brackets error at
    // runtime, in execution order.
    let mut jumps = vec![usize::MAX; cmds.len()];
    let mut open: Vec<usize> = Vec::new();
    for (i, &c) in cmds.iter().enumerate() {
        match c {
            b'[' => open.push(i),
            b']' => {
                if let Some(o) = open.pop() {
                    jumps[o] = i;
                    jumps[i] = o;
                }
            }
            _ => {}
        }
    }
    let mut input = BufReader::with_capacity(8192, input);
    let mut output = BufWriter::new(output);
    let mut tape = vec![0u8; TAPE_INIT];
    let mut origin: i64 = ORIGIN_INIT;
    let mut pointer: i64 = 0;
    let mut depth: usize = 0;
    let mut pc: usize = 0;
    let mut result = Ok(());
    while pc < cmds.len() {
        match cmds[pc] {
            b'<' => {
                pointer -= 1;
                pc += 1;
            }
            b'>' => {
                pointer += 1;
                pc += 1;
            }
            b'+' => {
                let i = cell_index(&mut tape, &mut origin, pointer);
                tape[i] = tape[i].wrapping_add(1);
                pc += 1;
            }
            b'-' => {
                let i = cell_index(&mut tape, &mut origin, pointer);
                tape[i] = tape[i].wrapping_sub(1);
                pc += 1;
            }
            b',' => {
                let mut b = [0u8; 1];
                // `read_exact` retries on Interrupted; EOF or any other
                // failure leaves the cell unchanged, like `get` failing.
                if input.read_exact(&mut b).is_ok() {
                    let i = cell_index(&mut tape, &mut origin, pointer);
                    tape[i] = b[0];
                }
                pc += 1;
            }
            b'.' => {
                let i = cell_index(&mut tape, &mut origin, pointer);
                let _ = output.write_all(&tape[i..i + 1]);
                pc += 1;
            }
            b'[' => {
                let i = cell_index(&mut tape, &mut origin, pointer);
                if tape[i] == 0 {
                    let target = jumps[pc];
                    if target == usize::MAX {
                        // C++ spins here; report instead (see above).
                        result = Err(ERR_UNCLOSED_OPEN);
                        break;
                    }
                    pc = target + 1;
                } else {
                    depth += 1;
                    pc += 1;
                }
            }
            b']' => {
                let target = jumps[pc];
                if target == usize::MAX {
                    result = Err(ERR_UNEXPECTED_CLOSE);
                    break;
                }
                depth -= 1;
                let i = cell_index(&mut tape, &mut origin, pointer);
                if tape[i] != 0 {
                    pc = target;
                } else {
                    pc += 1;
                }
            }
            _ => pc += 1, // unreachable: filtered above
        }
    }
    if result.is_ok() && depth != 0 {
        result = Err(ERR_UNCLOSED_OPEN);
    }
    let _ = output.flush();
    result
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::io::Cursor;

    fn run_str(code: &str, input: &[u8]) -> Result<Vec<u8>, &'static str> {
        let mut out = Vec::new();
        run(code.as_bytes(), &mut Cursor::new(input), &mut out)?;
        Ok(out)
    }

    #[test]
    fn nested_loops_match_fixture() {
        // tests/run/nested.bf + nested.out
        assert_eq!(run_str("++[>+++[>++++<-]<-]>>.", b"").unwrap(), vec![0x18]);
    }

    #[test]
    fn eof_leaves_cell_unchanged() {
        // tests/run/eof.bf + eof.out (`,` at EOF keeps the 3)
        assert_eq!(run_str("+++,.", b"").unwrap(), vec![3]);
    }

    #[test]
    fn eof_keeps_last_byte() {
        assert_eq!(run_str(",.,.", b"A").unwrap(), b"AA");
    }

    #[test]
    fn input_read_bytewise() {
        assert_eq!(run_str(",,.", b"AB").unwrap(), b"B");
    }

    #[test]
    fn ignores_non_commands() {
        assert_eq!(run_str("x+x+.\n", b"").unwrap(), vec![2]);
    }

    #[test]
    fn negative_index() {
        assert_eq!(run_str("<+.", b"").unwrap(), vec![1]);
    }

    #[test]
    fn far_negative_growth_past_origin() {
        let code = "<".repeat(600) + "+.";
        assert_eq!(run_str(&code, b"").unwrap(), vec![1]);
    }

    #[test]
    fn far_positive_growth() {
        let code = ">".repeat(2000) + "+.";
        assert_eq!(run_str(&code, b"").unwrap(), vec![1]);
    }

    #[test]
    fn wraparound_down() {
        assert_eq!(run_str("-.", b"").unwrap(), vec![255]);
    }

    #[test]
    fn wraparound_up() {
        assert_eq!(run_str(&("+".repeat(255) + "."), b"").unwrap(), vec![255]);
        assert_eq!(run_str(&("+".repeat(256) + "."), b"").unwrap(), vec![0]);
    }

    #[test]
    fn loop_skipped_when_zero() {
        assert_eq!(run_str("[.+]+.", b"").unwrap(), vec![1]);
    }

    #[test]
    fn unbalanced_close() {
        // tests/run/unbalanced_close.bf
        assert_eq!(run_str("++]", b"").unwrap_err(), ERR_UNEXPECTED_CLOSE);
    }

    #[test]
    fn unbalanced_open_nonzero() {
        // tests/run/unbalanced_open.bf
        assert_eq!(run_str("++[>>", b"").unwrap_err(), ERR_UNCLOSED_OPEN);
    }

    #[test]
    fn unclosed_zero_skip_reports() {
        // C++ spins forever here; the port reports instead.
        assert_eq!(run_str("[>>", b"").unwrap_err(), ERR_UNCLOSED_OPEN);
    }

    #[test]
    fn loop_reentry_balances_depth() {
        // 3 iterations through `]` jumps and re-executed `[`s.
        assert_eq!(run_str("+++[>+++<-]>.", b"").unwrap(), vec![9]);
    }

    #[test]
    fn zero_skip_jumps_nested() {
        assert_eq!(run_str("[[[]]]+.", b"").unwrap(), vec![1]);
    }

    #[test]
    fn partial_output_precedes_close_error() {
        // The jump table must not reject the stray `]` before running.
        let mut out = Vec::new();
        let err = run(b"+.]", &mut Cursor::new(b""), &mut out).unwrap_err();
        assert_eq!(err, ERR_UNEXPECTED_CLOSE);
        assert_eq!(out, vec![1]);
    }
}
