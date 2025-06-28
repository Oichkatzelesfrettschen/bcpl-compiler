# BCPL Compiler - Comprehensive CMake Build Options

## Analysis & Quality Tools

### Code Coverage (lcov/gcov)
```cmake
option(ENABLE_COVERAGE "Enable code coverage analysis" OFF)
if(ENABLE_COVERAGE)
    target_compile_options(target PRIVATE --coverage -fprofile-arcs -ftest-coverage)
    target_link_libraries(target PRIVATE --coverage)
    find_program(LCOV_PATH lcov)
    find_program(GENHTML_PATH genhtml)
    # Add custom targets for coverage reports
endif()
```

### Memory Analysis (Valgrind)
```cmake
option(ENABLE_VALGRIND "Enable Valgrind memory checking" OFF)
if(ENABLE_VALGRIND)
    find_program(VALGRIND_PROGRAM valgrind)
    add_custom_target(valgrind
        COMMAND ${VALGRIND_PROGRAM} --tool=memcheck --leak-check=full 
                --show-leak-kinds=all $<TARGET_FILE:bcpl_compiler>)
endif()
```

### Address Sanitizer (ASan)
```cmake
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)
if(ENABLE_ASAN)
    target_compile_options(target PRIVATE -fsanitize=address -fno-omit-frame-pointer)
    target_link_libraries(target PRIVATE -fsanitize=address)
endif()
```

### Memory Sanitizer (MSan)
```cmake
option(ENABLE_MSAN "Enable MemorySanitizer" OFF)
if(ENABLE_MSAN)
    target_compile_options(target PRIVATE -fsanitize=memory -fno-omit-frame-pointer)
    target_link_libraries(target PRIVATE -fsanitize=memory)
endif()
```

### Thread Sanitizer (TSan)
```cmake
option(ENABLE_TSAN "Enable ThreadSanitizer" OFF)
if(ENABLE_TSAN)
    target_compile_options(target PRIVATE -fsanitize=thread)
    target_link_libraries(target PRIVATE -fsanitize=thread)
endif()
```

### Undefined Behavior Sanitizer (UBSan)
```cmake
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)
if(ENABLE_UBSAN)
    target_compile_options(target PRIVATE -fsanitize=undefined)
    target_link_libraries(target PRIVATE -fsanitize=undefined)
endif()
```

## Static Analysis Tools

### Clang Static Analyzer
```cmake
option(ENABLE_CLANG_ANALYZER "Enable Clang Static Analyzer" OFF)
if(ENABLE_CLANG_ANALYZER)
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --analyze")
endif()
```

### Clang-Tidy
```cmake
option(ENABLE_CLANG_TIDY "Enable clang-tidy analysis" OFF)
if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
    set(CMAKE_C_CLANG_TIDY "${CLANG_TIDY_EXE};-checks=*,-modernize-*")
endif()
```

### PVS-Studio
```cmake
option(ENABLE_PVS_STUDIO "Enable PVS-Studio static analysis" OFF)
if(ENABLE_PVS_STUDIO)
    find_program(PVS_STUDIO_ANALYZER pvs-studio-analyzer)
    add_custom_target(pvs-analysis
        COMMAND ${PVS_STUDIO_ANALYZER} trace -- cmake --build .
        COMMAND ${PVS_STUDIO_ANALYZER} analyze -o analysis.log
        COMMAND plog-converter -a GA:1,2 -t tasklist analysis.log)
endif()
```

### Cppcheck
```cmake
option(ENABLE_CPPCHECK "Enable Cppcheck static analysis" OFF)
if(ENABLE_CPPCHECK)
    find_program(CPPCHECK_EXECUTABLE cppcheck)
    add_custom_target(cppcheck
        COMMAND ${CPPCHECK_EXECUTABLE} --enable=all --std=c11 ${CMAKE_SOURCE_DIR}/src)
endif()
```

## Performance & Profiling Tools

