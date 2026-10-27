// bfcompile: compile a C-subset file to Brainfuck (differential harness).
// BF goes to stdout; usage/open errors exit 2, compile errors exit 1.
use std::io::Write;
use std::process::exit;

use freud_core::compile;

fn main() {
    let args: Vec<String> = std::env::args().collect();
    if args.len() != 2 {
        eprintln!("usage: bfcompile FILE");
        exit(2);
    }
    let src = match std::fs::read(&args[1]) {
        Ok(b) => b,
        Err(_) => {
            eprintln!("{}: cannot open file", args[1]);
            exit(2);
        }
    };
    match compile::compile(&src) {
        Ok(bf) => {
            std::io::stdout().write_all(&bf).unwrap();
        }
        Err(e) => {
            eprintln!("{}: error: {}", args[1], e);
            exit(1);
        }
    }
}
