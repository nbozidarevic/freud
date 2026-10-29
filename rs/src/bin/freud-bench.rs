//! `freud-bench`: performance harness (Phase 5).
//!
//! In-process timing of transpilation (`compile`) and execution
//! (`runner::run`) for the corpus under `tests/compile/`, plus
//! synthetic runner microbenchmarks. Excludes process startup.
//!
//! Usage (from the repo root):
//!   freud-bench [--quick] [--json | --md | --write docs/perf.md] [root]
//!
//! Timing is adaptive: each case runs at least 3 iterations and until
//! ~2s total elapsed (cap 100 iterations), so fast and slow cases both
//! get stable means. CI runners are shared and noisy: compare numbers
//! within one run, not across runs. See `docs/perf.md`.

use std::env;
use std::ffi::OsStr;
use std::fs;
use std::io::Cursor;
use std::path::{Path, PathBuf};
use std::time::Instant;

use freud_core::{compile, runner};

struct Stats {
    iters: usize,
    mean_ms: f64,
    min_ms: f64,
}

fn bench<F: FnMut()>(mut f: F, min_iters: usize, target_ms: u128, cap: usize) -> Stats {
    f();
    let mut samples = Vec::new();
    let start = Instant::now();
    let mut iters = 0;
    while iters < min_iters || (start.elapsed().as_millis() < target_ms && iters < cap) {
        let t = Instant::now();
        f();
        samples.push(t.elapsed());
        iters += 1;
    }
    let vals: Vec<f64> = samples.iter().map(|d| d.as_secs_f64() * 1000.0).collect();
    let mean = vals.iter().sum::<f64>() / vals.len() as f64;
    let min = vals.iter().cloned().fold(f64::INFINITY, f64::min);
    Stats {
        iters,
        mean_ms: mean,
        min_ms: min,
    }
}

struct Case {
    name: String,
    bf_bytes: usize,
    compile: Stats,
    run: Stats,
    out_bytes: usize,
}

fn bench_corpus(root: &Path, target_ms: u128, cap: usize) -> Vec<Case> {
    let dir = root.join("tests/compile");
    let mut paths: Vec<PathBuf> = fs::read_dir(&dir)
        .unwrap_or_else(|e| panic!("cannot read {}: {}", dir.display(), e))
        .filter_map(|e| e.ok())
        .map(|e| e.path())
        .filter(|p| p.extension().is_some_and(|x| x == OsStr::new("c")))
        .collect();
    paths.sort();
    let mut cases = Vec::new();
    for cpath in paths {
        let stem = cpath
            .file_stem()
            .expect("stem")
            .to_string_lossy()
            .into_owned();
        eprintln!("benching corpus {stem}");
        let src = fs::read(&cpath).expect("read source");
        let input = fs::read(cpath.with_extension("in")).unwrap_or_default();
        let bf = compile::compile(&src).expect("compile corpus");
        let cstats = bench(|| {
            let _ = compile::compile(&src);
        }, 3, target_ms, cap);
        let mut out = Vec::new();
        let _ = runner::run(&bf, &mut Cursor::new(input.as_slice()), &mut out);
        let out_bytes = out.len();
        let code = bf.clone();
        let rstats = bench(
            || {
                let mut o = Vec::new();
                let _ = runner::run(&code, &mut Cursor::new(input.as_slice()), &mut o);
            },
            3,
            target_ms,
            cap,
        );
        cases.push(Case {
            name: stem,
            bf_bytes: bf.len(),
            compile: cstats,
            run: rstats,
            out_bytes,
        });
    }
    cases
}

struct Micro {
    name: &'static str,
    code: Vec<u8>,
    run: Stats,
    out_bytes: usize,
}

