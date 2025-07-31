# BCPL Compiler Development Container - Debian Sid

This directory contains the **bleeding-edge** development container configuration for the BCPL Compiler project, providing a cutting-edge Debian Sid (Unstable) development environment with the latest tools and compilers.

## ⚠️ Important Notice

**Debian Sid (Unstable)** is the development branch of Debian. This container provides access to the latest versions of development tools, but may be less stable than the Ubuntu 24.04 container. Use this for:

- Testing with the latest compiler features (C23, C++23)
- Experimenting with cutting-edge development tools
- Cross-platform development with the newest toolchains
- Performance analysis with the latest profiling tools

## What's Included

### Cutting-Edge Compilers
- **GCC 14**: Latest GCC with full C23 and C++23 support
- **Clang/LLVM**: Latest LLVM toolchain
- **Cross-compilers**: ARM, AARCH64, RISC-V, PowerPC, s390x, MIPS
- **Alternative compilers**: Rust, Go, Zig, Crystal, Nim, D

### Advanced Build Systems
- **CMake**: Latest version with modern features
- **Ninja**: High-performance build system
- **Meson**: Python-based build system
- **Bazel**: Google's build system (if available)
- **Buck2**: Meta's build system (experimental)

### Package Managers
- **Conan 2.x**: Modern C++ package manager
- **vcpkg**: Microsoft's C++ package manager
- **APT Experimental**: Access to experimental Debian packages

### Development Tools
- **Debugging**: GDB (multi-arch), LLDB, Valgrind with latest features
- **Analysis**: Cppcheck, Clang-tidy, static analyzers, sanitizers
- **Performance**: Perf tools, profilers, benchmarking tools
- **Documentation**: Doxygen, Pandoc, LaTeX

### Modern Utilities
- **File tools**: `exa`, `bat`, `fd`, `ripgrep`, `fzf`
- **Terminal**: `htop`, `tmux`, enhanced shell configuration
- **Version control**: Git with advanced configuration

### Python Ecosystem
- **Python 3.x**: Latest stable version
- **Development tools**: black, ruff, mypy, pytest
- **Scientific**: NumPy, Matplotlib, Pandas, SciPy
- **Modern tools**: Poetry, pre-commit, rich, typer

### VS Code Extensions
- Complete C/C++ development stack
- CMake tools with latest features
- Advanced debugging and analysis tools
- Documentation and formatting tools

## Getting Started

### Option 1: Use as Primary Container
Use `../select-devcontainer.sh debian` from the repository root to activate this
configuration, then reopen the folder in VS Code.

### Option 2: Use as Secondary Container
1. **Open specific container**: Use Command Palette → "Dev Containers: Reopen in Container"
2. **Select configuration**: Choose the Debian Sid configuration
3. **Build and connect**: Wait for the container to build

### Option 3: Manual Build
```bash
cd .devcontainer
docker build -f Dockerfile.debian -t bcpl-debian-sid .
docker run -it --mount type=bind,source="$(pwd)/..",target=/workspace bcpl-debian-sid
```

## Container Features

### Compiler Switching
```bash
# Switch between compilers
switch_compiler gcc-14    # Use GCC 14
switch_compiler clang     # Use Clang
switch_compiler gcc       # Use default GCC

# Enable experimental features
use-experimental          # Enable C23/C++23 flags
source ~/.bash_experimental  # Load experimental settings
```

### Build Configurations
```bash
# Multi-compiler builds
cmake-gcc                 # Configure with GCC
cmake-clang              # Configure with Clang  
cmake-experimental       # Use bleeding-edge features

# Package managers
conan-install            # Install Conan dependencies
vcpkg-install           # Install vcpkg packages
apt-experimental        # Install experimental packages
```

### Analysis and Debugging
```bash
# Comprehensive analysis
valgrind-check          # Memory analysis with latest Valgrind
clang-static           # Clang static analyzer
perf-record            # Performance profiling
cppcheck-all           # Static code analysis

# Code formatting
clang-format-all       # Format all C/C++ files
```

## Building the BCPL Compiler

