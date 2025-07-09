#!/bin/bash
# build_pgo.sh - Profile-Guided Optimization build for BCPL compiler
# Three-stage PGO build: instrument -> train -> optimize

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${GREEN}=== BCPL Compiler Profile-Guided Optimization Build ===${NC}"
echo "Three-stage build: Instrument -> Train -> Optimize"

# Check for required tools
command -v clang >/dev/null 2>&1 || { echo -e "${RED}Error: clang not found${NC}" >&2; exit 1; }
command -v llvm-profdata >/dev/null 2>&1 || { echo -e "${RED}Error: llvm-profdata not found${NC}" >&2; exit 1; }

# Build directories
STAGE1_DIR="build_pgo_stage1"
STAGE2_DIR="build_pgo_stage2"
FINAL_DIR="build_pgo_final"

# Clean previous builds
echo -e "${YELLOW}Cleaning previous PGO builds...${NC}"
rm -rf "${STAGE1_DIR}" "${STAGE2_DIR}" "${FINAL_DIR}"

# =============================================================================
# STAGE 1: INSTRUMENTED BUILD
# =============================================================================

echo
echo -e "${BLUE}=== STAGE 1: Building instrumented binary ===${NC}"

mkdir -p "${STAGE1_DIR}"

# Instrumentation flags
INSTRUMENT_FLAGS=(
    "-O3"
    "-fprofile-instr-generate"
    "-fcoverage-mapping"
    "-fvectorize"
    "-fslp-vectorize"
)

# Configure instrumented build
cmake -B "${STAGE1_DIR}" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_C_FLAGS="${INSTRUMENT_FLAGS[*]}" \
    -DCMAKE_CXX_FLAGS="${INSTRUMENT_FLAGS[*]}" \
    .

# Build instrumented version
cmake --build "${STAGE1_DIR}" --parallel $(nproc)

if [ ! -f "${STAGE1_DIR}/src/cg" ] || [ ! -f "${STAGE1_DIR}/src/op" ]; then
    echo -e "${RED}Stage 1 build failed!${NC}"
    exit 1
fi

echo -e "${GREEN}Stage 1 complete: Instrumented binaries built${NC}"

# =============================================================================
# STAGE 2: TRAINING PHASE
# =============================================================================

echo
echo -e "${BLUE}=== STAGE 2: Training with representative workloads ===${NC}"

# Set profile output
export LLVM_PROFILE_FILE="${STAGE1_DIR}/bcpl_%p.profraw"

cd "${STAGE1_DIR}"

# Create test workloads if they don't exist
if [ ! -f "../test_workload_1.bcpl" ]; then
    echo -e "${YELLOW}Creating test workloads...${NC}"
    cat > ../test_workload_1.bcpl << 'EOF'
// Simple BCPL test program for PGO training
GET "LIBHDR"

LET start() = VALOF
{ 
    FOR i = 1 TO 1000 DO
    {
        LET result = fibonacci(i MOD 20)
        writef("fib(%n) = %n*n", i MOD 20, result)
    }
    RESULTIS 0
}

AND fibonacci(n) = n <= 1 -> n, fibonacci(n-1) + fibonacci(n-2)
EOF

    cat > ../test_workload_2.ocode << 'EOF'
// Simple ocode for training the optimizer
1  LP3  ; Load parameter 3
2  LP4  ; Load parameter 4
3  PLUS ; Add them
4  SP5  ; Store in parameter 5
5  RTN  ; Return
EOF
fi

echo "Running training workloads..."

# Train with various inputs
echo "Training code generator..."
if [ -f "../test_workload_1.bcpl" ]; then
    ./src/cg < ../test_workload_1.bcpl > /dev/null 2>&1 || echo "CG training completed with non-zero exit"
fi

echo "Training optimizer..."
if [ -f "../test_workload_2.ocode" ]; then
    ./src/op < ../test_workload_2.ocode > /dev/null 2>&1 || echo "OP training completed with non-zero exit"
fi

# Run existing test suite if available
if [ -f "../test_bcpl.sh" ]; then
    echo "Running existing test suite..."
    bash ../test_bcpl.sh > /dev/null 2>&1 || echo "Test suite completed"
fi

# Train with BCPL library if available
if [ -f "../src/blib.bcpl" ]; then
    echo "Training with BCPL library..."
    ./src/cg < ../src/blib.bcpl > /dev/null 2>&1 || echo "Library training completed"
fi

# Merge profile data
echo "Merging profile data..."
if ls bcpl_*.profraw >/dev/null 2>&1; then
    llvm-profdata merge -output=bcpl.profdata bcpl_*.profraw
    echo -e "${GREEN}Profile data merged: $(ls -lh bcpl.profdata | awk '{print $5}')${NC}"
