#!/bin/bash
# BCPL Compiler Project Reorganization Script
# This script safely archives duplicate files and reorganizes the project structure

set -e  # Exit on any error

ARCHIVE_DIR="archive"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(git -C "$SCRIPT_DIR" rev-parse --show-toplevel 2>/dev/null || echo "$SCRIPT_DIR")"
# Determine the repository root dynamically.  This allows the
# reorganization script to be invoked from any location in or
# outside the repository, even if Git is unavailable.


echo "=== BCPL Compiler Project Reorganization ==="
echo "Starting reorganization at: $(date)"
echo "Project root: $REPO_ROOT"

cd "$REPO_ROOT"

# Create archive directories
mkdir -p "$ARCHIVE_DIR"/{duplicate_cmake,duplicate_docs,duplicate_scripts,legacy_source,build_artifacts}

echo "=== Phase 1: Archive Duplicate CMakeLists.txt Files ==="

# Archive duplicate CMakeLists files (keep main CMakeLists.txt)
duplicate_cmake_files=(
    "CMakeLists 3.txt"
    "CMakeLists 4.txt" 
    "CMakeLists_MODERNIZED.txt"
    "CMakeLists_complex.txt"
    "CMakeLists_legacy.txt"
    "CMakeLists_modern_simple.txt"
    "CMakeLists_proper.txt"
    "CMakeLists_test_modern.txt"
    "CMakeLists_working.txt"
)

for file in "${duplicate_cmake_files[@]}"; do
    if [ -f "$file" ]; then
        echo "Archiving: $file"
        mv "$file" "$ARCHIVE_DIR/duplicate_cmake/"
    fi
done

# Archive duplicate CMakeLists in src/
duplicate_src_cmake=(
    "src/CMakeLists 3.txt"
    "src/CMakeLists 4.txt"
    "src/CMakeLists_legacy.txt"
    "src/CMakeLists_modern.txt"
    "src/CMakeLists_old.txt"
)

for file in "${duplicate_src_cmake[@]}"; do
    if [ -f "$file" ]; then
        echo "Archiving: $file"
        mv "$file" "$ARCHIVE_DIR/duplicate_cmake/"
    fi
done

echo "=== Phase 2: Archive Duplicate Documentation ==="

# Archive duplicate documentation files
duplicate_docs=(
    "COPYING 2"
    "LICENSE 2"
    "COPYRIGHT"
    "README"
    "README_BUILDS.md"
    "README_MULTIARCH.md"
    "ARCHITECTURE_REFACTORING_SUCCESS.md"
    "BUILD_STATUS.md"
    "GAP_ANALYSIS.md"
    "MODERNIZATION_COMPLETE.md"
    "MODERNIZATION_PLAN.md"
    "MODERNIZATION_SUCCESS.md"
    "MODERNIZATION_SUCCESS_FINAL.md"
    "REFACTORING_SUMMARY.md"
    "ULTIMATE_MODERNIZATION_PLAN.md"
    "modernization_report.md"
    "Doxyfile 2"
    "PKGBUILD 2"
)

for file in "${duplicate_docs[@]}"; do
    if [ -f "$file" ]; then
        echo "Archiving: $file"
        mv "$file" "$ARCHIVE_DIR/duplicate_docs/"
    fi
done

echo "=== Phase 3: Archive Duplicate Build Scripts ==="

# Archive duplicate build scripts (keep build.sh if it exists, or create unified one)
duplicate_scripts=(
    "benchmark_variants.sh"
    "build_all_archs.sh"
    "build_max_performance.sh"
    "build_optimized.sh"
    "build_pgo.sh"
    "build_portable_optimized.sh"
    "build_solaris.sh"
    "build_variants.sh"
    "build_with_tools.sh"
    "build_x86_64.sh"
    "build_x86_64_safe.sh"
    "cleanup_legacy_builds.sh"
    "test_architectures.sh"
    "verify_builds.sh"
)

for file in "${duplicate_scripts[@]}"; do
    if [ -f "$file" ]; then
        echo "Archiving: $file"
        mv "$file" "$ARCHIVE_DIR/duplicate_scripts/"
    fi
done

echo "=== Phase 4: Archive Legacy Source Files ==="

# Archive duplicate source files
duplicate_source=(
    "st_clean.c"
    "st_complete.c"
    "st_final.c"
    "st_fixed.c"
    "st_generated.c"
    "st_improved.c"
    "st_simple"
    "bcplc 2"
)

