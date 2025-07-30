# Script Overview

This directory contains helper scripts for building and testing the BCPL compiler.
Only actively maintained utilities remain here.  Deprecated or superseded
scripts have been moved into `archive/scripts/`.

| Script | Purpose |
|-------|---------|
| `bcpl_wrapper.sh` | Run the compiler tools for a selected architecture. |
| `benchmark_variants.sh` | Benchmark different optimized builds. |
| `build_all_archs.sh` | Build for all supported architectures. |
| `build_arch.sh.in` | Template used by CMake to generate per-arch build scripts. |
| `build_max_performance.sh` | Build with aggressive native optimization flags. |
| `build_optimized.sh` | Create an optimized Release build. |
| `build_pgo.sh` | Perform a profile guided optimization build. |
| `build_portable_optimized.sh` | Produce a highly optimized yet portable build. |
| `build_solaris.sh` | Solaris/Illumos build helper. |
| `build_variants.sh` | Build a collection of optimization variants. |
| `build_with_tools.sh` | Build with analysis tools or sanitizer presets. |
| `build_x86_64.sh` | Build for macOS Rosetta x86‑_64. |
| `build_x86_64_safe.sh` | Safer wrapper around the Rosetta build. |
| `check-deps.sh` | Verify required build tools are present. |
| `check_status.sh` | Summarize repository status and existing builds. |
| `cleanup_legacy_builds.sh` | Move old build directories into the archive. |
| `consolidate.sh` | Helper used during repository reorganization. |
| `gas_to_clang.py` | Convert GNU assembler syntax to Clang format. |
| `hog_test.sh` | Run heavy sanitizer tests. |
| `makeall.sh` | Legacy Makefile based build used by CI. |
| `modernize.sh` | Comprehensive modernization and build script. |
| `reorganize.sh` | Archive duplicate files and tidy the repository. |
| `setup.sh` | Install development dependencies. |
| `test_architectures.sh` | Smoke test ARM64 and x86‑_64 binaries. |
| `test_bcpl.sh` | Minimal compiler functional test. |
| `validate_build.sh` | Build and repository validation checks. |
| `validate_modernization.sh` | Validate modernization progress. |
| `verify_builds.sh` | Check architecture of produced binaries. |

Scripts moved to `archive/scripts/` are kept for reference and are no longer
used by the current build system.
