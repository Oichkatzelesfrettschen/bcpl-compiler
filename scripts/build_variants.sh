#!/bin/bash
# build_variants.sh - Build all optimization variants of BCPL compiler
# This script creates multiple optimized builds for performance comparison

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${GREEN}=== BCPL Compiler Build Variants ===${NC}"
echo "Building multiple optimization levels for performance comparison"
echo

# Check for required tools
command -v clang >/dev/null 2>&1 || { echo -e "${RED}Error: clang not found${NC}" >&2; exit 1; }

# Function to build a variant
build_variant() {
    local name="$1"
    local build_dir="$2"
    local flags="$3"
    local description="$4"
    
    echo -e "${BLUE}Building ${name}...${NC}"
    echo "Description: ${description}"
    echo "Flags: ${flags}"
    echo
    
    mkdir -p "${build_dir}"
    
    cmake -B "${build_dir}" \
        -DCMAKE_BUILD_TYPE=Release \
        -DCMAKE_C_COMPILER=clang \
        -DCMAKE_C_FLAGS="${flags}" \
        -DCMAKE_CXX_FLAGS="${flags}" \
        . >/dev/null
    
    cmake --build "${build_dir}" --parallel $(nproc) >/dev/null
    
    if [ -f "${build_dir}/src/cg" ] && [ -f "${build_dir}/src/op" ]; then
        echo -e "${GREEN}✓ ${name} build successful${NC}"
        return 0
    else
        echo -e "${RED}✗ ${name} build failed${NC}"
        return 1
    fi
}

# Function to get binary size
get_size() {
    local binary="$1"
    if [ -f "${binary}" ]; then
        ls -lh "${binary}" | awk '{print $5}'
    else
        echo "N/A"
    fi
}

# Function to run a quick benchmark
quick_benchmark() {
    local binary="$1"
    local name="$2"
    
    if [ ! -f "${binary}" ]; then
        echo "N/A"
        return
    fi
    
    # Create a simple test input
    echo "// Quick benchmark test" > /tmp/bench_test.bcpl
    
    # Time the execution (3 runs, take the best)
    local best_time=999999
    for i in {1..3}; do
        local time_result=$(timeout 5 time -p "${binary}" < /tmp/bench_test.bcpl 2>&1 >/dev/null | grep real | awk '{print $2}' || echo "999")
        if (( $(echo "$time_result < $best_time" | bc -l) )); then
            best_time=$time_result
        fi
    done
    
    rm -f /tmp/bench_test.bcpl
    echo "${best_time}s"
}

echo -e "${CYAN}=== Building All Variants ===${NC}"
echo

# =============================================================================
# BUILD VARIANTS
# =============================================================================

failed_builds=0
total_builds=0

# 1. Baseline build (-O2)
total_builds=$((total_builds + 1))
if ! build_variant "Baseline" "build_baseline" "-O2" "Standard release optimization"; then
    failed_builds=$((failed_builds + 1))
fi
echo

# 2. O3 build
total_builds=$((total_builds + 1))
if ! build_variant "O3" "build_O3" "-O3" "High optimization level"; then
    failed_builds=$((failed_builds + 1))
fi
echo

# 3. O3 with vectorization
total_builds=$((total_builds + 1))
if ! build_variant "O3+Vec" "build_O3_vec" "-O3 -fvectorize -fslp-vectorize -funroll-loops" "O3 with explicit vectorization"; then
    failed_builds=$((failed_builds + 1))
fi
echo

# 4. O3 with LTO
total_builds=$((total_builds + 1))
if ! build_variant "O3+LTO" "build_O3_lto" "-O3 -flto=thin -fuse-ld=lld" "O3 with Link-Time Optimization"; then
    failed_builds=$((failed_builds + 1))
fi
echo

# 5. Fast math build
total_builds=$((total_builds + 1))
if ! build_variant "O3+Fast" "build_O3_fast" "-O3 -ffast-math -fvectorize -funroll-loops" "O3 with fast math optimizations"; then
    failed_builds=$((failed_builds + 1))
fi
echo

# 6. Size-optimized build
total_builds=$((total_builds + 1))
if ! build_variant "Size" "build_size" "-Os -flto=thin -fdata-sections -ffunction-sections -Wl,--gc-sections" "Size-optimized build"; then
    failed_builds=$((failed_builds + 1))
