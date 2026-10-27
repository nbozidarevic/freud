//! Brainfuck code generation: emitter plus emission helpers.
//!
//! Mirrors `src/compile/BrainfuckCompiler.cpp` helper-for-helper: same
//! allocation order, same pointer motion, same emitted bytes. The visitor
//! wiring (AST → helpers) lands in slice 4c.
//!
//! Notes on the port:
//! - `printAsDigit` is declared but never defined or called in C++;
//!   it is omitted here.
//! - The closures passed to `perform_while`/`perform_for` re-run their
//!   computation on every call (fresh cells each time), exactly like the
//!   C++ lambdas.
//! - Argument-evaluation order at multi-argument call sites is measured
//!   per site against GCC (order probe plus differentials): most sites are
//!   right-to-left, but binary-operator arithmetic operands are
//!   left-to-right (the `scanf` accumulate site excepted). Apple Clang
//!   differs per site too, so the reference
//!   output is platform-dependent; the byte differential is therefore
//!   Ubuntu-only (macOS CI stays behavioral).

use crate::memory::Memory;

/// Code emitter: cell allocator, output bytes, tracked data pointer.
#[derive(Debug, Default)]
pub struct Emitter {
    pub(crate) memory: Memory,
    output: Vec<u8>,
    pointer: i32,
    pub(crate) break_stack: Vec<i32>,
}

/// Compile failure: mirrors a C++ `throw "..."` site.
///
/// Message only, no position — the reference carries none either.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct CompileError {
    pub msg: String,
}

impl std::fmt::Display for CompileError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}", self.msg)
    }
}

impl std::error::Error for CompileError {}

impl Emitter {
    /// Fresh emitter; data pointer starts at cell 0.
    pub fn new() -> Self {
        Self::default()
    }

    /// Emitted bytes so far.
    pub fn output(&self) -> &[u8] {
        &self.output
    }

    fn emit(&mut self, s: &str) {
        self.output.extend_from_slice(s.as_bytes());
    }

    /// Emit pointer motion to `dest` (`movePointer`).
    pub fn move_pointer(&mut self, dest: i32) {
        if self.pointer == dest {
            return;
        }
        let c = if self.pointer > dest { b'<' } else { b'>' };
        for _ in 0..(self.pointer - dest).abs() {
            self.output.push(c);
        }
        self.pointer = dest;
    }

    /// Copy `source` to `destination`, preserving `source` (`copyValue`).
    pub fn copy_value(&mut self, source: i32, dest: i32) -> i32 {
        if source == dest {
            return dest;
        }
        let helper = self.memory.temp_cell();
        self.move_pointer(helper);
        self.emit("[-]");
        self.move_pointer(dest);
        self.emit("[-]");
        self.move_pointer(source);
        self.emit("[-");
        self.move_pointer(dest);
        self.emit("+");
        self.move_pointer(helper);
        self.emit("+");
        self.move_pointer(source);
        self.emit("]");
        self.move_pointer(helper);
        self.emit("[-");
        self.move_pointer(source);
        self.emit("+");
        self.move_pointer(helper);
        self.emit("]");
        dest
    }

    /// Move `source` to `destination`, zeroing `source` (`moveValue`).
    pub fn move_value(&mut self, source: i32, dest: i32) -> i32 {
        if source == dest {
            return dest;
        }
        self.move_pointer(dest);
        self.emit("[-]");
        self.move_pointer(source);
        self.emit("[-");
        self.move_pointer(dest);
        self.emit("+");
        self.move_pointer(source);
        self.emit("]");
        dest
    }

    /// Copy `source` into a fresh cell (`duplicateValue`).
    pub fn duplicate_value(&mut self, source: i32) -> i32 {
        let dest = self.memory.temp_cell();
        self.copy_value(source, dest);
        dest
    }

    /// Set `dest` to `value` (`setValue`).
    pub fn set_value(&mut self, dest: i32, value: u8) -> i32 {
        self.move_pointer(dest);
        self.emit("[-]");
        for _ in 0..value {
            self.emit("+");
        }
        dest
    }

    /// Fresh cell initialized to `value` (`getPointerForConstValue`).
    pub fn const_value(&mut self, value: u8) -> i32 {
        let cell = self.memory.temp_cell();
        self.set_value(cell, value);
        cell
    }

