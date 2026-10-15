# Rust Tuesday: build it, strip it, explain it

A two-hour workshop: solve **Two Sum**, learn functions, borrowing, traits and
`impl`, then investigate the compiled program with [REA](https://github.com/morluto/rea).

**Start here:** [Workshop PDF](output/pdf/rust-tuesday-workshop.pdf) ·
[Editable workshop plan](docs/WORKSHOP.md) · [Preparation plan](docs/PREPARATION.md)

The repository includes a complete facilitator reference, a learner scaffold,
tests, binary packaging, an investigation brief, and a behavioral comparison tool.
The native REA session still needs a rehearsal with a configured analysis engine;
see [verification](docs/VERIFICATION.md). This is an independent community workshop.

## Run the reference

Requires Rust/Cargo (1.74+; verified with 1.90.0). The Rust program has no third-party crates.

```sh
git clone https://github.com/superposition/rust-tuesday.git
cd rust-tuesday
cargo test --locked
cargo run -- a 9 2 7 11 15
cargo run -- b 9 2 7 11 15
```

Both print `0 1`. Mode `a` uses nested loops; mode `b` uses a hash map.
No match prints `none`. Invalid arguments print a diagnostic to stderr and exit 2.
Use `Ctrl-C` to stop a running command.

## Teach from the starter

```sh
bash scripts/new-learner.sh ../rust-tuesday-learner
cd ../rust-tuesday-learner
cargo check --locked
cargo test --locked
```

The starter compiles; tests intentionally fail at `todo!()` until learners implement
`src/lib.rs`. The CLI is provided so the session stays focused on Rust and algorithms.
Keep this reference repository closed during the exercise; reveal `src/lib.rs` at the debrief.
The setup script refuses to overwrite an existing destination.

## Make the binaries

From the completed reference repository (macOS/Linux):

```sh
bash scripts/package-binaries.sh
./artifacts/challenge/pair-finder b 6 3 3
```

`artifacts/warmup` contains a named debug binary. `artifacts/challenge` contains a
stripped, optimized binary plus a brief. `artifacts/manifest.json` records the host,
compiler, sizes, profiles and SHA-256 hashes. Build separately for each participant
OS/CPU. Packaging refuses to replace an existing directory; pass a fresh path for a new run.

REA native setup and investigation commands are in [the workshop guide](docs/WORKSHOP.md).
Node and a native analysis provider are prerequisites; Rust metadata inspection alone
does not decompile this program.

## Rebuild the PDF

```sh
python3 -m venv .venv
.venv/bin/pip install -r requirements-pdf.txt
.venv/bin/python scripts/build-pdf.py
```

The PDF is built from `docs/WORKSHOP.md`. Change that source and regenerate.
Its explicit page markers keep the printed exercises together. Render for review with:

```sh
mkdir -p tmp/pdfs
pdftoppm -r 110 -png output/pdf/rust-tuesday-workshop.pdf tmp/pdfs/page
```

## Contents

| Path | Purpose |
| --- | --- |
| `docs/PREPARATION.md` | The plan for finishing and rehearsing the event |
| `docs/WORKSHOP.md` | Timed guide, exercises, commands and worksheet |
| `docs/BINARY-BRIEF.md` | Handout for a fresh binary-only investigation |
| `src/` | Facilitator answer and provided CLI |
| `exercises/lib.rs` | Learner TODOs |
| `tests/` | Algorithm and CLI contract checks |
| `scripts/compare-binaries.py` | Compare original and reconstructed behavior |
| `docs/VERIFICATION.md` | What was actually checked and what remains |

MIT for original workshop materials. Problem links and REA retain their own attribution
and terms; this repo does not vendor their content or code.
