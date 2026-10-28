//! `freud`: unified CLI (compile/run/format), ported from retired C++ `main`.
//!
//! Dispatch, flag parsing, and all output bytes match the C++ binary;
//! see `cli` for the shared layer and its documented warts.

use freud_core::cli;
use std::process::exit;

fn main() {
    let args: Vec<String> = std::env::args().skip(1).collect();
    if args.is_empty() {
        cli::print_header_and_usage();
        return;
    }
    let command = args[0].clone();
    // Note: flags parse before dispatch, so `freud bogus -c` reports
    // the missing value, not the unknown command — exactly like C++.
    let params = match cli::parse_params(&command, &args[1..]) {
        Ok(p) => p,
        Err(e) => cli::fail(e),
    };
    if command == "compile" {
        if let Err(e) = cli::cmd_compile(&params) {
            cli::fail(&e);
        }
        return;
    }
    if command == "format" {
        cli::cmd_format(&params);
        return;
    }
    if command == "run" {
        if let Err(e) = cli::cmd_run(&params) {
            cli::fail(e);
        }
        return;
    }
    cli::print_unknown_command(&command);
    exit(1);
}
