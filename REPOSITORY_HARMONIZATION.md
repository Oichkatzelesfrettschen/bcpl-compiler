# BCPL Compiler Repository Harmonization Plan

## Current State Analysis

The repository contains significant duplication, fragmentation, and organizational issues:

### Issues Identified

1. **Multiple Duplicate Files**:
   - `COPYING` and `COPYING 2` (identical copyright files)
   - `LICENSE` and `LICENSE 2` (identical license files) 
   - `Doxyfile` and `Doxyfile 2` (identical documentation configs)
   - `bcplc` and `bcplc 2` (duplicate driver scripts)
   - `PKGBUILD` and `PKGBUILD 2` (duplicate package builds)

2. **Multiple CMakeLists Variants** (12 different versions):
   - `CMakeLists.txt` (current)
   - `CMakeLists_complex.txt`
   - `CMakeLists_legacy.txt`
   - `CMakeLists_modern_simple.txt`
   - `CMakeLists_proper.txt`
   - `CMakeLists_test_modern.txt`
   - `CMakeLists_working.txt`
   - `CMakeLists_MODERNIZED.txt`
   - `CMakeLists 3.txt`
   - `CMakeLists 4.txt`

3. **Multiple CMakePresets Variants** (4 different versions):
   - `CMakePresets.json`
   - `CMakePresets_clean.json`
   - `CMakePresets_legacy.json`
   - `CMakePresets_new.json`

4. **Scattered Generated Runtime Files**:
   - `st_clean.c`, `st_complete.c`, `st_final.c`, `st_fixed.c`, `st_generated.c`, `st_improved.c`, `st_simple.c`
   - These appear to be different iterations/experiments

5. **Excessive Build Directories**:
   - Multiple `build*` directories with unclear purposes
   - Some appear to be stale from previous builds

6. **Fragmented Documentation**:
   - Multiple similar documentation files with overlapping content
   - Status reports that duplicate information

## Harmonization Strategy

### Phase 1: Deduplication
1. Remove duplicate files, keeping the most current version
2. Consolidate CMakeLists variants into a single, robust version
3. Merge CMakePresets into a unified configuration
4. Remove stale generated files

### Phase 2: Reorganization  
1. Organize build scripts into `scripts/` directory
2. Consolidate documentation
3. Clean up build artifacts
4. Standardize naming conventions

### Phase 3: Synthesis
1. Create unified CMake configuration with presets
2. Single source of truth for build system
3. Clear directory structure
4. Comprehensive documentation

## Target Directory Structure

```
/
├── README.md                 # Primary documentation
├── LICENSE                   # Single license file
├── COPYRIGHT                 # Single copyright file
├── CMakeLists.txt           # Unified build system
├── CMakePresets.json        # Unified presets
├── Doxyfile                 # Single documentation config
├── bcplc                    # Single driver script
├── src/                     # Source code
├── tests/                   # Test suite
├── docs/                    # Documentation
├── scripts/                 # Build and utility scripts
├── cmake/                   # CMake modules
├── tools/                   # Development tools
├── util/                    # Utilities
└── archive/                 # Historical/legacy files
```

## Implementation Plan

1. **Create backup** of current state
2. **Analyze and merge** duplicate files
3. **Consolidate build system** components
4. **Reorganize** into target structure
5. **Validate** build system works
6. **Document** final organization

This harmonization will result in:
- Single source of truth for all configurations
- Eliminated duplication and confusion
- Clean, logical organization
- Maintainable build system
- Clear documentation structure