fn bench_micros(target_ms: u128, cap: usize) -> Vec<Micro> {
    let defs: Vec<(&'static str, Vec<u8>, Vec<u8>)> = vec![
        // 10x10x10 nested loops.
        (
            "nested-loops",
            b"++++++++++[>++++++++++[>++++++++++<-]<-]>>.".to_vec(),
            vec![],
        ),
        // 100k cells right, set, 100k back: growth + pointer motion.
        (
            "tape-walk",
            format!("{}+{}.", ">".repeat(100_000), "<".repeat(100_000)).into_bytes(),
            vec![],
        ),
        // 100k increments on one cell: per-op cell access.
        ("cell-bump", format!("{}.", "+".repeat(100_000)).into_bytes(), vec![]),
        // Zero cell, 100k-command skip: forward-scan cost of `[`.
        (
            "skip-scan",
            format!("[{}]", "+".repeat(100_000)).into_bytes(),
            vec![],
        ),
        // 4 KiB echo: one syscall-ish read/write per byte in the naive path.
        // Input ends with NUL: EOF leaves the cell unchanged, so `,[.,]`
        // without a zero terminator would loop forever.
        ("io-echo", b",[.,]".to_vec(), {
            let mut v = vec![b'A'; 4096];
            v.push(0);
            v
        }),
    ];
    defs.into_iter()
        .map(|(name, code, input)| {
            eprintln!("benching micro {name}");
            let mut out = Vec::new();
            let _ = runner::run(&code, &mut Cursor::new(input.as_slice()), &mut out);
            let out_bytes = out.len();
            let run = bench(
                || {
                    let mut o = Vec::new();
                    let _ = runner::run(&code, &mut Cursor::new(input.as_slice()), &mut o);
                },
                3,
                target_ms,
                cap,
            );
            Micro {
                name,
                code,
                run,
                out_bytes,
            }
        })
        .collect()
}

fn md_fragment(cases: &[Case], micros: &[Micro]) -> String {
    let mut s = String::new();
    s.push_str(&format!(
        "In-process timing on {}-{} (`freud-bench`, adaptive iterations: at least 3, until ~2s total, cap 100). Times exclude process startup.\n\n",
        env::consts::OS,
        env::consts::ARCH
    ));
    s.push_str("| program | BF bytes | compile mean (ms) | run mean (ms) | run min (ms) | iters | out bytes |\n");
    s.push_str("|---|---|---|---|---|---|---|\n");
    for c in cases {
        s.push_str(&format!(
            "| {} | {} | {:.3} | {:.3} | {:.3} | {} | {} |\n",
            c.name, c.bf_bytes, c.compile.mean_ms, c.run.mean_ms, c.run.min_ms, c.run.iters, c.out_bytes
        ));
    }
    s.push_str("\nRunner microbenchmarks:\n\n");
    s.push_str("| name | BF bytes | run mean (ms) | run min (ms) | iters | out bytes |\n");
    s.push_str("|---|---|---|---|---|---|\n");
    for m in micros {
        s.push_str(&format!(
            "| {} | {} | {:.3} | {:.3} | {} | {} |\n",
            m.name,
            m.code.len(),
            m.run.mean_ms,
            m.run.min_ms,
            m.run.iters,
            m.out_bytes
        ));
    }
    s
}

fn json_report(cases: &[Case], micros: &[Micro]) -> String {
    let mut s = String::new();
    s.push_str(&format!(
        "{{\"os\": \"{}\", \"arch\": \"{}\", \"corpus\": [",
        env::consts::OS,
        env::consts::ARCH
    ));
    for (i, c) in cases.iter().enumerate() {
        if i > 0 {
            s.push_str(", ");
        }
        s.push_str(&format!(
            "{{\"name\": \"{}\", \"bf_bytes\": {}, \"compile_mean_ms\": {:.3}, \"run_mean_ms\": {:.3}, \"run_min_ms\": {:.3}, \"iters\": {}, \"out_bytes\": {}}}",
            c.name, c.bf_bytes, c.compile.mean_ms, c.run.mean_ms, c.run.min_ms, c.run.iters, c.out_bytes
        ));
    }
    s.push_str("], \"micros\": [");
    for (i, m) in micros.iter().enumerate() {
        if i > 0 {
            s.push_str(", ");
        }
        s.push_str(&format!(
            "{{\"name\": \"{}\", \"bf_bytes\": {}, \"run_mean_ms\": {:.3}, \"run_min_ms\": {:.3}, \"iters\": {}, \"out_bytes\": {}}}",
            m.name,
            m.code.len(),
            m.run.mean_ms,
            m.run.min_ms,
            m.run.iters,
            m.out_bytes
        ));
    }
    s.push_str("]}\n");
    s
}

