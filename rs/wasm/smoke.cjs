// Node smoke test for the wasm-pack `--target nodejs` build.
// Usage: node rs/wasm/smoke.cjs <path-to-built-dir>
// The built dir contains freud_wasm.js (CommonJS) next to its .wasm.
// Exits nonzero on the first failed assertion.
"use strict";

const assert = require("node:assert/strict");
const path = require("node:path");

const dir = process.argv[2];
if (!dir) {
  console.error("usage: node smoke.cjs <built-dir>");
  process.exit(2);
}
const { compile, run, format_code, version } = require(path.join(dir, "freud_wasm.js"));

assert.match(version(), /^\d+\.\d+\.\d+$/, "version looks like semver");

const bf = compile('int main() { printf("%d\\n", 6 * 7); }');
assert.equal(typeof bf, "string");
assert.ok(bf.endsWith("\n"), "compile output ends with newline");

const out = run(bf, new Uint8Array(0));
assert.ok(out instanceof Uint8Array, "run returns bytes");
assert.deepEqual(Array.from(out), [52, 50, 10], 'run prints "42\\n"');

assert.throws(
  () => compile("int main( {"),
  (err) => typeof err === "string" && err.length > 0,
  "bad source throws a diagnostic",
);
assert.throws(
  () => run("]", new Uint8Array(0)),
  /unexpected/,
  "unbalanced close throws",
);

assert.equal(format_code("a + b [ignored]", true), "+[]\n", "minify keeps commands");

console.log("wasm smoke ok, version", version());