else
    echo -e "${RED}No profile data generated!${NC}"
    exit 1
fi

cd ..

echo -e "${GREEN}Stage 2 complete: Profile data collected${NC}"

# =============================================================================
# STAGE 3: OPTIMIZED BUILD WITH PROFILE DATA
# =============================================================================

echo
echo -e "${BLUE}=== STAGE 3: Building optimized binary with profile data ===${NC}"

mkdir -p "${FINAL_DIR}"

# Advanced optimization flags with profile data
PGO_OPTS=(
    "-O3"
    "-flto=thin"
    "-fuse-ld=lld"
    "-fprofile-instr-use=${STAGE1_DIR}/bcpl.profdata"
    "-fvectorize"
    "-fslp-vectorize" 
    "-funroll-loops"
    "-ffp-contract=fast"
    "-fno-math-errno"
    "-fno-signed-zeros"
    "-falign-functions=64"
    "-falign-loops=64"
    "-falign-jumps=64"
    "-fno-semantic-interposition"
    "-fdata-sections"
    "-ffunction-sections"
    "-march=native"
    "-mtune=native"
    "-pipe"
)

LINKER_OPTS=(
    "-Wl,--gc-sections"
    "-Wl,-O2"
    "-Wl,--thinlto-jobs=$(nproc)"
)

ALL_OPTS="${PGO_OPTS[*]} ${LINKER_OPTS[*]}"

echo -e "${YELLOW}PGO optimization flags:${NC}"
echo "${ALL_OPTS}"
echo

# Configure PGO-optimized build
cmake -B "${FINAL_DIR}" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_C_FLAGS="${ALL_OPTS}" \
    -DCMAKE_CXX_FLAGS="${ALL_OPTS}" \
    -DENABLE_MAX_OPTIMIZATION=ON \
    -DENABLE_LTO=ON \
    -DENABLE_PGO=ON \
    -DPGO_PROFILE_DATA="${PWD}/${STAGE1_DIR}/bcpl.profdata" \
    .

# Build final optimized version
cmake --build "${FINAL_DIR}" --parallel $(nproc)

# =============================================================================
# VERIFICATION AND SUMMARY
# =============================================================================

if [ -f "${FINAL_DIR}/src/cg" ] && [ -f "${FINAL_DIR}/src/op" ]; then
    echo -e "${GREEN}PGO build successful!${NC}"
    echo "Final optimized binaries located in: ${FINAL_DIR}/src/"
    
    echo
    echo -e "${YELLOW}Binary sizes comparison:${NC}"
    echo "Stage 1 (instrumented):"
    ls -lh "${STAGE1_DIR}/src/cg" "${STAGE1_DIR}/src/op" | awk '{print "  " $9 ": " $5}'
    echo "Stage 3 (PGO optimized):"
    ls -lh "${FINAL_DIR}/src/cg" "${FINAL_DIR}/src/op" | awk '{print "  " $9 ": " $5}'
    
    echo
    echo -e "${YELLOW}PGO optimization summary:${NC}"
    echo "  - Profile data size: $(ls -lh ${STAGE1_DIR}/bcpl.profdata | awk '{print $5}')"
    echo "  - Optimization level: -O3 + PGO"
    echo "  - ThinLTO: Enabled"
    echo "  - Vectorization: Profile-guided"
    echo "  - Loop unrolling: Profile-guided"
    echo "  - Branch prediction: Optimized"
    echo "  - Function layout: Optimized"
    echo "  - Inlining decisions: Profile-guided"
    
    # Quick verification test
    echo
    echo -e "${YELLOW}Quick verification test:${NC}"
    if echo "// Test comment" | "${FINAL_DIR}/src/cg" >/dev/null 2>&1; then
        echo -e "${GREEN}✓ Code generator works${NC}"
    else
        echo -e "${YELLOW}⚠ Code generator test failed${NC}"
    fi
    
else
    echo -e "${RED}PGO build failed!${NC}"
    exit 1
fi

# Cleanup option
echo
read -p "Remove intermediate build directories? (y/N): " -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]; then
    echo "Cleaning up intermediate directories..."
    rm -rf "${STAGE1_DIR}" "${STAGE2_DIR}"
    echo "Cleanup complete."
fi

echo
echo -e "${GREEN}=== PGO BUILD COMPLETE ===${NC}"
echo "Optimized binaries: ${FINAL_DIR}/src/"
echo "To use the PGO-optimized binaries:"
echo "  export PATH=$(pwd)/${FINAL_DIR}/src:\$PATH"
echo
echo "PGO provides performance improvements through:"
echo "  - Better branch prediction"
echo "  - Optimized function layout"
echo "  - Profile-guided inlining"
echo "  - Hot/cold code separation"
