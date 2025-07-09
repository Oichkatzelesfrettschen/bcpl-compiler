#!/bin/bash
# Multi-Architecture BCPL Compiler Status Report

set -e

echo "=================================="
echo "BCPL Multi-Architecture Status"
echo "=================================="
echo ""

# Repository information
echo "Repository Structure:"
echo "  Root: $(pwd)"
echo "  Git status: $(git rev-parse --short HEAD 2>/dev/null || echo 'Not a git repository')"
echo ""

# Architecture support
echo "Architecture Support:"
if [[ -f "cmake/MultiArch.cmake" ]]; then
    echo "  ✓ Multi-architecture system configured"
    echo "  ✓ Primary targets: ARM64, x86_64"
    echo "  ✓ Optional targets: ARM32, x86_32, x86_16"
else
    echo "  ✗ Multi-architecture system not found"
fi
echo ""

# Check architecture-specific runtime files
echo "Architecture-Specific Runtime Files:"
for arch in arm64 x86_64 arm32 x86_32 x86_16; do
    if [[ -f "src/arch/${arch}/runtime_${arch}.c" ]]; then
        echo "  ✓ ${arch}: src/arch/${arch}/runtime_${arch}.c"
    else
        echo "  ✗ ${arch}: Missing runtime file"
    fi
done
echo ""

# Check for duplicates
echo "Duplicate File Check:"
duplicate_count=$(find . -name "* 2.*" -type f 2>/dev/null | wc -l || echo "0")
if [[ "$duplicate_count" -eq 0 ]]; then
    echo "  ✓ No duplicate files found"
else
    echo "  ⚠ Found $duplicate_count duplicate files with ' 2.' pattern"
fi
echo ""

# Build system files
echo "Build System Files:"
files=(
    "CMakeLists.txt:Root CMake configuration"
    "src/CMakeLists.txt:Source CMake configuration"
    "cmake/MultiArch.cmake:Multi-architecture support"
    "cmake/Options.cmake:Build options"
    "cmake/PlatformConfig.cmake:Platform configuration"
    "build_all_archs.sh:Multi-architecture build script"
)

for file_desc in "${files[@]}"; do
    file="${file_desc%:*}"
    desc="${file_desc#*:}"
    if [[ -f "$file" ]]; then
        echo "  ✓ $file ($desc)"
    else
        echo "  ✗ $file ($desc) - Missing"
    fi
done
echo ""

# Check for existing build directories
echo "Existing Build Directories:"
for arch in arm64 x86_64 arm32 x86_32 x86_16 universal; do
    build_dir="build-${arch}"
    if [[ -d "$build_dir" ]]; then
        echo "  ✓ $build_dir"
        # Check for binaries
        if [[ -f "$build_dir/src/st_${arch}" ]] || [[ -f "$build_dir/src/st" ]]; then
            echo "    - Contains compiled binaries"
        else
            echo "    - Directory exists but no binaries found"
        fi
    fi
done

if ! ls build-* >/dev/null 2>&1; then
    echo "  (No build directories found)"
fi
echo ""

# Check for BCPL source files
echo "BCPL Source Files:"
if [[ -f "src/st.O" ]]; then
    echo "  ✓ src/st.O (BCPL OCODE)"
else
    echo "  ✗ src/st.O (BCPL OCODE) - Missing"
fi

if [[ -f "src/st.bcpl" ]]; then
    echo "  ✓ src/st.bcpl (BCPL source)"
else
    echo "  ✗ src/st.bcpl (BCPL source) - Missing"
fi

if [[ -f "src/blib.O" ]]; then
    echo "  ✓ src/blib.O (BCPL library OCODE)"
else
    echo "  ✗ src/blib.O (BCPL library OCODE) - Missing"
fi
echo ""

# Check runtime files
echo "Runtime Library Files:"
runtime_files=(
    "src/runtime/bcpl_runtime.c"
    "src/runtime/memory.c"
    "src/runtime/io.c"
    "src/runtime/strings.c"
    "src/runtime/vectors.c"
    "src/runtime/startup.c"
)

for file in "${runtime_files[@]}"; do
    if [[ -f "$file" ]]; then
        echo "  ✓ $(basename "$file")"
    else
        echo "  ✗ $(basename "$file") - Missing"
    fi
done
echo ""

# Check compiler tools
echo "Compiler Tool Sources:"
compiler_files=(
    "src/cg.c:Code generator"
    "src/op.c:Optimizer"
    "src/oc.c:Object code handler"
    "src/pt.c:Parse tree handler"
    "src/llcg.cpp:LLVM code generator"
)

for file_desc in "${compiler_files[@]}"; do
    file="${file_desc%:*}"
    desc="${file_desc#*:}"
    if [[ -f "$file" ]]; then
        echo "  ✓ $(basename "$file") ($desc)"
    else
        echo "  ✗ $(basename "$file") ($desc) - Missing"
    fi
done
echo ""

# System information
echo "System Information:"
echo "  OS: $(uname -s)"
echo "  Architecture: $(uname -m)"
if command -v sw_vers >/dev/null 2>&1; then
    echo "  macOS Version: $(sw_vers -productVersion)"
fi
if command -v clang >/dev/null 2>&1; then
    echo "  Clang Version: $(clang --version | head -1)"
fi
if command -v cmake >/dev/null 2>&1; then
    echo "  CMake Version: $(cmake --version | head -1)"
fi
echo ""

# Cross-compilation toolchains
echo "Cross-Compilation Toolchains:"
cross_compilers=(
    "aarch64-linux-gnu-gcc:ARM64 Linux"
    "arm-linux-gnueabihf-gcc:ARM32 Linux"
    "i686-linux-gnu-gcc:x86_32 Linux"
    "i8086-linux-gcc:x86_16"
)

for compiler_desc in "${cross_compilers[@]}"; do
    compiler="${compiler_desc%:*}"
    desc="${compiler_desc#*:}"
    if command -v "$compiler" >/dev/null 2>&1; then
        echo "  ✓ $compiler ($desc)"
    else
        echo "  ✗ $compiler ($desc) - Not available"
    fi
done
echo ""

# Recommendations
echo "Recommendations:"
echo ""

if [[ ! -f "src/st.O" ]]; then
    echo "⚠ Bootstrap files missing - run git checkout to restore them"
fi

if [[ "$(uname -s)" == "Darwin" ]]; then
    echo "ℹ On macOS - Universal Binary support available"
    echo "  Run: ./build_all_archs.sh to build both ARM64 and x86_64"
fi

if [[ ! -d "build-$(uname -m)" ]]; then
    echo "ℹ No build for native architecture ($(uname -m))"
    echo "  Run: mkdir build && cd build && cmake .. && make"
fi

echo ""
echo "Ready to build multi-architecture BCPL compiler!"
echo "Run ./build_all_archs.sh to build for all supported architectures."
