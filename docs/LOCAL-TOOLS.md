# Local REA toolchain

The repository launcher uses untracked dependencies under `.tools/`. It does not
register an MCP server or change the shell's default Node or Java version.

## Reuse this prepared checkout

```sh
bash scripts/rea.sh --version
bash scripts/rea.sh doctor --provider ghidra --json
bash scripts/rea.sh analyze "$PWD/artifacts/warmup/pair-finder" --provider ghidra --json
```

`scripts/rea.sh` is equivalent to the guide's `rea` command. It uses `.tools/node`,
`.tools/jdk`, `.tools/ghidra` and the local npm package. Override `REA_NODE_BIN`,
`JAVA_HOME` or `GHIDRA_INSTALL_DIR` to use another compatible installation.

## Prepare a new macOS ARM64 checkout

Requires a compatible Node runtime, JDK 21, Xcode Command Line Tools, `make`,
`bison`, Python 3, `curl`, `unzip` and `shasum`. Node 24.12.0 and Homebrew JDK
21.0.9 were selected for this rehearsal. Use your actual installation paths.
The tools directory needs roughly 2 GB including the downloaded archive and build.

```sh
mkdir -p .tools/downloads
# Point these at existing installations; ln refuses an existing link.
ln -s /absolute/path/to/node .tools/node
ln -s /absolute/path/to/jdk-home .tools/jdk
```

Put the compatible Node on PATH when installing the local package:

```sh
PATH="$PWD/.tools:$PATH" npm install --prefix .tools/rea \
  --no-audit --no-fund rea-agents@6.5.0
```

Download the exact [official Ghidra 12.1.4 release](https://github.com/NationalSecurityAgency/ghidra/releases/tag/Ghidra_12.1.4_build):

```sh
curl -fL --retry 2 \
  https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_12.1.4_build/ghidra_12.1.4_PUBLIC_20260921.zip \
  -o .tools/downloads/ghidra.zip
printf '%s  %s\n' \
  ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db \
  .tools/downloads/ghidra.zip | shasum -a 256 -c -
unzip -q .tools/downloads/ghidra.zip -d .tools
ln -s ghidra_12.1.4_PUBLIC .tools/ghidra
```

Only extract after the checksum passes. On Apple Silicon, if the archive lacks
the ARM64 decompiler, build it using REA's documented make overrides:

```sh
root="$PWD"
cd .tools/ghidra/Ghidra/Features/Decompiler/src/decompile/cpp
make -j8 ghidra_opt ARCH_TYPE="-arch arm64" OSDIR=mac_arm_64
cd "$root"
decompiler_dir="$PWD/.tools/ghidra/Ghidra/Features/Decompiler/os/mac_arm_64"
mkdir -p "$decompiler_dir"
test ! -e "$decompiler_dir/decompile" && \
  install -m 755 .tools/ghidra/Ghidra/Features/Decompiler/src/decompile/cpp/ghidra_opt \
    "$decompiler_dir/decompile"
bash scripts/rea.sh doctor --provider ghidra --json
```

Use a different platform's matching native component on Linux or Intel macOS;
do not use the ARM64 make flags there. See the pinned
[REA installation guide](https://github.com/morluto/rea/blob/78cf6100f33ad2412c0a3d60b83f8a44a43fbbb5/docs/installation.md#ghidra).

## Capture a command

```sh
python3 scripts/capture-rea.py warmup-overview \
  analyze "$PWD/artifacts/warmup/pair-finder" --provider ghidra --json
```

The helper records command, duration, exit status, stdout and stderr under
`tmp/rea-live/`. It refuses to overwrite an existing capture. Use a new label for
a rerun. These raw files stay local; curated public evidence identifies any
path redaction and retains the binary hash and actual provider output.
