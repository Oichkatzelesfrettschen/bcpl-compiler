# BCPL Compiler Repository — Gap Analysis & CMake Audit

**Date:** June 28, 2025

---

## 1. Top-Level Layout & Enumeration

```text
/ (root)
├── CMakeLists.txt
├── BUILD_* scripts & .md docs
├── bcplc (driver script)
├── build_*.sh (variants, PGO, optimized, max_performance, portable, x86_64, solaris, validation)
├── benchmark_variants.sh
├── docs/             ← Doxygen inputs, Sphinx, markdown
├── install_test/
├── scripts/
├── src/              ← Compiler sources, no sub-CMakeLists
├── tests/            ← Unit tests & fuzzers (no CMakeLists)
├── tools/            ← helper scripts (build_with_tools.sh, modernize.sh)
├── util/
└── …
```

### 1.1 Key Subdirectories & Contents

- **src/**
  - `CMakeLists.txt` (build driver for runtime, front-end, cg, op, llcg)
  - `runtime/` (bcpl_runtime.c, io.c, memory.c, …)
  - `platform/` (platform sources)
  - `cg/` & `op/` embedded in `src/CMakeLists.txt`
  - `llcg.cpp` (optional, behind `find_package(LLVM)`)
  - `bootstrap_main.c`, `st.O`

- **tests/**
  - `test_cg_modern.c`, `test_bcpl.sh`, `test_hello.bcpl`, fuzzers, benches
  - Missing: `tests/CMakeLists.txt`

- **docs/**
  - `Doxyfile.in`, markdown guides, Sphinx sources
  - Missing: `docs/CMakeLists.txt` integration (via `doxygen_add_docs` or `Add Sphinx`)

- **tools/**
  - `build_with_tools.sh`, `modernize.sh`, validation scripts
  - No CMake integration (scripts only)

## 2. Existing CMake Configuration (Workflows Supported)

- **Build Types**: Debug, Release, RelWithDebInfo, MinSizeRel
- **PGO**: via build_pgo.sh (external script)
- **Max/Portable Performance**: external build_*.sh scripts driving macros
- **Sanitizers**: configured manually in root `CMakeLists.txt` (flags appended)
- **Coverage**: outlined in `CMAKE_BUILD_OPTIONS.md` (not yet in src/CMakeLists)
- **Static Analysis**: clang-tidy, Cppcheck, Clang Analyzer — options defined but not invoked per-subdirectory
- **Docs**: Doxygen via `if(ENABLE_DOCS)` in root; Sphinx not wired
- **Fuzzing**: libFuzzer target in root; AFL only via script

## 3. Gaps & Missing CMakeLists Scopes

1. **Per-Module CMakeLists**
   - **src/runtime/**: no CMakeLists; flags and target defined in `src/CMakeLists.txt`.
   - **tests/**: no CMakeLists; unit tests not integrated via `add_subdirectory(tests)`.
   - **docs/**: no CMakeLists; docs/ not part of `add_subdirectory`.

2. **Workflow Coverage in CMake**
   - **PGO**: only external script; not exposed as `option(ENABLE_PGO)` with CMake custom targets.
   - **Max/Portable Perf**: external shell scripts only; recommend exposing `-DENABLE_MAX_PERF=ON` etc.
   - **Portable Builds**: no `-DCMAKE_C_FLAGS="-march=x86-64-v2"` option in CMake.
   - **Benchmarking**: Google Benchmark target exists only if `ENABLE_BENCHMARKS`; no per-subdir integration.

3. **Documentation & Testing**
   - **CTest**: `enable_testing()` is only in top-level; tests not in `add_subdirectory(src/tests)`.
   - **Fuzzing**: fuzzer target in root; tests/ directory fuzzing sources not hooked up.
   - **Coverage/Valgrind/Perf**: no custom targets in subdirectories; all in root.

4. **Modularization**
   - No `cmake/` directory containing reusable CMake modules (Options.cmake, Platform.cmake, LLVM.cmake).
   - Hard-coded logic in two distinct CMakeLists (root and src); inconsistent patterns.

## 4. Recommended Restructuring & Tooling

1. **Split CMakeLists**
   - Root `CMakeLists.txt`: orchestration, options, `add_subdirectory(src)`, `add_subdirectory(tests)`, `add_subdirectory(docs)`.
   - `src/CMakeLists.txt`: define `bcpl_runtime`, `cg`, `op`, `llcg` under one `add_library(bcpl_core)` or via `add_subdirectory(cuda)`, `add_subdirectory(op)`.
   - `tests/CMakeLists.txt`: collect all tests & fuzzers; set `target_compile_options(${test} PRIVATE ${SANITIZER_FLAGS})`.
   - `docs/CMakeLists.txt`: integrate `find_package(Doxygen)` and `add_custom_target(docs)` + Sphinx targets.

2. **Centralize Tools in `cmake/Options.cmake`**
   - One file with all `option(ENABLE_…` definitions, plus helper functions:
     ```cmake
     include(cmake/Options.cmake)
     apply_tooling_flags(target)
     ```
   - Remove duplicate flag lists from root and src.

3. **Expose Workflows as CMake Options**
   ```cmake
   option(ENABLE_PGO    "Generate Profile-Guided Optimization binaries" OFF)
   option(ENABLE_MAXPERF "Max hardware-specific performance" OFF)
   option(ENABLE_PORTABLE_PERF "Portable performance baseline" OFF)
   ```
   - Hook those into custom targets (pgo_instrument, pgo_train, pgo_final).
   - Remove external shell scripts or wrap them in CMake macros.

4. **Add Missing Modules**
   - **docs/CMakeLists.txt**: Sphinx and Doxygen targets.
   - **tests/CMakeLists.txt**: add_executable for each test, link against `bcpl_runtime`, set properties (TIMEOUT, PASS_REGEX).

5. **Additional Tools to Mesh with CMake**
   - **CTest/CPack**: package installers/distributions.
   - **CTest Coverage**: `set(CTEST_COVERAGE_COMMAND lcov …)` for CI integration.
   - **CTest MemCheck**: `set(CTEST_MEMORYCHECK_COMMAND valgrind …)`.
   - **CTest Perf**: custom test type for perf runs.
   - **CMake Presets**: `CMakePresets.json` to define dev/ci/security/perf/fuzz workflows in VSCode and CLI.

---

_By reorganizing into modular CMakeLists, centralizing all flags and options, and adding the missing sub-directories (tests, docs, runtime), you’ll have a unified, gap-free build system supporting every workflow directly through CMake._
