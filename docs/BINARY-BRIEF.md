# Binary lab: pair-finder

Investigate only the supplied executable and this brief. Record observations before
opening any reference source. Use a fresh agent conversation, and place the challenge
outside the source checkout. This is a teaching convention, not enforced isolation;
the public repository remains accessible. Ask the agent not to browse for the answer.

## Known interface

```text
pair-finder <a|b> <target:i32> [numbers:i32 ...]
```

Inputs are signed 32-bit integers. Valid runs print either two zero-based indices
`i j` with a newline, or `none` with a newline, and exit 0. Invalid arguments produce
a diagnostic on stderr and exit 2. The exact diagnostic wording is not contractual.

## Investigation

1. Record OS/CPU, file format and SHA-256. Try both modes on the same inputs.
2. Probe a match, absence, duplicate values, negative values, one item, empty input,
   multiple possible matches, and integers near the 32-bit boundaries.
3. Use REA's native provider to locate relevant logic. Save an address or exact
   symbol with each static observation; never invent addresses.
4. Infer the input/output contract, tie-break rule, and likely algorithmic difference.
   Input/output agreement alone cannot distinguish two equivalent algorithms.
5. Write a small compatible CLI in a separate project. Compare it against the
   original before looking at the reference. Reproducing behavior is the goal;
   original source syntax and names may be unrecoverable.

## Agent prompt

> Investigate the supplied pair-finder executable using REA. Do not read, search
> for, or fetch the workshop source or solutions. First record the binary hash
> and platform. Probe its public interface, then use the configured native
> provider to identify relevant functions. For each claim, separate observation,
> inference and uncertainty and cite a command/output or address. Reconstruct
> a compatible CLI and test it against the original. Do not claim to recover
> exact Rust traits, variable names, or source from behavioral agreement.

## Evidence record

- Artifact/hash and tool versions:
- Command or address:
- Observed output/instructions:
- Interpretation:
- Competing explanation or uncertainty:
- Test that could disprove the interpretation:

Hand in three evidence-backed claims, one unresolved question, and comparison results.
