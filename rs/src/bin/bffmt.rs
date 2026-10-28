//! `bffmt`: format a Brainfuck program (the `format` path of `src/main.cpp`).
//!
//! Mirrors `freud format` byte for byte: `-c`/`-o` default to stdin/stdout,
//! `-m` minifies, `-i` is ignored (C++ only recognizes it for `run`),
//! errors and usage on stdout, exit 0/1. Usage text identical to
//! `bfrun.rs` (both generated from `tests/run/unbalanced_close.out`);
//! the unified CLI (slice 5e) will deduplicate.
//!
//! Mirrored warts: unopenable output is a sink (silent C++ stream
//! failure). Unopenable code reads as empty; C++ instead spins forever
//! (`BrainfuckReader` never sees EOF on a failed stream) — documented,
//! not mirrored.

use freud_core::format;
use std::fs::File;
use std::io::{self, Read, Write};
use std::process::exit;

const USAGE: &str = "Usage:\n\t\x1b[1mfreud\x1b[0m \x1b[4mcommand\x1b[0m [parametres]\n\nSupported commands:\n\n\t\x1b[1mcompile\x1b[0m [-c code-file] [-o output-file]\n\n\t\tCompiles the specified C program to Brainfuck.\n\n\t\tIf no code file is specified, the standard\n\t\tinput is used.\n\n\t\tIf no output file is specified, the standard\n\t\toutput is used.\n\n\t\x1b[1mformat\x1b[0m [-c code-file] [-o output-file] [-m]\n\n\t\tFormats the specified Brainfuck program by removing all\n\t\tinvalid characters and adding indentation.\n\n\t\tIf no code file is specified, the standard\n\t\tinput is used.\n\n\t\tIf no output file is specified, the standard\n\t\toutput is used.\n\n\t\tIf the -m flag is specified, all whitespace is removed.\n\n\t\x1b[1mrun\x1b[0m -c code-file [-i input-file] [-o output-file]\n\n\t\tExecutes the specified Brainfuck program.\n\n\t\tIf no input file is specified, the standard\n\t\tinput is used.\n\n\t\tIf no output file is specified, the standard\n\t\toutput is used.\n\n";

fn fail(msg: &str) -> ! {
    let stdout = io::stdout();
    let mut h = stdout.lock();
    let _ = writeln!(h, "{}\n", msg);
    let _ = h.write_all(USAGE.as_bytes());
    let _ = h.flush();
    exit(1);
}

fn main() {
    // `parse_params` for `command == "format"`: `-i` and unknown flags
    // ignored, `-c`/`-o` consume the next arg.
    let args: Vec<String> = std::env::args().skip(1).collect();
    let mut code: Option<String> = None;
    let mut output: Option<String> = None;
    let mut minify = false;
    let mut i = 0;
    while i < args.len() {
        match args[i].as_str() {
            "-c" => {
                i += 1;
                if i < args.len() {
                    code = Some(args[i].clone());
                } else {
                    fail("Parameter -c is missing a value.");
                }
            }
            "-o" => {
                i += 1;
                if i < args.len() {
                    output = Some(args[i].clone());
                } else {
                    fail("Parameter -o is missing a value.");
                }
            }
            "-m" => minify = true,
            _ => {}
        }
        i += 1;
    }

    // Mirror: unopenable code reads as empty.
    let mut code_bytes = Vec::new();
    match code {
        Some(p) => {
            if let Ok(mut f) = File::open(&p) {
                let _ = f.read_to_end(&mut code_bytes);
            }
        }
        None => {
            let _ = io::stdin().read_to_end(&mut code_bytes);
        }
    }

    let mut output_box: Box<dyn Write> = match output {
        Some(p) => match File::create(&p) {
            Ok(f) => Box::new(f),
            Err(_) => Box::new(io::sink()),
        },
        None => Box::new(io::stdout()),
    };

    format::format(&code_bytes, &mut output_box, minify);
}
