#!/bin/bash
# BCPL Compiler Architecture Wrapper
# Usage: ./bcpl_wrapper.sh [arm64|x86_64] [cg|op] [args...]

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ARCH="${1:-native}"
TOOL="${2:-cg}"

if [[ $# -lt 2 ]]; then
    echo "🔧 BCPL Compiler Multi-Architecture Wrapper"
    echo "Usage: $0 [arch] [tool] [args...]"
    echo ""
    echo "Architectures:"
    echo "  arm64    - Use ARM64 native build (build_modern/)"
    echo "  x86_64   - Use x86_64 Rosetta build (build_x86_64/)"
    echo "  native   - Use ARM64 (default)"
    echo ""
    echo "Tools:"
    echo "  cg       - Code generator"
    echo "  op       - Object processor"
    echo ""
    echo "Examples:"
    echo "  $0 arm64 cg input.bcpl"
    echo "  $0 x86_64 op object.o"
    echo "  $0 native cg --version"
    exit 1
fi

# Shift to get remaining arguments
shift 2

case "$ARCH" in
    "arm64"|"native")
        BUILD_DIR="${PROJECT_ROOT}/build_modern"
        EXEC_PREFIX=""
        ;;
    "x86_64")
        BUILD_DIR="${PROJECT_ROOT}/build_x86_64"
        EXEC_PREFIX="arch -x86_64"
        ;;
    *)
        echo "❌ Unknown architecture: $ARCH"
        echo "Use: arm64, x86_64, or native"
        exit 1
        ;;
esac

EXECUTABLE="${BUILD_DIR}/${TOOL}"

if [[ ! -f "$EXECUTABLE" ]]; then
    echo "❌ Executable not found: $EXECUTABLE"
    echo "   Run the appropriate build script first:"
    if [[ "$ARCH" == "x86_64" ]]; then
        echo "   ./build_x86_64.sh"
    else
        echo "   cd src && cmake . && make"
    fi
    exit 1
fi

echo "🚀 Running $TOOL ($ARCH): $EXECUTABLE"
exec $EXEC_PREFIX "$EXECUTABLE" "$@"
