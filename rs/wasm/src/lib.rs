//! WebAssembly adapter over [`freud_core`]: `compile`, `run`, and
//! `format` for the browser demo and the npm package.
//!
//! Kept in its own crate so `freud-core` never depends on
//! `wasm-bindgen` (pollution veto, see
//! `docs/decisions/0006-distribution-adapters.md`). The exported
//! functions are thin wrappers: strings in, strings or byte arrays
//! out, errors as thrown strings.
//!
//! - `compile`/`format_code` return UTF-8 strings: transpiled and
//!   formatted Brainfuck contain only ASCII commands, newlines, and
//!   spaces.
//! - `run` returns a byte array (`Uint8Array`): program output may
//!   contain arbitrary bytes, including NULs.

use wasm_bindgen::prelude::*;

/// Transpile C source to Brainfuck (plus a trailing newline, as the
/// CLI emits). Throws the compile diagnostic on failure.
#[wasm_bindgen]
pub fn compile(src: &str) -> Result<String, JsValue> {
    freud_core::compile::compile(src.as_bytes())
        .map(|bf| String::from_utf8_lossy(&bf).into_owned())
        .map_err(|e| JsValue::from_str(&e.msg))
}

/// Run a Brainfuck program with `input` on stdin. Throws the runner
/// error (e.g. unbalanced brackets) on failure; partial output is
/// discarded.
#[wasm_bindgen]
pub fn run(code: &str, input: &[u8]) -> Result<Vec<u8>, JsValue> {
    let mut input = input;
    let mut output = Vec::new();
    freud_core::runner::run(code.as_bytes(), &mut input, &mut output)
        .map(|()| output)
        .map_err(JsValue::from_str)
}

/// Pretty-print (`minify == false`) or minify Brainfuck code.
#[wasm_bindgen]
pub fn format_code(code: &str, minify: bool) -> String {
    let mut output = Vec::new();
    freud_core::format::format(code.as_bytes(), &mut output, minify);
    String::from_utf8_lossy(&output).into_owned()
}

/// Library version (the crate version).
#[wasm_bindgen]
pub fn version() -> String {
    env!("CARGO_PKG_VERSION").to_owned()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn compile_run_round_trip() {
        let bf = compile("int main() { printf(\"%d\\n\", 6 * 7); }").unwrap();
        assert!(bf.ends_with('\n'));
        assert_eq!(run(&bf, &[]).unwrap(), b"42\n");
    }

    #[test]
    fn compile_error_is_reported() {
        let err = compile("int main( {").unwrap_err();
        assert!(err.as_string().is_some_and(|m| !m.is_empty()));
    }

    #[test]
    fn run_reports_unbalanced_brackets() {
        let err = run("]", &[]).unwrap_err();
        assert_eq!(
            err.as_string().as_deref(),
            Some(freud_core::runner::ERR_UNEXPECTED_CLOSE)
        );
    }

    #[test]
    fn format_minifies() {
        assert_eq!(format_code("a + b [ignored]", true), "+[]\n");
    }
}
