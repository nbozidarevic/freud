# 0006 — Distribution adapters: C ABI first, the rest gated

Date: 2026-10-30. Status: accepted. Records the Phase 7 shape decided
in 0005 and what is built, deferred, or gated.

## Decision

Distribution proceeds native-first, in this order:

1. **C ABI (built, Phase 7a).** A separate crate, `freud-ffi`
   (`rs/ffi/`), exposing `compile`/`run`/`format` over `extern "C"`
   with a hand-written header (`freud.h`) and a C example. The core
   crate (`freud-core`) gains no FFI module, no new dependency, and
   no `#[no_mangle]` surface: the pollution veto is enforced by the
   crate boundary, not by discipline. The C ABI is the interop floor
   for C++ embedders and for any future JNI bridge (JNI calls C).
2. **UniFFI (Kotlin/Swift) and JNI (Java): deferred, named.**
   Both were surveyed in 0005 and remain the intended paths, but
   neither is built now: UniFFI needs `uniffi-bindgen` plus
   Kotlin/Swift toolchains to verify generated bindings, and JNI
   needs a JDK plus hand-written glue that the C ABI already makes
   possible. Building either unverified in a CI-primary loop would
   ship scaffold the owner cannot run. Revisit when a consumer
   exists; the UDL/JNI surface will wrap this same C ABI.
3. **Web/WASM (gated, Phase 7b).** A separate `wasm-bindgen` crate
   under `wasm/` plus an npm package and a demo page, built and
   smoke-tested in CI but not published: npm publishing needs an
   owner token, and GitHub Pages deployment needs Pages enabled in
   repo settings. No `wasm-bindgen` (or any web) dependency enters
   `freud-core`. The demo deploys only on manual dispatch.

## Consequences

- `freud-core` stays dependency-free with one public surface (Rust).
  Every adapter is a separate crate or directory that depends on it
  by path.
- The C ABI is verified two ways: Rust tests calling the exported
  functions, and the C example built and run on Ubuntu and macOS
  (`c-abi` CI job).

## Update (2026-10-30): 7b built

The web adapter exists: `freud-wasm` crate (`rs/wasm/`), the
`demo/` page, a Node smoke test, and a dispatch-only Pages workflow.
CI verifies all three `wasm-pack` targets (`web`, `nodejs`,
`bundler`) and the smoke test. npm publishing and Pages deployment
remain owner-gated manual steps (see `rs/wasm/README.md`); neither
has been run.
- Symbol names (`freud_*`) change with the Phase 8 rename. That is a
  breaking change to this ABI, accepted while the version is 0.0.0;
  the contract shape (return codes, ownership, error accessor)
  survives the rename.
- The workspace root (`rs/Cargo.toml`) declares
  `default-members = ["."]`, so existing core build/test commands
  keep their meaning; adapter crates build via their own manifests.
