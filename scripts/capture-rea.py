#!/usr/bin/env python3
"""Capture an actual REA invocation, preserving output and elapsed time."""
from datetime import datetime, timezone
from pathlib import Path
import json
import re
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parents[1]
if len(sys.argv) < 3 or not re.fullmatch(r"[a-z0-9-]+", sys.argv[1]):
    raise SystemExit("Usage: python3 scripts/capture-rea.py LABEL REA-ARGUMENTS...")
label, args = sys.argv[1], sys.argv[2:]
folder = ROOT / "tmp/rea-live"
folder.mkdir(parents=True, exist_ok=True)
files = [folder / f"{label}.{suffix}" for suffix in ("json", "stderr.txt", "run.json")]
if any(path.exists() for path in files):
    raise SystemExit(f"Capture already exists: {label}; choose another label.")
started = datetime.now(timezone.utc).isoformat()
begin = time.monotonic()
command = ["bash", str(ROOT / "scripts/rea.sh"), *args]
with files[0].open("wb") as stdout, files[1].open("wb") as stderr:
    result = subprocess.run(command, stdout=stdout, stderr=stderr, cwd=ROOT)
record = {
    "started_at": started,
    "elapsed_seconds": round(time.monotonic() - begin, 3),
    "exit_code": result.returncode,
    "command": command,
}
files[2].write_text(json.dumps(record, indent=2) + "\n")
print(json.dumps(record, indent=2))
print(f"Saved {files[0]}")
raise SystemExit(result.returncode)
