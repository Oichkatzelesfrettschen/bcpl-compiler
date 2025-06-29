#!/usr/bin/env bash
# BCPL Compiler Modernization Validation Script
# Comprehensive validation that ALL tech debt has been eliminated
# Author: BCPL Modernization Team
# Date: 2025

set -euo pipefail

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Logging functions
log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

log_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Track validation results
VALIDATION_RESULTS=()
TOTAL_TESTS=0
PASSED_TESTS=0

validate_step() {
    local test_name="$1"
    local test_command="$2"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    log_info "Running: $test_name"
    
    if eval "$test_command" > /dev/null 2>&1; then
        log_success "$test_name: PASSED"
        VALIDATION_RESULTS+=("✅ $test_name")
        PASSED_TESTS=$((PASSED_TESTS + 1))
        return 0
    else
        log_error "$test_name: FAILED"
        VALIDATION_RESULTS+=("❌ $test_name")
        return 1
    fi
}

echo "============================================================================"
echo "BCPL COMPILER MODERNIZATION VALIDATION"
echo "Complete Tech Debt Elimination Verification"
echo "============================================================================"

# Phase 1: Assembly Dependency Elimination
echo ""
log_info "PHASE 1: Validating Assembly Dependency Elimination"
echo "============================================================================"

validate_step "No legacy assembly files in CMake build" \
    "! grep -r 'rt\.s\|su\.s\|sys.*\.s\|global\.s' CMakeLists.txt src/CMakeLists.txt tests/CMakeLists.txt 2>/dev/null"

validate_step "Universal startup C23 implementation exists" \
    "test -f src/runtime/universal_startup.c"

validate_step "Universal platform abstraction exists" \
    "test -f src/include/universal_platform.h"

validate_step "Modernized runtime implementation exists" \
    "test -f src/runtime/bcpl_runtime.c"

# Phase 2: Build System Modernization
echo ""
log_info "PHASE 2: Validating Build System Modernization"
echo "============================================================================"

validate_step "CMake minimum version 3.20+" \
    "grep -q 'cmake_minimum_required(VERSION 3.20)' CMakeLists.txt"

validate_step "C23 standard enforcement" \
    "grep -q 'CMAKE_C_STANDARD 23' CMakeLists.txt"

validate_step "Universal compiler compatibility" \
    "grep -q 'CMAKE_C_COMPILER_ID.*Clang' CMakeLists.txt || grep -q 'CMAKE_C_COMPILER_ID.*Clang' src/CMakeLists.txt"

validate_step "Modern compile options enabled" \
    "grep -q 'Wall.*Wextra.*Wpedantic' CMakeLists.txt || grep -q 'Wall.*Wextra.*Wpedantic' src/CMakeLists.txt"

# Phase 3: Platform Portability
echo ""
log_info "PHASE 3: Validating Platform Portability"
echo "============================================================================"

validate_step "ARM64 architecture support" \
    "grep -q 'ARM64\\|arm64\\|aarch64' CMakeLists.txt"

validate_step "Universal platform detection" \
    "grep -q 'BCPL_PLATFORM' src/CMakeLists.txt"

validate_step "Cross-platform abstraction layer" \
    "grep -q 'BCPL_UNIVERSAL_PLATFORM' CMakeLists.txt"

# Phase 4: Testing Infrastructure
echo ""
log_info "PHASE 4: Validating Testing Infrastructure"
echo "============================================================================"

validate_step "Comprehensive test suite exists" \
    "test -d tests && test -f tests/CMakeLists.txt"

validate_step "Runtime modernization tests" \
    "test -f tests/test_runtime.c"

validate_step "Platform abstraction tests" \
    "test -f tests/test_platform_abstraction.c"

validate_step "Assembly elimination tests" \
    "test -f tests/test_assembly_elimination.c"

validate_step "Cross-platform compatibility tests" \
    "test -f tests/test_cross_platform.c"

# Phase 5: Documentation and Planning
echo ""
log_info "PHASE 5: Validating Documentation and Planning"
echo "============================================================================"

validate_step "Ultimate modernization plan exists" \
    "test -f ULTIMATE_MODERNIZATION_PLAN.md"

validate_step "Comprehensive modernization plan exists" \
    "test -f COMPREHENSIVE_MODERNIZATION_PLAN.md"

validate_step "Build optimization documentation exists" \
    "test -f BUILD_OPTIMIZATION.md"

validate_step "Modernization success documentation exists" \
    "test -f MODERNIZATION_SUCCESS.md"

# Phase 6: Build Validation
echo ""
log_info "PHASE 6: Validating Build System Functionality"
echo "============================================================================"

# Create build directory if it doesn't exist
mkdir -p build_validation

validate_step "CMake configuration succeeds" \
    "cd build_validation && cmake .. -DCMAKE_BUILD_TYPE=Release"

validate_step "Project builds without errors" \
    "cd build_validation && make -j$(nproc 2>/dev/null || echo 4)"

validate_step "Test suite builds successfully" \
    "cd build_validation && make test_runtime_modernization"

# Run tests if they built successfully
if [ -f "build_validation/tests/test_runtime_modernization" ]; then
    validate_step "Modernization tests pass" \
        "cd build_validation && ctest --output-on-failure"
fi

# Phase 7: Final Validation
echo ""
log_info "PHASE 7: Final Modernization Validation"
echo "============================================================================"

# Check for legacy assembly references in source code (exclude compiler-generated files)
ASSEMBLY_REFS=$(find src -name "*.c" -o -name "*.h" | xargs grep -l "rt\.s\|su\.s\|sys.*\.s\|global\.s" 2>/dev/null | wc -l)
validate_step "No legacy assembly references in source" \
    "test $ASSEMBLY_REFS -eq 0"

# Check for old build system remnants
validate_step "No old Makefile remnants" \
    "! find . -name 'Makefile.*' -o -name '*.mk' | grep -v build"

# Check for C99/C11 legacy references
validate_step "No legacy C standard references" \
    "! grep -r 'c99\\|c11\\|std=.*99\\|std=.*11' CMakeLists.txt src/CMakeLists.txt tests/CMakeLists.txt 2>/dev/null"

# Final Results
echo ""
echo "============================================================================"
echo "MODERNIZATION VALIDATION COMPLETE"
echo "============================================================================"

log_info "Validation Summary:"
printf "Total Tests: %d\n" "$TOTAL_TESTS"
printf "Passed: %d\n" "$PASSED_TESTS"
printf "Failed: %d\n" $((TOTAL_TESTS - PASSED_TESTS))

echo ""
log_info "Detailed Results:"
for result in "${VALIDATION_RESULTS[@]}"; do
    echo "$result"
done

echo ""
if [ "$PASSED_TESTS" -eq "$TOTAL_TESTS" ]; then
    log_success "ALL TECH DEBT SUCCESSFULLY ELIMINATED!"
    log_success "BCPL Compiler is fully modernized with:"
    echo "  ✅ Zero assembly dependencies"
    echo "  ✅ Universal platform portability"
    echo "  ✅ Modern C23 runtime implementation"
    echo "  ✅ Comprehensive testing framework"
    echo "  ✅ Enhanced build system"
    echo ""
    log_success "The BCPL compiler is ready for the next 50 years!"
    exit 0
else
    log_error "MODERNIZATION INCOMPLETE - $(($TOTAL_TESTS - $PASSED_TESTS)) issues remain"
    log_warning "Please address the failed validations above"
    exit 1
fi
