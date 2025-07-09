#!/bin/bash
# build_max_performance.sh - Maximum performance build for BCPL compiler
# This script builds the BCPL compiler with maximum optimization flags
# WARNING: This build is optimized for the specific hardware it's built on

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}=== BCPL Compiler Maximum Performance Build ===${NC}"
echo "Building with -O3 and aggressive optimization flags"
echo "Target: Native hardware optimization"

# Check for required tools
command -v clang >/dev/null 2>&1 || { echo -e "${RED}Error: clang not found${NC}" >&2; exit 1; }
command -v lld >/dev/null 2>&1 || { echo -e "${YELLOW}Warning: lld linker not found, using default linker${NC}" >&2; }

# Build directory
BUILD_DIR="build_max_perf"
mkdir -p "${BUILD_DIR}"

# Optimization level
OPTIMIZATION_LEVEL="-O3"

# Advanced optimization flags for maximum performance
ADVANCED_OPTS=(
    # Link-time optimization
    "-flto=thin"
    "-fuse-ld=lld"
    
    # Vectorization
    "-fvectorize"
    "-fslp-vectorize"
    "-funroll-loops"
    
    # Floating-point optimizations
    "-ffp-contract=fast"
    "-fno-math-errno"
    "-fno-signed-zeros"
    
    # Memory hierarchy optimizations
    "-falign-functions=64"
    "-falign-loops=64"
    "-falign-jumps=64"
    
    # Code generation improvements
    "-fno-semantic-interposition"
    "-fdata-sections"
    "-ffunction-sections"
    
    # Native hardware optimization
    "-march=native"
    "-mtune=native"
    
    # Build pipeline optimization
    "-pipe"
)

# Linker optimizations
LINKER_OPTS=(
    "-Wl,--gc-sections"
    "-Wl,-O2"
    "-Wl,--thinlto-jobs=$(nproc)"
)

# Combine all optimization flags
ALL_OPTS="${OPTIMIZATION_LEVEL} ${ADVANCED_OPTS[*]} ${LINKER_OPTS[*]}"

echo -e "${YELLOW}Optimization flags:${NC}"
echo "${ALL_OPTS}"
echo

# Configure build
echo -e "${GREEN}Configuring build...${NC}"
cmake -B "${BUILD_DIR}" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_C_FLAGS="${ALL_OPTS}" \
    -DCMAKE_CXX_FLAGS="${ALL_OPTS}" \
    -DENABLE_MAX_OPTIMIZATION=ON \
    -DENABLE_LTO=ON \
    .

# Build
echo -e "${GREEN}Building with $(nproc) parallel jobs...${NC}"
cmake --build "${BUILD_DIR}" --parallel $(nproc)

# Verify build
if [ -f "${BUILD_DIR}/src/cg" ] && [ -f "${BUILD_DIR}/src/op" ]; then
    echo -e "${GREEN}Build successful!${NC}"
    echo "Binaries located in: ${BUILD_DIR}/src/"
    echo "  - cg (code generator)"
    echo "  - op (optimizer)"
    
    # Display binary sizes
    echo
    echo -e "${YELLOW}Binary sizes:${NC}"
    ls -lh "${BUILD_DIR}/src/cg" "${BUILD_DIR}/src/op" | awk '{print $9 ": " $5}'
    
    # Display optimization report
    echo
    echo -e "${YELLOW}Optimization summary:${NC}"
    echo "  - Optimization level: -O3"
    echo "  - ThinLTO: Enabled"
    echo "  - Vectorization: Enabled (auto + SLP)"
    echo "  - Loop unrolling: Enabled"
    echo "  - Native CPU optimization: Enabled"
    echo "  - Function/data sections: Enabled"
    echo "  - Dead code elimination: Enabled"
    
else
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi

echo
echo -e "${GREEN}Maximum performance build complete!${NC}"
echo "To use the optimized binaries:"
echo "  export PATH=$(pwd)/${BUILD_DIR}/src:\$PATH"
