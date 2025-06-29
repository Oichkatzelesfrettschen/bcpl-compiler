# BCPL Compiler Build Optimization Documentation

## Table of Contents

1. [Quick Start](#quick-start)
2. [Available Build Scripts](#available-build-scripts)
3. [Documentation Files](#documentation-files)
4. [Performance Optimization Strategies](#performance-optimization-strategies)
5. [Usage Examples](#usage-examples)
6. [Benchmarking](#benchmarking)
7. [Advanced Techniques](#advanced-techniques)

## Quick Start

To build the BCPL compiler with maximum performance optimization:

```bash
# Quick maximum performance build
./build_max_performance.sh

# Portable high-performance build  
./build_portable_optimized.sh

# Compare all optimization variants
./build_variants.sh
./benchmark_variants.sh
```

## Available Build Scripts

### Core Build Scripts

| Script | Purpose | Build Time | Performance | Portability |
|--------|---------|------------|-------------|-------------|
| `build_max_performance.sh` | Maximum speed for current hardware | Medium | Highest | Low |
| `build_portable_optimized.sh` | High performance + portability | Medium | High | High |
| `build_pgo.sh` | Profile-guided optimization | Long | Highest* | Medium |
| `build_variants.sh` | Build all optimization levels | Long | Various | Various |
| `benchmark_variants.sh` | Performance comparison | Long | N/A | N/A |

*Highest for trained workloads

### Script Descriptions

#### build_max_performance.sh
- **Optimization Level**: -O3 with aggressive flags
- **Target**: Native hardware (`-march=native`)
- **Features**: ThinLTO, vectorization, fast math, cache alignment
- **Use Case**: Maximum performance on known hardware
- **Binary Portability**: Limited to same CPU family

#### build_portable_optimized.sh  
- **Optimization Level**: -O3 with portable flags
- **Target**: Architecture baseline (x86-64-v2, ARMv8-A)
- **Features**: ThinLTO, vectorization, conservative optimizations
- **Use Case**: Distribution across similar architectures
- **Binary Portability**: Good within architecture family

#### build_pgo.sh
- **Process**: Three-stage Profile-Guided Optimization
- **Stages**: Instrument → Train → Optimize
- **Features**: Workload-specific optimization, branch prediction
- **Use Case**: Maximum performance for specific use patterns
- **Build Time**: Longest (requires training phase)

#### build_variants.sh
- **Purpose**: Build multiple optimization variants for comparison
- **Variants**: Baseline, O3, O3+Vec, O3+LTO, Fast Math, Size-optimized
- **Output**: Multiple build directories
- **Use Case**: Performance evaluation and testing

#### benchmark_variants.sh
- **Purpose**: Comprehensive performance testing
- **Tests**: Small, medium, large, and stdlib workloads
- **Output**: CSV results and summary report
- **Metrics**: Average, min, max times with standard deviation

## Documentation Files

### BUILD_OPTIMIZATION.md
Comprehensive optimization guide covering:
- Foundational optimization principles
- Platform-specific optimizations
- Advanced techniques (PGO, LTO, BOLT)
- CMake integration
- Validation and testing procedures

### OPTIMIZATION_QUICK_REFERENCE.md
Quick reference guide with:
- Immediate-use commands
- Optimization flag reference
- Platform-specific flags
- Troubleshooting guide
- Performance tips

## Performance Optimization Strategies

### 1. Baseline Strategy (-O3)
```bash
# Standard high-performance build
-O3 -fvectorize -fslp-vectorize -funroll-loops
```

### 2. Link-Time Optimization
```bash  
# Add ThinLTO for whole-program optimization
-O3 -flto=thin -fuse-ld=lld -Wl,--thinlto-jobs=$(nproc)
```

### 3. Memory Hierarchy Optimization
```bash
# Cache-line alignment and memory optimization
-falign-functions=64 -falign-loops=64 -falign-jumps=64
```

### 4. Architecture-Specific Optimization
```bash
# Native hardware optimization (not portable)
-march=native -mtune=native

# Portable baseline optimization
-march=x86-64-v2 -mtune=generic  # for x86_64
-march=armv8-a -mtune=generic    # for ARM64
```

### 5. Profile-Guided Optimization
```bash
# Three-stage process for workload-specific optimization
# Stage 1: -fprofile-instr-generate
# Stage 2: Run training workloads
# Stage 3: -fprofile-instr-use=profile.profdata
```

## Usage Examples

### Development Build
```bash
# Quick development build with debugging
mkdir build_dev
cmake -B build_dev -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS="-O0 -g3"
cmake --build build_dev
```

### Production Build - Maximum Performance
```bash
# Use the pre-configured script
./build_max_performance.sh

# Manual configuration
mkdir build_prod
cmake -B build_prod \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_FLAGS="-O3 -flto=thin -fvectorize -funroll-loops -march=native" \
  .
cmake --build build_prod --parallel $(nproc)
```

### Production Build - Portable
```bash
# Use the pre-configured script
./build_portable_optimized.sh

# Manual configuration for x86_64
mkdir build_portable
cmake -B build_portable \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_FLAGS="-O3 -flto=thin -fvectorize -march=x86-64-v2" \
  .
cmake --build build_portable --parallel $(nproc)
```

### Size-Optimized Build
```bash
mkdir build_size
cmake -B build_size \
  -DCMAKE_BUILD_TYPE=MinSizeRel \
  -DCMAKE_C_FLAGS="-Os -flto=thin -fdata-sections -ffunction-sections" \
  -DCMAKE_EXE_LINKER_FLAGS="-Wl,--gc-sections" \
  .
cmake --build build_size --parallel $(nproc)
```

## Benchmarking

### Quick Performance Test
```bash
# Build all variants and compare
./build_variants.sh
./benchmark_variants.sh

# Check results
cat benchmark_results/summary_*.txt
```

### Manual Benchmarking
```bash
# Time a specific build
time ./build_max_perf/src/cg < test_program.bcpl

# Detailed performance analysis
perf stat ./build_max_perf/src/cg < test_program.bcpl

# Memory usage analysis
valgrind --tool=massif ./build_max_perf/src/cg < test_program.bcpl
```

### Optimization Verification
```bash
# Check if vectorization occurred
clang -O3 -Rpass=loop-vectorize -c source.c 2>&1 | grep vectorized

# Check generated instructions
objdump -d binary | grep -E "avx|sse|fma"

# Verify cache alignment
objdump -t binary | grep -E "\.text|\.data" | head -5
```

## Advanced Techniques

### 1. BOLT Post-Link Optimization
```bash
# After building with PGO
perf record -e cycles:u -j any,u ./optimized_binary < workload.bcpl
llvm-bolt ./optimized_binary -data=perf.data -o binary.bolt
```

### 2. Function Multi-versioning
```c
// CPU-specific optimization while maintaining portability
__attribute__((target_clones("avx2,sse4.2,default")))
void optimized_function(void) {
    // Automatically optimized for each target
}
```

### 3. Runtime CPU Detection
```c
// Dynamic optimization selection
if (__builtin_cpu_supports("avx2")) {
    use_avx2_path();
} else if (__builtin_cpu_supports("sse4.2")) {
    use_sse42_path();
} else {
    use_scalar_path();
}
```

### 4. Custom CMake Optimization Targets
```cmake
# Add to CMakeLists.txt
option(ENABLE_NATIVE_OPTIMIZATION "Enable native CPU optimization" OFF)

if(ENABLE_NATIVE_OPTIMIZATION)
    target_compile_options(bcpl_target PRIVATE 
        -march=native -mtune=native
    )
endif()
```

## Platform-Specific Notes

### Apple Silicon (M1/M2/M3)
```bash
# Optimize for Apple Silicon
-mcpu=apple-m1 -falign-loops=32
```

### Intel x86_64
```bash
# Optimize for modern Intel CPUs
-march=skylake -mprefer-vector-width=256
```

### AMD x86_64
```bash
# Optimize for Zen architecture
-march=znver3 -mtune=znver3
```

## Troubleshooting

### Common Issues

1. **Build Failures**
   - Check Clang version: `clang --version`
   - Install LLD linker: `apt install lld` or `brew install llvm`
   - Remove unsupported flags for older Clang versions

2. **Performance Issues**
   - Verify vectorization: `-Rpass=loop-vectorize`
   - Check for illegal instructions on different hardware
   - Profile to identify actual bottlenecks

3. **Binary Compatibility**
   - Use portable flags instead of `-march=native`
   - Test on target deployment platforms
   - Use function multi-versioning for CPU-specific code

### Getting Help

1. Check the [optimization documentation](docs/BUILD_OPTIMIZATION.md)
2. Review the [quick reference](docs/OPTIMIZATION_QUICK_REFERENCE.md)
3. Run benchmarks to identify the best configuration for your use case
4. Profile your specific workloads to guide optimization decisions

## Performance Tips Summary

1. **Start with -O3**: Enables most important optimizations
2. **Add ThinLTO**: Whole-program optimization with reasonable build times
3. **Enable vectorization**: `-fvectorize -funroll-loops` for data-parallel code
4. **Use PGO for critical applications**: 3-stage build for maximum performance
5. **Consider build time vs. performance**: Balance based on your development workflow
6. **Always validate**: Test correctness and performance on target platforms
7. **Profile first**: Identify actual bottlenecks before optimizing
