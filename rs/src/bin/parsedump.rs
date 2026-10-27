// parsedump: dump the freud-core parse tree in differential-test format.
// One single-line S-expression (see tests/differential/SPEC.md).
use std::io::Write;
use std::process::exit;

use freud_core::ast;
use freud_core::parser;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 2 {
        eprintln!("usage: parsedump FILE");
        exit(2);
    }
    let src = match std::fs::read(&args[1]) {
        Ok(b) => b,
        Err(_) => {
            eprintln!("{}: cannot open file", args[1]);
            exit(2);
        }
    };
    let tu = match parser::parse(&src) {
        Ok(t) => t,
        Err(e) => {
            eprintln!("{}:{}", args[1], e);
            exit(1);
        }
    };
    let mut out: Vec<u8> = Vec::new();
    ast::dump_tu(&tu, &out);
    out.push(b'\n');
    std::io::stdout().write_all(&out).unwrap();
}
