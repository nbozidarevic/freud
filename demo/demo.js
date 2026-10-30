// Demo wiring: load the wasm-pack `--target web` build from ./pkg/
// and hook up the Transpile / Run buttons. No framework, no bundler.
import init, { compile, run, version } from "./pkg/freud_wasm.js";

const srcEl = document.getElementById("src");
const inputEl = document.getElementById("input");
const bfEl = document.getElementById("bf");
const outEl = document.getElementById("out");
const statusEl = document.getElementById("status");
const compileBtn = document.getElementById("compile");
const runBtn = document.getElementById("run");

const decoder = new TextDecoder();

function showError(err) {
  statusEl.textContent = `Error: ${err}`;
  statusEl.classList.add("error");
}

function transpile() {
  const bf = compile(srcEl.value);
  bfEl.textContent = bf;
  statusEl.textContent = `Transpiled ok (freud ${version()}).`;
  statusEl.classList.remove("error");
  return bf;
}

compileBtn.addEventListener("click", () => {
  try {
    transpile();
  } catch (err) {
    showError(err);
  }
});

runBtn.addEventListener("click", () => {
  try {
    const bf = transpile();
    const input = new TextEncoder().encode(inputEl.value);
    const output = run(bf, input);
    outEl.textContent = decoder.decode(output);
    statusEl.textContent = `Ran ok (freud ${version()}).`;
    statusEl.classList.remove("error");
  } catch (err) {
    showError(err);
  }
});

compileBtn.disabled = true;
runBtn.disabled = true;
try {
  await init();
  compileBtn.disabled = false;
  runBtn.disabled = false;
  statusEl.textContent = `Ready (freud ${version()}).`;
} catch (err) {
  showError(`failed to load WebAssembly: ${err}`);
}