### Standard Build
```bash
# Quick build
bcpl-build

# CMake build with latest features
cmake-experimental
cmake-build
```

### Multi-Compiler Testing
```bash
# Test with different compilers
switch_compiler gcc-14
cmake-gcc && cmake-build

switch_compiler clang  
cmake-clang && cmake-build
```

### Performance Build
```bash
# Optimized build with profiling
use-experimental
cmake -S . -B build_perf -G Ninja \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_FLAGS="-O3 -flto -march=native" \
  -DCMAKE_CXX_FLAGS="-O3 -flto -march=native"
cmake --build build_perf
```

## Testing and Validation

### Comprehensive Testing
```bash
# Run all tests
bcpl-test

# Memory testing
valgrind-check ./bcplc test_input.bcpl

# Performance testing  
perf-record ./bcplc large_input.bcpl
perf-report
```

### Cross-Platform Testing
```bash
# ARM cross-compilation
CC=aarch64-linux-gnu-gcc cmake -S . -B build_arm64
cmake --build build_arm64

# RISC-V cross-compilation
CC=riscv64-linux-gnu-gcc cmake -S . -B build_riscv
cmake --build build_riscv
```

## Advanced Features

### Experimental Language Features
```bash
# Test C23 features
echo 'int main() { typeof(1) x = 42; return 0; }' | \
  gcc-14 -std=c2x -x c - -o test_c23

# Test C++23 features (if available)
echo '#include <print>\nint main() { std::print("Hello\\n"); }' | \
  g++-14 -std=c++23 -x c++ - -o test_cpp23
```

### Package Management
```bash
# Conan 2.x workflow
conan profile detect
conan install . --build=missing

# vcpkg integration
vcpkg install boost sqlite3 fmt
cmake -DCMAKE_TOOLCHAIN_FILE=/opt/vcpkg/scripts/buildsystems/vcpkg.cmake
```

## Useful Commands

### Project Information
```bash
project_info           # Show comprehensive project info
compiler-info          # Show current compiler settings
```

### Build Shortcuts
```bash
cmake-configure        # Standard CMake configuration
ninja-build           # Fast Ninja build
cmake-clean           # Clean build directory
```

### Analysis Tools
```bash
time-detailed         # Detailed timing analysis
coverage              # Code coverage analysis
```

## Troubleshooting

### Common Issues

1. **Package conflicts**: Debian Sid packages may conflict
   ```bash
   sudo apt-get update
   sudo apt-get upgrade
   ```

2. **Experimental packages**: Some features may not be stable
   ```bash
   # Fallback to stable packages
   sudo apt-get install -t stable <package>
   ```

3. **Container rebuild**: For major updates
   ```bash
   # In VS Code: Command Palette → "Rebuild Container"
   ```

### Performance Issues
```bash
# Check system resources
htop
df -h
free -h

# Optimize build parallelism
export MAKEFLAGS="-j$(nproc)"
```

## Container Specifications

- **Base Image**: `debian:sid`
- **User**: `vscode` (non-root with sudo)
- **Workspace**: `/workspace`
- **Shell**: Zsh with Oh My Zsh (fallback to Bash)
- **Compilers**: GCC 14, Clang (latest), cross-compilers
- **Build Systems**: CMake, Ninja, Meson, Bazel
- **Package Managers**: APT, Conan 2.x, vcpkg

## Comparison with Ubuntu Container

| Feature | Ubuntu 24.04 | Debian Sid |
|---------|--------------|------------|
| Stability | High | Experimental |
| Compiler versions | Stable | Latest |
| Package availability | LTS packages | Cutting-edge |
| C23 support | Partial | Full |
| Experimental features | Limited | Extensive |
| Recommended for | Production | Development/Testing |

## Contributing

When developing with this container:

1. Test with both GCC and Clang
2. Use experimental features carefully
3. Document any Debian Sid specific requirements
4. Test cross-compilation if applicable
5. Run comprehensive analysis tools

The bleeding-edge environment is perfect for pushing the boundaries of C23 development and testing the latest compiler features with the BCPL compiler project.