    /// `result = a + b` in a fresh cell (`addValues`).
    pub fn add_values(&mut self, a: i32, b: i32) -> i32 {
        let a_copy = self.duplicate_value(a);
        let b_copy = self.duplicate_value(b);
        let result = self.memory.temp_cell();
        self.move_pointer(result);
        self.emit("[-]");
        self.move_pointer(a_copy);
        self.emit("[-");
        self.move_pointer(result);
        self.emit("+");
        self.move_pointer(a_copy);
        self.emit("]");
        self.move_pointer(b_copy);
        self.emit("[-");
        self.move_pointer(result);
        self.emit("+");
        self.move_pointer(b_copy);
        self.emit("]");
        result
    }

    /// `result = a - b` in a fresh cell (`subtractValues`).
    pub fn subtract_values(&mut self, a: i32, b: i32) -> i32 {
        let a_copy = self.duplicate_value(a);
        let b_copy = self.duplicate_value(b);
        let result = self.memory.temp_cell();
        self.move_pointer(result);
        self.emit("[-]");
        self.move_pointer(a_copy);
        self.emit("[-");
        self.move_pointer(result);
        self.emit("+");
        self.move_pointer(a_copy);
        self.emit("]");
        self.move_pointer(b_copy);
        self.emit("[-");
        self.move_pointer(result);
        self.emit("-");
        self.move_pointer(b_copy);
        self.emit("]");
        result
    }

    /// `result = a * b` in a fresh cell (`multiplyValues`).
    pub fn multiply_values(&mut self, a: i32, b: i32) -> i32 {
        let a_copy = self.duplicate_value(a);
        let result = self.const_value(0);
        self.move_pointer(a_copy);
        self.emit("[-");
        let new_result = self.add_values(b, result);
        self.move_value(new_result, result);
        self.move_pointer(a_copy);
        self.emit("]");
        result
    }

    /// `result = a / b` in a fresh cell (`divideValues`).
    pub fn divide_values(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let a_copy = self.duplicate_value(a);
        let result = self.const_value(0);
        self.perform_while(
            |em| Ok(em.greater_than_or_equal(a_copy, b)?),
            |em| {
                em.move_pointer(result);
                em.emit("+");
                let diff = em.subtract_values(a_copy, b);
                em.move_value(diff, a_copy);
                Ok(())
            },
        )?;
        Ok(result)
    }

    /// `result = a % b` in a fresh cell (`modValues`).
    pub fn mod_values(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let result = self.const_value(0);
        let q = self.divide_values(a, b)?;
        let prod = self.multiply_values(q, b);
        let diff = self.subtract_values(a, prod);
        self.move_value(diff, result);
        Ok(result)
    }

    /// Logical NOT of `a` in a fresh cell (`negate`).
    pub fn negate(&mut self, a: i32) -> Result<i32, CompileError> {
        let result = self.memory.temp_cell();
        self.perform_if_else(
            a,
            |em| {
                em.set_value(result, 0);
                Ok(())
            },
            |em| {
                em.set_value(result, 1);
                Ok(())
            },
        )?;
        Ok(result)
    }

    /// `result = (a == b)` in a fresh cell (`isEqual`).
    pub fn is_equal(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let a_copy = self.duplicate_value(a);
        let b_copy = self.duplicate_value(b);
        let result = self.const_value(0);
        self.move_pointer(a_copy);
        self.emit("[-");
        self.move_pointer(b_copy);
        self.emit("-");
        self.move_pointer(a_copy);
        self.emit("]");
        let not_a = self.negate(a_copy)?;
        self.perform_if_else(
            not_a,
            |em| {
                let not_b = em.negate(b_copy)?;
                em.perform_if_else(
                    not_b,
                    |em| {
                        em.set_value(result, 1);
                        Ok(())
                    },
                    |_| Ok(()),
                )
            },
            |_| Ok(()),
        )?;
        Ok(result)
    }

