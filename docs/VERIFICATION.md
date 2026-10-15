# Verification record

Checked 15 October 2026 on macOS arm64 with Rust/Cargo 1.90.0.
Includes authoring checks and the completed native technical rehearsal.
This is not a completed live teaching rehearsal.

## Executed successfully

- `cargo fmt --check` and `cargo test --locked`: the reference passes all 3
  integration tests. They cover fixed examples/boundaries, 12,285 small-domain
  input/target combinations, and command-line output/error behavior.
- `bash scripts/new-learner.sh /tmp/rust-tuesday-learner-review`: created a separate
  learner project. `cargo check --locked` passed there; its contract tests failed
  at the expected `todo!("call find")`. This is the intended starting state.
- `bash scripts/package-binaries.sh`: produced both native Mach-O arm64 executables
  and a manifest with host, compiler, profile, size and SHA-256.
- `python3 scripts/compare-binaries.py artifacts/warmup/pair-finder artifacts/challenge/pair-finder`:
  all 225 cases agreed. This compares two builds of the reference, **not** a fresh
  reverse-engineered reconstruction. That remains a participant/rehearsal task.
- `file` identified both as Mach-O 64-bit arm64. `nm` produced 1,180 lines for
  warmup and 72 for challenge; the warmup contained the two `find` implementation
  symbols and two `solve` instantiations. Symbol counts alone do not prove behavior.
- PDF generated with ReportLab, extracted with pypdf, rendered with Poppler, and
  all 12 pages visually reviewed for layout, code blocks, page numbers and clipping.

## Artifact record

| Build | Bytes | SHA-256 |
| --- | ---: | --- |
| Warmup | 605,936 | `d7ede7290fc4c35a69aab4f3945cae43e8c51a20e0e1d6dc4e33ca9bdb2e1297` |
| Challenge | 354,896 | `c13981d9bec980d21e1be9b8706eaf0ee5476b2697e23575a45c79f44f20adca` |

Build outputs are intentionally untracked and can be regenerated. Debug paths,
toolchains and host details can change the resulting bytes; these hashes identify
this run, not a promise of reproducible bytes on another machine.

## Native rehearsal: executed

- Reused installed Node 24.12.0 and JDK 21.0.9 through local symlinks. Installed
  REA 6.5.0 and Ghidra 12.1.4 under ignored `.tools/`. No default shell runtime or
  agent MCP registration was changed.
- Downloaded Ghidra from the official GitHub release and verified SHA-256
  `ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db`.
- The initial scoped doctor correctly failed for the missing macOS ARM64 native
  decompiler. Built it with `make -j8 ghidra_opt ARCH_TYPE='-arch arm64' OSDIR=mac_arm_64`
  and Apple clang 21; the repeated scoped doctor passed all required checks.
- Native imports, procedure/string searches, function dossiers, decompilations
  and xrefs succeeded. Relevant warmup functions: loop `0x100005bd4`, hash
  `0x100005d84`, direct caller `0x1000028b0`. Challenge usage-string references
  led to CLI function `0x100000e20` and loop/hash functions `0x1000015a8`/`0x10000160c`.
- Warmup import took 18.434 seconds and challenge import 14.524 seconds. Individual
  native commands took 14.5-18.5 seconds including startup, query and cleanup.
- Captured 23 runtime probes. Compiled the alternate `reconstruction/main.rs`
  implementation and compared it with the stripped original: **225/225 cases agreed**.
- Created and visually inspected three annotated pseudocode images. Updated and
  rendered the 13-page guide with actual results and remaining limitations.

[Evidence walkthrough](evidence/README.md) includes review copies of provider output,
binary hashes, pseudocode, instructions, command receipts and comparison results.
The author had already seen the reference source: this is an evidence-guided
rehearsal, not an independent blind reconstruction. Both modes in the replacement
use loops, so it does not preserve the hash implementation's performance.

The stripped challenge retains algorithm name fragments inside its Mach-O export
trie. This was verified from file offsets and Ghidra's recovered names. It is not
an anonymous challenge. Ghidra also reported Rust calling-convention and CLI type
propagation warnings; decompiler types are not treated as original Rust types.

## Still requires a human or another environment

- A timed teaching rehearsal with a learner, independent blind solve, date and venue.
- Checks on Linux, native Windows or Intel macOS.
- Rust 1.74 specifically; it is the declared minimum, while 1.90.0 was exercised.
- MCP registration if the event uses an agent integration instead of the verified CLI.

Before the event, repeat the native route on the event machine and rehearse the
human teaching sequence in `docs/PREPARATION.md`.
