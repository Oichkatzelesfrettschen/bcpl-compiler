# BCPL Compiler Build Guide

## Overview

This document provides comprehensive build instructions for the modernized BCPL compiler with multi-architecture support.

## System Requirements

### Minimum Requirements
- **CMake**: 3.20 or later
- **C Compiler**: Clang with C23 support (recommended) or GCC 9+
- **Memory**: 2GB RAM for compilation
- **Disk Space**: 500MB for source and build artifacts

### Platform-Specific Requirements

#### macOS
- Xcode Command Line Tools: `xcode-select --install`
- Homebrew (optional): For additional dependencies

#### Linux
```bash
# Ubuntu/Debian
sudo apt update && sudo apt install build-essential cmake clang

# Fedora/RHEL
sudo dnf install gcc-toolset cmake clang

# Arch Linux
sudo pacman -S base-devel cmake clang
```

#### FreeBSD
```bash
pkg install cmake clang
```

#### Windows
- Visual Studio 2022 with C++ workload
- CMake 3.20+
- Clang (optional, but recommended)

### Python Dependencies
The auxiliary tooling and tests rely on a small set of Python packages.
Install them once per checkout:

```bash
pip install -r requirements.txt
```

### Quick Start (Linux)

```bash
sudo apt-get update
sudo apt-get install build-essential cmake clang
pip install -r requirements.txt
cmake -S . -B build
cmake --build build
cd build && ctest --output-on-failure
```

## Build Methods

### Method 1: Unified Build Script (Recommended)

The project includes a unified build script that handles all configurations:

```bash
# Basic build (Release, native architecture)
./build.sh

# Specify build type and architecture
./build.sh [BUILD_TYPE] [ARCHITECTURE]
```

**Build Types:**
- `Release` (default): Optimized for performance
- `Debug`: Includes debug symbols and assertions
- `RelWithDebInfo`: Optimized with debug info
- `MinSizeRel`: Optimized for size

**Architectures:**
- `native` (default): Detect and use system architecture
- `x86_64`: 64-bit Intel/AMD
- `arm64`: 64-bit ARM (Apple Silicon, ARM servers)
- `x86_32`: 32-bit Intel/AMD
- `arm32`: 32-bit ARM

**Examples:**
```bash
./build.sh Release x86_64     # Release build for x86_64
./build.sh Debug arm64        # Debug build for ARM64
./build.sh Release native     # Release build for current system
```

### Method 2: CMake Presets

The new build system provides CMake presets that encapsulate
common configurations. Presets create their own build directories
and enable the appropriate options automatically.

```bash
# Configure and build using the default preset
cmake --preset default
cmake --build --preset default

# Debug build with sanitizers
cmake --preset debug
cmake --build --preset debug
```

### Method 3: Direct CMake

For more control over the build process:

```bash
# Create and enter build directory
mkdir build && cd build

# Configure
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBCPL_TARGET_ARCH=x86_64 \
      ..

# Build
cmake --build . --parallel
```

### Method 4: Cross-Compilation

Example cross-compilation for different architectures:

```bash
# ARM64 on x86_64 macOS (Universal Binary)
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_OSX_ARCHITECTURES="arm64;x86_64" \
      ..

# ARM64 Linux on x86_64 host
cmake -DCMAKE_BUILD_TYPE=Release \
      -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc \
      -DBCPL_TARGET_ARCH=arm64 \
      ..
```

## Build Configuration Options

### CMake Variables

| Variable | Default | Description |
|----------|---------|-------------|
| `CMAKE_BUILD_TYPE` | Release | Build configuration |
| `BCPL_TARGET_ARCH` | native | Target architecture |
| `BCPL_ENABLE_TESTING` | ON | Enable test suite |
| `BCPL_ENABLE_DOCS` | OFF | Generate documentation |
| `BCPL_LEGACY_RUNTIME` | OFF | Use assembly runtime |
| `BCPL_STATIC_LINKING` | OFF | Static linking |

### Architecture-Specific Options

#### x86_64
```bash
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBCPL_TARGET_ARCH=x86_64 \
      -DBCPL_X86_64_OPTIMIZATION=ON \
      ..
```

#### ARM64
```bash
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBCPL_TARGET_ARCH=arm64 \
      -DBCPL_ARM64_NEON=ON \
      ..
```

## Build Outputs

After a successful build, you'll find:

