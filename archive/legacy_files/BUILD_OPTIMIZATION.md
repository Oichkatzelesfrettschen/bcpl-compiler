# BCPL Compiler Build Documentation

## Project Status

**COMPLETED**: Modernized BCPL compiler with C23 runtime and LLVM backend
**BUILD STATUS**: Success - All core components functional

## Built Components

### Core Compiler Tools
- **Code Generator (`cg`)**: 52KB - Converts OCODE to assembly
- **Optimizer (`op`)**: 52KB - Assembly-level optimization
- **LLVM Backend (`llcg`)**: 41MB - Modern LLVM IR generation
- **Runtime Library**: 38KB - Pure C23 implementation

### Build Variants
- **Debug Build**: `build_c23/src/` - Development binaries
- **Optimized Build**: `build_optimized/src/` - Production binaries

## Build Instructions

### Standard Build
```bash
mkdir build_c23 && cd build_c23
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=/opt/homebrew
make -j$(sysctl -n hw.ncpu)
```

### Optimized Build
```bash
./build_optimized.sh
```

## Optimization Features

The optimized build uses:
- `-O3`: Maximum compiler optimization
- `-march=native`: CPU-specific optimizations
- `-mtune=native`: Performance tuning for target CPU
- `-flto=thin`: Link-time optimization
- Release build configuration

## Compiler Architecture

1. **BCPL Source** → Frontend (requires assembly runtime)
2. **OCODE** → Code Generator (`cg`) → Assembly
3. **Assembly** → Optimizer (`op`) → Optimized Assembly
4. **OCODE** → LLVM Backend (`llcg`) → LLVM IR

## Technical Notes

- **Platform**: ARM64 macOS (Apple Silicon)
- **Standards**: C23 for runtime, C++17 for LLVM backend
- **Dependencies**: LLVM 20.1.7, Clang toolchain
- **Architecture**: 64-bit word size, native ARM64 code generation

## Limitations

The traditional BCPL frontend requires x86 assembly files that do not build on ARM64.
The modernized components (cg, op, llcg, runtime) build successfully and are functional.

## Installation

Built binaries are ready for use from their build directories.
No system installation required for testing and development.