    /// `result = (a && b)` in a fresh cell (`logicalAnd`).
    pub fn logical_and(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let result = self.const_value(0);
        self.perform_if_else(
            a,
            |em| {
                em.perform_if_else(
                    b,
                    |em| {
                        em.set_value(result, 1);
                        Ok(())
                    },
                    |_| Ok(()),
                )
            },
            |_| Ok(()),
        )?;
        Ok(result)
    }

    /// `result = (a || b)` in a fresh cell (`logicalOr`).
    pub fn logical_or(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let result = self.const_value(0);
        self.perform_if_else(
            a,
            |em| {
                em.set_value(result, 1);
                Ok(())
            },
            |_| Ok(()),
        )?;
        self.perform_if_else(
            b,
            |em| {
                em.set_value(result, 1);
                Ok(())
            },
            |_| Ok(()),
        )?;
        Ok(result)
    }

    /// `result = (a < b)` in a fresh cell (`lessThan`).
    pub fn less_than(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let a_copy = self.duplicate_value(a);
        let b_copy = self.duplicate_value(b);
        let result = self.memory.temp_cell();
        self.move_pointer(result);
        self.emit("[-]");
        self.perform_while(
            |em| Ok(em.logical_and(a_copy, b_copy)?),
            |em| {
                em.move_pointer(a_copy);
                em.emit("-");
                em.move_pointer(b_copy);
                em.emit("-");
                Ok(())
            },
        )?;
        let not_a = self.negate(a_copy)?;
        let cond = self.logical_and(not_a, b_copy)?;
        self.perform_if_else(
            cond,
            |em| {
                em.set_value(result, 1);
                Ok(())
            },
            |_| Ok(()),
        )?;
        Ok(result)
    }

    /// `result = (a <= b)` (`lessThanOrEqual`).
    ///
    /// Operand order is GCC right-to-left (`isEqual` first), per the probe.
    pub fn less_than_or_equal(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let eq = self.is_equal(a, b)?;
        let lt = self.less_than(a, b)?;
        self.logical_or(lt, eq)
    }

    /// `result = (a > b)` (`greaterThan`).
    pub fn greater_than(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let le = self.less_than_or_equal(a, b)?;
        self.negate(le)
    }

    /// `result = (a >= b)` (`greaterThanOrEqual`).
    pub fn greater_than_or_equal(&mut self, a: i32, b: i32) -> Result<i32, CompileError> {
        let lt = self.less_than(a, b)?;
        self.negate(lt)
    }

    /// If/else on `expression` (`performIfElse`).
    pub fn perform_if_else(
        &mut self,
        expression: i32,
        mut iff: impl FnMut(&mut Self) -> Result<(), CompileError>,
        mut els: impl FnMut(&mut Self) -> Result<(), CompileError>,
    ) -> Result<(), CompileError> {
        let if_value = self.duplicate_value(expression);
        let else_value = self.const_value(1);
        self.move_pointer(if_value);
        self.emit("[");
        self.set_value(if_value, 0);
        self.set_value(else_value, 0);
        iff(self)?;
        self.move_pointer(if_value);
        self.emit("]");
        self.move_pointer(else_value);
        self.emit("[");
        self.set_value(else_value, 0);
        els(self)?;
        self.move_pointer(else_value);
        self.emit("]");
        Ok(())
    }

    /// While loop, re-evaluating `cond` every iteration (`performWhile`).
    pub fn perform_while(
        &mut self,
        mut cond: impl FnMut(&mut Self) -> Result<i32, CompileError>,
        mut body: impl FnMut(&mut Self) -> Result<(), CompileError>,
    ) -> Result<(), CompileError> {
        let expression = cond(self)?;
        self.move_pointer(expression);
        self.emit("[");
        self.move_pointer(expression);
        body(self)?;
        let new_expression = cond(self)?;
        self.move_value(new_expression, expression);
        self.move_pointer(expression);
        self.emit("]");
        Ok(())
    }

    /// For loop over init/cond/update/body (`performFor`).
    pub fn perform_for(
        &mut self,
        mut init: impl FnMut(&mut Self) -> Result<(), CompileError>,
        cond: impl FnMut(&mut Self) -> Result<i32, CompileError>,
        mut update: impl FnMut(&mut Self) -> Result<(), CompileError>,
        mut body: impl FnMut(&mut Self) -> Result<(), CompileError>,
    ) -> Result<(), CompileError> {
        init(self)?;
        self.perform_while(cond, |em| {
            body(em)?;
            update(em)
        })
    }

