//! Compile-time tape-cell allocator for Brainfuck code generation.
//!
//! Ported from the retired C++ `BrainfuckMemory`: a bump allocator handing out
//! cell indices from 0 upward. Named variables are memoized: asking twice
//! for the same name yields the same cell. There is no free or scoping —
//! indices only grow, exactly like the reference.

use std::collections::HashMap;

/// Bump-allocating tape-cell index assignment.
#[derive(Debug, Default)]
pub struct Memory {
    next: i32,
    vars: HashMap<Vec<u8>, i32>,
}

impl Memory {
    /// Fresh allocator; first index handed out is 0.
    pub fn new() -> Self {
        Self::default()
    }

    /// Allocate a fresh temporary cell (`getTemporaryCell`).
    pub fn temp_cell(&mut self) -> i32 {
        let cell = self.next;
        self.next += 1;
        cell
    }

    /// Look up (allocating on first use) the cell for `name`
    /// (`getVariableCell`).
    pub fn var_cell(&mut self, name: &[u8]) -> i32 {
        if let Some(&cell) = self.vars.get(name) {
            return cell;
        }
        let cell = self.temp_cell();
        self.vars.insert(name.to_vec(), cell);
        cell
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn temps_count_from_zero() {
        let mut m = Memory::new();
        assert_eq!(m.temp_cell(), 0);
        assert_eq!(m.temp_cell(), 1);
        assert_eq!(m.temp_cell(), 2);
    }

    #[test]
    fn vars_are_memoized() {
        let mut m = Memory::new();
        assert_eq!(m.var_cell(b"x"), 0);
        assert_eq!(m.var_cell(b"y"), 1);
        assert_eq!(m.var_cell(b"x"), 0);
        assert_eq!(m.var_cell(b"y"), 1);
    }

    #[test]
    fn temps_and_vars_share_one_sequence() {
        let mut m = Memory::new();
        assert_eq!(m.temp_cell(), 0);
        assert_eq!(m.var_cell(b"a"), 1);
        assert_eq!(m.var_cell(b"a"), 1);
        assert_eq!(m.temp_cell(), 2);
        assert_eq!(m.var_cell(b"b"), 3);
    }

    #[test]
    fn similar_names_are_distinct() {
        let mut m = Memory::new();
        assert_eq!(m.var_cell(b"x"), 0);
        assert_eq!(m.var_cell(b"xx"), 1);
        assert_eq!(m.var_cell(b"X"), 2);
        assert_eq!(m.var_cell(b"x"), 0);
    }
}
