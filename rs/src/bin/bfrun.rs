//! `bfrun`: run a Brainfuck program (the `run` path of `src/main.cpp`).
//!
//! Mirrors `freud run` byte for byte: same flags (`-c` required, `-i`,
//! `-o`), errors and usage on stdout, exit 0/1. The usage text is taken
//! from `tests/run/unbalanced_close.out` (which CI proves equals the C++
//! output), not hand-transcribed.
//!
//! Mirrored warts (revisit in the Phase 3 CLI reframe):
//! - Unopenable input is empty and unopenable output is a sink (silent
//!   C++ stream failures).
//! - Unopenable code reads as empty. C++ instead spins forever here:
//!   `BrainfuckReader` only breaks on `eof()`, which a failed-open
//!   stream never reports. A hang is documented, not mirrored.

use freud_core::runner;
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
    // `parse_params` for `command == "run"`: unknown flags ignored.
    let args: Vec<String> = std::env::args().skip(1).collect();
    let mut code: Option<String> = None;
    let mut input: Option<String> = None;
    let mut output: Option<String> = None;
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
            "-i" => {
                i += 1;
                if i < args.len() {
                    input = Some(args[i].clone());
                } else {
                    fail("Parameter -i is missing a value.");
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
            _ => {}
        }
        i += 1;
    }
    let code_path = match code {
        Some(p) => p,
        None => fail("Parameter -c is required"),
    };

    // Mirror: unopenable code reads as empty; a mid-read failure keeps
    // whatever was read (as with the C++ stream).
    let mut code_bytes = Vec::new();
    if let Ok(mut f) = File::open(&code_path) {
        let _ = f.read_to_end(&mut code_bytes);
    }

    let mut input_box: Box<dyn Read> = match input {
        Some(p) => match File::open(&p) {
            Ok(f) => Box::new(f),
            Err(_) => Box::new(io::empty()),
        },
        None => Box::new(io::stdin()),
    };
    let mut output_box: Box<dyn Write> = match output {
        Some(p) => match File::create(&p) {
            Ok(f) => Box::new(f),
            Err(_) => Box::new(io::sink()),
        },
        None => Box::new(io::stdout()),
    };

    if let Err(e) = runner::run(&code_bytes, &mut input_box, &mut output_box) {
        // Flush program output first so the error lands after it,
        // exactly like the C++ `cout` interleaving.
        let _ = output_box.flush();
        fail(e);
    }
}
