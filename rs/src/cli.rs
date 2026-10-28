//! Shared command-line layer for the `freud` CLI.
//!
//! Transpile-first contract:
//! - `compile` is the default command: `freud program.c -o program.bf`
//!   just works. `run` and `format` are auxiliary subcommands.
//! - The code file is positional or `-c`; output is `-o` (stdout by
//!   default); run input is `-i` (stdin by default). Without a code
//!   file, `compile`/`format` read stdin; `run` requires a file.
//! - `-i` only exists for `run`, `-m` only affects `format`; anything
//!   else unknown is ignored.
//! - Errors go to stderr with usage, exit 1. Unopenable files are
//!   errors (the retired C++ CLI spun forever on missing code and
//!   silently discarded missing input/output — not mirrored).
//! - On compile errors, no partial output precedes the message (the
//!   port compiles all-or-nothing); error text, usage, and exit 1 match
//!   the old shape.

use std::fs::File;
use std::io::{self, Read, Write};
use std::process::exit;

use crate::{compile, format, runner};

pub const USAGE: &str = "Usage: freud [command] [file] [options]\n\nCompiles by default: `freud program.c -o program.bf` transpiles\nprogram.c. Without -o, output goes to stdout; without a file, input\ncomes from stdin (`run` requires a file).\n\nCommands:\n  compile    Transpile C source to Brainfuck (the default command)\n  run        Run a Brainfuck program\n  format     Pretty-print Brainfuck (-m minifies)\n  help       Show this help\n\nOptions:\n  -c file    Code file (same as the positional file)\n  -o file    Output file (default stdout)\n  -i file    Input file for run (default stdin)\n  -m         Minify (format only)\n";

pub const HEADER: &str = "freud \u{2013} C-to-Brainfuck transpiler\n\n";

/// Parsed flags (`parse_params`).
pub struct Params {
    pub code: Option<String>,
    pub positional: Vec<String>,
    pub input: Option<String>,
    pub output: Option<String>,
    pub minify: bool,
}

impl Params {
    /// The code file: explicit `-c` wins, else the first positional arg.
    pub fn code_file(&self) -> Option<&str> {
        self.code
            .as_deref()
            .or_else(|| self.positional.first().map(String::as_str))
    }
}

/// Parse flags for `command`: `-c`/`-o` consume the next arg (missing
/// value is an error), `-i` only exists for `run`, `-m` is recorded for
/// every command, bare args are collected as positional files, anything
/// else is ignored.
pub fn parse_params(command: &str, args: &[String]) -> Result<Params, &'static str> {
    let mut p = Params {
        code: None,
        positional: Vec::new(),
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
            s if s.starts_with('-') => {}
            s => p.positional.push(s.to_string()),
        }
        i += 1;
    }
    Ok(p)
}

/// Print `msg` plus usage on stderr and exit 1.
pub fn fail(msg: &str) -> ! {
    let stderr = io::stderr();
    let mut h = stderr.lock();
    let _ = writeln!(h, "{}\n", msg);
    let _ = h.write_all(USAGE.as_bytes());
    let _ = h.flush();
    exit(1);
}

/// Print the header plus usage on stdout (no-args and `help`).
pub fn print_header_and_usage() {
    let stdout = io::stdout();
    let mut h = stdout.lock();
    let _ = h.write_all(HEADER.as_bytes());
    let _ = h.write_all(USAGE.as_bytes());
    let _ = h.flush();
}

/// Read code bytes: file, or stdin when no file was given. Unopenable
/// files are errors; a mid-read failure keeps what was read.
pub fn read_code(path: Option<&str>) -> Result<Vec<u8>, String> {
    match path {
        Some(p) => match File::open(p) {
            Ok(mut f) => {
                let mut buf = Vec::new();
                let _ = f.read_to_end(&mut buf);
                Ok(buf)
            }
            Err(_) => Err(format!("Cannot open code file '{}'.", p)),
        },
        None => {
            let mut buf = Vec::new();
            let _ = io::stdin().read_to_end(&mut buf);
            Ok(buf)
        }
    }
}

/// Open the run input: file, or stdin when `-i` is absent.
pub fn open_input(path: Option<&str>) -> Result<Box<dyn Read>, String> {
    match path {
        Some(p) => match File::open(p) {
            Ok(f) => Ok(Box::new(f)),
            Err(_) => Err(format!("Cannot open input file '{}'.", p)),
        },
        None => Ok(Box::new(io::stdin())),
    }
}

/// Open an output: file, or stdout when `-o` is absent.
pub fn open_output(path: Option<&str>) -> Result<Box<dyn Write>, String> {
    match path {
        Some(p) => match File::create(p) {
            Ok(f) => Ok(Box::new(f)),
            Err(_) => Err(format!("Cannot open output file '{}'.", p)),
        },
        None => Ok(Box::new(io::stdout())),
    }
}

/// `compile`: C-subset source to Brainfuck. Returns the error message
/// on failure (the caller reports it with usage).
pub fn cmd_compile(p: &Params) -> Result<(), String> {
    let src = read_code(p.code_file())?;
    let bf = compile::compile(&src).map_err(|e| e.to_string())?;
    let mut out = open_output(p.output.as_deref())?;
    let _ = out.write_all(&bf);
    let _ = out.flush();
    Ok(())
}

/// `run`: execute a Brainfuck program. Returns the error message on
/// failure (the caller reports it with usage).
pub fn cmd_run(p: &Params) -> Result<(), String> {
    let code_path = match p.code_file() {
        Some(path) => path,
        None => return Err("run requires a code file.".to_string()),
    };
    let code_bytes = read_code(Some(code_path))?;
    let mut input = open_input(p.input.as_deref())?;
    let mut output = open_output(p.output.as_deref())?;
    if let Err(e) = runner::run(&code_bytes, &mut input, &mut output) {
        // Flush program output first so the error lands after it.
        let _ = output.flush();
        return Err(e.to_string());
    }
    let _ = output.flush();
    Ok(())
}

/// `format`: pretty-print (`minify` strips instead). Returns the error
/// message on failure (the caller reports it with usage).
pub fn cmd_format(p: &Params) -> Result<(), String> {
    let src = read_code(p.code_file())?;
    let mut out = open_output(p.output.as_deref())?;
    format::format(&src, &mut out, p.minify);
    let _ = out.flush();
    Ok(())
}
