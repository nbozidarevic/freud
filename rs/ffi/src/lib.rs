//! C ABI over [`freud_core`]: `compile`, `run`, `format` for C/C++
//! (and, through it, JNI) embedders.
//!
//! This crate is deliberately separate from `freud-core` (see
//! `docs/decisions/0006-distribution-adapters.md`): the core stays a
//! dependency-free Rust library with no FFI surface, and adapters live
//! in their own crates. Nothing here changes core behavior.
//!
//! Contract (mirrored in `freud.h`):
//! - Inputs are `(pointer, length)` byte slices; no NUL termination
//!   is assumed. A null pointer with a nonzero length is an argument
//!   error; null with length 0 is an empty input.
//! - On success (`0`), `*out` points to `*out_len` heap bytes owned
//!   by the caller, freed with [`freud_free`]. Empty output is
//!   (`NULL`, `0`). On failure, `*out` is `NULL` and `*out_len` is 0.
//! - Return codes: `0` ok, `1` operation error (see
//!   [`freud_last_error`]), `2` invalid argument. No panic crosses
//!   the boundary: panics are caught and reported as code `1`.
//! - [`freud_last_error`] is thread-local and valid until the next
//!   FFI call on the same thread.

use std::cell::RefCell;
use std::ffi::{CString, c_char};
use std::panic::{AssertUnwindSafe, catch_unwind};

#[cfg(test)]
use std::ffi::CStr;

thread_local! {
    static LAST_ERROR: RefCell<Option<CString>> = const { RefCell::new(None) };
}

fn set_error(msg: &str) {
    // A NUL in the message cannot be represented in C; drop the
    // message rather than truncate it silently into a valid prefix.
    let stored = CString::new(msg.as_bytes()).unwrap_or_default();
    LAST_ERROR.with(|e| *e.borrow_mut() = Some(stored));
}

fn clear_error() {
    LAST_ERROR.with(|e| *e.borrow_mut() = None);
}

/// Borrow the caller's byte slice. Null with length 0 is empty;
/// null with a nonzero length is an argument error.
fn in_slice<'a>(ptr: *const u8, len: usize) -> Result<&'a [u8], i32> {
    if ptr.is_null() {
        if len == 0 {
            return Ok(&[]);
        }
        return Err(2);
    }
    // SAFETY: the header requires `ptr` to stay valid for `len`
    // bytes for the duration of the call.
    Ok(unsafe { std::slice::from_raw_parts(ptr, len) })
}

/// Publish `bytes` through `(*out, *out_len)`. Both out-pointers
/// must be non-null. Empty output publishes (`NULL`, `0`).
fn deliver(out: *mut *mut u8, out_len: *mut usize, bytes: Vec<u8>) -> i32 {
    if out.is_null() || out_len.is_null() {
        return 2;
    }
    if bytes.is_empty() {
        // SAFETY: `out`/`out_len` were just null-checked.
        unsafe {
            *out = std::ptr::null_mut();
            *out_len = 0;
        }
        return 0;
    }
    let mut boxed = bytes.into_boxed_slice();
    let len = boxed.len();
    let ptr = boxed.as_mut_ptr();
    std::mem::forget(boxed);
    // SAFETY: `out`/`out_len` were just null-checked.
    unsafe {
        *out = ptr;
        *out_len = len;
    }
    0
}

/// Run `f`, catching panics at the boundary. `f` returns a status
/// code; panics report as an operation error.
fn guard<F: FnOnce() -> i32>(f: F) -> i32 {
    match catch_unwind(AssertUnwindSafe(f)) {
        Ok(code) => code,
        Err(_) => {
            set_error("freud: internal error");
            1
        }
    }
}

/// Library version (the crate version), as a NUL-terminated string
/// valid for the life of the process.
#[no_mangle]
pub extern "C" fn freud_version() -> *const c_char {
    static VERSION: &str = concat!(env!("CARGO_PKG_VERSION"), "\0");
    VERSION.as_ptr() as *const c_char
}

/// Transpile C source to Brainfuck (plus a trailing newline, as the
/// CLI emits). See the module docs for the output contract.
#[no_mangle]
pub extern "C" fn freud_compile(
    src: *const u8,
    src_len: usize,
    out: *mut *mut u8,
    out_len: *mut usize,
) -> i32 {
    clear_error();
    guard(|| {
        let src = match in_slice(src, src_len) {
            Ok(s) => s,
            Err(code) => return code,
        };
        match freud_core::compile::compile(src) {
            Ok(bf) => deliver(out, out_len, bf),
            Err(e) => {
                set_error(&e.msg);
                1
            }
        }
    })
}

/// Run a Brainfuck program with `input` on stdin. Output bytes (which
/// may contain NULs) come back through `(*out, *out_len)`. Runner
/// errors (e.g. unbalanced brackets) report code `1`; partial
/// output is discarded — stream via the CLI for partial output.
#[no_mangle]
pub extern "C" fn freud_run(
    code: *const u8,
    code_len: usize,
    input: *const u8,
    input_len: usize,
    out: *mut *mut u8,
    out_len: *mut usize,
) -> i32 {
    clear_error();
    guard(|| {
        let code = match in_slice(code, code_len) {
            Ok(s) => s,
            Err(code) => return code,
        };
        let input = match in_slice(input, input_len) {
            Ok(s) => s,
            Err(code) => return code,
        };
        let mut input = input;
        let mut output = Vec::new();
        match freud_core::runner::run(code, &mut input, &mut output) {
            Ok(()) => deliver(out, out_len, output),
            Err(e) => {
                set_error(e);
                1
            }
        }
    })
}

