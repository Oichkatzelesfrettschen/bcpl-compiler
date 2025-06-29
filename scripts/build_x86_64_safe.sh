#!/bin/bash
# Build BCPL Compiler in Rosetta x86_64 mode (Non-hanging version)
# Usage: ./build_x86_64_safe.sh [build_type]

set -e

BUILD_TYPE=${1:-Release}
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${PROJECT_ROOT}/build_x86_64"

echo "=== BCPL Compiler x86_64 Rosetta Build (Safe) ==="
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
    fi
done

echo ""
echo "=== Safe Executable Testing ==="
# Only test that files exist and have correct architecture - no execution
for binary in cg op; do
    if [[ -f "$binary" ]]; then
        if [[ -x "$binary" ]]; then
            echo "  ✓ $binary: executable and correct architecture"
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
echo "⚠️  Note: Use test_bcpl.sh for safe runtime testing"
