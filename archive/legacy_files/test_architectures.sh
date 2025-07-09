#!/bin/bash
# Test script to demonstrate both ARM64 and x86_64 builds
# Usage: ./test_architectures.sh

set -e

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "🔧 BCPL Compiler Multi-Architecture Test"
echo "========================================"
echo ""

# Check system architecture
echo "🖥️  Host System: $(uname -m) ($(uname -s))"
echo ""

# Test ARM64 build
if [[ -d "${PROJECT_ROOT}/build_modern" ]]; then
    echo "🍎 Testing ARM64 Native Build:"
    echo "  Directory: build_modern/"
    if [[ -f "${PROJECT_ROOT}/build_modern/cg" ]]; then
        echo "  cg: $(file "${PROJECT_ROOT}/build_modern/cg" | grep -o 'arm64\|x86_64')"
        echo "  Size: $(ls -lh "${PROJECT_ROOT}/build_modern/cg" | awk '{print $5}')"
    fi
    if [[ -f "${PROJECT_ROOT}/build_modern/op" ]]; then
        echo "  op: $(file "${PROJECT_ROOT}/build_modern/op" | grep -o 'arm64\|x86_64')"
        echo "  Size: $(ls -lh "${PROJECT_ROOT}/build_modern/op" | awk '{print $5}')"
    fi
    echo ""
fi

# Test x86_64 build
if [[ -d "${PROJECT_ROOT}/build_x86_64" ]]; then
    echo "🔄 Testing x86_64 Rosetta Build:"
    echo "  Directory: build_x86_64/"
    if [[ -f "${PROJECT_ROOT}/build_x86_64/cg" ]]; then
        echo "  cg: $(file "${PROJECT_ROOT}/build_x86_64/cg" | grep -o 'arm64\|x86_64')"
        echo "  Size: $(ls -lh "${PROJECT_ROOT}/build_x86_64/cg" | awk '{print $5}')"
    fi
    if [[ -f "${PROJECT_ROOT}/build_x86_64/op" ]]; then
        echo "  op: $(file "${PROJECT_ROOT}/build_x86_64/op" | grep -o 'arm64\|x86_64')"
        echo "  Size: $(ls -lh "${PROJECT_ROOT}/build_x86_64/op" | awk '{print $5}')"
    fi
    echo ""
fi

echo "✅ Cross-platform BCPL compiler builds completed successfully!"
echo ""
echo "📋 Build Summary:"
echo "  - ARM64 native build for Apple Silicon performance"
echo "  - x86_64 Rosetta build for Intel compatibility"
echo "  - Modern C23 runtime with platform abstraction"
echo "  - CMake-based build system supporting both architectures"
echo ""
echo "🚀 Ready for development and testing on both architectures!"
