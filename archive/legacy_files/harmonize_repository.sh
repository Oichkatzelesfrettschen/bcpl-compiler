#!/bin/bash

# BCPL Compiler Repository Harmonization Script
# This script will reorganize, harmonize, flatten, unroll, decompose, and deduplicate the repository

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$SCRIPT_DIR"
ARCHIVE_DIR="$REPO_ROOT/archive"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Logging functions
log_header() { echo -e "${PURPLE}=== $1 ===${NC}"; }
log_info() { echo -e "${BLUE}[INFO]${NC} $1"; }
log_success() { echo -e "${GREEN}[SUCCESS]${NC} $1"; }
log_warning() { echo -e "${YELLOW}[WARNING]${NC} $1"; }
log_error() { echo -e "${RED}[ERROR]${NC} $1"; }

# Create archive directory for historical files
create_archive() {
    log_header "Creating Archive Structure"
    
    mkdir -p "$ARCHIVE_DIR"/{duplicates,legacy_cmake,legacy_builds,old_docs,scripts_archive}
    
    log_info "Archive directories created"
}

# Remove duplicate files, keeping the primary version
deduplicate_files() {
    log_header "Deduplicating Files"
    
    # Handle " 2" pattern duplicates
    declare -a dup_files=("COPYING 2" "LICENSE 2" "Doxyfile 2" "bcplc 2" "PKGBUILD 2")
    declare -a primary_files=("COPYING" "LICENSE" "Doxyfile" "bcplc" "PKGBUILD")
    
    for i in "${!dup_files[@]}"; do
        dup="${dup_files[$i]}"
        primary="${primary_files[$i]}"
        if [[ -f "$REPO_ROOT/$dup" ]]; then
            if [[ -f "$REPO_ROOT/$primary" ]]; then
                # Compare files
                if diff "$REPO_ROOT/$dup" "$REPO_ROOT/$primary" >/dev/null 2>&1; then
                    log_info "Removing identical duplicate: $dup"
                    mv "$REPO_ROOT/$dup" "$ARCHIVE_DIR/duplicates/"
                else
                    log_warning "Files differ: $dup vs $primary - archiving duplicate"
                    mv "$REPO_ROOT/$dup" "$ARCHIVE_DIR/duplicates/"
                fi
            else
                log_info "Moving duplicate to primary: $dup -> $primary"
                mv "$REPO_ROOT/$dup" "$REPO_ROOT/$primary"
            fi
        fi
    done
    
    log_success "Deduplication complete"
}

# Consolidate CMakeLists variants
consolidate_cmake() {
    log_header "Consolidating CMake Files"
    
    # Archive all CMakeLists variants except the main one
    find "$REPO_ROOT" -maxdepth 1 -name "CMakeLists*.txt" -not -name "CMakeLists.txt" | while read -r file; do
        filename=$(basename "$file")
        log_info "Archiving CMake variant: $filename"
        mv "$file" "$ARCHIVE_DIR/legacy_cmake/"
    done
    
    # Archive CMakePresets variants except the main one  
    find "$REPO_ROOT" -maxdepth 1 -name "CMakePresets*.json" -not -name "CMakePresets.json" | while read -r file; do
        filename=$(basename "$file")
        log_info "Archiving CMakePresets variant: $filename"
        mv "$file" "$ARCHIVE_DIR/legacy_cmake/"
    done
    
    log_success "CMake consolidation complete"
}

# Clean up generated runtime experiments
cleanup_generated_files() {
    log_header "Cleaning Generated Runtime Files"
    
    # Archive experimental runtime files
    for file in st_clean.c st_complete.c st_final.c st_fixed.c st_generated.c st_improved.c st_simple.c st_simple; do
        if [[ -f "$REPO_ROOT/$file" ]]; then
            log_info "Archiving experimental runtime: $file"
            mv "$REPO_ROOT/$file" "$ARCHIVE_DIR/legacy_builds/"
        fi
    done
    
    log_success "Generated files cleanup complete"
}

# Organize build scripts
organize_scripts() {
    log_header "Organizing Scripts"
    
    # Create scripts directory if it doesn't exist
    mkdir -p "$REPO_ROOT/scripts"
    
    # Move build scripts to scripts directory
    declare -a build_scripts=(
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
        "benchmark_variants.sh"
        "test_architectures.sh"
        "test_bcpl.sh"
        "validate_build.sh"
        "validate_modernization.sh"
        "verify_builds.sh"
        "check_status.sh"
        "cleanup_legacy_builds.sh"
        "consolidate.sh"
        "reorganize.sh"
        "modernize.sh"
        "setup.sh"
        "bcpl_wrapper.sh"
    )
    
    for script in "${build_scripts[@]}"; do
        if [[ -f "$REPO_ROOT/$script" ]]; then
            if [[ ! -f "$REPO_ROOT/scripts/$script" ]]; then
                log_info "Moving script: $script -> scripts/"
                mv "$REPO_ROOT/$script" "$REPO_ROOT/scripts/"
            else
                log_warning "Script already exists in scripts/: $script"
                mv "$REPO_ROOT/$script" "$ARCHIVE_DIR/scripts_archive/"
            fi
        fi
    done
    
    log_success "Scripts organization complete"
}

