#!/bin/bash
# build_with_tools.sh - Build BCPL compiler with various analysis and development tools
# Usage: ./build_with_tools.sh [preset]

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

echo -e "${GREEN}=== BCPL Compiler Advanced Build System ===${NC}"
echo "Available presets: dev, ci, security, performance, analysis, fuzz"
echo

PRESET=${1:-dev}
BUILD_DIR="build_${PRESET}"

case $PRESET in
    "dev")
        echo -e "${BLUE}Development Build - Debug with sanitizers and static analysis${NC}"
        CMAKE_OPTIONS=(
            "-DCMAKE_BUILD_TYPE=Debug"
            "-DENABLE_ASAN=ON"
            "-DENABLE_UBSAN=ON"
            "-DENABLE_CLANG_TIDY=ON"
            "-DENABLE_DOCS=ON"
        )
        ;;
    
    "ci")
        echo -e "${CYAN}CI/CD Build - Coverage and comprehensive analysis${NC}"
        CMAKE_OPTIONS=(
            "-DCMAKE_BUILD_TYPE=RelWithDebInfo"
            "-DENABLE_COVERAGE=ON"
            "-DENABLE_CLANG_ANALYZER=ON"
            "-DENABLE_CPPCHECK=ON"
            "-DENABLE_DOCS=ON"
        )
        ;;
    
    "security")
        echo -e "${YELLOW}Security Audit Build - All sanitizers and hardening${NC}"
        CMAKE_OPTIONS=(
            "-DCMAKE_BUILD_TYPE=RelWithDebInfo"
            "-DENABLE_ASAN=ON"
            "-DENABLE_MSAN=ON"
            "-DENABLE_UBSAN=ON"
            "-DENABLE_CFI=ON"
            "-DENABLE_CLANG_ANALYZER=ON"
        )
        ;;
    
    "performance")
        echo -e "${GREEN}Performance Build - Optimized with profiling support${NC}"
        CMAKE_OPTIONS=(
            "-DCMAKE_BUILD_TYPE=Release"
            "-DENABLE_THIN_LTO=ON"
            "-DENABLE_VTUNE=ON"
            "-DENABLE_BENCHMARKS=ON"
        )
        ;;
    
    "analysis")
        echo -e "${CYAN}Deep Analysis Build - All static analysis tools${NC}"
        CMAKE_OPTIONS=(
            "-DCMAKE_BUILD_TYPE=Debug"
            "-DENABLE_CLANG_TIDY=ON"
            "-DENABLE_CLANG_ANALYZER=ON"
            "-DENABLE_CPPCHECK=ON"
            "-DENABLE_VALGRIND=ON"
            "-DENABLE_COVERAGE=ON"
        )
        ;;
    
    "fuzz")
        echo -e "${RED}Fuzzing Build - Fuzzer with sanitizers${NC}"
        CMAKE_OPTIONS=(
            "-DCMAKE_BUILD_TYPE=Debug"
            "-DENABLE_FUZZING=ON"
            "-DENABLE_ASAN=ON"
            "-DENABLE_UBSAN=ON"
        )
        ;;
    
    *)
        echo -e "${RED}Unknown preset: $PRESET${NC}"
        echo "Available: dev, ci, security, performance, analysis, fuzz"
        exit 1
        ;;
esac

# Check for required tools based on options
check_tools() {
    if [[ " ${CMAKE_OPTIONS[*]} " =~ " -DENABLE_COVERAGE=ON " ]]; then
        command -v lcov >/dev/null 2>&1 || echo -e "${YELLOW}Warning: lcov not found, install with: brew install lcov${NC}"
    fi
    
    if [[ " ${CMAKE_OPTIONS[*]} " =~ " -DENABLE_VALGRIND=ON " ]]; then
        command -v valgrind >/dev/null 2>&1 || echo -e "${YELLOW}Warning: valgrind not found, install with: brew install valgrind${NC}"
    fi
    
    if [[ " ${CMAKE_OPTIONS[*]} " =~ " -DENABLE_CLANG_TIDY=ON " ]]; then
        command -v clang-tidy >/dev/null 2>&1 || echo -e "${YELLOW}Warning: clang-tidy not found, install with: brew install llvm${NC}"
    fi
    
    if [[ " ${CMAKE_OPTIONS[*]} " =~ " -DENABLE_CPPCHECK=ON " ]]; then
        command -v cppcheck >/dev/null 2>&1 || echo -e "${YELLOW}Warning: cppcheck not found, install with: brew install cppcheck${NC}"
    fi
}

check_tools

# Clean and create build directory
echo -e "${BLUE}Cleaning and creating build directory: ${BUILD_DIR}${NC}"
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"

# Configure with CMake
echo -e "${BLUE}Configuring with CMake...${NC}"
echo "Options: ${CMAKE_OPTIONS[*]}"
echo

cmake -B "${BUILD_DIR}" "${CMAKE_OPTIONS[@]}" .

# Build
echo -e "${BLUE}Building...${NC}"
cmake --build "${BUILD_DIR}" --parallel $(sysctl -n hw.ncpu 2>/dev/null || nproc 2>/dev/null || echo 4)

# Run appropriate targets based on configuration
if [[ " ${CMAKE_OPTIONS[*]} " =~ " -DENABLE_COVERAGE=ON " ]]; then
    echo -e "${CYAN}Running tests and generating coverage report...${NC}"
    cd "${BUILD_DIR}"
    ctest --output-on-failure
    make coverage 2>/dev/null || true
    cd ..
fi

if [[ " ${CMAKE_OPTIONS[*]} " =~ " -DENABLE_VALGRIND=ON " ]]; then
    echo -e "${CYAN}Running Valgrind analysis...${NC}"
    cd "${BUILD_DIR}"
    make valgrind 2>/dev/null || true
    cd ..
fi

if [[ " ${CMAKE_OPTIONS[*]} " =~ " -DENABLE_CPPCHECK=ON " ]]; then
    echo -e "${CYAN}Running Cppcheck analysis...${NC}"
    cd "${BUILD_DIR}"
    make cppcheck 2>/dev/null || true
    cd ..
fi

echo -e "${GREEN}✓ Build completed successfully!${NC}"
echo -e "${BLUE}Build artifacts in: ${BUILD_DIR}${NC}"

# Show next steps
echo
echo -e "${YELLOW}Next steps:${NC}"
case $PRESET in
    "dev")
        echo "• Run tests: cd ${BUILD_DIR} && ctest"
        echo "• View docs: open ${BUILD_DIR}/docs/html/index.html"
        ;;
    "ci")
        echo "• View coverage: open ${BUILD_DIR}/coverage_html/index.html"
        echo "• Check docs: open ${BUILD_DIR}/docs/html/index.html"
        ;;
    "security")
        echo "• Run with sanitizers: ./${BUILD_DIR}/test_bcpl_modern"
        echo "• The binary has all security features enabled"
        ;;
    "performance")
        echo "• Run benchmarks: ./${BUILD_DIR}/bcpl_benchmarks"
        echo "• Profile with VTune: vtune -collect hotspots ./${BUILD_DIR}/test_bcpl_modern"
        ;;
    "analysis")
        echo "• Check coverage: open ${BUILD_DIR}/coverage_html/index.html"
        echo "• All static analysis reports generated"
        ;;
    "fuzz")
        echo "• Start fuzzing: ./${BUILD_DIR}/bcpl_fuzzer corpus/"
        echo "• Create corpus directory first: mkdir -p corpus"
        ;;
esac
