//! `bffmt`: format a Brainfuck program (differential harness over `cli`).

use freud_core::cli;

fn main() {
    let args: Vec<String> = std::env::args().skip(1).collect();
    let params = match cli::parse_params("format", &args) {
        Ok(p) => p,
        Err(e) => cli::fail(e),
    };
    cli::cmd_format(&params);
}