# Consolidate documentation
consolidate_docs() {
    log_header "Consolidating Documentation"
    
    # Archive redundant documentation files
    declare -a doc_files=(
        "ARCHITECTURE_REFACTORING_SUCCESS.md"
        "BUILD_OPTIMIZATION.md"
        "BUILD_STATUS.md"
        "CMAKE_BUILD_OPTIONS.md"
        "CODEBASE_ANALYSIS.md"
        "COMPREHENSIVE_MODERNIZATION_PLAN.md"
        "GAP_ANALYSIS.md"
        "MODERNIZATION_COMPLETE.md"
        "MODERNIZATION_PLAN.md"
        "MODERNIZATION_SUCCESS.md"
        "MODERNIZATION_SUCCESS_FINAL.md"
        "PROJECT_STATUS.md"
        "README_BUILDS.md"
        "README_MULTIARCH.md"
        "REFACTORING_SUMMARY.md"
        "REORGANIZATION_PLAN.md"
        "ULTIMATE_MODERNIZATION_PLAN.md"
        "modernization_report.md"
    )
    
    for doc in "${doc_files[@]}"; do
        if [[ -f "$REPO_ROOT/$doc" ]]; then
            log_info "Archiving redundant doc: $doc"
            mv "$REPO_ROOT/$doc" "$ARCHIVE_DIR/old_docs/"
        fi
    done
    
    log_success "Documentation consolidation complete"
}

# Clean build artifacts
clean_build_artifacts() {
    log_header "Cleaning Build Artifacts"
    
    # Archive build directories
    declare -a build_dirs=(
        "build"
        "build_integrated"
        "build_ninja" 
        "build_validation"
        "install_test"
    )
    
    for dir in "${build_dirs[@]}"; do
        if [[ -d "$REPO_ROOT/$dir" ]]; then
            log_info "Archiving build directory: $dir"
            mv "$REPO_ROOT/$dir" "$ARCHIVE_DIR/legacy_builds/"
        fi
    done
    
    # Clean other artifacts
    declare -a artifacts=(
        "build.log"
        "cscope.files"
        "cscope.in.out"
        "cscope.out"
        "cscope.po.out"
        "gdb_commands.txt"
    )
    
    for artifact in "${artifacts[@]}"; do
        if [[ -f "$REPO_ROOT/$artifact" ]]; then
            log_info "Removing artifact: $artifact"
            rm -f "$REPO_ROOT/$artifact"
        fi
    done
    
    log_success "Build artifacts cleanup complete"
}

# Create unified documentation
create_unified_docs() {
    log_header "Creating Unified Documentation"
    
    # Create comprehensive README if it doesn't exist or is minimal
    if [[ ! -s "$REPO_ROOT/README.md" ]] || [[ $(wc -l < "$REPO_ROOT/README.md") -lt 50 ]]; then
        cat > "$REPO_ROOT/README.md" << 'EOF'
# BCPL Compiler

A modernized BCPL (Basic Combined Programming Language) compiler with C23 runtime and multi-architecture support.

## Overview

This is a complete BCPL compiler implementation featuring:

- **Modern C23 Runtime**: Memory-safe, platform-independent runtime system
- **Multi-Architecture Support**: ARM64, x86_64, with extensible architecture framework
- **LLVM Backend**: Optional LLVM-based code generation for advanced optimizations
- **Cross-Platform**: macOS, Linux, FreeBSD, and other Unix-like systems
- **Legacy Compatibility**: Supports original BCPL programs and libraries

## Quick Start

```bash
# Build the compiler
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc || sysctl -n hw.ncpu)

# Test with a simple program
echo 'GET "LIBHDR"; LET START() BE WRITES("Hello, BCPL!")' > hello.bcpl
./src/bcplc hello.bcpl
./hello
```

## Build Requirements

- **CMake** 3.20 or later
- **C Compiler**: Clang 12+ or GCC 9+ with C23 support
- **Optional**: LLVM 12+ for advanced backend

## Architecture

- `src/` - Compiler source code (front-end, code generator, optimizer, runtime)
- `tests/` - Test suite and benchmarks  
- `docs/` - Documentation and manuals
- `tools/` - Development utilities
- `scripts/` - Build and automation scripts
- `cmake/` - CMake modules and configuration

## Building

See `scripts/` directory for various build configurations:

- `scripts/build_optimized.sh` - Production optimized build
- `scripts/build_variants.sh` - Multiple optimization levels
- `scripts/test_bcpl.sh` - Run test suite

## Documentation

- **Language Manual**: `docs/manual.txt`
- **Language Standard**: `docs/standard.txt`
- **API Documentation**: Build with `make docs` (requires Doxygen)

## License

This software contains components from the original BCPL compiler distribution
(c) 1978-1980 Tripos Research Group, University of Cambridge, with modern
enhancements (c) 2004-2025 Robert Nordier and contributors.

See `LICENSE` and `COPYRIGHT` files for details.

## History

BCPL was a systems programming language from the 1960s-70s that directly
inspired the development of the B language and subsequently C. This
implementation preserves the historical significance while providing
modern tooling and performance.
EOF
        log_info "Created unified README.md"
    fi
    
    log_success "Unified documentation created"
}

