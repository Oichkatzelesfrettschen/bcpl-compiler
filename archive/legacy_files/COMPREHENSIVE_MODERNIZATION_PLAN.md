# BCPL Compiler Complete Modernization to C23

## Overview
This plan outlines the complete modernization of the BCPL compiler to pure C23 standards with universal portability, maintaining compatibility while leveraging modern paradigms.

## Phase 1: Core Runtime Modernization (PRIORITY 1)

### 1.1 Runtime System Conversion (rt.s → C23)
- **File**: `src/runtime/rt.c` (New)
- **Replaces**: `rt.s` assembly implementation
- **Features**:
  - Memory management (GETVEC, FREEVEC)
  - I/O operations (RDCH, WRCH, FINDINPUT, FINDOUTPUT)
  - String operations 
  - File control blocks (FCB management)
  - Buffer management
  - Error handling

### 1.2 Startup System Conversion (su.s → C23)
- **File**: `src/runtime/startup.c` (New)
- **Replaces**: `su.s` assembly implementation
- **Features**:
  - Program entry point
  - Global vector initialization
  - Stack setup (separate BCPL stack)
  - Command line processing
  - Platform-specific initialization

### 1.3 System Interface Modernization (sys*.s → C23)
- **Files**: `src/platform/{linux,macos,freebsd,windows}.c`
- **Replaces**: `sys_linux.s`, `sys_freebsd.s`, etc.
- **Features**:
  - System call wrappers
  - Platform-specific I/O
  - File operations
  - Memory allocation
  - Process control

## Phase 2: Code Generator Modernization (PRIORITY 2)

### 2.1 Enhanced Code Generator (cg.c)
- **Current**: Assembly output only
- **Target**: Multi-target backend
- **Outputs**:
  - C23 code generation (primary)
  - Assembly code generation (legacy)
  - LLVM IR generation (optional)

### 2.2 LLVM Integration Enhancement
- **File**: `src/llcg.c` (enhance existing)
- **Features**:
  - Complete OCODE coverage
  - Optimization passes
  - Target-specific code generation

## Phase 3: Universal Architecture Support

### 3.1 Architecture Abstraction
- **x86_64**: Native 64-bit support (Linux, macOS, Windows, FreeBSD)
- **ARM64**: Apple Silicon M1/M2/M3, ARM servers
- **x86_32**: Legacy 32-bit support
- **x86_16**: MASM-based 16-bit support (8086/8088)
- **RISC-V**: Future extensibility
- **WebAssembly**: Browser targets

### 3.2 Platform Matrix
```
        | Linux | macOS | Windows | FreeBSD | Web
x86_64  |   ✓   |   ✓   |    ✓    |    ✓    |  ✓
ARM64   |   ✓   |   ✓   |    ✓    |    ✓    |  ✓
x86_32  |   ✓   |   ○   |    ✓    |    ✓    |  ✓
x86_16  |   ○   |   ○   |    ✓    |    ○    |  ○
RISC-V  |   ◐   |   ○   |    ○    |    ◐    |  ○

✓ = Full support
◐ = Planned support
○ = Limited/legacy support
```

## Phase 4: Modern Paradigms Integration

### 4.1 Memory Safety Enhancements
- **Bounds checking**: Optional runtime bounds checking
- **Reference counting**: Smart pointer-like vector management
- **Memory pools**: Efficient allocation strategies
- **Garbage collection**: Optional mark-and-sweep GC

### 4.2 Concurrency Support
- **Thread safety**: Thread-local storage for BCPL contexts
- **Async I/O**: Non-blocking I/O operations
- **Parallel compilation**: Multi-threaded compilation

### 4.3 Modern Tooling Integration
- **LSP server**: Language Server Protocol for IDE support
- **Debug info**: DWARF debug information generation
- **Profiling**: Built-in performance profiling
- **Testing**: Comprehensive test framework

## Phase 5: Enhanced Build System

### 5.1 CMake Modernization
- **Multi-platform**: Windows, macOS, Linux, FreeBSD support
- **Cross-compilation**: Easy cross-target builds
- **Dependency management**: Automatic dependency resolution
- **Testing integration**: CTest framework integration

### 5.2 Package Management
- **vcpkg**: Windows package management
- **Homebrew**: macOS package management
- **APT/DNF**: Linux package management
- **Conan**: Cross-platform C++ packages

## Implementation Priority

### Week 1-2: Core Runtime (Phase 1)
1. Complete runtime system conversion
2. Startup system modernization
3. Basic platform interfaces
4. Initial testing framework

### Week 3-4: Code Generation (Phase 2)
1. Enhanced code generator
2. C23 backend implementation
3. LLVM backend completion
4. Multi-target output support

### Week 5-6: Architecture Support (Phase 3)
1. ARM64 native support
2. Windows compatibility
3. Cross-compilation setup
4. Architecture abstraction layer

### Week 7-8: Modern Features (Phase 4)
1. Memory safety features
2. Concurrency support
3. Modern tooling integration
4. Performance optimizations

## Testing Strategy

### Unit Tests
- Runtime function tests
- Memory management tests
- I/O operation tests
- Platform compatibility tests

### Integration Tests
- Full compilation pipeline tests
- Cross-platform compatibility tests
- Performance regression tests
- Original BCPL program compatibility tests

### Compliance Tests
- BCPL language specification compliance
- Original compiler output compatibility
- Performance benchmarking

## Success Metrics

1. **Functionality**: All original BCPL programs compile and run correctly
2. **Performance**: ≥95% of original performance
3. **Portability**: Builds on all target platforms without modification
4. **Maintainability**: Clean, documented C23 code
5. **Extensibility**: Easy to add new targets and features

## Deliverables

1. **Modernized Compiler**: Complete C23 implementation
2. **Cross-Platform Support**: Universal build system
3. **Documentation**: Complete developer and user documentation
4. **Test Suite**: Comprehensive testing framework
5. **Migration Guide**: Guide for upgrading existing BCPL projects
