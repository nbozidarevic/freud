# WebAssembly adapter (`freud-wasm`)

A `wasm-bindgen` adapter over `freud-core`, kept in its own crate so
the core never depends on `wasm-bindgen` (pollution veto, see
`docs/decisions/0006-distribution-adapters.md`). It exports
`compile`, `run`, `format_code`, and `version` for the browser demo
and the npm package. The adapter adds no behavior.

## Build

`wasm-pack` builds the crate for a chosen target. `demo/pkg/` is the
`web` build output directory (gitignored build artifact):

```
wasm-pack build rs/wasm --target web --out-dir demo/pkg
```

For Node (smoke tests, bundlers) and for npm publishing:

```
wasm-pack build rs/wasm --target bundler --out-dir /tmp/freud-pkg
```

## Tests

Rust unit tests (plain functions, no browser needed):

```
cargo test --manifest-path rs/wasm/Cargo.toml
```

Node smoke test against a `--target nodejs` build:

```
wasm-pack build rs/wasm --target nodejs --out-dir /tmp/freud-node-pkg
node rs/wasm/smoke.cjs /tmp/freud-node-pkg
```

Both builds and the smoke test run in the `wasm` CI job.

## npm publishing (owner-gated, not run by CI)

The `--target bundler` output directory *is* the npm package: it
contains `package.json`, the JS glue, TypeScript definitions, and the
`.wasm` binary. Publishing is deliberately manual:

```
wasm-pack build rs/wasm --target bundler --out-dir /tmp/freud-pkg
cd /tmp/freud-pkg
npm publish --access public   # needs an npm account + token
```

The published name and version come from `rs/wasm/Cargo.toml`
(`freud-wasm`, currently `0.0.0`); set a real version before the
first publish, and expect the `freud-*` name to change with the
Phase 8 rename.

## Demo site (owner-gated, not deployed by CI)

`demo/` is a static page using the `web` build. Deploying it to
GitHub Pages is a manual dispatch of `.github/workflows/pages.yml`
after enabling Pages in the repo settings (Settings → Pages →
Source: GitHub Actions). The deploy itself is unverified until the
owner runs it once; the build it uses is the same one CI verifies.
