#!/bin/bash
# benchmark_variants.sh - Comprehensive benchmarking of BCPL compiler variants
# This script runs performance tests across all built optimization variants

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${GREEN}=== BCPL Compiler Performance Benchmark ===${NC}"
echo "Comprehensive performance comparison across optimization variants"
echo

# Check for required tools
command -v time >/dev/null 2>&1 || { echo -e "${RED}Error: time command not found${NC}" >&2; exit 1; }
command -v bc >/dev/null 2>&1 || { echo -e "${RED}Error: bc calculator not found${NC}" >&2; exit 1; }

# Configuration
WARMUP_RUNS=2
BENCHMARK_RUNS=5
RESULTS_DIR="benchmark_results"
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")

# Create results directory
mkdir -p "${RESULTS_DIR}"

# Find all build variants
VARIANTS=()
for dir in build_*; do
    if [ -d "$dir" ] && [ -f "$dir/src/cg" ] && [ -f "$dir/src/op" ]; then
        VARIANTS+=("$dir")
    fi
done

if [ ${#VARIANTS[@]} -eq 0 ]; then
    echo -e "${RED}No build variants found! Run build_variants.sh first.${NC}"
    exit 1
fi

echo -e "${CYAN}Found ${#VARIANTS[@]} build variants:${NC}"
for variant in "${VARIANTS[@]}"; do
    echo "  - $variant"
done
echo

# =============================================================================
# CREATE BENCHMARK WORKLOADS
# =============================================================================

echo -e "${BLUE}Creating benchmark workloads...${NC}"

# Create test directory
TEST_DIR="benchmark_tests"
mkdir -p "${TEST_DIR}"

# Small test (quick compilation)
cat > "${TEST_DIR}/small.bcpl" << 'EOF'
// Small BCPL program for quick compilation test
GET "LIBHDR"

LET start() = VALOF
{
    LET sum = 0
    FOR i = 1 TO 100 DO
        sum := sum + i
    writef("Sum: %n*n", sum)
    RESULTIS 0
}
EOF

# Medium test (moderate complexity)
cat > "${TEST_DIR}/medium.bcpl" << 'EOF'
// Medium BCPL program with functions and loops
GET "LIBHDR"

LET start() = VALOF
{
    LET result = 0
    FOR i = 1 TO 50 DO
    {
        result := result + factorial(i MOD 10)
        result := result + fibonacci(i MOD 15)
    }
    writef("Result: %n*n", result)
    RESULTIS 0
}

AND factorial(n) = VALOF
{
    LET result = 1
    FOR i = 1 TO n DO
        result := result * i
    RESULTIS result
}

AND fibonacci(n) = n <= 1 -> n, fibonacci(n-1) + fibonacci(n-2)

AND gcd(a, b) = b = 0 -> a, gcd(b, a MOD b)

AND isprime(n) = VALOF
{
    IF n <= 1 THEN RESULTIS FALSE
    IF n <= 3 THEN RESULTIS TRUE
    IF n MOD 2 = 0 OR n MOD 3 = 0 THEN RESULTIS FALSE
    
    LET i = 5
    WHILE i * i <= n DO
    {
        IF n MOD i = 0 OR n MOD (i + 2) = 0 THEN
            RESULTIS FALSE
        i := i + 6
    }
    RESULTIS TRUE
}
EOF

# Large test (complex program)
cat > "${TEST_DIR}/large.bcpl" << 'EOF'
// Large BCPL program with complex algorithms
GET "LIBHDR"

MANIFEST
{
    MAXSIZE = 1000
}

LET start() = VALOF
{
    LET vector = getvec(MAXSIZE)
    LET matrix = getvec(MAXSIZE)
    
    // Initialize data
    FOR i = 0 TO MAXSIZE-1 DO
    {
        vector!i := i * 17 MOD 101
        matrix!i := i * 23 MOD 97
    }
    
    // Perform various computations
    LET result1 = bubblesort(vector, MAXSIZE/10)
    LET result2 = matrixmult(matrix, vector, MAXSIZE/10)
    LET result3 = primesieve(MAXSIZE/10)
    
    writef("Results: %n, %n, %n*n", result1, result2, result3)
    
    freevec(vector)
    freevec(matrix)
    RESULTIS 0
}

AND bubblesort(arr, n) = VALOF
{
    FOR i = 0 TO n-1 DO
    {
        FOR j = 0 TO n-2-i DO
        {
            IF arr!j > arr!(j+1) THEN
            {
                LET temp = arr!j
                arr!j := arr!(j+1)
                arr!(j+1) := temp
            }
        }
    }
    RESULTIS arr!0
}

AND matrixmult(a, b, n) = VALOF
{
    LET sum = 0
    FOR i = 0 TO n-1 DO
        FOR j = 0 TO n-1 DO
            sum := sum + (a!i * b!j)
    RESULTIS sum
}

AND primesieve(n) = VALOF
{
    LET sieve = getvec(n)
    LET count = 0
    
    FOR i = 0 TO n-1 DO
        sieve!i := TRUE
        
    FOR i = 2 TO n-1 DO
    {
        IF sieve!i THEN
        {
            count := count + 1
            FOR j = i*i TO n-1 BY i DO
                sieve!j := FALSE
        }
    }
    
    freevec(sieve)
    RESULTIS count
}
EOF

# Standard library test (if available)
if [ -f "src/blib.bcpl" ]; then
    cp "src/blib.bcpl" "${TEST_DIR}/stdlib.bcpl"
    echo "  - stdlib.bcpl (BCPL standard library)"
fi

echo "Created benchmark workloads:"
echo "  - small.bcpl (simple program)"
echo "  - medium.bcpl (moderate complexity)"
echo "  - large.bcpl (complex algorithms)"

# =============================================================================
# BENCHMARK FUNCTIONS
# =============================================================================

# Function to run a single benchmark
run_benchmark() {
    local binary="$1"
    local test_file="$2"
    local variant_name="$3"
    local test_name="$4"
    
    if [ ! -f "$binary" ]; then
        echo "N/A,N/A,N/A,N/A"
        return
    fi
    
    # Warmup runs
    for ((i=1; i<=WARMUP_RUNS; i++)); do
        timeout 30 "$binary" < "$test_file" >/dev/null 2>&1 || true
    done
    
    # Benchmark runs
    local times=()
    local total_time=0
    local success_count=0
    
    for ((i=1; i<=BENCHMARK_RUNS; i++)); do
        local start_time=$(date +%s.%N)
        
        if timeout 30 "$binary" < "$test_file" >/dev/null 2>&1; then
            local end_time=$(date +%s.%N)
            local elapsed=$(echo "$end_time - $start_time" | bc -l)
            times+=("$elapsed")
            total_time=$(echo "$total_time + $elapsed" | bc -l)
            success_count=$((success_count + 1))
        fi
    done
    
    if [ $success_count -eq 0 ]; then
        echo "N/A,N/A,N/A,N/A"
        return
    fi
    
    # Calculate statistics
    local avg_time=$(echo "scale=6; $total_time / $success_count" | bc -l)
    
    # Find min and max
    local min_time=${times[0]}
    local max_time=${times[0]}
    
    for time in "${times[@]}"; do
        if (( $(echo "$time < $min_time" | bc -l) )); then
            min_time=$time
        fi
        if (( $(echo "$time > $max_time" | bc -l) )); then
            max_time=$time
        fi
    done
    
    # Calculate standard deviation
    local variance=0
    for time in "${times[@]}"; do
        local diff=$(echo "$time - $avg_time" | bc -l)
        local sq_diff=$(echo "$diff * $diff" | bc -l)
        variance=$(echo "$variance + $sq_diff" | bc -l)
    done
    variance=$(echo "scale=6; $variance / $success_count" | bc -l)
    local std_dev=$(echo "scale=6; sqrt($variance)" | bc -l)
    
    echo "$avg_time,$min_time,$max_time,$std_dev"
}

# =============================================================================
# RUN BENCHMARKS
# =============================================================================

echo
echo -e "${BLUE}Running benchmarks (${WARMUP_RUNS} warmup + ${BENCHMARK_RUNS} measurement runs per test)...${NC}"

# Results file
RESULTS_FILE="${RESULTS_DIR}/benchmark_${TIMESTAMP}.csv"

# CSV header
echo "Variant,Test,Binary,Avg_Time,Min_Time,Max_Time,Std_Dev" > "$RESULTS_FILE"

# Test files
TESTS=(
    "small.bcpl:Small Test"
    "medium.bcpl:Medium Test" 
    "large.bcpl:Large Test"
)

if [ -f "${TEST_DIR}/stdlib.bcpl" ]; then
    TESTS+=("stdlib.bcpl:Stdlib Test")
fi

# Progress tracking
total_tests=$((${#VARIANTS[@]} * ${#TESTS[@]} * 2))  # 2 binaries per variant
current_test=0

for variant in "${VARIANTS[@]}"; do
    variant_name=$(basename "$variant")
    echo
    echo -e "${CYAN}Testing variant: ${variant_name}${NC}"
    
    for test in "${TESTS[@]}"; do
        IFS=':' read -r test_file test_name <<< "$test"
        test_path="${TEST_DIR}/${test_file}"
        
        if [ ! -f "$test_path" ]; then
            continue
        fi
        
        echo -n "  ${test_name}..."
        
        # Test code generator
        current_test=$((current_test + 1))
        echo -n " CG($current_test/$total_tests)"
        cg_result=$(run_benchmark "$variant/src/cg" "$test_path" "$variant_name" "$test_name")
        echo "$variant_name,$test_name,cg,$cg_result" >> "$RESULTS_FILE"
        
        # Test optimizer  
        current_test=$((current_test + 1))
        echo -n " OP($current_test/$total_tests)"
        op_result=$(run_benchmark "$variant/src/op" "$test_path" "$variant_name" "$test_name")
        echo "$variant_name,$test_name,op,$op_result" >> "$RESULTS_FILE"
        
        echo " ✓"
    done
done

# =============================================================================
# ANALYZE RESULTS
# =============================================================================

echo
echo -e "${BLUE}Analyzing results...${NC}"

# Create summary report
SUMMARY_FILE="${RESULTS_DIR}/summary_${TIMESTAMP}.txt"

cat > "$SUMMARY_FILE" << EOF
BCPL Compiler Performance Benchmark Summary
==========================================
Timestamp: $(date)
Test Configuration:
  - Warmup runs: ${WARMUP_RUNS}
  - Benchmark runs: ${BENCHMARK_RUNS}
  - Variants tested: ${#VARIANTS[@]}
  - Tests per variant: ${#TESTS[@]}

EOF

# Generate summary table
echo -e "${YELLOW}Performance Summary:${NC}"
echo
printf "%-20s %-12s %-8s %-12s %-12s %-12s\n" "Variant" "Test" "Binary" "Avg (s)" "Min (s)" "Max (s)"
printf "%-20s %-12s %-8s %-12s %-12s %-12s\n" "--------------------" "------------" "--------" "------------" "------------" "------------"

# Parse and display results
while IFS=',' read -r variant test binary avg_time min_time max_time std_dev; do
    if [ "$variant" != "Variant" ]; then  # Skip header
        if [ "$avg_time" != "N/A" ]; then
            avg_formatted=$(printf "%.6f" "$avg_time")
            min_formatted=$(printf "%.6f" "$min_time") 
            max_formatted=$(printf "%.6f" "$max_time")
        else
            avg_formatted="N/A"
            min_formatted="N/A"
            max_formatted="N/A"
        fi
        
        printf "%-20s %-12s %-8s %-12s %-12s %-12s\n" "$variant" "$test" "$binary" "$avg_formatted" "$min_formatted" "$max_formatted"
    fi
done < "$RESULTS_FILE"

# Find fastest variants
echo >> "$SUMMARY_FILE"
echo "Fastest Variants by Test:" >> "$SUMMARY_FILE"
echo "========================" >> "$SUMMARY_FILE"

for test in "${TESTS[@]}"; do
    IFS=':' read -r test_file test_name <<< "$test"
    echo >> "$SUMMARY_FILE"
    echo "${test_name}:" >> "$SUMMARY_FILE"
    
    # Find fastest CG
    fastest_cg=$(awk -F',' -v test="$test_name" '$2==test && $3=="cg" && $4!="N/A" {print $4 " " $1}' "$RESULTS_FILE" | sort -n | head -1)
    if [ -n "$fastest_cg" ]; then
        echo "  Fastest CG: $fastest_cg" >> "$SUMMARY_FILE"
    fi
    
    # Find fastest OP
    fastest_op=$(awk -F',' -v test="$test_name" '$2==test && $3=="op" && $4!="N/A" {print $4 " " $1}' "$RESULTS_FILE" | sort -n | head -1)
    if [ -n "$fastest_op" ]; then
        echo "  Fastest OP: $fastest_op" >> "$SUMMARY_FILE"
    fi
done

echo
echo -e "${GREEN}Benchmark complete!${NC}"
echo "Results saved to:"
echo "  - Raw data: $RESULTS_FILE"
echo "  - Summary: $SUMMARY_FILE"
echo
echo -e "${YELLOW}Quick Analysis:${NC}"

# Show top performers
echo "Fastest variants overall:"
echo "Code Generator:"
awk -F',' '$3=="cg" && $4!="N/A" {total+=$4; count++; print $4 " " $1}' "$RESULTS_FILE" | sort -n | head -3 | nl
echo "Optimizer:"
awk -F',' '$3=="op" && $4!="N/A" {total+=$4; count++; print $4 " " $1}' "$RESULTS_FILE" | sort -n | head -3 | nl

echo
echo -e "${YELLOW}Recommendations:${NC}"
echo "For best overall performance, use one of the top-performing variants."
echo "Consider build time vs. runtime performance trade-offs."
echo "Run additional workload-specific benchmarks for production deployment."
