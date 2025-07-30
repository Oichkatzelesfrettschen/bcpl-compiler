# BCPL Compiler

This repository contains a modernized distribution of the classic **BCPL** compiler with multi-architecture support and a fully portable C23 runtime.  The project builds on the original work of Martin Richards and includes additional tooling and documentation for contemporary development environments.

## Features

- **Multi-Architecture**: build for `x86_64`, `arm64`, and experimental `x86_16` targets.
- **Cross‑Platform**: Linux, macOS, Windows, and FreeBSD.
- **C23 Runtime**: memory-safe and thread-friendly implementation.
- **Optimization Scripts**: advanced Clang/LLVM optimizations including ThinLTO and PGO.
- **Legacy Compatibility**: supports historic BCPL sources out of the box.

## Quick Start

```bash
# Clone
git clone https://github.com/eirikr/bcpl-compiler.git
cd bcpl-compiler

# Build the compiler (native release)
./build.sh

# Test with a simple program
echo 'GET "LIBHDR"; LET START() BE WRITES("Hello, BCPL!")' > hello.bcpl
./build/Release/src/bcplc hello.bcpl
./hello
```

## Build Requirements

Ensure the following tools are installed:

- `clang` and `cmake`
- `make` or `ninja`
- `binutils`, `gcc-multilib`, and `qemu` for cross builds

Running `./setup.sh` installs all dependencies along with an IA‑16 toolchain.

For convenience, a `build.sh` helper script wraps the standard CMake
configuration and build commands. It places artifacts under
`build/<BuildType>` where *BuildType* defaults to `Release`.

## Building

### Native Build

```
./scripts/makeall.sh        # build
./scripts/makeall.sh install
```

Alternatively with CMake:

```
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build build
cmake --install build
```

### Architecture Specific

```
./build.sh Release x86_64   # 64‑bit
./build.sh Release arm64    # ARM64
./build.sh Debug native     # Debug build
```

Set `BITS=32` (or `-DBITS=32`) for a 32‑bit runtime.  `BITS=16` enables the experimental IA‑16 backend.

After installation run:

```
bcplc tools/cmpltest.bcpl
```

to verify the environment; 119 tests should pass without failure.

## Multi‑Architecture Builds

The original Apple Silicon build experiments have been consolidated into a single workflow.  Example scripts remain under `scripts/` for reference:

- `build_x86_64.sh` and `build_x86_64_safe.sh` – Rosetta based x86_64 builds
- `verify_builds.sh` – non‑interactive validation of generated binaries

These scripts demonstrate cross‑compilation setups and size/architecture checks for both ARM64 and x86_64 outputs.

## Development Containers

Preconfigured dev containers are provided for Ubuntu 24.04 LTS and Debian Sid.  Use `./select-devcontainer.sh <ubuntu|debian>` and open the repository in VS Code to work inside a fully provisioned environment.

## Documentation

Additional guides are available in the `docs/` directory:

- `BUILD.md` – detailed build instructions
- `BUILD_OPTIMIZATION.md` – comprehensive optimization guide
- `OPTIMIZATION_QUICK_REFERENCE.md` – quick reference for build flags
- `MODERNIZATION.md` – overview of the C23 modernization effort

## Repository Maintenance

Duplicate configuration files occasionally surface during merges.  Run
`cleanup_duplicates.py` from the repository root to automatically remove
identical copies and archive differing `2.*` variants under
`archive/duplicates/`.  Pass an explicit path if the repository is located
elsewhere:

```bash
python3 cleanup_duplicates.py /path/to/bcpl-compiler
```

## License

This project retains the license terms of the original BCPL distribution.  See [LICENSE](LICENSE) for details.

## Credits

- **Original BCPL** – Martin Richards, University of Cambridge
- **Port and Modernization** – Robert Nordier and contributors

