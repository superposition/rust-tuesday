# Behavioral reconstruction

This is a deliberately simple implementation of the observed CLI contract.
It uses a loop for both modes. It has no trait or hash table and does not claim
the original program's performance or source design.

The author had already seen the reference source. This is an evidence-guided
rehearsal and a test of the comparison workflow, not an independent blind solve.

From the repository root, after packaging the original binaries:

```sh
rustc --edition 2021 -O reconstruction/main.rs -o artifacts/reconstructed-pair-finder
python3 scripts/compare-binaries.py \
  artifacts/challenge/pair-finder artifacts/reconstructed-pair-finder
```

Keep this directory closed for the learner's binary-only exercise. See the
recorded behavior probes and native evidence in `docs/evidence/` after the reveal.