### Intel VTune Profiler
```cmake
option(ENABLE_VTUNE "Enable Intel VTune profiling support" OFF)
if(ENABLE_VTUNE)
    target_compile_options(target PRIVATE -g -O2 -fno-omit-frame-pointer)
    find_path(VTUNE_INCLUDE_DIR ittnotify.h PATHS /opt/intel/vtune/include)
    if(VTUNE_INCLUDE_DIR)
        target_include_directories(target PRIVATE ${VTUNE_INCLUDE_DIR})
        target_compile_definitions(target PRIVATE ENABLE_VTUNE)
    endif()
endif()
```

### Google Benchmark
```cmake
option(ENABLE_BENCHMARKS "Enable Google Benchmark performance tests" OFF)
if(ENABLE_BENCHMARKS)
    find_package(benchmark REQUIRED)
    add_executable(bcpl_benchmarks src/benchmarks.cpp)
    target_link_libraries(bcpl_benchmarks benchmark::benchmark)
endif()
```

### Perf Integration
```cmake
option(ENABLE_PERF "Enable Linux perf integration" OFF)
if(ENABLE_PERF)
    target_compile_options(target PRIVATE -g -fno-omit-frame-pointer)
    add_custom_target(perf-record
        COMMAND perf record -g $<TARGET_FILE:bcpl_compiler> 
        COMMAND perf report)
endif()
```

### Flame Graph Generation
```cmake
option(ENABLE_FLAMEGRAPH "Enable FlameGraph generation" OFF)
if(ENABLE_FLAMEGRAPH)
    find_program(FLAMEGRAPH_PATH FlameGraph/flamegraph.pl)
    add_custom_target(flamegraph
        COMMAND perf record -g $<TARGET_FILE:bcpl_compiler>
        COMMAND perf script | ${FLAMEGRAPH_PATH} > flamegraph.svg)
endif()
```

## Security & Hardening

### Control Flow Integrity (CFI)
```cmake
option(ENABLE_CFI "Enable Control Flow Integrity" OFF)
if(ENABLE_CFI)
    target_compile_options(target PRIVATE -fsanitize=cfi -flto)
    target_link_libraries(target PRIVATE -fsanitize=cfi -flto)
endif()
```

### Stack Clash Protection
```cmake
option(ENABLE_STACK_CLASH_PROTECTION "Enable stack clash protection" OFF)
if(ENABLE_STACK_CLASH_PROTECTION)
    target_compile_options(target PRIVATE -fstack-clash-protection)
endif()
```

### Intel CET (Control-flow Enforcement Technology)
```cmake
option(ENABLE_CET "Enable Intel CET" OFF)
if(ENABLE_CET)
    target_compile_options(target PRIVATE -fcf-protection=full)
endif()
```

## Documentation Tools

### Doxygen
```cmake
option(ENABLE_DOCS "Enable documentation generation" OFF)
if(ENABLE_DOCS)
    find_package(Doxygen REQUIRED dot)
    doxygen_add_docs(docs ${CMAKE_SOURCE_DIR}/src)
endif()
```

### Sphinx
```cmake
option(ENABLE_SPHINX_DOCS "Enable Sphinx documentation" OFF)
if(ENABLE_SPHINX_DOCS)
    find_program(SPHINX_EXECUTABLE sphinx-build)
    add_custom_target(sphinx-docs
        COMMAND ${SPHINX_EXECUTABLE} -b html docs/ docs/_build/html)
endif()
```

## Testing Frameworks

### Fuzzing (libFuzzer)
```cmake
option(ENABLE_FUZZING "Enable fuzzing with libFuzzer" OFF)
if(ENABLE_FUZZING)
    target_compile_options(target PRIVATE -fsanitize=fuzzer)
    target_link_libraries(target PRIVATE -fsanitize=fuzzer)
endif()
```

### American Fuzzy Lop (AFL)
```cmake
option(ENABLE_AFL "Enable AFL fuzzing" OFF)
if(ENABLE_AFL)
    set(CMAKE_C_COMPILER "afl-clang-fast")
    set(CMAKE_CXX_COMPILER "afl-clang-fast++")
endif()
```