for file in "${duplicate_source[@]}"; do
    if [ -f "$file" ]; then
        echo "Archiving: $file"
        mv "$file" "$ARCHIVE_DIR/legacy_source/"
    fi
done

echo "=== Phase 5: Archive Build Artifacts ==="

# Archive build artifacts and temporary files
build_artifacts=(
    "cscope.files"
    "cscope.in.out"
    "cscope.out"
    "cscope.po.out"
    "build.log"
    "gdb_commands.txt"
)

for file in "${build_artifacts[@]}"; do
    if [ -f "$file" ]; then
        echo "Archiving: $file"
        mv "$file" "$ARCHIVE_DIR/build_artifacts/"
    fi
done

echo "=== Phase 6: Archive Duplicate CMakePresets ==="

# Archive duplicate CMakePresets
duplicate_presets=(
    "CMakePresets_clean.json"
    "CMakePresets_legacy.json"
    "CMakePresets_new.json"
)

for file in "${duplicate_presets[@]}"; do
    if [ -f "$file" ]; then
        echo "Archiving: $file"
        mv "$file" "$ARCHIVE_DIR/duplicate_cmake/"
    fi
done

echo "=== Creating Unified Build Script ==="

# Create a unified build script if it doesn't exist
if [ ! -f "build.sh" ]; then
    cat > build.sh << 'EOF'
#!/bin/bash
# Unified BCPL Compiler Build Script

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_TYPE="${1:-Release}"
ARCHITECTURE="${2:-native}"

echo "=== BCPL Compiler Build ==="
echo "Build type: $BUILD_TYPE"
echo "Architecture: $ARCHITECTURE"

# Create build directory
BUILD_DIR="build/$BUILD_TYPE"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# Configure with CMake
cmake -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
      -DBCPL_TARGET_ARCH="$ARCHITECTURE" \
      "$SCRIPT_DIR"

# Build
cmake --build . --parallel "$(nproc 2>/dev/null || sysctl -n hw.ncpu 2>/dev/null || echo 4)"

echo "Build completed successfully!"
echo "Executables are in: $BUILD_DIR/src/"
EOF
    chmod +x build.sh
    echo "Created unified build.sh script"
fi

echo "=== Creating Project Status Summary ==="

# Create a summary of what was done
cat > REORGANIZATION_SUMMARY.md << EOF
# BCPL Compiler Reorganization Summary

Generated on: $(date)

## Files Archived

### Duplicate CMakeLists.txt files ($(ls -1 archive/duplicate_cmake/CMakeLists*.txt 2>/dev/null | wc -l) files)
$(ls -1 archive/duplicate_cmake/CMakeLists*.txt 2>/dev/null || echo "None")

### Duplicate Documentation ($(ls -1 archive/duplicate_docs/ 2>/dev/null | wc -l) files)
$(ls -1 archive/duplicate_docs/ 2>/dev/null || echo "None")

### Duplicate Build Scripts ($(ls -1 archive/duplicate_scripts/ 2>/dev/null | wc -l) files)
$(ls -1 archive/duplicate_scripts/ 2>/dev/null || echo "None")

### Legacy Source Files ($(ls -1 archive/legacy_source/ 2>/dev/null | wc -l) files)
$(ls -1 archive/legacy_source/ 2>/dev/null || echo "None")

### Build Artifacts ($(ls -1 archive/build_artifacts/ 2>/dev/null | wc -l) files)
$(ls -1 archive/build_artifacts/ 2>/dev/null || echo "None")

## Current Clean Structure

\`\`\`
$(find . -maxdepth 2 -type f -name "*.txt" -o -name "*.md" -o -name "*.sh" | grep -v archive | sort)
\`\`\`

## Next Steps

1. Review archived files to ensure nothing important was lost
2. Update documentation to reflect new structure
3. Test the unified build system
4. Update CI/CD pipelines if any exist
5. Consider creating symbolic links for critical archived files if needed

## Recovery

If any archived file is needed, it can be restored from the archive/ directory.
All files are preserved and can be restored with:
\`cp archive/<category>/<filename> .\`
EOF

echo "=== Reorganization Complete ==="
echo "Summary written to: REORGANIZATION_SUMMARY.md"
echo "Archived $(find archive -type f | wc -l) duplicate files"
echo "Project structure has been cleaned and simplified"
echo ""
echo "To build the project, run: ./build.sh"
echo "To see what was archived, check: REORGANIZATION_SUMMARY.md"
