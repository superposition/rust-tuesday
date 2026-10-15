#!/usr/bin/env bash
# Project-local REA launcher. See docs/LOCAL-TOOLS.md for setup.
set -euo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
node_bin="${REA_NODE_BIN:-$root/.tools/node}"
if [[ ! -x "$node_bin" ]]; then
  node_bin="$(command -v node)"
fi
export JAVA_HOME="${JAVA_HOME:-$root/.tools/jdk}"
export GHIDRA_INSTALL_DIR="${GHIDRA_INSTALL_DIR:-$root/.tools/ghidra}"
export PATH="$(dirname "$node_bin"):$JAVA_HOME/bin:$PATH"
entry="$root/.tools/rea/node_modules/rea-agents/scripts/rea.mjs"
if [[ ! -f "$entry" ]]; then
  echo "Local REA is missing. Follow docs/LOCAL-TOOLS.md." >&2
  exit 1
fi
exec "$node_bin" "$entry" "$@"