```
build/
├── src/
│   ├── bcplc                  # Main compiler executable
│   ├── blib.O                 # BCPL standard library
│   └── librt.a                # Runtime library
├── tests/                     # Test executables
└── docs/                      # Generated documentation (if enabled)
```

## Runtime Memory Semantics

The modernized runtime centralizes all heap management in
`src/platform/common_memory.c`.  The platform layer now guarantees that
zero-byte allocations and re-allocations return a minimal, aligned block
instead of `NULL`, mirroring historical BCPL behaviour.  Use
`bcpl_platform_realloc` to resize allocations while preserving this
contract across operating systems.

## Validation

### Build Validation
```bash
# Test the compiler with a simple program
echo 'GET "LIBHDR"; LET START() BE WRITES("Hello, BCPL!")' > test.bcpl
./build/Release/src/bcplc test.bcpl
./test
```

### Run Test Suite
The `gencode()` refactor introduced a consolidated unit-test driver
named `bcpl_tests`.
Run the suite from your build directory:

```bash
cd build/Release
ctest --output-on-failure       # Execute all unit and integration tests
```

## Performance Optimization

### Profile-Guided Optimization (PGO)
```bash
# Build with PGO instrumentation
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBCPL_ENABLE_PGO_GENERATE=ON \
      ..
cmake --build .

# Run training workload
./src/bcplc examples/*.bcpl

# Rebuild with PGO optimization
cmake -DBCPL_ENABLE_PGO_GENERATE=OFF \
      -DBCPL_ENABLE_PGO_USE=ON \
      ..
cmake --build .
```

### Link-Time Optimization (LTO)
```bash
cmake -DCMAKE_BUILD_TYPE=Release \
      -DBCPL_ENABLE_LTO=ON \
      ..
```

## Troubleshooting

### Common Issues

#### CMake Version Too Old
```bash
# macOS
brew upgrade cmake

# Linux
pip install --upgrade cmake

# From source
wget https://cmake.org/files/v3.20/cmake-3.20.0.tar.gz
tar xzf cmake-3.20.0.tar.gz && cd cmake-3.20.0
./bootstrap && make && sudo make install
```

#### Clang Not Found
```bash
# Set specific compiler
export CC=clang
export CXX=clang++
cmake ..

# Or specify in CMake
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ..
```

#### Architecture Detection Fails
```bash
# Force specific architecture
cmake -DBCPL_TARGET_ARCH=x86_64 ..
```

#### Missing Dependencies
```bash
# macOS
xcode-select --install

# Linux
sudo apt install build-essential

# Check CMake requirements
cmake .. 2>&1 | grep -i "could not find"
```

### Build Logs

Enable verbose build output for debugging:
```bash
cmake --build . --verbose
```

Or with the build script:
```bash
VERBOSE=1 ./build.sh
```

## Integration with IDEs

### Visual Studio Code
1. Install CMake Tools extension
2. Open project folder
3. Press `Ctrl+Shift+P` and select "CMake: Configure"
4. Select kit (compiler)
5. Build with `Ctrl+Shift+P` -> "CMake: Build"

### CLion
1. Open project folder
2. CLion will automatically detect CMakeLists.txt
3. Configure build profiles in Settings -> Build -> CMake
4. Build with `Ctrl+F9`

### Xcode (macOS)
```bash
cmake -G Xcode ..
open BCPL.xcodeproj
```

## Continuous Integration

### GitHub Actions Example
```yaml
name: Build BCPL
on: [push, pull_request]
jobs:
  build:
    strategy:
      matrix:
        os: [ubuntu-latest, macos-latest, windows-latest]
        arch: [x86_64, arm64]
    runs-on: ${{ matrix.os }}
    steps:
    - uses: actions/checkout@v3
    - name: Build
      run: ./build.sh Release ${{ matrix.arch }}
    - name: Test
      run: cd build/Release && ctest
```

## Custom Builds

### Minimal Build (Embedded Systems)
```bash
cmake -DCMAKE_BUILD_TYPE=MinSizeRel \
      -DBCPL_MINIMAL_RUNTIME=ON \
      -DBCPL_NO_STDLIB=ON \
      ..
```

### Development Build
```bash
cmake -DCMAKE_BUILD_TYPE=Debug \
      -DBCPL_ENABLE_SANITIZERS=ON \
      -DBCPL_ENABLE_COVERAGE=ON \
      ..
```

This guide should cover most build scenarios. For advanced configurations or specific platform issues, consult the platform-specific documentation in the `docs/platforms/` directory.
