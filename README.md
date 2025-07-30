# BCPL Compiler

This repository contains a modernized distribution of the classic **BCPL** compiler with multi-architecture support and a fully portable C23 runtime.  The project builds on the original work of Martin Richards and includes additional tooling and documentation for contemporary development environments.

## Features

- **Multi-Architecture**: build for `x86_64`, `arm64`, and experimental `x86_16` targets.
- **Cross‑Platform**: Linux, macOS, Windows, and FreeBSD.
- **C23 Runtime**: memory-safe and thread-friendly implementation.
- **Optimization Scripts**: advanced Clang/LLVM optimizations including ThinLTO and PGO.
- **Legacy Compatibility**: supports historic BCPL sources out of the box.
- **Performance Optimized**: modern compile-time and runtime performance enhancements.
- **Standards Compliant**: adheres to the official BCPL language specification.

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

### Example Invocations

```
./build.sh                  # Release build for native architecture
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

The original Apple Silicon build experiments have been consolidated into the unified `build.sh` workflow.  Legacy helper scripts remain in `archive/` for reference.

## Development Containers

Preconfigured dev containers are provided for Ubuntu 24.04 LTS and Debian Sid. A single `.devcontainer` directory holds templates for both. Run `./select-devcontainer.sh <ubuntu|debian>` to switch the symlinks before reopening the folder in VS Code.

## Project Structure

```
bcpl-compiler/
├── CMakeLists.txt        # Build configuration
├── build.sh             # Unified build script
├── src/                 # Source code
│   ├── compiler/        # Compiler components
│   ├── runtime/         # C23 runtime system
│   ├── arch/            # Architecture-specific code
│   └── include/         # Header files
├── tests/               # Test suite
├── docs/                # Documentation
└── archive/             # Archived historical files
```

## Documentation

Additional guides are available in the `docs/` directory:

- `BUILD.md` – detailed build instructions
- `BUILD_OPTIMIZATION.md` – comprehensive optimization guide
- `OPTIMIZATION_QUICK_REFERENCE.md` – quick reference for build flags
- `MODERNIZATION.md` – overview of the C23 modernization effort

## Contributing

1. Fork the repository and create a feature branch.
2. Make your changes and test thoroughly.
3. Commit with clear messages and open a Pull Request.

### Development Guidelines

- Follow C23 standards.
- Maintain compatibility with the original BCPL sources.
- Add tests for new features and update documentation.
- Use consistent formatting via `clang-format`.
## Roadmap

- [x] C23 runtime modernization
- [x] Multi-architecture support
- [x] Cross-platform builds
- [ ] IDE integration (LSP server)
- [ ] WebAssembly target
- [ ] Enhanced debugging support

## Bug Reports

Please open issues on GitHub with your platform, architecture, compiler version, and a minimal reproduction case.


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

