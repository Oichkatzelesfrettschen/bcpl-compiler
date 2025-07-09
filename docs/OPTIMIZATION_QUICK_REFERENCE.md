# BCPL Compiler Optimization Quick Reference

## Overview
This quick reference provides immediate access to optimization commands and flags for the BCPL compiler build system.

## Quick Start Commands

### 1. Maximum Performance (Native Hardware)
```bash
./build_max_performance.sh
```
**Use when**: Building for deployment on the same hardware
**Performance**: Highest
**Portability**: Limited to same CPU family

### 2. Portable Optimized 
```bash
./build_portable_optimized.sh
```
**Use when**: Building for distribution across similar architectures
**Performance**: High
**Portability**: Good within architecture family

### 3. Profile-Guided Optimization
```bash
./build_pgo.sh
```
**Use when**: Maximum performance with workload-specific optimization
**Performance**: Highest for specific workloads
**Build time**: Longest (3-stage process)

### 4. All Variants Comparison
```bash
./build_variants.sh
./benchmark_variants.sh
```
**Use when**: Evaluating different optimization strategies
**Output**: Performance comparison across all builds

## Optimization Flag Reference

### Core Optimization Levels
| Flag | Description | Use Case |
|------|-------------|----------|
| `-O2` | Standard optimization | Development/baseline |
| `-O3` | Aggressive optimization | Production builds |
| `-Ofast` | `-O3` + fast math | Numerical computation |
| `-Os` | Size optimization | Memory-constrained systems |

### Vectorization Flags
```bash
-fvectorize              # Enable loop vectorization
-fslp-vectorize          # Enable superword-level parallelism  
-funroll-loops           # Unroll loops for vectorization
-mllvm -force-vector-width=N  # Force specific vector width
```

### Link-Time Optimization
```bash
-flto=thin               # ThinLTO (recommended)
-flto=full               # Full LTO (slower build)
-fuse-ld=lld             # Use LLD linker (best for LTO)
-Wl,--thinlto-jobs=N     # Parallel LTO jobs
```

### Profile-Guided Optimization
```bash
# Stage 1: Instrument
-fprofile-instr-generate -fcoverage-mapping

# Stage 2: Use profile data  
-fprofile-instr-use=profile.profdata
```

### Memory/Cache Optimization
```bash
-falign-functions=64     # Align functions to cache lines
-falign-loops=64         # Align loops to cache lines
-falign-jumps=64         # Align jump targets
```

### Code Generation
```bash
-fno-semantic-interposition  # Allow more aggressive optimization
-fdata-sections              # Separate data sections
-ffunction-sections          # Separate function sections
-Wl,--gc-sections           # Remove unused sections
```

### Architecture-Specific
```bash
# Native optimization (not portable)
-march=native -mtune=native

# Portable baselines
-march=x86-64-v2         # x86_64 with SSE4.2, POPCNT
-march=armv8-a           # ARM64 baseline

# Generic tuning
-mtune=generic
```

### Floating-Point Optimization
```bash
-ffast-math              # Full fast-math bundle
-ffp-contract=fast       # Enable FMA instructions
-fno-math-errno          # Don't set errno for math functions
-fno-signed-zeros        # Treat +0 and -0 as equal
-freciprocal-math        # Allow reciprocal approximations
```

## Build Configuration Examples

### Development Build
```bash
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_FLAGS="-O0 -g3"
```

### Release Build  
```bash
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_FLAGS="-O3"
```

### Maximum Performance
```bash
cmake -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_C_FLAGS="-O3 -flto=thin -fvectorize -funroll-loops -march=native"
```

### Size-Optimized
```bash
cmake -DCMAKE_BUILD_TYPE=MinSizeRel \
  -DCMAKE_C_FLAGS="-Os -flto=thin -fdata-sections -ffunction-sections"
```

## Platform-Specific Optimizations

### Apple Silicon (M1/M2/M3)
```bash
-mcpu=apple-m1           # Optimize for Apple Silicon
-falign-loops=32         # ARM64 typically uses 32-byte alignment
```

### Intel x86_64
```bash
-march=skylake           # Optimize for Skylake and newer
-mprefer-vector-width=256 # Prefer AVX2 over AVX-512
```

### AMD x86_64  
```bash
-march=znver3            # Optimize for Zen 3 architecture
-mtune=znver3
```

## Validation Commands

### Check Vectorization
```bash
clang -O3 -Rpass=loop-vectorize -c source.c
```

### Check Binary Features
```bash
objdump -d binary | grep -E "avx|sse|fma"
```

### Performance Testing
```bash
time ./optimized_binary < test_input
perf stat ./optimized_binary < test_input
```

## Common Optimization Combinations

### High Performance + Portable
```bash
-O3 -flto=thin -fvectorize -funroll-loops -march=x86-64-v2
```

### Maximum Performance (Native)
```bash
-O3 -flto=thin -fvectorize -funroll-loops -march=native -mtune=native
```

### Fast Math Numerical
```bash
-O3 -ffast-math -fvectorize -funroll-loops -march=native
```

### Size + Performance Balance
```bash
-O3 -flto=thin -fdata-sections -ffunction-sections -Wl,--gc-sections
```

## Troubleshooting

### Build Issues
- **LTO failures**: Remove `-flto` or switch to `-flto=full`
- **Linker errors**: Remove `-fuse-ld=lld` or install LLD
- **Unknown flags**: Check Clang version (`clang --version`)

### Performance Issues  
- **No speedup**: Check if vectorization occurred (`-Rpass=loop-vectorize`)
- **Slower performance**: Try without `-ffast-math` or aggressive flags
- **Large binaries**: Use `-Os` or add `-Wl,--gc-sections`

### Compatibility Issues
- **Illegal instruction**: Remove `-march=native`, use portable baseline
- **Different results**: Check if `-ffast-math` is affecting numerical accuracy

## Build Script Quick Reference

| Script | Purpose | Time | Portability |
|--------|---------|------|-------------|
| `build_max_performance.sh` | Fastest execution | Medium | Low |
| `build_portable_optimized.sh` | Balanced | Medium | High |
| `build_pgo.sh` | Workload-optimized | High | Medium |
| `build_variants.sh` | Compare all | High | Various |
| `benchmark_variants.sh` | Performance test | High | N/A |

## Environment Variables

```bash
# Profile data location
export LLVM_PROFILE_FILE="profile_%p.profraw"

# Disable CPU features for testing
export LLVM_CPU_FEATURES_DISABLE="avx2,fma"

# Set build parallelism
export CMAKE_BUILD_PARALLEL_LEVEL=$(nproc)
```

## Performance Tips

1. **Always profile before optimizing** - Use `perf` or similar tools
2. **Test with representative workloads** - PGO training should match production
3. **Validate optimizations** - Ensure correctness isn't compromised
4. **Consider build time vs. runtime tradeoffs** - LTO/PGO increase build time
5. **Test across target platforms** - Especially for portable builds

## Quick Decision Matrix

| Requirement | Recommended Build |
|-------------|-------------------|
| Maximum speed, same hardware | `build_max_performance.sh` |
| Fast + portable | `build_portable_optimized.sh` |
| Workload-specific optimization | `build_pgo.sh` |
| Size-constrained | Custom with `-Os` |
| Development/debugging | Standard `-O2` |
| Numerical computation | Custom with `-Ofast` |
