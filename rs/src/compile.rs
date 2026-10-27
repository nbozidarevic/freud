//! AST-to-Brainfuck compilation: statement/expression wiring over [`Emitter`].
//!
//! Mirrors the `BrainfuckCompiler` visitor methods: same emission order,
//! same allocation order, same error messages. Orders at multi-argument
//! call sites follow GCC right-to-left (last argument first), per the
//! order probe in `tests/differential/micro/`.
//!
//! Intentional strictness deltas vs the ANTLR frontend (all reject inputs
//! the reference accepts-with-garbage or crashes on; none occur in the
//! fixture corpus):
//! - Non-lvalue assignment targets are rejected at parse time (the C++
//!   silently compiles them into temporaries).
//! - String literals in value position are rejected (the C++ crashes with
//!   `bad_cast` when the value is used).
//! - Non-string `printf`/`scanf` formats are rejected with a message (the
//!   C++ crashes with `bad_cast`).
//! - Too few format arguments are rejected (the C++ reads out of bounds).

use crate::ast::{Block, BlockItem, Decl, Expr, External, ForDecl, ForInit, Stmt};
use crate::codegen::{CompileError, Emitter};
use crate::parser;

fn err(msg: impl Into<String>) -> CompileError {
    CompileError { msg: msg.into() }
}

/// Parse and compile `src` to Brainfuck plus trailing newline.
///
/// Mirrors `BrainfuckCompiler::run()`: externals compile in source order
/// and a final newline is appended. Parse failures surface as
/// `CompileError` carrying the parse diagnostic.
pub fn compile(src: &[u8]) -> Result<Vec<u8>, CompileError> {
    let tu = parser::parse(src).map_err(|e| err(e.to_string()))?;
    let mut em = Emitter::new();
    for item in &tu.0 {
        match item {
            External::FuncDef(f) => {
                if f.name.as_slice() != b"main" {
                    return Err(err("Unsupported function definition"));
                }
                em.compile_block(&f.body)?;
            }
            External::Decl(d) => {
                em.compile_decl(d)?;
            }
        }
    }
    let mut out = em.output().to_vec();
    out.push(b'\n');
    Ok(out)
}

struct SwitchCase<'a> {
    is_default: bool,
    label_cell: i32,
    body: Vec<SwitchBodyItem<'a>>,
}

enum SwitchBodyItem<'a> {
    Decl(&'a Decl),
    Stmt(&'a Stmt),
}

fn push_switch_body<'a>(
    item: SwitchBodyItem<'a>,
    cases: &mut Vec<SwitchCase<'a>>,
) -> Result<(), CompileError> {
    match cases.last_mut() {
        None => Err(err("Unsupported statements before the first case label")),
        Some(c) => {
            c.body.push(item);
            Ok(())
        }
    }
}

impl Emitter {
    /// Compile a declaration: cell first, then the value.
    fn compile_decl(&mut self, d: &Decl) -> Result<(), CompileError> {
        let init = match &d.init {
            // `int;` — no declarator, the base visitor emits nothing.
            None => return Ok(()),
            Some(init) => init,
        };
        let e = match &init.init {
            None => return Err(err("Unsupported init declarator")),
            Some(e) => e,
        };
        let dest = self.memory.var_cell(&init.name);
        let src = self.compile_expr(e)?;
        self.copy_value(src, dest);
        Ok(())
    }

    fn compile_block(&mut self, b: &Block) -> Result<(), CompileError> {
        for item in &b.0 {
            match item {
                BlockItem::Decl(d) => self.compile_decl(d)?,
                BlockItem::Stmt(s) => self.compile_stmt(s)?,
            }
        }
        Ok(())
    }

