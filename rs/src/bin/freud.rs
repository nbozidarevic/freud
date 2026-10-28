//! `freud`: transpile-first CLI (compile by default; run/format/help auxiliary).

use freud_core::cli;

fn main() {
    let args: Vec<String> = std::env::args().skip(1).collect();
    if args.is_empty() {
        cli::print_header_and_usage();
        return;
    }
    // Note: flags parse before dispatch, so `freud bogus -c` reports
    // the missing value (compile path), not an unknown command.
    let (command, cmd_args) = match args[0].as_str() {
        "compile" | "run" | "format" => (args[0].as_str(), &args[1..]),
        "help" | "--help" | "-h" => {
            cli::print_header_and_usage();
            return;
        }
        "--version" => {
            println!("freud {}", env!("CARGO_PKG_VERSION"));
            return;
        }
        _ => ("compile", &args[..]),
    };
    let params = match cli::parse_params(command, cmd_args) {
        Ok(p) => p,
        Err(e) => cli::fail(e),
    };
    let result = match command {
        "run" => cli::cmd_run(&params),
        "format" => cli::cmd_format(&params),
        _ => cli::cmd_compile(&params),
    };
    if let Err(e) = result {
        cli::fail(&e);
    }
}
