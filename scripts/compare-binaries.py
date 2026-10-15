#!/usr/bin/env python3
"""Compare the public CLI behavior of an original and a reconstruction."""
from pathlib import Path
import random
import subprocess
import sys

if len(sys.argv) != 3:
    raise SystemExit("Usage: python3 scripts/compare-binaries.py ORIGINAL RECONSTRUCTION")
original, rebuilt = (str(Path(path).resolve(strict=True)) for path in sys.argv[1:])
cases = [
    (9, [2, 7, 11, 15]), (6, [3, 3]), (6, [3]), (0, []),
    (99, [1, 2, 3]), (0, [-3, 4, 3, 90]), (5, [1, 1, 4]),
    (5, [1, 2, 3, 4]), (-1, [-2147483648, 2147483647]),
    (-2147483648, [2147483647, 1]),
]
rng = random.Random(2026)
cases += [(rng.randint(-15, 15), [rng.randint(-9, 9) for _ in range(rng.randrange(9))]) for _ in range(100)]
arguments = [[mode, str(target), *map(str, nums)] for mode in ("a", "b") for target, nums in cases]
arguments += [[], ["c", "9"], ["a"], ["b", "9", "x"], ["a", "2147483648"]]

def run(binary, args):
    result = subprocess.run([binary, *args], capture_output=True, timeout=5)
    # Error wording is not contractual. Its presence and channel are.
    return result.returncode, result.stdout, bool(result.stderr)

for args in arguments:
    left, right = run(original, args), run(rebuilt, args)
    if left != right:
        raise SystemExit(f"Mismatch for {args!r}\noriginal={left!r}\nrebuilt={right!r}")
print(f"PASS: {len(arguments)} CLI cases agree (exit code, stdout, stderr presence).")
print("This is finite behavioral evidence, not proof of identical source or all inputs.")
