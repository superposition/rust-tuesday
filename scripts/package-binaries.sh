#!/usr/bin/env bash
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
destination="${1:-artifacts}"
if [[ -e "$destination" ]]; then
  echo "Refusing to replace an existing evidence package: $destination" >&2
  exit 1
fi
# Explicit target/output paths avoid ambiguity from a user's Cargo config.
host="$(rustc -vV | sed -n 's/^host: //p')"
cargo build --locked --target "$host" --target-dir "$root/target/workshop"
cargo build --locked --release --target "$host" --target-dir "$root/target/workshop"
mkdir -p "$destination/warmup" "$destination/challenge"
cp "$root/target/workshop/$host/debug/pair-finder" "$destination/warmup/pair-finder"
cp "$root/target/workshop/$host/release/pair-finder" "$destination/challenge/pair-finder"
cp docs/BINARY-BRIEF.md "$destination/challenge/BRIEF.md"
python3 - "$destination" "$host" <<'PY'
from pathlib import Path
import hashlib, json, subprocess, sys
root = Path(sys.argv[1])
manifest = {
    "host": sys.argv[2],
    "rustc": subprocess.check_output(["rustc", "-vV"], text=True),
    "cargo": subprocess.check_output(["cargo", "-V"], text=True).strip(),
    "profiles": {"warmup": "dev; opt=0; debug=2; strip=none", "challenge": "release; opt=3; debug=0; strip=symbols"},
    "binaries": {}
}
for lane in ("warmup", "challenge"):
    path = root / lane / "pair-finder"
    manifest["binaries"][lane] = {"sha256": hashlib.sha256(path.read_bytes()).hexdigest(), "bytes": path.stat().st_size}
(root / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")
print(f"Packaged native binaries for {sys.argv[2]} in {root}")
PY
