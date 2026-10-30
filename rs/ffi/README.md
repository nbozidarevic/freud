# C ABI adapter (`freud-ffi`)

A dependency-free C ABI over `freud-core`, kept in its own crate so
the core stays free of FFI surface (pollution veto, see
`docs/decisions/0006-distribution-adapters.md`). The adapter adds no
behavior: it forwards to `compile`, `runner::run`, and `format`.

## Build

```
cargo build --release --manifest-path rs/ffi/Cargo.toml
```

The shared library lands at `rs/target/release/libfreud.so` (Linux)
or `libfreud.dylib` (macOS). The header is [freud.h](/Users/nenad/Code/freud/rs/ffi/freud.h);
the worked example is [example.c](/Users/nenad/Code/freud/rs/ffi/example.c):

```
cc -std=c11 -Wall -Wextra -Werror rs/ffi/example.c -Irs/ffi \
  -o /tmp/freud_example -Lrs/target/release -lfreud
LD_LIBRARY_PATH=rs/target/release /tmp/freud_example       # Linux
DYLD_LIBRARY_PATH=rs/target/release /tmp/freud_example   # macOS
```

## Contract

See [freud.h](/Users/nenad/Code/freud/rs/ffi/freud.h) for the authoritative wording.
In short: inputs are `(pointer, length)` byte slices; outputs come
back through `(*out, *out_len)` and are freed with `freud_free`
passing the exact length; return codes are `0` ok, `1` operation
error (`freud_last_error()`), `2` invalid argument; no panic crosses
the boundary.

## Tests

```
cargo test --manifest-path rs/ffi/Cargo.toml
```

The Rust tests exercise the ABI itself (compile/run round-trip,
error and argument validation, format). The C example is built and
run by the `c-abi` CI job on Ubuntu and macOS.

## Notes

- Symbol names (`freud_*`) follow the crate name and will change with
  the Phase 8 rename. The contract shape will not.
- Kotlin/Swift (UniFFI) and Java (JNI) bridges are named follow-ups
  in `docs/decisions/0006-distribution-adapters.md`; both build on
  this ABI. The web/WASM adapter lives separately under `wasm/`.
