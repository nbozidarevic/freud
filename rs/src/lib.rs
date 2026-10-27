//! freud-core: dependency-free transpiler core (C subset → Brainfuck).

pub mod ast;
pub mod codegen;
pub mod compile;
pub mod format;
pub mod memory;
pub mod parser;
pub mod runner;
pub mod token;
