#!/usr/bin/env python3
"""Publish review copies of rehearsal captures; raw originals remain in tmp/."""
from pathlib import Path
import hashlib
import json

ROOT = Path(__file__).resolve().parents[1]
RAW = ROOT / "tmp/rea-live"
OUT = ROOT / "docs/evidence"
OUT.mkdir(parents=True, exist_ok=True)
names = [
    "warmup-overview", "warmup-find", "warmup-loop", "warmup-hash", "warmup-caller",
    "challenge-overview", "challenge-usage", "challenge-usage-xrefs", "challenge-main",
    "challenge-loop", "challenge-hash", "rust-metadata",
]

def redact(value):
    if isinstance(value, str):
        return (value.replace(str(ROOT), "<WORKSHOP>")
                .replace(str(Path.home()), "<LOCAL_HOME>")
                .replace(str(Path.home()).replace("/", "_") + "_", "_LOCAL_HOME_"))
    if isinstance(value, list):
        return [redact(item) for item in value]
    if isinstance(value, dict):
        return {key: redact(item) for key, item in value.items()}
    return value

def save(name, value):
    (OUT / name).write_text(json.dumps(redact(value), indent=2) + "\n")

timings = []
for name in names:
    path = RAW / f"{name}.json"
    data = json.loads(path.read_text())
    normalized = data["normalized_result"]
    if isinstance(normalized, dict) and "pseudocode" in normalized:
        # Dossiers repeat metadata for every stack reference. Retain the useful
        # facets and leave the complete unmodified dossier in tmp/rea-live/.
        normalized = {key: normalized[key] for key in
            ("procedure", "pseudocode", "assembly", "callers", "callees", "incoming_references")
            if key in normalized}
        for field in ("callers", "callees"):
            normalized[field] = [{k: x[k] for k in ("address", "name", "classification") if k in x}
                                 for x in normalized.get(field, [])]
        normalized["incoming_references"] = [x for x in normalized.get("incoming_references", [])
                                               if x.get("kind", {}).get("call")]
    selected = {key: data[key] for key in
        ("evidence_id", "subject", "provider", "analysis_profile", "operation", "parameters",
         "confidence", "authority", "limitations") if key in data}
    selected["normalized_result"] = normalized
    save(f"{name}.json", {
        "review_copy": True,
        "source_capture_sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
        "transform": "Selected dossier facets; local paths and home-derived labels redacted. Not a canonical REA import bundle.",
        "rea_output": selected,
    })
    code = normalized.get("pseudocode") if isinstance(normalized, dict) else normalized
    if isinstance(code, str) and name != "rust-metadata":
        # Preserve line numbers but trim trailing spaces and terminal blank lines.
        clean = "\n".join(line.rstrip() for line in redact(code).splitlines()).rstrip() + "\n"
        (OUT / f"{name}.c").write_text(clean)
    run_path = RAW / f"{name}.run.json"
    if run_path.exists():
        timings.append({"capture": name, **json.loads(run_path.read_text())})

doctor = json.loads((RAW / "doctor-ready.json").read_text())
save("doctor.json", {key: doctor[key] for key in ("healthy", "scope", "scope_checks")})
save("timings.json", timings)
save("behavior.json", json.loads((RAW / "behavior.json").read_text()))
save("binaries.json", json.loads((ROOT / "artifacts/manifest.json").read_text()))
(OUT / "comparison.txt").write_text((RAW / "reconstruction-comparison.txt").read_text())
print(f"Curated {len(names)} native/metadata captures into {OUT}")
