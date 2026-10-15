# Verification record

Checked 15 October 2026 on macOS arm64 with Rust/Cargo 1.90.0.
These are authoring checks, not a completed event rehearsal.

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

## Not yet executed

- REA native analysis, decompilation, references, or a binary-only reconstruction.
- Live end-to-end teaching rehearsal or checks on Linux/Windows/Intel macOS.
- Rust 1.74 specifically; it is the declared minimum, while 1.90.0 was exercised.

The checked machine had Node 22.14.0, below REA 6.5.0's supported baseline.
`rea` was not on PATH; no Ghidra/Hopper installation was found in the checked
PATH and Applications locations. No global tool or agent configuration was changed.

REA commands were checked against its official documentation. npm reported 6.5.0
as the published version, with Node engine constraint
`^22.19.0 || ^24.11.0 || >=26.0.0`. The documentation snapshot is linked in the guide.

Before the event, follow `docs/PREPARATION.md`: prepare the provider, retrieve a
relevant function from these binaries, save actual evidence with hashes, and time
the investigation. A planned command is not a successful analysis result.
