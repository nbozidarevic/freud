//! Shared command-line layer for the `freud` CLI (`src/main.cpp`).
//!
//! Byte-for-byte mirror: usage text (generated from the golden, as in
//! `bfrun.rs`), flag-parsing quirks, errors on stdout, exit codes. Used
//! by the unified `freud` binary and the differential harnesses.
//!
//! Mirrored warts (revisit in the Phase 3 CLI reframe):
//! - Unopenable input is empty and unopenable output is a sink (silent
//!   C++ stream failures).
//! - Unopenable code reads as empty. C++ instead spins forever here
//!   (`BrainfuckReader` never sees EOF on a failed stream) — a hang is
//!   documented, not mirrored (see `docs/semantics.md`).
//! - On compile errors, no partial output precedes the message: C++
//!   emits whatever the visitor generated before the throw, while the
//!   port compiles all-or-nothing. Error text, usage, and exit 1 match.

use std::fs::File;
use std::io::{self, Read, Write};
use std::process::exit;

use crate::{compile, format, runner};

pub const USAGE: &str = "Usage:\n\t\x1b[1mfreud\x1b[0m \x1b[4mcommand\x1b[0m [parametres]\n\nSupported commands:\n\n\t\x1b[1mcompile\x1b[0m [-c code-file] [-o output-file]\n\n\t\tCompiles the specified C program to Brainfuck.\n\n\t\tIf no code file is specified, the standard\n\t\tinput is used.\n\n\t\tIf no output file is specified, the standard\n\t\toutput is used.\n\n\t\x1b[1mformat\x1b[0m [-c code-file] [-o output-file] [-m]\n\n\t\tFormats the specified Brainfuck program by removing all\n\t\tinvalid characters and adding indentation.\n\n\t\tIf no code file is specified, the standard\n\t\tinput is used.\n\n\t\tIf no output file is specified, the standard\n\t\toutput is used.\n\n\t\tIf the -m flag is specified, all whitespace is removed.\n\n\t\x1b[1mrun\x1b[0m -c code-file [-i input-file] [-o output-file]\n\n\t\tExecutes the specified Brainfuck program.\n\n\t\tIf no input file is specified, the standard\n\t\tinput is used.\n\n\t\tIf no output file is specified, the standard\n\t\toutput is used.\n\n";

pub const HEADER: &str =
    "Freud \u{2013} A toolset for working with the Brainfuck programming language\n\n";

/// Parsed flags (`parse_params`).
pub struct Params {
    pub code: Option<String>,
    pub input: Option<String>,
    pub output: Option<String>,
    pub minify: bool,
}

/// Parse flags for `command`: `-c`/`-o` consume the next arg (missing
/// value is an error), `-i` only exists for `run`, `-m` is recorded for
/// every command, anything else is ignored.
pub fn parse_params(command: &str, args: &[String]) -> Result<Params, &'static str> {
    let mut p = Params {
        code: None,
        input: None,
        output: None,
        minify: false,
    };
    let mut i = 0;
    while i < args.len() {
        match args[i].as_str() {
            "-c" => {
                i += 1;
                if i < args.len() {
                    p.code = Some(args[i].clone());
                } else {
                    return Err("Parameter -c is missing a value.");
                }
            }
            "-i" if command == "run" => {
                i += 1;
                if i < args.len() {
                    p.input = Some(args[i].clone());
                } else {
                    return Err("Parameter -i is missing a value.");
                }
            }
            "-o" => {
                i += 1;
                if i < args.len() {
                    p.output = Some(args[i].clone());
                } else {
                    return Err("Parameter -o is missing a value.");
                }
            }
            "-m" => p.minify = true,
            _ => {}
        }
        i += 1;
    }
    Ok(p)
}

/// Print `msg` plus usage on stdout and exit 1 (`print_caught_error`).
pub fn fail(msg: &str) -> ! {
    let stdout = io::stdout();
    let mut h = stdout.lock();
    let _ = writeln!(h, "{}\n", msg);
    let _ = h.write_all(USAGE.as_bytes());
    let _ = h.flush();
    exit(1);
}

/// Print the header plus usage on stdout (no-args invocation).
pub fn print_header_and_usage() {
    let stdout = io::stdout();
    let mut h = stdout.lock();
    let _ = h.write_all(HEADER.as_bytes());
    let _ = h.write_all(USAGE.as_bytes());
    let _ = h.flush();
}

/// Print the unknown-command error plus usage on stdout.
pub fn print_unknown_command(command: &str) {
    let stdout = io::stdout();
    let mut h = stdout.lock();
    let _ = writeln!(h, "Unknown command \"{}\".\n", command);
    let _ = h.write_all(USAGE.as_bytes());
    let _ = h.flush();
}

/// Read code bytes: file, or stdin when `-c` is absent. Unopenable
/// files read as empty; a mid-read failure keeps what was read.
pub fn read_code(path: Option<&str>) -> Vec<u8> {
    let mut buf = Vec::new();
    match path {
        Some(p) => {
            if let Ok(mut f) = File::open(p) {
                let _ = f.read_to_end(&mut buf);
            }
        }
        None => {
            let _ = io::stdin().read_to_end(&mut buf);
        }
    }
    buf
}

/// Open the run input: file, or stdin when `-i` is absent. Unopenable
/// files read as empty.
pub fn open_input(path: Option<&str>) -> Box<dyn Read> {
    match path {
        Some(p) => match File::open(p) {
            Ok(f) => Box::new(f),
            Err(_) => Box::new(io::empty()),
        },
        None => Box::new(io::stdin()),
    }
}

/// Open an output: file, or stdout when `-o` is absent. Unopenable
/// files behave as a sink.
pub fn open_output(path: Option<&str>) -> Box<dyn Write> {
    match path {
        Some(p) => match File::create(p) {
            Ok(f) => Box::new(f),
            Err(_) => Box::new(io::sink()),
        },
        None => Box::new(io::stdout()),
    }
}

/// `freud compile`: C-subset source to Brainfuck. Returns the error
/// message on failure (the caller reports it with usage).
pub fn cmd_compile(p: &Params) -> Result<(), String> {
    let src = read_code(p.code.as_deref());
    let bf = compile::compile(&src).map_err(|e| e.to_string())?;
    let mut out = open_output(p.output.as_deref());
    let _ = out.write_all(&bf);
    let _ = out.flush();
    Ok(())
}

/// `freud run`: execute a Brainfuck program. Returns the error message
/// on failure (the caller reports it with usage).
pub fn cmd_run(p: &Params) -> Result<(), &'static str> {
    let code_path = match p.code.as_deref() {
        Some(path) => path,
        None => return Err("Parameter -c is required"),
    };
    let mut code_bytes = Vec::new();
    if let Ok(mut f) = File::open(code_path) {
        let _ = f.read_to_end(&mut code_bytes);
    }
    let mut input = open_input(p.input.as_deref());
    let mut output = open_output(p.output.as_deref());
    if let Err(e) = runner::run(&code_bytes, &mut input, &mut output) {
        // Flush program output first so the error lands after it,
        // exactly like the C++ `cout` interleaving.
        let _ = output.flush();
        return Err(e);
    }
    let _ = output.flush();
    Ok(())
}

/// `freud format`: pretty-print (`minify` strips instead).
pub fn cmd_format(p: &Params) {
    let src = read_code(p.code.as_deref());
    let mut out = open_output(p.output.as_deref());
    format::format(&src, &mut out, p.minify);
    let _ = out.flush();
}