### Criterion Testing Framework
```cmake
option(ENABLE_CRITERION "Enable Criterion testing framework" OFF)
if(ENABLE_CRITERION)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(CRITERION REQUIRED criterion)
    add_executable(tests src/tests.c)
    target_link_libraries(tests ${CRITERION_LIBRARIES})
endif()
```

## Compiler-Specific Options

### Link-Time Optimization Variants
```cmake
option(ENABLE_THIN_LTO "Enable ThinLTO" OFF)
option(ENABLE_FULL_LTO "Enable Full LTO" OFF)
if(ENABLE_THIN_LTO)
    target_compile_options(target PRIVATE -flto=thin)
    target_link_libraries(target PRIVATE -flto=thin)
elseif(ENABLE_FULL_LTO)
    target_compile_options(target PRIVATE -flto)
    target_link_libraries(target PRIVATE -flto)
endif()
```

### Polly Loop Optimization
```cmake
option(ENABLE_POLLY "Enable Polly loop optimizations" OFF)
if(ENABLE_POLLY)
    target_compile_options(target PRIVATE -mllvm -polly)
endif()
```

### BOLT Binary Optimization
```cmake
option(ENABLE_BOLT "Enable BOLT binary optimization" OFF)
if(ENABLE_BOLT)
    find_program(LLVM_BOLT llvm-bolt)
    add_custom_target(bolt-optimize
        COMMAND ${LLVM_BOLT} $<TARGET_FILE:bcpl_compiler> -o bcpl_compiler_bolt
                -instrument --instrumentation-file=profile.fdata)
endif()
```

## Cross-Compilation & Emulation

### QEMU User Mode Emulation
```cmake
option(ENABLE_QEMU_TESTING "Enable QEMU cross-architecture testing" OFF)
if(ENABLE_QEMU_TESTING)
    find_program(QEMU_ARM qemu-arm)
    find_program(QEMU_AARCH64 qemu-aarch64)
    add_custom_target(test-arm
        COMMAND ${QEMU_ARM} $<TARGET_FILE:bcpl_compiler>)
endif()
```

### WebAssembly (Emscripten)
```cmake
option(ENABLE_WASM "Enable WebAssembly build" OFF)
if(ENABLE_WASM)
    set(CMAKE_TOOLCHAIN_FILE ${EMSCRIPTEN}/cmake/Modules/Platform/Emscripten.cmake)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s WASM=1")
endif()
```

## Usage Examples

```bash
# Coverage analysis
cmake -DENABLE_COVERAGE=ON ..
make && make test && make coverage

# Memory checking with Valgrind
cmake -DENABLE_VALGRIND=ON ..
make && make valgrind

# All sanitizers
cmake -DENABLE_ASAN=ON -DENABLE_UBSAN=ON -DENABLE_TSAN=ON ..

# Performance profiling
cmake -DENABLE_VTUNE=ON -DENABLE_BENCHMARKS=ON ..

# Security hardening
cmake -DENABLE_CFI=ON -DENABLE_STACK_CLASH_PROTECTION=ON ..

# Complete analysis suite
cmake -DENABLE_COVERAGE=ON -DENABLE_CLANG_TIDY=ON -DENABLE_CPPCHECK=ON \
      -DENABLE_ASAN=ON -DENABLE_UBSAN=ON -DENABLE_DOCS=ON ..
```

## Recommended Combinations

### Development Build
```bash
-DENABLE_ASAN=ON -DENABLE_UBSAN=ON -DENABLE_CLANG_TIDY=ON
```

### CI/CD Build
```bash
-DENABLE_COVERAGE=ON -DENABLE_CLANG_ANALYZER=ON -DENABLE_CPPCHECK=ON
```

### Performance Testing
```bash
-DENABLE_VTUNE=ON -DENABLE_BENCHMARKS=ON -DENABLE_THIN_LTO=ON
```

### Security Audit
```bash
-DENABLE_CFI=ON -DENABLE_ASAN=ON -DENABLE_FUZZING=ON -DENABLE_PVS_STUDIO=ON
```
