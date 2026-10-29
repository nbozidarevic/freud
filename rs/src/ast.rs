//! Typed AST for the freud C subset, with S-expression serialization.
//!
//! [`dump_tu`] renders exactly the `tests/differential/SPEC.md` v1 format:
//! single-line S-expression, tokenizer-dump escaping, no positions.

use crate::token::escape_into;

#[derive(Debug)]
pub struct TranslationUnit(pub Vec<External>);

#[derive(Debug)]
pub enum External {
    FuncDef(FuncDef),
    Decl(Decl),
}

#[derive(Debug)]
pub struct FuncDef {
    pub name: Vec<u8>,
    pub body: Block,
}

#[derive(Debug)]
pub struct Decl {
    pub spec: Vec<u8>,
    pub init: Option<InitDecl>,
}

#[derive(Debug)]
pub struct InitDecl {
    pub name: Vec<u8>,
    pub init: Option<Expr>,
}

#[derive(Debug)]
pub struct Block(pub Vec<BlockItem>);

#[derive(Debug)]
pub enum BlockItem {
    Decl(Decl),
    Stmt(Stmt),
}

#[derive(Debug)]
pub enum Stmt {
    Compound(Block),
    Expr(Expr),
    Empty,
    If {
        cond: Expr,
        then: Box<Stmt>,
        els: Option<Box<Stmt>>,
    },
    Switch {
        expr: Expr,
        body: Box<Stmt>,
    },
    While {
        cond: Expr,
        body: Box<Stmt>,
    },
    DoWhile {
        body: Box<Stmt>,
        cond: Expr,
    },
    For {
        init: ForInit,
        cond: Option<Expr>,
        incr: Option<Expr>,
        body: Box<Stmt>,
    },
    Return(Option<Expr>),
    Break,
    Continue,
    Case {
        label: Expr,
        body: Box<Stmt>,
    },
    Default {
        body: Box<Stmt>,
    },
    GotoLabel {
        name: Vec<u8>,
        body: Box<Stmt>,
    },
}

#[derive(Debug)]
pub enum ForInit {
    Decl(ForDecl),
    Empty,
    Expr(Expr),
}

#[derive(Debug)]
pub struct ForDecl {
    pub spec: Vec<u8>,
    pub name: Option<Vec<u8>>,
    pub init: Option<Expr>,
}

#[derive(Debug)]
pub enum Expr {
    Comma(Vec<Expr>),
    Assign {
        op: Vec<u8>,
        lhs: Box<Expr>,
        rhs: Box<Expr>,
    },
    Ternary {
        cond: Box<Expr>,
        then: Box<Expr>,
        els: Box<Expr>,
    },
    BinOp {
        op: Vec<u8>,
        l: Box<Expr>,
        r: Box<Expr>,
    },
    Unary {
        op: Vec<u8>,
        e: Box<Expr>,
    },
    Postfix {
        op: Vec<u8>,
        e: Box<Expr>,
    },
    Call {
        callee: Box<Expr>,
        args: Vec<Expr>,
    },
    Paren(Box<Expr>),
    Int(Vec<u8>),
    Char(Vec<u8>),
    StringLit {
        /// Concatenated cooked contents (escapes processed).
        cooked: Vec<u8>,
        /// First literal's raw inner text (escapes unprocessed).
        raw: Vec<u8>,
    },
    Ident(Vec<u8>),
}

fn open(out: &mut Vec<u8>, kind: &str) {
    out.push(b'(');
    out.extend_from_slice(kind.as_bytes());
}

fn open_text(out: &mut Vec<u8>, kind: &str, text: &[u8]) {
    open(out, kind);
    out.push(b' ');
    escape_into(out, text);
}

fn close(out: &mut Vec<u8>) {
    out.push(b')');
}

/// Serialize `tu` in the SPEC.md v1 format (no trailing newline).
pub fn dump_tu(tu: &TranslationUnit, out: &mut Vec<u8>) {
    open(out, "tu");
    for e in &tu.0 {
        out.push(b' ');
        dump_external(e, out);
    }
    close(out);
}

fn dump_external(e: &External, out: &mut Vec<u8>) {
    match e {
        External::FuncDef(f) => {
            open_text(out, "funcdef", &f.name);
            out.push(b' ');
            dump_block(&f.body, out);
            close(out);
        }
        External::Decl(d) => dump_decl(d, out),
    }
}

fn dump_decl(d: &Decl, out: &mut Vec<u8>) {
    open_text(out, "decl", &d.spec);
    if let Some(init) = &d.init {
        out.push(b' ');
        open_text(out, "initdecl", &init.name);
        if let Some(e) = &init.init {
            out.push(b' ');
            dump_expr(e, out);
        }
        close(out);
    }
    close(out);
}

fn dump_block(b: &Block, out: &mut Vec<u8>) {
    open(out, "compound");
    for item in &b.0 {
        out.push(b' ');
        match item {
            BlockItem::Decl(d) => dump_decl(d, out),
            BlockItem::Stmt(s) => dump_stmt(s, out),
        }
    }
    close(out);
}

