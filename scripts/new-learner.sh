#!/usr/bin/env bash
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
destination="${1:?Usage: bash scripts/new-learner.sh /new/learner/path}"
if [[ -e "$destination" ]]; then
  echo "Refusing to overwrite an existing path: $destination" >&2
  exit 1
fi
mkdir -p "$destination/src" "$destination/tests"
cp "$root/Cargo.toml" "$root/Cargo.lock" "$destination/"
cp "$root/exercises/lib.rs" "$destination/src/lib.rs"
cp "$root/src/main.rs" "$destination/src/"
cp "$root/tests/contract.rs" "$root/tests/cli.rs" "$destination/tests/"
printf 'Learner project created at %s\nTests intentionally fail until the TODOs are complete.\n' "$destination"