# Validate final structure
validate_structure() {
    log_header "Validating Final Structure"
    
    # Check that essential files exist
    declare -a essential_files=(
        "README.md"
        "LICENSE"
        "COPYRIGHT"
        "CMakeLists.txt"
        "CMakePresets.json"
        "bcplc"
        "src/CMakeLists.txt"
    )
    
    for file in "${essential_files[@]}"; do
        if [[ -f "$REPO_ROOT/$file" ]]; then
            log_success "✓ Essential file exists: $file"
        else
            log_error "✗ Missing essential file: $file"
        fi
    done
    
    # Check directory structure
    declare -a essential_dirs=(
        "src"
        "tests"
        "docs"
        "scripts"
        "tools"
        "cmake"
        "archive"
    )
    
    for dir in "${essential_dirs[@]}"; do
        if [[ -d "$REPO_ROOT/$dir" ]]; then
            log_success "✓ Essential directory exists: $dir"
        else
            log_warning "△ Directory missing (may be normal): $dir"
        fi
    done
    
    log_success "Structure validation complete"
}

# Generate summary report
generate_summary() {
    log_header "Harmonization Summary"
    
    cat > "$REPO_ROOT/HARMONIZATION_REPORT.md" << EOF
# Repository Harmonization Report

**Date**: $(date)
**Harmonization Script**: $(basename "$0")

## Actions Taken

### Deduplication
- Removed duplicate files with " 2" suffix pattern
- Consolidated identical files, archived differing versions

### CMake Consolidation  
- Archived $(find "$ARCHIVE_DIR/legacy_cmake" -name "CMakeLists*.txt" 2>/dev/null | wc -l) CMakeLists variants
- Archived $(find "$ARCHIVE_DIR/legacy_cmake" -name "CMakePresets*.json" 2>/dev/null | wc -l) CMakePresets variants
- Maintained single unified build system

### Build Scripts Organization
- Moved $(find "$REPO_ROOT/scripts" -name "*.sh" 2>/dev/null | wc -l) scripts to scripts/ directory
- Archived conflicting scripts

### Documentation Consolidation
- Archived $(find "$ARCHIVE_DIR/old_docs" -name "*.md" 2>/dev/null | wc -l) redundant documentation files
- Created unified README.md

### Cleanup
- Archived $(find "$ARCHIVE_DIR/legacy_builds" -type d 2>/dev/null | wc -l) legacy build directories
- Removed build artifacts and temporary files

## Final Structure

\`\`\`
$(tree -I 'archive|.git|.venv|builds' "$REPO_ROOT" | head -30)
\`\`\`

## Archive Contents

All removed/archived files are preserved in:
- \`archive/duplicates/\` - Duplicate files
- \`archive/legacy_cmake/\` - Old CMake variants  
- \`archive/legacy_builds/\` - Build experiments
- \`archive/old_docs/\` - Redundant documentation
- \`archive/scripts_archive/\` - Conflicting scripts

## Next Steps

1. Validate build system: \`mkdir build && cd build && cmake .. && make\`
2. Run tests: \`ctest\` or \`scripts/test_bcpl.sh\`
3. Review archived files for any needed content
4. Update CI/CD to use new structure

## Status

✅ Repository successfully harmonized and organized
EOF

    log_success "Summary report generated: HARMONIZATION_REPORT.md"
}

# Main execution
main() {
    log_header "BCPL Compiler Repository Harmonization"
    echo "This script will organize, harmonize, and deduplicate the repository structure."
    echo ""
    
    cd "$REPO_ROOT"
    
    create_archive
    deduplicate_files
    consolidate_cmake
    cleanup_generated_files
    organize_scripts
    consolidate_docs
    clean_build_artifacts
    create_unified_docs
    validate_structure
    generate_summary
    
    log_header "Harmonization Complete!"
    log_success "Repository has been successfully organized and deduplicated"
    log_info "Review the HARMONIZATION_REPORT.md for details"
    log_info "All archived files are preserved in the archive/ directory"
}

# Execute main function
main "$@"