fn dump_stmt(s: &Stmt, out: &mut Vec<u8>) {
    match s {
        Stmt::Compound(b) => dump_block(b, out),
        Stmt::Expr(e) => {
            open(out, "exprstmt");
            out.push(b' ');
            dump_expr(e, out);
            close(out);
        }
        Stmt::Empty => {
            open(out, "empty");
            close(out);
        }
        Stmt::If { cond, then, els } => {
            open(out, if els.is_some() { "ifelse" } else { "if" });
            out.push(b' ');
            dump_expr(cond, out);
            out.push(b' ');
            dump_stmt(then, out);
            if let Some(e) = els {
                out.push(b' ');
                dump_stmt(e, out);
            }
            close(out);
        }
        Stmt::Switch { expr, body } => {
            open(out, "switch");
            out.push(b' ');
            dump_expr(expr, out);
            out.push(b' ');
            dump_stmt(body, out);
            close(out);
        }
        Stmt::While { cond, body } => {
            open(out, "while");
            out.push(b' ');
            dump_expr(cond, out);
            out.push(b' ');
            dump_stmt(body, out);
            close(out);
        }
        Stmt::DoWhile { body, cond } => {
            open(out, "dowhile");
            out.push(b' ');
            dump_stmt(body, out);
            out.push(b' ');
            dump_expr(cond, out);
            close(out);
        }
        Stmt::For {
            init,
            cond,
            incr,
            body,
        } => {
            open(out, "for");
            out.push(b' ');
            match init {
                ForInit::Decl(f) => dump_fordecl(f, out),
                ForInit::Empty => {
                    open(out, "empty-init");
                    close(out);
                }
                ForInit::Expr(e) => dump_expr(e, out),
            }
            if let Some(c) = cond {
                out.push(b' ');
                dump_expr(c, out);
            }
            if let Some(i) = incr {
                out.push(b' ');
                dump_expr(i, out);
            }
            out.push(b' ');
            dump_stmt(body, out);
            close(out);
        }
        Stmt::Return(e) => {
            open(out, "return");
            if let Some(x) = e {
                out.push(b' ');
                dump_expr(x, out);
            }
            close(out);
        }
        Stmt::Break => {
            open(out, "break");
            close(out);
        }
        Stmt::Continue => {
            open(out, "continue");
            close(out);
        }
        Stmt::Case { label, body } => {
            open(out, "case");
            out.push(b' ');
            dump_expr(label, out);
            out.push(b' ');
            dump_stmt(body, out);
            close(out);
        }
        Stmt::Default { body } => {
            open(out, "default");
            out.push(b' ');
            dump_stmt(body, out);
            close(out);
        }
        Stmt::GotoLabel { name, body } => {
            open_text(out, "goto-label", name);
            out.push(b' ');
            dump_stmt(body, out);
            close(out);
        }
    }
}

fn dump_fordecl(f: &ForDecl, out: &mut Vec<u8>) {
    // Text is "spec" or "spec name", byte-identical to the reference's
    // single-string text (spec/name never need escaping).
    open(out, "fordecl");
    out.push(b' ');
    escape_into(out, &f.spec);
    if let Some(name) = &f.name {
        out.push(b' ');
        escape_into(out, name);
    }
    if let Some(init) = &f.init {
        out.push(b' ');
        dump_expr(init, out);
    }
    close(out);
}

fn dump_expr(e: &Expr, out: &mut Vec<u8>) {
    match e {
        Expr::Comma(es) => {
            open(out, "comma");
            for x in es {
                out.push(b' ');
                dump_expr(x, out);
            }
            close(out);
        }
        Expr::Assign { op, lhs, rhs } => {
            open_text(out, "assign", op);
            out.push(b' ');
            dump_expr(lhs, out);
            out.push(b' ');
            dump_expr(rhs, out);
            close(out);
        }
        Expr::Ternary { cond, then, els } => {
            open(out, "ternary");
            out.push(b' ');
            dump_expr(cond, out);
            out.push(b' ');
            dump_expr(then, out);
            out.push(b' ');
            dump_expr(els, out);
            close(out);
        }
        Expr::BinOp { op, l, r } => {
            open_text(out, "binop", op);
            out.push(b' ');
            dump_expr(l, out);
            out.push(b' ');
            dump_expr(r, out);
            close(out);
        }
        Expr::Unary { op, e } => {
            open_text(out, "unary", op);
            out.push(b' ');
            dump_expr(e, out);
            close(out);
        }
        Expr::Postfix { op, e } => {
            open_text(out, "postfix", op);
            out.push(b' ');
            dump_expr(e, out);
            close(out);
        }
        Expr::Call { callee, args } => {
            open(out, "call");
            out.push(b' ');
            dump_expr(callee, out);
            for a in args {
                out.push(b' ');
                dump_expr(a, out);
            }
            close(out);
        }
        Expr::Paren(e) => {
            open(out, "paren");
            out.push(b' ');
            dump_expr(e, out);
            close(out);
        }
        Expr::Int(t) => {
            open_text(out, "int", t);
            close(out);
        }
        Expr::Char(t) => {
            open_text(out, "char", t);
            close(out);
        }
        Expr::StringLit { cooked, .. } => {
            open_text(out, "string", cooked);
            close(out);
        }
        Expr::Ident(t) => {
            open_text(out, "ident", t);
            close(out);
        }
    }
}