    fn compile_stmt(&mut self, s: &Stmt) -> Result<(), CompileError> {
        match s {
            Stmt::Compound(b) => self.compile_block(b),
            Stmt::Expr(e) => {
                self.compile_expr(e)?;
                Ok(())
            }
            Stmt::Empty => Ok(()),
            Stmt::If { cond, then, els } => {
                let c = self.compile_expr(cond)?;
                self.perform_if_else(
                    c,
                    |em| em.compile_stmt(then),
                    |em| match els {
                        Some(e) => em.compile_stmt(e),
                        None => Ok(()),
                    },
                )
            }
            Stmt::Switch { expr, body } => self.compile_switch(expr, body),
            Stmt::While { cond, body } => {
                self.break_stack.push(-1);
                let r = self.perform_while(
                    |em| em.compile_expr(cond),
                    |em| em.compile_stmt(body),
                );
                self.break_stack.pop();
                r
            }
            Stmt::For { init, cond, incr, body } => {
                self.break_stack.push(-1);
                let r = self.perform_for(
                    |em| em.compile_for_init(init),
                    |em| match cond {
                        Some(e) => em.compile_expr(e),
                        None => Ok(em.const_value(1)),
                    },
                    |em| match incr {
                        Some(e) => em.compile_expr(e).map(|_| ()),
                        None => Ok(()),
                    },
                    |em| em.compile_stmt(body),
                );
                self.break_stack.pop();
                r
            }
            // Return values are ignored: the C++ never compiles the operand.
            Stmt::Return(_) => Ok(()),
            Stmt::Break => {
                let Some(&top) = self.break_stack.last() else {
                    return Err(err("Unsupported break outside of any loop or switch"));
                };
                if top < 0 {
                    return Err(err("Unsupported break inside loops (only switch is supported)"));
                }
                self.set_value(top, 1);
                Ok(())
            }
            Stmt::Continue => {
                if self.break_stack.is_empty() {
                    return Err(err("Unsupported continue outside of any loop"));
                }
                Err(err("Unsupported continue inside loops"))
            }
            // Labels outside `switch`: the label (if any) compiles and is
            // dropped, the body compiles normally — the base visitor does
            // the same with unhandled labeled statements.
            Stmt::Case { label, body } => {
                self.compile_expr(label)?;
                self.compile_stmt(body)
            }
            Stmt::Default { body } => self.compile_stmt(body),
            Stmt::GotoLabel { body, .. } => self.compile_stmt(body),
        }
    }

    fn compile_for_init(&mut self, init: &ForInit) -> Result<(), CompileError> {
        match init {
            ForInit::Decl(d) => self.compile_for_decl(d),
            ForInit::Empty => Ok(()),
            ForInit::Expr(e) => {
                self.compile_expr(e)?;
                Ok(())
            }
        }
    }

    fn compile_for_decl(&mut self, d: &ForDecl) -> Result<(), CompileError> {
        let name = match &d.name {
            // `for (int;;)` — specifier only, no code.
            None => return Ok(()),
            Some(name) => name,
        };
        let e = match &d.init {
            None => return Err(err("Unsupported init declarator")),
            Some(e) => e,
        };
        let dest = self.memory.var_cell(name);
        let src = self.compile_expr(e)?;
        self.copy_value(src, dest);
        Ok(())
    }

    fn compile_switch(&mut self, expr: &Expr, body: &Stmt) -> Result<(), CompileError> {
        let expr_cell = self.compile_expr(expr)?;
        let mut cases: Vec<SwitchCase<'_>> = Vec::new();
        self.collect_switch_stmt(body, &mut cases)?;
        let any_match = self.const_value(0);
        let mut matched: Vec<i32> = Vec::new();
        for c in &cases {
            if c.is_default {
                matched.push(-1);
                continue;
            }
            let m = self.is_equal(expr_cell, c.label_cell)?;
            matched.push(m);
            let o = self.logical_or(any_match, m)?;
            self.move_value(o, any_match);
        }
        let fall = self.const_value(0);
        let broken = self.const_value(0);
        self.break_stack.push(broken);
        for (i, c) in cases.iter().enumerate() {
            // GCC right-to-left within each nested call (see order probe).
            let run_cond = if c.is_default {
                let nb = self.negate(broken)?;
                let nm = self.negate(any_match)?;
                let o = self.logical_or(fall, nm)?;
                self.logical_and(o, nb)?
            } else {
                let nb = self.negate(broken)?;
                let o = self.logical_or(matched[i], fall)?;
                self.logical_and(o, nb)?
            };
            self.perform_if_else(
                run_cond,
                |em| {
                    em.set_value(fall, 1);
                    for item in &c.body {
                        match item {
                            SwitchBodyItem::Decl(d) => em.compile_decl(d)?,
                            SwitchBodyItem::Stmt(s) => em.compile_stmt(s)?,
                        }
                    }
                    Ok(())
                },
                |_| Ok(()),
            )?;
        }
        self.break_stack.pop();
        Ok(())
    }

