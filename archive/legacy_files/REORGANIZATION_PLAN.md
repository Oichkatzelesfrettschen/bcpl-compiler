# BCPL Compiler Project Reorganization Plan

## Current Issues Identified

### 1. Excessive Duplication
- **12+ CMakeLists.txt variants** (keep only 1 main + 1 per subdirectory)
- **Multiple documentation files** with overlapping content
- **Duplicate license files** (COPYING, COPYING 2, LICENSE, LICENSE 2, COPYRIGHT)
- **Multiple README variants** (README, README.md, README_BUILDS.md, etc.)
- **Scattered build scripts** (20+ build_*.sh files doing similar things)

### 2. Inconsistent Structure
- Assembly and C code mixed in src/
- Platform code scattered across multiple directories
- Test files in multiple locations

### 3. Legacy Artifacts
- Old assembly runtime (rt.s, su.s, sys_*.s) alongside modern C23 implementations
- Multiple st_*.c variants (clean, complete, final, fixed, generated, improved)
- Obsolete build artifacts (cscope files, build logs)

## Proposed Clean Structure

```
bcpl-compiler/
├── CMakeLists.txt                 # Single unified build system
├── README.md                      # Primary documentation
├── LICENSE                        # Single license file
├── CHANGELOG.md                   # Version history
├── 
├── cmake/                         # CMake modules and configuration
│   ├── ArchitectureConfig.cmake
│   ├── PlatformConfig.cmake
│   └── CompilerFlags.cmake
│
├── docs/                          # Consolidated documentation
│   ├── BUILD.md                   # Build instructions
│   ├── MODERNIZATION.md           # Modernization status
│   ├── API.md                     # API documentation
│   └── sphinx/                    # Sphinx docs (keep)
│
├── src/                           # Core source code
│   ├── CMakeLists.txt             # Source build configuration
│   ├── compiler/                  # Compiler core
│   │   ├── lexer/
│   │   ├── parser/
│   │   ├── codegen/
│   │   └── optimizer/
│   ├── runtime/                   # Modern C23 runtime
│   │   ├── memory.c
│   │   ├── io.c
│   │   ├── startup.c
│   │   └── platform/
│   ├── include/                   # Header files
│   └── legacy/                    # Legacy assembly (if needed)
│
├── tests/                         # Comprehensive test suite
│   ├── unit/
│   ├── integration/
│   └── performance/
│
├── tools/                         # Development tools
│   ├── build.sh                   # Single unified build script
│   └── validate.sh                # Validation script
│
└── examples/                      # Example BCPL programs
    └── hello.bcpl
```

## Deduplication Strategy

### Phase 1: CMake Cleanup
1. **Keep**: Root CMakeLists.txt (most comprehensive)
2. **Keep**: src/CMakeLists.txt (modular version)
3. **Keep**: tests/CMakeLists.txt, docs/CMakeLists.txt
4. **Remove**: All CMakeLists_* variants (12 files)

### Phase 2: Documentation Consolidation
1. **Keep**: README.md (merge content from others)
2. **Create**: CHANGELOG.md (from CHANGES)
3. **Keep**: Single LICENSE file
4. **Consolidate**: All modernization docs into docs/MODERNIZATION.md
5. **Remove**: Duplicate documentation files (8 files)

### Phase 3: Source Code Organization
1. **Modernize**: Keep C23 implementations, archive assembly
2. **Consolidate**: Merge duplicate st_*.c files
3. **Organize**: Group by functionality (compiler/, runtime/, include/)

### Phase 4: Build System Simplification
1. **Keep**: Single build.sh script
2. **Remove**: 20+ build_*.sh variants
3. **Keep**: Essential validation scripts

### Phase 5: Cleanup
1. **Remove**: Build artifacts (cscope files, logs)
2. **Remove**: Duplicate executables (bcplc, bcplc 2)
3. **Archive**: Legacy assembly code

## Implementation Priority

1. **High**: CMakeLists.txt deduplication
2. **High**: Documentation consolidation  
3. **Medium**: Source code organization
4. **Medium**: Build script consolidation
5. **Low**: Legacy archive creation

## Files to Remove (47 files)

### CMake Files (11)
- CMakeLists 3.txt, CMakeLists 4.txt
- CMakeLists_*.txt (9 variants)

### Documentation (8)
- COPYING 2, LICENSE 2, COPYRIGHT
- README, README_BUILDS.md, README_MULTIARCH.md
- Multiple MODERNIZATION_*.md variants

### Build Scripts (20)
- build_*.sh variants (keeping only build.sh)
- benchmark_variants.sh, test_architectures.sh

### Source Duplicates (5)
- st_clean.c, st_complete.c, st_final.c, st_fixed.c, st_improved.c
- bcplc 2

### Build Artifacts (3)
- cscope.*, build.log, gdb_commands.txt

## Expected Benefits

1. **Clarity**: Single source of truth for each component
2. **Maintainability**: Unified build system and documentation
3. **Performance**: Faster builds with less complexity
4. **Onboarding**: Clear project structure for new developers
5. **CI/CD**: Simplified automation pipelines

## Migration Safety

- Archive deleted files in archive/ directory
- Maintain git history
- Test builds after each phase
- Document breaking changes
