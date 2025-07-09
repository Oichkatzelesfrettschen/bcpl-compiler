# BCPL Compiler Build Optimization Guide

## Overview

This documentation provides a comprehensive guide for building the BCPL compiler with maximum performance optimizations using modern Clang/LLVM (≥ 17) features. The optimization strategies are designed to be platform-agnostic yet feature-maximal, ensuring optimal performance across x86_64, ARM64, and other architectures.

## Table of Contents

- [Foundational Principles](#foundational-principles)
- [Optimization Levels](#optimization-levels)
- [Build Configurations](#build-configurations)
- [Advanced Optimization Techniques](#advanced-optimization-techniques)
- [Platform-Specific Optimizations](#platform-specific-optimizations)
- [Profile-Guided Optimization (PGO)](#profile-guided-optimization-pgo)
- [Link-Time Optimization (LTO)](#link-time-optimization-lto)
- [BOLT Post-Link Optimization](#bolt-post-link-optimization)
- [Validation and Testing](#validation-and-testing)

## Foundational Principles

### 1. Separation of Concerns
- **What to optimize**: Whole-program optimization (WPO) and profile-aware passes are enabled unconditionally
- **Where to run**: SIMD/FPU/ISA specialization uses late-binding via function multi-versioning
- **Architecture neutrality**: Alignment, cache-line tuning, and loop transforms expose regularity for backend exploitation

### 2. Binary Portability
- Single binary adapts at runtime instead of compile-time
- Function multi-versioning for SIMD dispatch
- Runtime CPU feature detection

## Optimization Levels

### Standard Optimization Tiers

| Level | Use Case | Flags | Notes |
|-------|----------|-------|--------|
| `-O2` | Release default | Standard optimizations | Baseline for production |
| `-O3` | Latency-critical | Aggressive optimization | Adds loop fusion, unswitching |
| `-Ofast` | Numerical computation | `-O3` + `-ffast-math` | Relaxes IEEE compliance |

### BCPL-Specific Optimization Strategy

Starting with `-O3` as the foundation, we layer additional optimizations:

```bash
# Base optimization level
-O3

# Enable all vectorization passes
-fvectorize -fslp-vectorize -funroll-loops

# Floating-point optimizations (where applicable)
-ffp-contract=fast -fno-math-errno -fno-signed-zeros

# Memory hierarchy optimizations
-falign-functions=64 -falign-loops=64 -falign-jumps=64

# Link-time optimizations
-flto=thin -fuse-ld=lld
```

## Build Configurations

### 1. Maximum Performance Build

For absolute maximum performance on known hardware:

```bash
#!/bin/bash
# build_max_performance.sh

CMAKE_BUILD_TYPE=Release
OPTIMIZATION_LEVEL="-O3"

# Advanced optimization flags
ADVANCED_OPTS=(
    "-flto=thin"
    "-fuse-ld=lld"
    "-fvectorize"
    "-fslp-vectorize"
    "-funroll-loops"
    "-ffp-contract=fast"
    "-fno-math-errno"
    "-fno-signed-zeros"
    "-falign-functions=64"
    "-falign-loops=64"
    "-falign-jumps=64"
    "-fno-semantic-interposition"
    "-fdata-sections"
    "-ffunction-sections"
    "-Wl,--gc-sections"
    "-Wl,-O2"
    "-Wl,--thinlto-jobs=$(nproc)"
    "-march=native"
    "-mtune=native"
    "-pipe"
)

# Build with maximum optimizations
cmake -B build_max_perf \
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} \
    -DCMAKE_C_FLAGS="${OPTIMIZATION_LEVEL} ${ADVANCED_OPTS[*]}" \
    -DCMAKE_CXX_FLAGS="${OPTIMIZATION_LEVEL} ${ADVANCED_OPTS[*]}" \
    .

cmake --build build_max_perf --parallel $(nproc)
```

### 2. Portable Optimized Build

For maximum performance while maintaining binary portability:

```bash
#!/bin/bash
# build_portable_optimized.sh

CMAKE_BUILD_TYPE=Release
OPTIMIZATION_LEVEL="-O3"

# Portable optimization flags (no -march=native)
PORTABLE_OPTS=(
    "-flto=thin"
    "-fuse-ld=lld"
    "-fvectorize"
    "-fslp-vectorize"
    "-funroll-loops"
    "-ffp-contract=fast"
    "-fno-math-errno"
    "-fno-signed-zeros"
    "-falign-functions=64"
    "-falign-loops=64"
    "-falign-jumps=64"
    "-fno-semantic-interposition"
    "-fdata-sections"
    "-ffunction-sections"
    "-Wl,--gc-sections"
    "-Wl,-O2"
    "-Wl,--thinlto-jobs=$(nproc)"
    "-march=x86-64-v2"  # or appropriate baseline
    "-mtune=generic"
    "-pipe"
)

cmake -B build_portable \
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} \
    -DCMAKE_C_FLAGS="${OPTIMIZATION_LEVEL} ${PORTABLE_OPTS[*]}" \
    -DCMAKE_CXX_FLAGS="${OPTIMIZATION_LEVEL} ${PORTABLE_OPTS[*]}" \
    .

cmake --build build_portable --parallel $(nproc)
```

### 3. PGO-Enabled Build

Three-stage Profile-Guided Optimization build:

```bash
#!/bin/bash
# build_pgo.sh

set -e

# Stage 1: Instrumented build
echo "Stage 1: Building instrumented binary..."
cmake -B build_pgo_stage1 \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_FLAGS="-O3 -fprofile-instr-generate -fcoverage-mapping" \
    -DCMAKE_CXX_FLAGS="-O3 -fprofile-instr-generate -fcoverage-mapping" \
    .

cmake --build build_pgo_stage1 --parallel $(nproc)

# Stage 2: Training run
echo "Stage 2: Training with representative workloads..."
export LLVM_PROFILE_FILE="bcpl_%p.profraw"
cd build_pgo_stage1

# Run representative workloads
./cg < ../test_workload_1.bcpl > /dev/null
./op < ../test_workload_2.ocode > /dev/null
# Add more representative workloads as needed

# Merge profile data
llvm-profdata merge -output=bcpl.profdata *.profraw
cd ..

# Stage 3: Optimized build with profile data
echo "Stage 3: Building optimized binary with profile data..."
ADVANCED_OPTS=(
    "-O3"
    "-flto=thin"
    "-fuse-ld=lld"
    "-fprofile-instr-use=build_pgo_stage1/bcpl.profdata"
    "-fvectorize"
    "-fslp-vectorize"
    "-funroll-loops"
    "-ffp-contract=fast"
    "-fno-math-errno"
    "-fno-signed-zeros"
    "-falign-functions=64"
    "-falign-loops=64"
    "-falign-jumps=64"
    "-fno-semantic-interposition"
    "-fdata-sections"
    "-ffunction-sections"
    "-Wl,--gc-sections"
    "-Wl,-O2"
    "-Wl,--thinlto-jobs=$(nproc)"
    "-march=native"
    "-mtune=native"
)

cmake -B build_pgo_final \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_FLAGS="${ADVANCED_OPTS[*]}" \
    -DCMAKE_CXX_FLAGS="${ADVANCED_OPTS[*]}" \
    .

cmake --build build_pgo_final --parallel $(nproc)

echo "PGO build complete. Final optimized binaries in build_pgo_final/"
```

## Advanced Optimization Techniques

### 1. Vectorization and SIMD

#### Frontend Switches
```bash
# Core vectorization flags
-fvectorize -fslp-vectorize    # ON at -O2, explicit for clarity
-funroll-loops                 # Widen search space for vectorizer

# Diagnostics (development builds)
-Rpass=loop-vectorize -Rpass-missed=loop-vectorize

# Force specific vector width (when you know it's safe)
-mllvm -force-vector-width=8
```

#### Multi-versioning for Portable SIMD
For CPU-specific optimizations while maintaining portability:

```c
// Example: Optimized memory operations
__attribute__((target_clones("avx2,sse4.2,default")))
void optimized_memcopy(void *dst, const void *src, size_t n) {
    // Implementation automatically vectorized for each target
    memcpy(dst, src, n);
}

// Runtime dispatch
if (__builtin_cpu_supports("avx2")) {
    // Use AVX2 path
} else if (__builtin_cpu_supports("sse4.2")) {
    // Use SSE4.2 path
} else {
    // Use scalar path
}
```

### 2. Memory Hierarchy Optimization

#### Static Alignment
```c
// Cache-line aligned structures
struct alignas(64) bcpl_context {
    // Hot data members first
    uint64_t pc;
    uint64_t sp;
    // ...
};

// Function attributes for alignment
__attribute__((aligned(64))) void hot_function(void);
```

#### Prefetch Optimization
```c
// Strategic prefetching in tight loops
for (size_t i = 0; i < n; i += CACHE_LINE_SIZE) {
    __builtin_prefetch(&data[i + PREFETCH_DISTANCE], 0, 3);
    // Process current cache line
    process_data(&data[i]);
}
```

### 3. Floating-Point Optimization

For numerical workloads (where applicable):

```bash
# Fast math bundle
-ffast-math

# Or fine-grained control
-fno-math-errno         # Don't set errno for math functions
-freciprocal-math       # Allow reciprocal approximations
-fno-signed-zeros       # Treat +0 and -0 as equivalent
-fno-trapping-math      # Don't generate trapping FP operations
-ffp-contract=fast      # Enable FMA where hardware supports
```

## Platform-Specific Optimizations

### Apple Silicon (ARM64)

```bash
# Apple Silicon optimized build
APPLE_ARM64_OPTS=(
    "-O3"
    "-mcpu=apple-m1"        # Or apple-m2, apple-m3 as appropriate
    "-flto=thin"
    "-fvectorize"
    "-funroll-loops"
    "-falign-functions=64"
    "-falign-loops=32"      # ARM64 typically uses 32-byte alignment
    "-fno-semantic-interposition"
    "-pipe"
)
```

### Intel x86_64

```bash
# Intel x86_64 optimized build
INTEL_X64_OPTS=(
    "-O3"
    "-march=skylake"        # Or appropriate microarchitecture
    "-mtune=skylake"
    "-flto=thin"
    "-fvectorize"
    "-funroll-loops"
    "-falign-functions=64"
    "-falign-loops=64"
    "-mprefer-vector-width=256"  # Prefer AVX2 over AVX-512 if both available
    "-pipe"
)
```

### Cross-Platform Universal

```bash
# Universal binary approach
UNIVERSAL_OPTS=(
    "-O3"
    "-flto=thin"
    "-fvectorize"
    "-funroll-loops"
    "-falign-functions=64"
    "-falign-loops=64"
    # No -march flags - use runtime dispatch instead
    "-pipe"
)
```

## Profile-Guided Optimization (PGO)

### Complete PGO Workflow

1. **Instrumentation Phase**:
```bash
export CMAKE_C_FLAGS="-O3 -fprofile-instr-generate -fcoverage-mapping"
export CMAKE_CXX_FLAGS="-O3 -fprofile-instr-generate -fcoverage-mapping"
cmake -B build_instrument -DCMAKE_BUILD_TYPE=Release .
cmake --build build_instrument
```

2. **Training Phase**:
```bash
export LLVM_PROFILE_FILE="bcpl_%p.profraw"
cd build_instrument

# Run comprehensive test suite
./test_bcpl.sh

# Run typical workloads
find ../test_programs -name "*.bcpl" -exec ./cg {} \;

# Merge profiles
llvm-profdata merge -output=bcpl.profdata *.profraw
```

3. **Optimization Phase**:
```bash
export CMAKE_C_FLAGS="-O3 -flto=thin -fprofile-instr-use=build_instrument/bcpl.profdata"
export CMAKE_CXX_FLAGS="-O3 -flto=thin -fprofile-instr-use=build_instrument/bcpl.profdata"
cmake -B build_pgo_optimized -DCMAKE_BUILD_TYPE=Release .
cmake --build build_pgo_optimized
```

## Link-Time Optimization (LTO)

### ThinLTO Configuration

```bash
# Recommended ThinLTO settings
-flto=thin                      # Enable ThinLTO
-fuse-ld=lld                    # Use LLD linker for best ThinLTO support
-Wl,--thinlto-jobs=$(nproc)     # Parallelize ThinLTO passes
-Wl,-O2                         # Enable linker optimizations
```

### Full LTO (for smaller projects)

```bash
# Full LTO - slower build, potentially better optimization
-flto=full
-fuse-ld=lld
```

## BOLT Post-Link Optimization

For maximum performance, apply BOLT post-link optimization:

```bash
#!/bin/bash
# bolt_optimization.sh

BINARY="./build_optimized/cg"
WORKLOAD_SCRIPT="./run_training_workload.sh"

echo "Collecting profile data with perf..."
perf record -e cycles:u -j any,u ${BINARY} < test_input.bcpl

echo "Applying BOLT optimization..."
llvm-bolt ${BINARY} \
    -data=perf.data \
    -reorder-blocks=ext-tsp \
    -reorder-functions=hfsort+ \
    -split-functions \
    -split-all-cold \
    -dyno-stats \
    -o ${BINARY}.bolt

echo "BOLT optimization complete. Optimized binary: ${BINARY}.bolt"
```

## CMake Integration

### Enhanced CMakeLists.txt for Optimization

```cmake
# Add to src/CMakeLists.txt

option(ENABLE_MAX_OPTIMIZATION "Enable maximum optimization flags" OFF)
option(ENABLE_PGO "Enable Profile-Guided Optimization" OFF)
option(ENABLE_LTO "Enable Link-Time Optimization" ON)

if(ENABLE_MAX_OPTIMIZATION)
    set(MAX_OPT_FLAGS
        -O3
        -fvectorize
        -fslp-vectorize
        -funroll-loops
        -ffp-contract=fast
        -fno-math-errno
        -fno-signed-zeros
        -falign-functions=64
        -falign-loops=64
        -falign-jumps=64
        -fno-semantic-interposition
        -fdata-sections
        -ffunction-sections
        -march=native
        -mtune=native
    )
    
    target_compile_options(cg PRIVATE ${MAX_OPT_FLAGS})
    target_compile_options(op PRIVATE ${MAX_OPT_FLAGS})
    target_compile_options(bcpl_runtime PRIVATE ${MAX_OPT_FLAGS})
endif()

if(ENABLE_LTO)
    set_property(TARGET cg PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET op PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    set_property(TARGET bcpl_runtime PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
    
    # ThinLTO specific flags
    target_link_options(cg PRIVATE -fuse-ld=lld)
    target_link_options(op PRIVATE -fuse-ld=lld)
endif()

if(ENABLE_PGO AND PGO_PROFILE_DATA)
    target_compile_options(cg PRIVATE -fprofile-instr-use=${PGO_PROFILE_DATA})
    target_compile_options(op PRIVATE -fprofile-instr-use=${PGO_PROFILE_DATA})
endif()
```

## Validation and Testing

### Performance Validation Checklist

1. **Vectorization Verification**:
```bash
# Check if critical loops were vectorized
clang -O3 -Rpass=loop-vectorize -c source.c 2>&1 | grep "vectorized"
```

2. **SIMD Dispatch Testing**:
```bash
# Test multi-versioned functions
export LLVM_CPU_FEATURES_DISABLE=avx2
./optimized_binary  # Should fall back to SSE4.2 or scalar
```

3. **Cache Alignment Verification**:
```c
// Runtime alignment check
assert((uintptr_t)aligned_data % 64 == 0);
```

4. **Performance Benchmarking**:
```bash
# Comprehensive performance test
#!/bin/bash
echo "Testing build variants..."

for build in baseline O2 O3 O3_vectorized O3_lto O3_pgo; do
    echo "Testing $build..."
    time ./build_${build}/cg < large_test.bcpl > /dev/null
done
```

### Build Scripts

Create the following build scripts for different optimization levels:

```bash
# build_variants.sh
#!/bin/bash

# Create all optimization variants
./build_baseline.sh        # -O2 only
./build_O3.sh             # -O3 with vectorization
./build_max_perf.sh       # Maximum optimization
./build_portable.sh       # Portable optimization
./build_pgo.sh            # PGO optimization
```

## Performance Tips

1. **Profile First**: Always profile before optimizing to identify actual bottlenecks
2. **Measure Impact**: Benchmark each optimization to verify performance gains
3. **Test Thoroughly**: Aggressive optimizations can introduce subtle bugs
4. **Consider Build Time**: Balance optimization level with build time requirements
5. **Platform Testing**: Test optimized builds on target deployment platforms

## Conclusion

This optimization guide provides a comprehensive approach to building high-performance BCPL compiler binaries. The techniques are layered from basic (-O3) to advanced (PGO + LTO + BOLT), allowing you to choose the appropriate level based on your performance requirements and build constraints.

Key takeaways:
- Start with -O3 and vectorization flags
- Use ThinLTO for scalable whole-program optimization
- Apply PGO for workload-specific optimization
- Use BOLT for post-link layout optimization
- Maintain binary portability through runtime dispatch
- Always validate optimizations through testing and profiling
