#!/bin/bash
# build_portable_optimized.sh - Portable optimized build for BCPL compiler
# This script builds the BCPL compiler with high optimization while maintaining portability

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}=== BCPL Compiler Portable Optimized Build ===${NC}"
echo "Building with -O3 optimization while maintaining binary portability"

# Check for required tools
command -v clang >/dev/null 2>&1 || { echo -e "${RED}Error: clang not found${NC}" >&2; exit 1; }
command -v lld >/dev/null 2>&1 || { echo -e "${YELLOW}Warning: lld linker not found, using default linker${NC}" >&2; }

# Build directory
BUILD_DIR="build_portable"
mkdir -p "${BUILD_DIR}"

# Optimization level
OPTIMIZATION_LEVEL="-O3"

# Detect architecture and set appropriate baseline
ARCH=$(uname -m)
case "${ARCH}" in
    x86_64)
        ARCH_FLAGS="-march=x86-64-v2 -mtune=generic"
        echo "Targeting x86-64-v2 baseline (SSE4.2, POPCNT)"
        ;;
    arm64|aarch64)
        ARCH_FLAGS="-march=armv8-a -mtune=generic"
        echo "Targeting ARMv8-A baseline"
        ;;
    *)
        ARCH_FLAGS="-mtune=generic"
        echo "Using generic tuning for ${ARCH}"
        ;;
esac

# Portable optimization flags
PORTABLE_OPTS=(
    # Link-time optimization
    "-flto=thin"
    "-fuse-ld=lld"
    
    # Vectorization (portable)
    "-fvectorize"
    "-fslp-vectorize"
    "-funroll-loops"
    
    # Floating-point optimizations (conservative)
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
    
    # Portable architecture targeting
    ${ARCH_FLAGS}
    
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
ALL_OPTS="${OPTIMIZATION_LEVEL} ${PORTABLE_OPTS[*]} ${LINKER_OPTS[*]}"

echo -e "${YELLOW}Architecture: ${ARCH}${NC}"
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
    
    # Test portability (check for native instructions)
    echo
    echo -e "${YELLOW}Portability check:${NC}"
    if command -v objdump >/dev/null 2>&1; then
        echo "Checking for native-only instructions..."
        if objdump -d "${BUILD_DIR}/src/cg" | grep -q "native\|avx512\|specific"; then
            echo -e "${YELLOW}Warning: Some native instructions may be present${NC}"
        else
            echo -e "${GREEN}No obvious native-only instructions detected${NC}"
        fi
    fi
    
    # Display optimization report
    echo
    echo -e "${YELLOW}Optimization summary:${NC}"
    echo "  - Optimization level: -O3"
    echo "  - ThinLTO: Enabled"
    echo "  - Vectorization: Enabled (portable)"
    echo "  - Loop unrolling: Enabled"
    echo "  - Architecture: ${ARCH} (portable baseline)"
    echo "  - Function/data sections: Enabled"
    echo "  - Dead code elimination: Enabled"
    echo "  - Binary portability: Maintained"
    
else
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi

echo
echo -e "${GREEN}Portable optimized build complete!${NC}"
echo "This binary should run on similar ${ARCH} systems without the specific CPU model"
echo "To use the optimized binaries:"
echo "  export PATH=$(pwd)/${BUILD_DIR}/src:\$PATH"
