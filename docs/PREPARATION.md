# A plan for producing and running Rust Tuesday

## Fixed decisions

- Format: 120 minutes, pairs, beginner-friendly programmers.
- Output: a small native command-line program, a written Rust explanation, and a
  binary investigation supported by observations.
- Core problem: Two Sum. One contract, nested loops and hash lookup, one trait.
- Materials: public GitHub repository and printable PDF with editable source.
- Primary native analysis route: REA with Ghidra; Hopper is an alternative if already available.
- Baseline shells: macOS/Linux. Windows participants use a rehearsed Linux environment
  such as WSL, building Linux binaries inside it; native Windows is outside this script set.
- No event date or venue has been booked.

## Phase 1: shape the session (complete in this draft)

Write the learning outcomes first. Each participant should explain a free function,
an inherent method, an associated function, a trait requirement, a trait implementation,
a borrowed slice, and `Option`. The binary section must distinguish observations from
guesses and verify a reconstructed behavior with tests.

Choose one problem with a visible algorithm contrast. Two Sum wins over Contains Duplicate
because indices, duplicate values, and early return make useful tests. Valid Parentheses
is a follow-up because it introduces a stack and pattern matching but expands the lesson.
Write an original problem brief rather than reproducing a platform's statement.

## Phase 2: author materials (included)

- A facilitator reference and compiling learner scaffold with intentional TODOs.
- Explicit input, output, tie-break, arithmetic and error contracts.
- A 120-minute run of show with checkpoints and cuts if time slips.
- Debug and stripped-release packaging with artifact fingerprints.
- A binary-only brief, evidence worksheet, and original/reconstruction comparison.
- A printable guide and reproducible PDF builder.

## Phase 3: rehearse the native toolchain (required before the event)

Owner: facilitator. Reserve 45-60 minutes, at least one day before the event.

1. Choose the actual host/CPU and install a REA-compatible Node runtime plus the
   chosen native provider. Record exact REA, Ghidra/Hopper, JDK and OS versions.
2. Run the scoped provider doctor, package both binaries, and inspect the warmup.
3. Find one relevant function, save its pseudocode or instructions, and follow one
   reference. Repeat enough of the stripped challenge to identify a teachable path.
4. Save actual provider output, the matching binary hashes, and 2-3 annotated images
   for projection. Do not label a mockup or planned output as captured evidence.
5. Time the import and first query. If the loop cannot be explained in a five-minute
   segment, simplify the demo or prioritize the warmup binary.
6. Run the session with one learner. Time all steps, note confusing terms, and revise
   the PDF. Freeze versions and material commit after that rehearsal.

Done means a person can follow the exact commands and reach a relevant function;
a successful installation or provider listing alone does not pass this gate.

## Phase 4: deliver and revise

Owner: facilitator. Send the setup checklist one day ahead. Before attendees arrive,
prepare one learner directory per pair and a working projector machine. Keep the
reference source separate from the investigation directory. During the session use
the guide's checkpoints. Collect the evidence worksheets and exit tickets; record
what actually fit in 120 minutes before scheduling a second session.

## Contingencies

- Coding behind at minute 45: explain the completed second implementation and let
  pairs write the trait delegation; preserve the binary segment.
- Native provider unavailable: use the rehearsed instructor machine or saved real
  evidence. Neither is bundled yet. If those are also unavailable, demonstrate the
  local `file`/`strings`/`nm`/`objdump` route and explicitly defer the REA exercise.
- Import slow: switch to already captured evidence for the exact binary hash.
- Assembly unfamiliar: start with an input/output trace, then one comparison and
  branch in pseudocode. Do not try to explain the entire Rust standard library.
- Time left: contrast `S: PairSearch` with `&dyn PairSearch`, or implement another problem.

## Acceptance criteria

Reference tests pass; learner scaffold compiles and fails for the expected TODOs;
both binaries satisfy the CLI contract; reconstructed CLI agrees on supplied and
generated cases; every binary conclusion cites an observation; rendered PDF has no
clipping; repo clone commands work. The REA-specific gate remains separate until
a real provider session has been captured.
