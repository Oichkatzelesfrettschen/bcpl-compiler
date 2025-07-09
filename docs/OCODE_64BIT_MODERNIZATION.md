# 64-bit OCODE Modernization

## Overview

This document describes the modernization of the BCPL compiler's OCODE intermediate representation for native 64-bit builds. The modernization provides enhanced performance, type safety, and architecture-specific optimizations while maintaining full backward compatibility with the legacy 32-bit OCODE system.

## Architecture

### Legacy OCODE System

The original OCODE system was designed for 32-bit architectures and includes:
- 32-bit word operations
- Basic arithmetic and logical operations
- Simple memory access patterns
- Limited optimization opportunities

### 64-bit OCODE Enhancement

The new 64-bit OCODE system extends the legacy system with:

#### Native 64-bit Operations
- `OCODE_MULT64`: 64-bit multiplication with overflow detection
- `OCODE_DIV64`: 64-bit division with enhanced error handling
- `OCODE_LSHIFT64/RSHIFT64`: 64-bit shift operations (up to 63 bits)
- `OCODE_LOAD_PTR64/STORE_PTR64`: Native 64-bit pointer operations

#### Pointer Arithmetic
- `OCODE_PTR_ADD`: Pointer arithmetic addition
- `OCODE_PTR_SUB`: Pointer arithmetic subtraction  
- `OCODE_PTR_DIFF`: Pointer difference calculation

#### Memory Management
- `OCODE_ALLOC`: Aligned memory allocation
- `OCODE_FREE`: Memory deallocation
- `OCODE_REALLOC`: Memory reallocation
- `OCODE_MEMCPY/MEMSET/MEMMOVE`: Optimized memory operations

#### Atomic Operations
- `OCODE_ATOMIC_LOAD/STORE`: Atomic memory operations
- `OCODE_ATOMIC_ADD`: Atomic arithmetic
- `OCODE_ATOMIC_CAS`: Compare-and-swap operations

#### Vector/SIMD Operations
- `OCODE_VEC_ADD/MUL`: Vector arithmetic operations
- `OCODE_VEC_LOAD/STORE`: Vector memory operations

## Implementation

### File Structure

```
src/
├── oc.h                    # Legacy OCODE definitions
├── oc.c                    # Legacy OCODE implementation
├── ocode_64bit.h           # 64-bit OCODE definitions
├── ocode_64bit.c           # 64-bit OCODE implementation
├── ocode_bridge.h          # Compatibility bridge
├── ocode_64bit_x86_64.h    # x86-64 optimizations
├── ocode_64bit_aarch64.h   # ARM64 optimizations
├── ocode_64bit_riscv64.h   # RISC-V 64 optimizations
├── ocode_64bit_generic.h   # Generic 64-bit optimizations
└── test_ocode_64bit.c      # Test program
```

### Build Integration

The 64-bit OCODE system is automatically enabled for 64-bit builds:

```cmake
# CMakeLists.txt automatically selects implementation
if(BCPL_ARCH_BITS EQUAL 64)
    set(OCODE_SOURCES oc.c ocode_64bit.c)
    set(OCODE_DEFINES -DBCPL_USE_64BIT_OCODE=1)
else()
    set(OCODE_SOURCES oc.c)
    set(OCODE_DEFINES -DBCPL_USE_64BIT_OCODE=0)
endif()
```

### Compatibility Bridge

The `ocode_bridge.h` header provides a unified API that works with both systems:

```c
#include "ocode_bridge.h"

// Initialize context (works with both legacy and 64-bit)
ocode_context_t ctx;
ocode_init_context(&ctx, 1024);

// Query operation attributes
const ocode_attr_t *attr = ocode_get_attributes(OCODE_OP_MULT);

// Check feature availability
if (ocode_has_64bit_features()) {
    // Use enhanced operations
    if (OCODE_ATOMIC_AVAILABLE) {
        // Use atomic operations
    }
}

// Cleanup
ocode_cleanup_context(&ctx);
```

## Performance Benefits

### 64-bit Native Operations
- Faster arithmetic on 64-bit values
- Native pointer operations without extension
- Better register utilization

### Enhanced Type Safety
- Compile-time operation validation
- Overflow detection for arithmetic
- Memory access alignment checking

### Architecture-Specific Optimizations
- x86-64: SSE/AVX instruction utilization
- ARM64: Advanced SIMD and crypto extensions
- RISC-V: Compressed instruction support

### Memory Management
- Aligned allocations for better cache performance
- Atomic operations for thread safety
- Vector operations for data parallelism

## Migration Guide

### For Existing Code

Existing BCPL code requires no changes. The compiler automatically uses the appropriate OCODE implementation based on the target architecture.

### For Backend Developers

When extending the code generator:

1. Include the bridge header:
   ```c
   #include "ocode_bridge.h"
   ```

2. Use feature detection:
   ```c
   if (ocode_has_64bit_features()) {
       // Use enhanced operations
   }
   ```

3. Check operation availability:
   ```c
   if (OCODE_ATOMIC_AVAILABLE) {
       // Use atomic operations
   }
   ```

### For Performance Optimization

To take advantage of 64-bit features:

1. Enable 64-bit builds:
   ```bash
   cmake -DBCPL_ARCH_BITS=64 ..
   ```

2. Use architecture-specific optimizations:
   ```bash
   cmake -DBCPL_OPTIMIZE_FOR_ARCH=ON ..
   ```

3. Enable native instructions:
   ```bash
   cmake -DBCPL_USE_NATIVE_INSTRUCTIONS=ON ..
   ```

## Testing

Run the test suite to validate the implementation:

```bash
# Build the test program (64-bit builds only)
make test_ocode_64bit_x86_64

# Run the tests
./build/src/test_ocode_64bit_x86_64
```

Expected output:
```
=== BCPL 64-bit OCODE Integration Test ===

Testing context operations...
  Implementation: 64-bit Native OCODE
  Version: 2025.1.0-64bit
  Word size: 8 bytes
  64-bit features: Yes
  ✓ Context operations passed

Testing operation attributes...
  Testing 64-bit specific operations...
    ✓ 64-bit operations verified
  ✓ Operation attributes passed

Testing legacy/64-bit compatibility...
  ✓ Compatibility test passed

Testing word size consistency...
  Word size: 8 bytes
  ✓ Word size consistency passed

Running basic performance benchmark...
  ✓ Completed 50000 operation queries

=== All tests passed! ===
```

## Future Enhancements

### Planned Features
- Advanced vector operations (AVX-512, SVE)
- Profile-guided optimization integration
- Just-in-time compilation support
- LLVM backend integration with 64-bit OCODE

### Architecture Support
- PowerPC 64-bit support
- SPARC 64-bit support  
- Custom embedded 64-bit architectures

### Optimization Research
- Machine learning-guided instruction scheduling
- Auto-vectorization improvements
- Memory prefetching optimizations

## References

- [BCPL Language Specification](../docs/bcpl-language.md)
- [OCODE Intermediate Representation](../docs/ocode-specification.md)
- [Architecture Configuration](../docs/architecture-config.md)
- [Build System Documentation](../docs/build-system.md)
