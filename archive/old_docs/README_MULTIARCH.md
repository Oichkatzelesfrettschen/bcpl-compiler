# Multi-Architecture BCPL Compiler

A modernized BCPL (Basic Combined Programming Language) compiler with comprehensive multi-architecture support, featuring native compilation for ARM64, x86_64, ARM32, x86_32, and x86_16 architectures.

## Features

- **Multi-Architecture Support**: Native compilation for multiple CPU architectures
- **Modern C23 Runtime**: High-performance runtime with architecture-specific optimizations
- **Cross-Platform**: macOS, Linux, FreeBSD, and other Unix-like systems
- **Universal Binaries**: Support for macOS Universal Binaries (ARM64 + x86_64)
- **OCODE Translation**: Platform-independent code generation via C translation
- **LLVM Backend**: Optional LLVM backend for advanced optimizations

## Supported Architectures

### Primary Architectures (Always Built)
- **ARM64 (AArch64)**: Apple Silicon, ARM64 servers, embedded systems
- **x86_64 (AMD64)**: Intel/AMD 64-bit processors

### Optional Architectures (Cross-compilation)
- **ARM32**: 32-bit ARM processors (ARMv7-A, ARMv8-A in 32-bit mode)
- **x86_32 (i386)**: 32-bit Intel/AMD processors
- **x86_16 (8086/80286)**: Legacy 16-bit processors (requires special toolchain)

## Architecture-Specific Optimizations

Each architecture includes specialized runtime optimizations:

- **ARM64**: NEON SIMD instructions, hardware performance counters, cache management
- **x86_64**: SSE/AVX optimizations, Intel/AMD specific features
- **ARM32**: NEON support, VFP floating-point, cache coherency
- **x86_32**: SSE/MMX where available, 32-bit specific optimizations
- **x86_16**: Legacy string instructions, segment management, real-mode support

## Building

### Quick Start (Native Architecture)
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Multi-Architecture Build
```bash
./build_all_archs.sh
```

### Specific Architecture
```bash
mkdir build-arm64 && cd build-arm64
cmake -DTARGET_ARCH=arm64 ..
make -j$(nproc)
```

### Cross-Compilation
```bash
# Enable cross-compilation
export ENABLE_CROSS_COMPILE=ON
./build_all_archs.sh

# Or for specific architecture
cmake -DTARGET_ARCH=arm32 -DENABLE_CROSS_COMPILE=ON ..
```

### Universal Binary (macOS)
```bash
# The build script automatically creates universal binaries
./build_all_archs.sh
# Results in build-universal/ containing universal binaries
```

## Build Options

### Architecture Selection
- `-DTARGET_ARCH=<arch>`: Target specific architecture (arm64, x86_64, arm32, x86_32, x86_16)
- `-DENABLE_CROSS_COMPILE=ON`: Enable cross-compilation support
- `-DENABLE_ARM64=ON/OFF`: Include ARM64 support
- `-DENABLE_X86_64=ON/OFF`: Include x86_64 support
- `-DENABLE_ARM32=ON/OFF`: Include ARM32 support
- `-DENABLE_X86_32=ON/OFF`: Include x86_32 support
- `-DENABLE_X86_16=ON/OFF`: Include x86_16 support

### Performance Options
- `-DENABLE_THIN_LTO=ON`: Enable ThinLTO optimization
- `-DENABLE_FULL_LTO=ON`: Enable Full LTO optimization
- `-DENABLE_PGO=ON`: Enable Profile-Guided Optimization

### Analysis Tools
- `-DENABLE_ASAN=ON`: Address Sanitizer
- `-DENABLE_UBSAN=ON`: Undefined Behavior Sanitizer
- `-DENABLE_CLANG_TIDY=ON`: Static analysis with clang-tidy

## Generated Binaries

All binaries include architecture suffixes for multi-arch builds:

- `cg_<arch>`: Code generator for target architecture
- `op_<arch>`: Optimizer for target architecture  
- `st_<arch>`: BCPL syntax translator for target architecture
- `llcg_<arch>`: LLVM code generator (if available)
- `libbcpl_runtime_<arch>.a`: Architecture-specific runtime library

## Cross-Compilation Prerequisites

### ARM64 (from x86_64)
- **Linux**: `apt install gcc-aarch64-linux-gnu`
- **macOS**: Built-in with Xcode

### ARM32
- **Linux**: `apt install gcc-arm-linux-gnueabihf`

### x86_16
- **Special toolchain**: ia16-elf-gcc or i8086-linux-gcc
- Download from: https://github.com/tkchia/build-ia16

## Usage Examples

### Native Compilation
```bash
# Compile hello.bcpl for current architecture
./build/src/st_$(uname -m) hello.bcpl
./build/src/cg_$(uname -m) hello.ocode
```

### Cross-Architecture Compilation
```bash
# Compile for ARM64 from x86_64
./build-arm64/src/st_arm64 hello.bcpl
./build-arm64/src/cg_arm64 hello.ocode
```

### Universal Binary (macOS)
```bash
# Use the universal binary
./build-universal/src/st hello.bcpl
./build-universal/src/cg hello.ocode
```

## Project Structure

```
├── src/
│   ├── arch/              # Architecture-specific code
│   │   ├── arm64/         # ARM64 optimizations
│   │   ├── x86_64/        # x86_64 optimizations
│   │   ├── arm32/         # ARM32 optimizations
│   │   ├── x86_32/        # x86_32 optimizations
│   │   └── x86_16/        # x86_16 legacy support
│   ├── runtime/           # Core runtime library
│   ├── platform/          # Platform-specific code
│   └── *.c               # Core compiler sources
├── cmake/
│   ├── MultiArch.cmake    # Multi-architecture configuration
│   ├── Options.cmake      # Build options
│   └── PlatformConfig.cmake # Platform detection
└── scripts/               # Build and utility scripts
```

## Testing

### Architecture-Specific Tests
```bash
cd build-<arch>
make test
```

### All Architectures
```bash
for arch in arm64 x86_64; do
    echo "Testing $arch..."
    cd build-$arch && make test && cd ..
done
```

## Compatibility

### Operating Systems
- **macOS**: 10.15+ (Universal Binary support requires 11.0+)
- **Linux**: Any distribution with glibc 2.17+
- **FreeBSD**: 12.0+
- **Other Unix**: Generic POSIX support

### Compilers
- **Required**: Clang 13+ or AppleClang 13+
- **C Standard**: C23 (with C11 fallback)

## Performance Notes

- **ARM64**: Optimized for Apple Silicon and ARM64 servers
- **x86_64**: Uses SSE2/SSE4/AVX when available
- **Cross-compilation**: May have slight performance impact vs native builds
- **Universal Binaries**: No runtime performance impact, only larger file size

## Troubleshooting

### Cross-Compilation Issues
```bash
# Check available cross-compilers
ls /usr/bin/*-gcc

# Verify architecture support
file build-<arch>/src/st_<arch>
```

### macOS Universal Binary Issues
```bash
# Check universal binary
lipo -info build-universal/src/st

# Test specific architecture
arch -arm64 ./build-universal/src/st
arch -x86_64 ./build-universal/src/st
```

## Contributing

When adding new architecture support:

1. Create `src/arch/<arch>/` directory
2. Implement `runtime_<arch>.c` with optimizations
3. Update `cmake/MultiArch.cmake` configuration
4. Add cross-compilation toolchain detection
5. Update build scripts and documentation

## License

See COPYING and LICENSE files for license information.