    /// Print cell `a` as a character (`printAsChar`).
    pub fn print_as_char(&mut self, a: i32) {
        self.move_pointer(a);
        self.emit(".");
    }

    /// Print cell `a` as a decimal number (`printAsNumber`).
    pub fn print_as_number(&mut self, a: i32) -> Result<(), CompileError> {
        let a_copy = self.duplicate_value(a);
        let digit = self.duplicate_value(a);
        let helper = self.const_value(0);
        let zero_char = self.const_value(b'0');
        let nine = self.const_value(9);
        let ten = self.const_value(10);
        let newly_built = self.const_value(0);
        self.perform_if_else(
            a,
            |em| {
                em.perform_while(
                    |em| Ok(em.less_than(newly_built, a)?),
                    |em| {
                        em.set_value(helper, 1);
                        em.copy_value(a_copy, digit);
                        em.perform_while(
                            |em| Ok(em.greater_than(digit, nine)?),
                            |em| {
                                let q = em.divide_values(digit, ten)?;
                                em.move_value(q, digit);
                                let h = em.multiply_values(helper, ten);
                                em.move_value(h, helper);
                                Ok(())
                            },
                        )?;
                        let shifted = em.multiply_values(newly_built, ten);
                        let acc = em.add_values(shifted, digit);
                        em.move_value(acc, newly_built);
                        let glyph = em.add_values(digit, zero_char);
                        em.print_as_char(glyph);
                        let scaled = em.multiply_values(digit, helper);
                        let rest = em.subtract_values(a_copy, scaled);
                        em.move_value(rest, a_copy);
                        Ok(())
                    },
                )
            },
            |em| {
                em.print_as_char(zero_char);
                Ok(())
            },
        )
    }

    /// Read one character into cell `a` (`readAsChar`).
    pub fn read_as_char(&mut self, a: i32) {
        self.move_pointer(a);
        self.emit(",");
    }

    /// Read a decimal number into cell `a` (`readAsNumber`).
    pub fn read_as_number(&mut self, a: i32) -> Result<(), CompileError> {
        let reader = self.const_value(0);
        let result = self.const_value(0);
        let zero = self.const_value(b'0');
        let nine = self.const_value(b'9');
        let ten = self.const_value(10);
        self.move_pointer(reader);
        self.emit(",");
        self.perform_while(
            |em| {
                // GCC right-to-left here (measured: the divergence window
                // shows the nine-cell duplicated second).
                let above = em.greater_than(reader, nine)?;
                let below = em.less_than(reader, zero)?;
                em.logical_or(below, above)
            },
            |em| {
                em.move_pointer(reader);
                em.emit(",");
                Ok(())
            },
        )?;
        self.perform_while(
            |em| {
                // GCC right-to-left here (measured via io.c differential;
                // symmetric with the first condition).
                let le = em.less_than_or_equal(reader, nine)?;
                let ge = em.greater_than_or_equal(reader, zero)?;
                em.logical_and(ge, le)
            },
            |em| {
                // GCC right-to-left here (measured via io.c differential):
                // unlike BinOp arithmetic, the multiply side allocates first.
                let shifted = em.multiply_values(result, ten);
                let dig = em.subtract_values(reader, zero);
                let acc = em.add_values(dig, shifted);
                em.move_value(acc, result);
                em.move_pointer(reader);
                em.emit(",");
                Ok(())
            },
        )?;
        self.move_value(result, a);
        Ok(())
    }