    fn collect_switch_stmt<'a>(
        &mut self,
        s: &'a Stmt,
        cases: &mut Vec<SwitchCase<'a>>,
    ) -> Result<(), CompileError> {
        match s {
            Stmt::Case { label, body } => {
                let cell = self.compile_expr(label)?;
                cases.push(SwitchCase {
                    is_default: false,
                    label_cell: cell,
                    body: Vec::new(),
                });
                self.collect_switch_stmt(body, cases)
            }
            Stmt::Default { body } => {
                cases.push(SwitchCase {
                    is_default: true,
                    label_cell: -1,
                    body: Vec::new(),
                });
                self.collect_switch_stmt(body, cases)
            }
            Stmt::Compound(b) => {
                for item in &b.0 {
                    match item {
                        BlockItem::Decl(d) => {
                            push_switch_body(SwitchBodyItem::Decl(d), cases)?
                        }
                        BlockItem::Stmt(s) => self.collect_switch_stmt(s, cases)?,
                    }
                }
                Ok(())
            }
            other => push_switch_body(SwitchBodyItem::Stmt(other), cases),
        }
    }

    fn compile_expr(&mut self, e: &Expr) -> Result<i32, CompileError> {
        match e {
            Expr::Int(bytes) => {
                // `atoi` with `strtol` clamping, narrowed to a byte.
                let text = std::str::from_utf8(bytes).unwrap_or("");
                let v: i64 = text.parse().unwrap_or(i64::MAX);
                let clamped = v.clamp(i32::MIN as i64, i32::MAX as i64) as i32;
                Ok(self.const_value(clamped as u8))
            }
            Expr::Char(bytes) => {
                // Raw slice including quotes; byte 1 is the value — even for
                // escapes (`'\n'` yields '\\' = 92, exactly like the C++).
                Ok(self.const_value(bytes.get(1).copied().unwrap_or(0)))
            }
            Expr::Ident(name) => Ok(self.memory.var_cell(name)),
            Expr::StringLit { .. } => Err(err("Unsupported string expression")),
            Expr::Paren(e) => self.compile_expr(e),
            Expr::Comma(es) => {
                debug_assert!(!es.is_empty());
                let mut last = 0;
                for e in es {
                    last = self.compile_expr(e)?;
                }
                Ok(last)
            }
            Expr::Assign { op, lhs, rhs } => {
                if op.as_slice() == b"=" {
                    // GCC right-to-left: the target (last argument) first.
                    let target = self.compile_lvalue(lhs)?;
                    let r = self.compile_expr(rhs)?;
                    Ok(self.copy_value(r, target))
                } else {
                    // Sequenced statements in C++: right-hand side first.
                    let r = self.compile_expr(rhs)?;
                    let target = self.compile_lvalue(lhs)?;
                    let res = match op.as_slice() {
                        b"+=" => self.add_values(target, r),
                        b"-=" => self.subtract_values(target, r),
                        b"*=" => self.multiply_values(target, r),
                        b"/=" => self.divide_values(target, r)?,
                        b"%=" => self.mod_values(target, r)?,
                        _ => return Err(err("Unsupported assignment expression")),
                    };
                    Ok(self.copy_value(res, target))
                }
            }
            Expr::BinOp { op, l, r } => {
                // GCC evaluates arithmetic operands left-to-right but every
                // other binary operator right-to-left (measured per site:
                // the probe plus cmp.c/logic.c green runs pin comparisons
                // and logic; addition/div/mul/mod/order_arith pin arithmetic).
                let (ll, rr) = match op.as_slice() {
                    b"+" | b"-" | b"*" | b"/" | b"%" => {
                        let ll = self.compile_expr(l)?;
                        let rr = self.compile_expr(r)?;
                        (ll, rr)
                    }
                    _ => {
                        let rr = self.compile_expr(r)?;
                        let ll = self.compile_expr(l)?;
                        (ll, rr)
                    }
                };
                match op.as_slice() {
                    b"+" => Ok(self.add_values(ll, rr)),
                    b"-" => Ok(self.subtract_values(ll, rr)),
                    b"*" => Ok(self.multiply_values(ll, rr)),
                    b"/" => self.divide_values(ll, rr),
                    b"%" => self.mod_values(ll, rr),
                    b"==" => self.is_equal(ll, rr),
                    b"!=" => {
                        let e = self.is_equal(ll, rr)?;
                        self.negate(e)
                    }
                    b"&&" => self.logical_and(ll, rr),
                    b"||" => self.logical_or(ll, rr),
                    b"<" => self.less_than(ll, rr),
                    b"<=" => self.less_than_or_equal(ll, rr),
                    b">" => self.greater_than(ll, rr),
                    b">=" => self.greater_than_or_equal(ll, rr),
                    _ => Err(err("Unsupported binary operator")),
                }
            }
            Expr::Unary { op, e } => match op.as_slice() {
                b"!" => {
                    let v = self.compile_expr(e)?;
                    self.negate(v)
                }
                b"&" => self.compile_expr(e),
                b"++" => {
                    let t = self.compile_expr(e)?;
                    let one = self.const_value(1);
                    let sum = self.add_values(t, one);
                    self.copy_value(sum, t);
                    Ok(self.duplicate_value(t))
                }
                b"--" => {
                    let t = self.compile_expr(e)?;
                    let one = self.const_value(1);
                    let diff = self.subtract_values(t, one);
                    self.copy_value(diff, t);
                    Ok(self.duplicate_value(t))
                }
                _ => Err(err("Unsupported unary expression")),
            },
            Expr::Postfix { op, e } => {
                let target = self.compile_expr(e)?;
                let old = self.duplicate_value(target);
                let one = self.const_value(1);
                if op.as_slice() == b"++" {
                    let sum = self.add_values(target, one);
                    self.copy_value(sum, target);
                } else if op.as_slice() == b"--" {
                    let diff = self.subtract_values(target, one);
                    self.copy_value(diff, target);
                } else {
                    return Err(err("Unsupported postfix expression"));
                }
                Ok(old)
            }
            Expr::Call { callee, args } => self.compile_call(callee, args),
        }
    }

    /// Compile an assignment target. The C++ performs no lvalue check;
    /// our frontend rejects invalid targets at parse time, so anything
    /// reaching here is an identifier or parenthesized lvalue.
    fn compile_lvalue(&mut self, e: &Expr) -> Result<i32, CompileError> {
        match e {
            Expr::Ident(name) => Ok(self.memory.var_cell(name)),
            Expr::Paren(inner) => self.compile_lvalue(inner),
            _ => Err(err("invalid lvalue in assignment")),
        }
    }

    /// Compile a call: only `printf`/`scanf` with a string-literal format.
    fn compile_call(&mut self, callee: &Expr, args: &[Expr]) -> Result<i32, CompileError> {
        let name = match callee {
            Expr::Ident(name) => name.as_slice(),
            _ => return Err(err("Unsupported postfix expression")),
        };
        let is_printf = match name {
            b"printf" => true,
            b"scanf" => false,
            _ => return Err(err("Unsupported postfix expression")),
        };
        // Arguments compile left-to-right (sequenced vector construction).
        let mut vals: Vec<i32> = Vec::new();
        let mut format: &[u8] = b"";
        for (i, a) in args.iter().enumerate() {
            if i == 0 {
                match a {
                    Expr::StringLit { raw, .. } => format = raw,
                    _ => {
                        // Evaluate for emission parity, then fail: the C++
                        // crashes casting a non-string format argument.
                        self.compile_expr(a)?;
                        return Err(err(if is_printf {
                            "printf format must be a string literal"
                        } else {
                            "scanf format must be a string literal"
                        }));
                    }
                }
            } else {
                vals.push(self.compile_expr(a)?);
            }
        }
        let mut next_var = 0usize;
        let mut i = 0usize;
        while i < format.len() {
            let c = format[i];
            if is_printf {
                match c {
                    b'\\' => {
                        i += 1;
                        match format.get(i).copied() {
                            Some(b'n') => self.print_char(b'\n'),
                            Some(b't') => self.print_char(b'\t'),
                            _ => return Err(err("Incorrect backslash in printf")),
                        }
                    }
                    b'%' => {
                        i += 1;
                        let cell = next_format_arg(&vals, &mut next_var)?;
                        match format.get(i).copied() {
                            Some(b'c') => self.print_as_char(cell),
                            Some(b'd') => self.print_as_number(cell)?,
                            _ => return Err(err("Unexpected printf format")),
                        }
                    }
                    _ => self.print_char(c),
                }
            } else {
                match c {
                    b'%' => {
                        i += 1;
                        let cell = next_format_arg(&vals, &mut next_var)?;
                        match format.get(i).copied() {
                            Some(b'c') => self.read_as_char(cell),
                            Some(b'd') => self.read_as_number(cell)?,
                            _ => return Err(err("Unexpected scanf format")),
                        }
                    }
                    b' ' => {}
                    _ => return Err(err("Unexpected scanf format")),
                }
            }
            i += 1;
        }
        // Calls yield no usable value (the C++ returns null Any); statements
        // drop it. Zero is a dummy for the unreachable use-as-value spot.
        Ok(0)
    }
}

fn next_format_arg(vals: &[i32], next: &mut usize) -> Result<i32, CompileError> {
    let v = *vals
        .get(*next)
        .ok_or_else(|| err("Too few arguments for format string"))?;
    *next += 1;
    Ok(v)
}
