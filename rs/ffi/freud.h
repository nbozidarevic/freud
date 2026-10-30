/* freud.h - C ABI over the freud transpiler core (see rs/ffi/).
 *
 * The core accepts a C subset and transpiles it to Brainfuck; this
 * header exposes compile/run/format to C and C++ embedders (and,
 * through it, to JNI and other C-FFI bridges). Symbol names follow the
 * crate name and will change with the Phase 8 rename; the shape of
 * this contract will not.
 *
 * Ownership: every function that produces bytes returns them through
 * (*out, *out_len). The buffer is heap-allocated, owned by the caller,
 * and freed with freud_free() passing back the exact length. Empty
 * output is (NULL, 0); freud_free(NULL, 0) is a no-op. Buffers must
 * not be freed with free(), and must not be used after freud_free().
 *
 * Inputs are (pointer, length) byte slices; no NUL termination is
 * assumed, and output bytes may contain NULs (a program may print
 * '\0'). A NULL input pointer with length 0 means "empty input".
 *
 * Return codes: 0 ok, 1 operation error (freud_last_error() holds
 * the message), 2 invalid argument (NULL out-pointers, or a NULL
 * input pointer with a nonzero length). On failure *out is NULL and
 * *out_len is 0. freud_last_error() is thread-local and valid until
 * the next freud_* call on the same thread; it returns NULL when the
 * last call on this thread succeeded.
 *
 * Thread safety: all functions are safe to call concurrently from
 * multiple threads (error state is thread-local). No global state is
 * shared between calls.
 *
 * Linking: build the shared library with
 *   cargo build --release --manifest-path rs/ffi/Cargo.toml
 * which produces rs/target/release/libfreud.so (Linux),
 * libfreud.dylib (macOS). Link with -lfreud and point the loader at
 * that directory (LD_LIBRARY_PATH on Linux, DYLD_LIBRARY_PATH on
 * macOS, or an rpath).
 */

#ifndef FREUD_H
#define FREUD_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Library version (the crate version), NUL-terminated, process-lifetime. */
const char *freud_version(void);

/* Transpile C source to Brainfuck (plus a trailing newline, as the
 * CLI emits). */
int freud_compile(const uint8_t *src, size_t src_len,
                  uint8_t **out, size_t *out_len);

/* Run a Brainfuck program; `input` feeds its `,` reads. Runner errors
 * (e.g. unbalanced brackets) report 1 and discard partial output;
 * use the CLI to stream partial output before an error. */
int freud_run(const uint8_t *code, size_t code_len,
              const uint8_t *input, size_t input_len,
              uint8_t **out, size_t *out_len);

/* Pretty-print (minify == 0) or minify (minify != 0) Brainfuck code. */
int freud_format(const uint8_t *code, size_t code_len, int minify,
                 uint8_t **out, size_t *out_len);

/* Last operation error on this thread, NUL-terminated, or NULL. */
const char *freud_last_error(void);

/* Free a buffer returned through (*out, *out_len). */
void freud_free(uint8_t *ptr, size_t len);

#ifdef __cplusplus
}
#endif

#endif /* FREUD_H */