fi
echo

# 7. Maximum performance (if not already built)
if [ ! -d "build_max_perf" ]; then
    echo -e "${BLUE}Building Maximum Performance variant...${NC}"
    if [ -f "build_max_performance.sh" ]; then
        if bash build_max_performance.sh >/dev/null 2>&1; then
            echo -e "${GREEN}✓ Maximum Performance build successful${NC}"
        else
            echo -e "${RED}✗ Maximum Performance build failed${NC}"
            failed_builds=$((failed_builds + 1))
        fi
        total_builds=$((total_builds + 1))
    fi
    echo
fi

# 8. Portable optimized (if not already built)
if [ ! -d "build_portable" ]; then
    echo -e "${BLUE}Building Portable Optimized variant...${NC}"
    if [ -f "build_portable_optimized.sh" ]; then
        if bash build_portable_optimized.sh >/dev/null 2>&1; then
            echo -e "${GREEN}✓ Portable Optimized build successful${NC}"
        else
            echo -e "${RED}✗ Portable Optimized build failed${NC}"
            failed_builds=$((failed_builds + 1))
        fi
        total_builds=$((total_builds + 1))
    fi
    echo
fi

# =============================================================================
# RESULTS SUMMARY
# =============================================================================

echo -e "${CYAN}=== Build Results Summary ===${NC}"
echo "Successful builds: $((total_builds - failed_builds))/${total_builds}"
echo

# Build comparison table
echo -e "${YELLOW}Build Variant Comparison:${NC}"
printf "%-15s %-10s %-10s %-12s %s\n" "Variant" "CG Size" "OP Size" "CG Time" "Description"
printf "%-15s %-10s %-10s %-12s %s\n" "---------------" "--------" "--------" "----------" "----------------------------------------"

variants=(
    "Baseline:build_baseline:Standard -O2 optimization"
    "O3:build_O3:High optimization level"
    "O3+Vec:build_O3_vec:O3 with vectorization"
    "O3+LTO:build_O3_lto:O3 with LTO"
    "O3+Fast:build_O3_fast:O3 with fast math"
    "Size:build_size:Size-optimized"
    "Max Perf:build_max_perf:Maximum performance"
    "Portable:build_portable:Portable optimized"
)

for variant in "${variants[@]}"; do
    IFS=':' read -r name dir desc <<< "$variant"
    
    if [ -d "$dir" ]; then
        cg_size=$(get_size "${dir}/src/cg")
        op_size=$(get_size "${dir}/src/op")
        cg_time=$(quick_benchmark "${dir}/src/cg" "$name")
        
        printf "%-15s %-10s %-10s %-12s %s\n" "$name" "$cg_size" "$op_size" "$cg_time" "$desc"
    else
        printf "%-15s %-10s %-10s %-12s %s\n" "$name" "N/A" "N/A" "N/A" "$desc (not built)"
    fi
done

echo

# Performance recommendations
echo -e "${YELLOW}Performance Recommendations:${NC}"
echo
echo "For development/debugging:"
echo "  → Use 'Baseline' build (-O2)"
echo
echo "For production deployment:"
echo "  → Use 'O3+LTO' or 'Max Perf' for best performance"
echo "  → Use 'Portable' for cross-platform deployment"
echo "  → Use 'Size' for memory-constrained environments"
echo
echo "For numerical computation:"
echo "  → Use 'O3+Fast' if IEEE compliance isn't critical"
echo

# Next steps
echo -e "${YELLOW}Next Steps:${NC}"
echo "1. Run comprehensive benchmarks:"
echo "   ./benchmark_variants.sh"
echo
echo "2. Build with Profile-Guided Optimization:"
echo "   ./build_pgo.sh"
echo
echo "3. Apply BOLT post-link optimization:"
echo "   ./build_bolt.sh"
echo

if [ $failed_builds -eq 0 ]; then
    echo -e "${GREEN}All builds completed successfully!${NC}"
    exit 0
else
    echo -e "${YELLOW}${failed_builds} build(s) failed. Check the error messages above.${NC}"
    exit 1
fi
