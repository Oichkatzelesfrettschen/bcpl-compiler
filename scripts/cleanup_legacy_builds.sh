#!/bin/bash
# cleanup_legacy_builds.sh - Clean up the build directory chaos

echo "🧹 Cleaning up legacy build directories..."

# Create archive directory for important legacy builds
mkdir -p archive/legacy_builds

# List current build directories
echo "Current build directories:"
find . -maxdepth 1 -name "build*" -type d | sort

echo ""
echo "Moving legacy builds to archive..."

# Move obviously legacy/test builds to archive
for dir in build_32bit build_test build_audit build_portable build_c build_make build_arm64_static; do
    if [ -d "$dir" ]; then
        echo "  Moving $dir to archive/legacy_builds/"
        mv "$dir" archive/legacy_builds/
    fi
done

# Keep only essential builds and rename them properly
if [ -d "build_Debug" ]; then
    echo "  Renaming build_Debug to build/debug_legacy"
    mkdir -p build
    mv build_Debug build/debug_legacy
fi

if [ -d "build_Release" ]; then
    echo "  Renaming build_Release to build/release_legacy"
    mkdir -p build
    mv build_Release build/release_legacy
fi

if [ -d "build_modern" ]; then
    echo "  Renaming build_modern to build/modern_legacy"
    mkdir -p build
    mv build_modern build/modern_legacy
fi

# Move builds directory content
if [ -d "builds" ]; then
    echo "  Moving builds/* to archive/legacy_builds/"
    mv builds/* archive/legacy_builds/ 2>/dev/null || true
    rmdir builds 2>/dev/null || true
fi

# Show final state
echo ""
echo "✅ Cleanup complete. Remaining structure:"
echo "📁 build/ (for new CMake presets)"
ls -la build/ 2>/dev/null || echo "  (empty - ready for new builds)"
echo ""
echo "📁 archive/legacy_builds/ (archived old builds)"
ls -la archive/legacy_builds/ 2>/dev/null || echo "  (no legacy builds found)"

echo ""
echo "🎯 Ready for new architecture-based build system!"
echo "Use: cmake --preset <preset-name>"
echo "Available presets: default, debug, arm64, x86_64, universal, cross"
