#!/bin/bash
# Simple verification script that avoids hanging
# Checks build outputs without executing potentially hanging binaries

echo "🔍 BCPL Build Verification (Non-hanging)"
echo "========================================"
echo ""

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "📂 Current directory: ${PROJECT_ROOT}"
echo "🖥️  Host architecture: $(uname -m)"
echo ""

# Check ARM64 build
echo "🍎 ARM64 Build Status:"
if [[ -d "${PROJECT_ROOT}/build_modern" ]]; then
    echo "  ✓ Build directory exists: build_modern/"
    cd "${PROJECT_ROOT}/build_modern"
    for binary in cg op; do
        if [[ -f "$binary" ]]; then
            arch=$(file "$binary" | grep -o 'arm64\|x86_64')
            size=$(ls -lh "$binary" | awk '{print $5}')
            echo "  ✓ $binary: $arch ($size)"
        else
            echo "  ❌ $binary: not found"
        fi
    done
    cd "${PROJECT_ROOT}"
else
    echo "  ❌ build_modern/ directory not found"
fi
echo ""

# Check x86_64 build
echo "🔄 x86_64 Build Status:"
if [[ -d "${PROJECT_ROOT}/build_x86_64" ]]; then
    echo "  ✓ Build directory exists: build_x86_64/"
    cd "${PROJECT_ROOT}/build_x86_64"
    for binary in cg op; do
        if [[ -f "$binary" ]]; then
            arch=$(file "$binary" | grep -o 'arm64\|x86_64')
            size=$(ls -lh "$binary" | awk '{print $5}')
            echo "  ✓ $binary: $arch ($size)"
        else
            echo "  ❌ $binary: not found"
        fi
    done
    cd "${PROJECT_ROOT}"
else
    echo "  ❌ build_x86_64/ directory not found"
fi
echo ""

# Check x86_64 Homebrew tools
echo "🛠️  x86_64 Rosetta Tools:"
if arch -x86_64 /usr/local/bin/cmake --version >/dev/null 2>&1; then
    cmake_version=$(arch -x86_64 /usr/local/bin/cmake --version | head -1)
    echo "  ✓ CMake: $cmake_version"
else
    echo "  ❌ x86_64 CMake not available"
fi

if arch -x86_64 /usr/local/bin/gmake --version >/dev/null 2>&1; then
    gmake_version=$(arch -x86_64 /usr/local/bin/gmake --version | head -1)
    echo "  ✓ GNU Make: $gmake_version"
else
    echo "  ❌ x86_64 GNU Make not available"
fi
echo ""

echo "✅ Verification complete!"
echo ""
echo "💡 To build x86_64 version:"
echo "   ./build.sh Release x86_64"
echo ""
echo "💡 To test without hanging:"
echo "   Use file/lipo commands instead of executing binaries"
