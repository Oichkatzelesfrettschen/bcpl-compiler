#!/bin/bash

# BCPL Compiler Optimization Build Script
# Engineering-grade build automation

set -e

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${PROJECT_ROOT}/build_optimized"

# Detect system capabilities
if command -v nproc >/dev/null 2>&1; then
    JOBS=$(nproc)
elif command -v sysctl >/dev/null 2>&1; then
    JOBS=$(sysctl -n hw.ncpu)
else
    JOBS=4
fi

echo "=== BCPL Compiler Optimized Build ==="
echo "Jobs: ${JOBS}"
echo "Build directory: ${BUILD_DIR}"

# Clean previous build
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

# Configure with optimization flags
cmake .. \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_FLAGS="-O3 -march=native -mtune=native -flto=thin" \
    -DCMAKE_CXX_FLAGS="-O3 -march=native -mtune=native -flto=thin" \
    -DCMAKE_PREFIX_PATH=/opt/homebrew \
    -DLLVM_DIR=/opt/homebrew/opt/llvm/lib/cmake/llvm

# Build optimized binaries
make -j"${JOBS}"

echo "=== Build Complete ==="
echo "Optimized binaries in: ${BUILD_DIR}/src/"
ls -la src/{cg,op,llcg} 2>/dev/null || echo "Check build output above"

# Test basic functionality
echo "=== Testing Components ==="
echo "Code Generator test:"
echo "" | ./src/cg | head -5

echo "Build optimization complete."
