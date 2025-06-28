#!/bin/bash
# Build BCPL Compiler in Rosetta x86_64 mode
# Usage: ./build_x86_64.sh [build_type]

set -e  # Exit on any error

BUILD_TYPE=${1:-Release}
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${PROJECT_ROOT}/build_x86_64"

echo "=== BCPL Compiler x86_64 Rosetta Build ==="
echo "Project root: ${PROJECT_ROOT}"
echo "Build type: ${BUILD_TYPE}"
echo "Target architecture: x86_64 (Rosetta)"
echo ""

# Check if we're on Apple Silicon
if [[ "$(uname -m)" != "arm64" ]]; then
    echo "Warning: This script is designed for Apple Silicon Macs"
    echo "Current architecture: $(uname -m)"
fi

# Clean previous build
if [[ -d "${BUILD_DIR}" ]]; then
    echo "Cleaning previous x86_64 build..."
    rm -rf "${BUILD_DIR}"
fi

# Create build directory
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

echo "=== Configuring CMake for x86_64 ==="

# Use arch command to force x86_64 execution and set appropriate flags
arch -x86_64 /usr/local/bin/cmake "${PROJECT_ROOT}/src" \
    -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
    -DCMAKE_OSX_ARCHITECTURES=x86_64 \
    -DBITS=64 \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_C_FLAGS="-target x86_64-apple-macos11 -march=x86-64" \
    -DCMAKE_MAKE_PROGRAM=/usr/local/bin/gmake \
    -DCMAKE_VERBOSE_MAKEFILE=ON \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

echo ""
echo "=== Building BCPL Compiler for x86_64 ==="

# Build using 8 cores in x86_64 mode
arch -x86_64 /usr/local/bin/gmake -j8

echo ""
echo "=== Build Complete ==="
echo "Built executables:"
ls -la cg op *.a 2>/dev/null || echo "No executables found"

echo ""
echo "=== Verifying x86_64 Architecture ==="
for binary in cg op; do
    if [[ -f "$binary" ]]; then
        echo "$binary: $(file "$binary" | grep -o 'x86_64\|arm64')"
        echo "  $(lipo -info "$binary" 2>/dev/null || echo 'lipo info not available')"
    fi
done

echo ""
echo "=== Safe Executable Testing ==="
# Only test that files exist and have correct architecture - no execution
for binary in cg op; do
    if [[ -f "$binary" ]]; then
        if [[ -x "$binary" ]]; then
            arch_info=$(file "$binary" | grep -o 'x86_64\|arm64')
            size_info=$(ls -lh "$binary" | awk '{print $5}')
            echo "  ✓ $binary: executable, $arch_info architecture ($size_info)"
        else
            echo "  ⚠️  $binary: file exists but not executable"
        fi
    else
        echo "  ❌ $binary: not found"
    fi
done

echo ""
echo "🎉 x86_64 Rosetta build completed successfully!"
echo "📁 Build directory: ${BUILD_DIR}"
echo "🔧 Architecture: x86_64 (Rosetta emulation)"
echo "⚡ Performance: Optimized for Intel architecture"
echo ""
echo "⚠️  Note: These executables expect BCPL input and may hang if run without proper input."
echo "💡 Use 'file' and 'lipo' commands to verify architecture instead of direct execution."
echo "💡 For safe testing, use the verify_builds.sh script."
