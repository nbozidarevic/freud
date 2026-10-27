// tokdump: dump the freud-core token stream in differential-test format.
// One `LINE:COL KIND TEXT` line per token; mirrors the C++ reference.
use std::io::Write;
use std::process::exit;

use freud_core::token::{self, Kind};

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 2 {
        eprintln!("usage: tokdump FILE");
        exit(2);
    }
    let src = match std::fs::read(&args[1]) {
        Ok(b) => b,
        Err(_) => {
            eprintln!("{}: cannot open file", args[1]);
            exit(2);
        }
    };
    let toks = match token::tokenize(&src) {
        Ok(t) => t,
        Err(e) => {
            eprintln!("{}:{}", args[1], e);
            exit(1);
        }
    };
    let mut out: Vec<u8> = Vec::new();
    for t in &toks {
        out.extend_from_slice(
            format!("{}:{} {}", t.line, t.col, t.kind.dump_name()).as_bytes(),
        );
        if t.kind != Kind::End {
            out.push(b' ');
            token::escape_into(&mut out, &t.text);
        }
        out.push(b'\n');
    }
    std::io::stdout().write_all(&out).unwrap();
}