/// Pretty-print (`minify == 0`) or minify (`minify != 0`) Brainfuck
/// code. Infallible apart from argument validation.
#[no_mangle]
pub extern "C" fn freud_format(
    code: *const u8,
    code_len: usize,
    minify: std::ffi::c_int,
    out: *mut *mut u8,
    out_len: *mut usize,
) -> i32 {
    clear_error();
    guard(|| {
        let code = match in_slice(code, code_len) {
            Ok(s) => s,
            Err(code) => return code,
        };
        let mut output = Vec::new();
        freud_core::format::format(code, &mut output, minify != 0);
        deliver(out, out_len, output)
    })
}

/// The last operation error on this thread, as a NUL-terminated
/// string, or `NULL` when the last call succeeded. Valid until the
/// next FFI call on the same thread.
#[no_mangle]
pub extern "C" fn freud_last_error() -> *const c_char {
    LAST_ERROR.with(|e| match e.borrow().as_ref() {
        Some(msg) => msg.as_ptr(),
        None => std::ptr::null(),
    })
}

/// Free a buffer returned through `(*out, *out_len)`, passing back
/// the exact length received. Null is a no-op. Buffers must not be
/// freed with any other allocator.
#[no_mangle]
pub extern "C" fn freud_free(ptr: *mut u8, len: usize) {
    if ptr.is_null() || len == 0 {
        return;
    }
    // SAFETY: `ptr`/`len` came from `deliver`, which leaked exactly
    // one boxed slice per buffer; reconstructing it drops the
    // allocation once.
    unsafe {
        drop(Box::from_raw(std::ptr::slice_from_raw_parts_mut(ptr, len)));
    }
}

/// Read a C string for tests (the header's contract, not FFI).
#[cfg(test)]
fn last_error_str() -> Option<String> {
    let ptr = freud_last_error();
    if ptr.is_null() {
        return None;
    }
    // SAFETY: `freud_last_error` returns a valid NUL-terminated
    // string or null, checked above.
    Some(unsafe { CStr::from_ptr(ptr) }.to_string_lossy().into_owned())
}

#[cfg(test)]
mod tests {
    use super::*;

    /// Read back a delivered buffer, then free it through the FFI.
    unsafe fn take(out: *mut u8, len: usize) -> Vec<u8> {
        if out.is_null() {
            assert_eq!(len, 0);
            return Vec::new();
        }
        // SAFETY: the buffer was delivered by the FFI call under
        // test, with exactly this length.
        let bytes = unsafe { std::slice::from_raw_parts(out, len) }.to_vec();
        freud_free(out, len);
        bytes
    }

    #[test]
    fn compile_run_round_trip() {
        let src = b"int main() { printf(\"%d\\n\", 6 * 7); }";
        let mut bf: *mut u8 = std::ptr::null_mut();
        let mut bf_len = 0usize;
        let rc = freud_compile(src.as_ptr(), src.len(), &mut bf, &mut bf_len);
        assert_eq!(rc, 0);
        assert!(bf_len > 0);
        let bf = unsafe { take(bf, bf_len) };
        assert_eq!(bf.last(), Some(&b'\n'));

        let mut out: *mut u8 = std::ptr::null_mut();
        let mut out_len = 0usize;
        let rc = freud_run(bf.as_ptr(), bf.len(), std::ptr::null(), 0, &mut out, &mut out_len);
        assert_eq!(rc, 0);
        assert_eq!(unsafe { take(out, out_len) }, b"42\n");
        assert_eq!(last_error_str(), None);
    }

    #[test]
    fn run_reports_unbalanced_brackets() {
        let mut out: *mut u8 = std::ptr::null_mut();
        let mut out_len = 0usize;
        let rc = freud_run(b"]".as_ptr(), 1, std::ptr::null(), 0, &mut out, &mut out_len);
        assert_eq!(rc, 1);
        assert!(out.is_null() && out_len == 0);
        assert_eq!(
            last_error_str().as_deref(),
            Some(freud_core::runner::ERR_UNEXPECTED_CLOSE)
        );
    }

    #[test]
    fn compile_error_reports_message() {
        let mut out: *mut u8 = std::ptr::null_mut();
        let mut out_len = 0usize;
        let rc = freud_compile(b"int main( {".as_ptr(), 11, &mut out, &mut out_len);
        assert_eq!(rc, 1);
        assert!(out.is_null() && out_len == 0);
        assert!(last_error_str().is_some_and(|m| !m.is_empty()));
    }

    #[test]
    fn format_minifies() {
        let mut out: *mut u8 = std::ptr::null_mut();
        let mut out_len = 0usize;
        let rc = freud_format(b"a + b [ignored]".as_ptr(), 15, 1, &mut out, &mut out_len);
        assert_eq!(rc, 0);
        assert_eq!(unsafe { take(out, out_len) }, b"+[]\n");
    }

    #[test]
    fn null_arguments_are_rejected() {
        let mut out: *mut u8 = std::ptr::null_mut();
        let mut out_len = 0usize;
        // Null input with a nonzero length.
        assert_eq!(
            freud_compile(std::ptr::null(), 3, &mut out, &mut out_len),
            2
        );
        // Null out-pointers.
        let src = b"int main() {}";
        assert_eq!(
            freud_compile(src.as_ptr(), src.len(), std::ptr::null_mut(), &mut out_len),
            2
        );
        assert_eq!(
            freud_compile(src.as_ptr(), src.len(), &mut out, std::ptr::null_mut()),
            2
        );
    }

    #[test]
    fn version_is_present() {
        let ptr = freud_version();
        assert!(!ptr.is_null());
        // SAFETY: `freud_version` returns a valid NUL-terminated string.
        let v = unsafe { CStr::from_ptr(ptr) }.to_str().unwrap();
        assert!(!v.is_empty());
    }
}