    /// Print the constant byte `c` (`printChar`).
    pub fn print_char(&mut self, c: u8) {
        let a = self.const_value(c);
        self.move_pointer(a);
        self.emit(".");
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn bf(em: &Emitter) -> String {
        String::from_utf8(em.output().to_vec()).expect("non-utf8 bf")
    }

    #[test]
    fn const_cells_count_and_emit() {
        let mut em = Emitter::new();
        assert_eq!(em.const_value(3), 0);
        assert_eq!(bf(&em), "[-]+++");
        assert_eq!(em.const_value(1), 1);
        assert_eq!(bf(&em), "[-]+++>[-]+");
    }

    #[test]
    fn copy_value_exact() {
        let mut em = Emitter::new();
        let a = em.const_value(2);
        let b = em.const_value(0);
        assert_eq!(em.copy_value(a, b), 1);
        assert_eq!(
            bf(&em),
            "[-]++>[-]>[-]<[-]<[->+>+<<]>>[-<<+>>]"
        );
    }

    #[test]
    fn copy_same_cell_is_noop() {
        let mut em = Emitter::new();
        let a = em.const_value(1);
        let len = em.output().len();
        assert_eq!(em.copy_value(a, a), a);
        assert_eq!(em.output().len(), len);
    }

    #[test]
    fn move_value_exact() {
        let mut em = Emitter::new();
        let a = em.const_value(2);
        let b = em.const_value(0);
        assert_eq!(em.move_value(a, b), 1);
        assert_eq!(bf(&em), "[-]++>[-][-]<[->+<]");
    }

    #[test]
    fn move_same_cell_is_noop() {
        let mut em = Emitter::new();
        let a = em.const_value(1);
        let len = em.output().len();
        assert_eq!(em.move_value(a, a), a);
        assert_eq!(em.output().len(), len);
    }

    #[test]
    fn duplicate_value_exact() {
        let mut em = Emitter::new();
        let a = em.const_value(1);
        assert_eq!(em.duplicate_value(a), 1);
        assert_eq!(bf(&em), "[-]+>>[-]<[-]<[->+>+<<]>>[-<<+>>]");
    }

    #[test]
    fn add_values_exact() {
        let mut em = Emitter::new();
        let a = em.const_value(2);
        let b = em.const_value(3);
        assert_eq!(em.add_values(a, b), 6);
        assert_eq!(
            bf(&em),
            "[-]++>[-]+++\
             >>[-]<[-]<<[->>+>+<<<]>>>[-<<<+>>>]\
             >>[-]<[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>]\
             >[-]<<<<[->>>>+<<<<]>>[->>+<<]"
                .replace(|c: char| c.is_whitespace(), ""),
        );
    }

    #[test]
    fn subtract_values_exact() {
        let mut em = Emitter::new();
        let a = em.const_value(2);
        let b = em.const_value(3);
        assert_eq!(em.subtract_values(a, b), 6);
        assert_eq!(
            bf(&em),
            "[-]++>[-]+++\
             >>[-]<[-]<<[->>+>+<<<]>>>[-<<<+>>>]\
             >>[-]<[-]<<<[->>>+>+<<<<]>>>>[-<<<<+>>>>]\
             >[-]<<<<[->>>>+<<<<]>>[->>-<<]"
                .replace(|c: char| c.is_whitespace(), ""),
        );
    }

    #[test]
    fn compound_helpers_return_fresh_cells_in_order() {
        // Pins allocation order: result cell index after fixed setups.
        let mut em = Emitter::new();
        let a = em.const_value(5);
        assert_eq!(em.negate(a).unwrap(), 1);

        let mut em = Emitter::new();
        let a = em.const_value(5);
        let b = em.const_value(7);
        assert_eq!(em.is_equal(a, b).unwrap(), 6);

        let mut em = Emitter::new();
        let a = em.const_value(5);
        let b = em.const_value(7);
        assert_eq!(em.logical_and(a, b).unwrap(), 2);

        let mut em = Emitter::new();
        let a = em.const_value(5);
        let b = em.const_value(7);
        assert_eq!(em.logical_or(a, b).unwrap(), 2);

        let mut em = Emitter::new();
        let a = em.const_value(5);
        let b = em.const_value(7);
        assert_eq!(em.multiply_values(a, b), 4);

        let mut em = Emitter::new();
        let a = em.const_value(5);
        let b = em.const_value(7);
        assert_eq!(em.divide_values(a, b).unwrap(), 4);

        let mut em = Emitter::new();
        let a = em.const_value(5);
        let b = em.const_value(7);
        assert_eq!(em.mod_values(a, b).unwrap(), 2);

        let mut em = Emitter::new();
        let a = em.const_value(5);
        let b = em.const_value(7);
        assert_eq!(em.less_than(a, b).unwrap(), 6);
    }
}
