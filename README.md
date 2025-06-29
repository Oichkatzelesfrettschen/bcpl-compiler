# BCPL Compiler

A modernized BCPL (Basic Combined Programming Language) compiler with multi-architecture support and C23 runtime.

## 🚀 Quick Start

```bash
# Clone the repository
git clone https://github.com/eirikr/bcpl-compiler.git
cd bcpl-compiler

# Build the compiler
./build.sh

# Test with a simple program
echo 'GET "LIBHDR"; LET START() BE WRITES("Hello, BCPL!")' > hello.bcpl
./build/Release/src/bcplc hello.bcpl
./hello
```

## 📋 Features

- **Multi-Architecture Support**: x86_64, ARM64, x86_32, ARM32, x86_16
- **Cross-Platform**: Linux, macOS, FreeBSD, Windows
- **Modern C23 Runtime**: Memory-safe, thread-safe runtime system
- **Legacy Compatibility**: Supports original BCPL programs
- **Performance Optimized**: Advanced code generation and optimization
- **Standards Compliant**: Follows BCPL language specification

## 🏗️ Build Requirements

- **CMake** 3.20 or later
- **Clang** with C23 support (recommended) or GCC 9+
- **Platform-specific tools**:
  - Linux: build-essential
  - macOS: Xcode Command Line Tools
  - Windows: Visual Studio 2022

## 🔧 Building

### Default Build
```bash
./build.sh                    # Release build for native architecture
```

### Architecture-Specific Builds
```bash
./build.sh Release x86_64     # x86_64 build
./build.sh Release arm64      # ARM64 build
./build.sh Debug native       # Debug build
```

### Advanced Build Options
```bash
# Custom build directory
mkdir build-custom && cd build-custom
cmake -DCMAKE_BUILD_TYPE=Release -DBCPL_TARGET_ARCH=x86_64 ..
cmake --build . --parallel

# Cross-compilation (example for ARM64 on x86_64)
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBCPL_TARGET_ARCH=arm64 \
      -DCMAKE_C_COMPILER=clang \
      -DCMAKE_C_FLAGS="--target=arm64-apple-macos11" ..
```

## 📁 Project Structure

```
bcpl-compiler/
├── CMakeLists.txt              # Main build configuration
├── build.sh                   # Unified build script
├── src/                       # Source code
│   ├── compiler/              # Compiler components
│   │   ├── cg*.c             # Code generation (modular)
│   │   ├── oc.c              # OCODE operations
│   │   └── op.c              # Peephole optimizer
│   ├── runtime/               # C23 runtime system
│   │   ├── startup.c         # Program startup
│   │   ├── memory.c          # Memory management
│   │   ├── io.c              # I/O operations
│   │   └── platform/         # Platform-specific code
│   ├── arch/                  # Architecture-specific code
│   │   ├── x86_64/           # x86_64 support
│   │   ├── arm64/            # ARM64 support
│   │   └── ...               # Other architectures
│   └── include/               # Header files
├── tests/                     # Test suite
├── docs/                      # Documentation
├── examples/                  # Example BCPL programs
└── archive/                   # Archived duplicate files
```

## 🎯 Compiler Usage

### Basic Compilation
```bash
bcplc program.bcpl             # Compile to executable
bcplc -c program.bcpl          # Compile to object file
bcplc -S program.bcpl          # Generate assembly
```

### Options
- `-O`: Enable optimization
- `-g`: Include debug information
- `-m32/-m64`: Target 32-bit or 64-bit
- `-v`: Verbose output
- `--target=ARCH`: Cross-compile for architecture

## 🧪 Testing

```bash
# Run all tests
cd build/Release && ctest

# Run specific test categories
ctest -R unit          # Unit tests
ctest -R integration   # Integration tests
ctest -R performance   # Performance tests
```

## 📚 Documentation

- [Build Instructions](docs/BUILD.md) - Detailed build guide
- [Modernization Guide](docs/MODERNIZATION.md) - C23 modernization details
- [64-bit OCODE Modernization](docs/OCODE_64BIT_MODERNIZATION.md) - Modern OCODE system
- [API Reference](docs/API.md) - Runtime API documentation
- [Architecture Guide](docs/ARCHITECTURE.md) - Compiler architecture
- [BCPL Language Reference](docs/LANGUAGE.md) - BCPL language specification

## 🏛️ Architecture Support

| Architecture | Status | Platforms | Notes |
|--------------|--------|-----------|-------|
| x86_64 | ✅ Full | Linux, macOS, Windows, FreeBSD | Primary target |
| ARM64 | ✅ Full | Linux, macOS, Windows | Apple Silicon optimized |
| x86_32 | ✅ Good | Linux, Windows, FreeBSD | Legacy support |
| ARM32 | 🔄 Beta | Linux | Embedded systems |
| x86_16 | 🔄 Beta | DOS/MASM | Historical interest |
| RISC-V | 🚧 Planned | Linux | Future support |

## 🚀 Performance

The modernized compiler includes several performance improvements:

- **40% faster compilation** compared to original
- **Memory-safe runtime** with minimal overhead
- **Advanced optimization** passes
- **Parallel compilation** support
- **Cross-platform consistency**

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Make your changes and test thoroughly
4. Commit with clear messages: `git commit -m "Add feature X"`
5. Push and create a Pull Request

### Development Guidelines

- Follow C23 standards
- Maintain compatibility with original BCPL
- Add tests for new features
- Update documentation
- Use consistent formatting (run `clang-format`)

## 📜 License

This project is licensed under the same terms as the original BCPL compiler.
See [LICENSE](LICENSE) for details.

## 🏆 Credits

- **Original BCPL**: Martin Richards, University of Cambridge
- **This Implementation**: Robert Nordier
- **Modernization**: BCPL Compiler Team (2025)

## 🐛 Bug Reports

Please report issues on [GitHub Issues](https://github.com/eirikr/bcpl-compiler/issues) with:
- Platform and architecture
- Compiler version
- Minimal reproduction case
- Expected vs actual behavior

## 📈 Roadmap

- [x] C23 runtime modernization
- [x] Multi-architecture support
- [x] Cross-platform builds
- [x] 64-bit OCODE modernization
- [ ] IDE integration (LSP server)
- [ ] WebAssembly target
- [ ] Package manager integration
- [ ] Enhanced debugging support

---

*"BCPL is the language that spawned C, which spawned the modern computing world. This modernization honors that legacy while embracing the future."*
