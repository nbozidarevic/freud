# Rename checklist (Phase 8, owner-executed)

The rename from `freud` to the owner's chosen name (`c2bf` family per
decision 0001; exact name is the owner's call) is a single sweep:
every item below changes together, goldens regenerate, CI goes green,
then the tag lands. Do not rename piecemeal — the C ABI symbols, the
binary names, and the goldens must move in one commit (plus the
golden-snapshot follow-up), or the suite disagrees with itself.

This inventory was taken from the tree at the Phase 7 completion
(`git grep -i freud` over tracked files, plus file names). Re-run the
grep after the sweep: it must return only the historical records
listed under "Leave alone".

## 1. Decide (owner, before any edit)

- [ ] Exact new name (crate, binary, repo, npm package).
- [ ] Whether the GitHub repo itself is renamed (Settings →
      General → Repository name) or only the code. If the repo is
      renamed, update the local remote URL and every
      `github.com/nbozidarevic/freud` link (demo page, docs);
      GitHub redirects old repo URLs, but links should still move.

## 2. Code and build

- [ ] `rs/Cargo.toml`: package `freud-core` → new core name;
      workspace members (`ffi`, `wasm` unchanged paths).
- [ ] `rs/src/lib.rs`: crate doc name.
- [ ] `rs/src/cli.rs`: binary/help/usage/error text (the `freud`
      word in help and error output), `--version` string.
- [ ] `rs/src/bin/freud.rs` → renamed binary file; `rs/Cargo.toml`
      `[[bin]]` entry and `rs/src/main.rs` (`tokdump` driver)
      references.
- [ ] `rs/src/bin/freud-bench.rs` → renamed bench file + `[[bin]]`
      entry; `docs/perf.md` command lines.
- [ ] `rs/ffi/`: crate `freud-ffi` → new name; lib name `freud` →
      new name; `freud.h` → new header file, include guard, and all
      `freud_*` symbols (breaking ABI change — expected, version is
      still 0.0.0); `example.c` (`-lfreud`, include, comments);
      `freud.h` doc links; `src/lib.rs` (docs, symbol names, error
      prefix `freud: internal error`, version env).
- [ ] `rs/wasm/`: crate `freud-wasm` → new name; lib name
      `freud_wasm` → new name (regenerates `freud_wasm.js` /
      `freud_wasm_bg.wasm` file names — do not hand-edit generated
      files); `smoke.cjs` (file name, version assertion is
      name-agnostic); `README.md` (commands, publish name).
- [ ] `demo/`: page title/text (`index.html`), `demo.js` (import
      path `./pkg/<new>_wasm.js`, status strings, repo link).
- [ ] `tests/test`: `FREUD_BIN` env var and default binary path
      `../rs/target/release/freud` (rename the env var too, or keep
      it as a deprecated alias — decide and document; the default
      path must change either way).
- [ ] `tests/golden/generate.sh`: `FREUD=../rs/target/release/freud`
      path and variable name.
- [ ] `.github/workflows/ci.yml`: binary paths in build, golden,
      probe, `c-abi` (`-lfreud`, example build), `wasm`, and perf
      steps; job names stay, artifact names stay.
- [ ] `.github/workflows/perf-snapshot.yml`: `freud-bench` path.
- [ ] `.github/workflows/pages.yml`: no binary name (only paths) —
      verify, don't assume.
- [ ] `README.md`, `rs/ffi/README.md`, `rs/wasm/README.md`,
      `demo/README.md`, `docs/perf.md` (command lines, bench
      invocation, links): all `freud` mentions.
- [ ] `docs/roadmap.md`: mark Phase 8 `[x]` in the rename commit
      (it carries no `freud` string, so the grep will not flag it).
- [ ] `CHANGELOG.md`: add a release entry for the rename; keep the
      old entries' wording (they describe history under the old
      name).

## 3. Goldens and generated files (regenerate, don't hand-edit)

- [ ] `tests/golden/cli/*.out` (usage/help/version/error text
      carries the binary name).
- [ ] `tests/golden/bf/*.bf`, `tokdump/*.tok`,
      `parsedump/*.parse`: regenerate via the temporary snapshot
      workflow (as in Phases 6a–6d); the diff must show no
      *content* change other than the binary-name strings in CLI
      goldens — any BF byte change means the rename leaked into
      codegen and must be investigated.
- [ ] `tests/run/*.out`: regenerate via `generate.sh` on the
      snapshot run; runner error text is name-free, so these must
      be byte-identical.
- [ ] `docs/perf.md`: refresh via `freud-bench --write` (new
      binary name) on the snapshot run; the table gains no new
      rows from a pure rename.
- [ ] `demo/pkg/`: gitignored build output — delete and rebuild;
      never commit it.

## 4. Leave alone

- [ ] `docs/decisions/0001–0006.md`: historical records. Do not
      rewrite them; the rename is recorded in the CHANGELOG and in
      the rename commit message.
- [ ] `docs/baseline.md`: dated historical record.
- [ ] `LICENSE`: copyright names the author, not the project.
- [ ] `bin/`, `obj/`: ignored legacy C++ build dirs. Delete them;
      do not rename them into the new layout.
- [ ] Commit history: never rewrite it for the rename.

## 5. Verify (in order)

1. [ ] `cargo build --release`, `cargo test`, `tests/test`, C
      example, Node smoke: all green locally or in CI.
2. [ ] Full CI green on the rename commit, including golden jobs
      after the snapshot commit.
3. [ ] `git grep -i freud` returns only "Leave alone" files.
4. [ ] Tag the rename commit (owner's step; no tags exist yet),
      e.g. `v0.1.0`, and push the tag.
5. [ ] If the repo was renamed: confirm the old URL redirects,
      update any external links (blog, demo), and re-clone
      cleanly once as a sanity check.

## 6. Publish again, under the new name (owner, only if wanted)

- [ ] npm: set the new package name/version in `rs/wasm/Cargo.toml`
      and publish the `--target bundler` output (see
      `rs/wasm/README.md`).
- [ ] GitHub Pages: re-dispatch `.github/workflows/pages.yml` so
      the demo rebuilds under the new bundle file names.