fn table_report(cases: &[Case], micros: &[Micro]) -> String {
    let mut s = String::new();
    s.push_str(&format!(
        "freud-bench on {}-{} (adaptive: >=3 iters, ~2s target, cap 100)\n\n",
        env::consts::OS,
        env::consts::ARCH
    ));
    s.push_str("corpus:\n");
    s.push_str("program          bf_bytes  compile_ms  run_mean_ms  run_min_ms  iters  out\n");
    for c in cases {
        s.push_str(&format!(
            "{:<16} {:>8}  {:>10.3}  {:>11.3}  {:>10.3}  {:>5}  {}\n",
            c.name, c.bf_bytes, c.compile.mean_ms, c.run.mean_ms, c.run.min_ms, c.run.iters, c.out_bytes
        ));
    }
    s.push_str("\nmicros:\n");
    s.push_str("name             bf_bytes  run_mean_ms  run_min_ms  iters  out\n");
    for m in micros {
        s.push_str(&format!(
            "{:<16} {:>8}  {:>11.3}  {:>10.3}  {:>5}  {}\n",
            m.name,
            m.code.len(),
            m.run.mean_ms,
            m.run.min_ms,
            m.run.iters,
            m.out_bytes
        ));
    }
    s
}

fn splice(path: &Path, fragment: &str) {
    let text = fs::read_to_string(path)
        .unwrap_or_else(|e| panic!("cannot read {}: {}", path.display(), e));
    let start = "<!-- BEGIN RESULTS -->";
    let end = "<!-- END RESULTS -->";
    let si = text.find(start).expect("BEGIN marker missing");
    let ei = text.find(end).expect("END marker missing");
    assert!(si < ei, "markers out of order");
    let mut out = String::new();
    out.push_str(&text[..si + start.len()]);
    out.push('\n');
    out.push_str(fragment);
    out.push_str(&text[ei..]);
    fs::write(path, out).expect("write results");
}

fn main() {
    let mut root = PathBuf::from(".");
    let mut json = false;
    let mut md = false;
    let mut write: Option<PathBuf> = None;
    let mut target_ms: u128 = 2000;
    let mut cap: usize = 100;
    let mut args = env::args().skip(1);
    while let Some(a) = args.next() {
        match a.as_str() {
            "--json" => json = true,
            "--md" => md = true,
            "--write" => {
                write = Some(PathBuf::from(
                    args.next().expect("--write needs a path"),
                ));
            }
            "--quick" => {
                target_ms = 200;
                cap = 10;
            }
            "--target-ms" => {
                target_ms = args
                    .next()
                    .expect("--target-ms needs a value")
                    .parse()
                    .expect("bad --target-ms value");
            }
            "--cap" => {
                cap = args
                    .next()
                    .expect("--cap needs a value")
                    .parse()
                    .expect("bad --cap value");
            }
            s if s.starts_with('-') => {
                eprintln!("freud-bench: unknown flag {s}");
                std::process::exit(2);
            }
            s => root = PathBuf::from(s),
        }
    }
    let cases = bench_corpus(&root, target_ms, cap);
    let micros = bench_micros(target_ms, cap);
    if let Some(path) = write {
        splice(&path, &md_fragment(&cases, &micros));
        eprintln!("wrote results to {}", path.display());
    } else if json {
        print!("{}", json_report(&cases, &micros));
    } else if md {
        print!("{}", md_fragment(&cases, &micros));
    } else {
        print!("{}", table_report(&cases, &micros));
    }
}
