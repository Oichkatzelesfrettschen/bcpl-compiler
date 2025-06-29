# BCPL Compiler Modernization Plan

## Phase 1: Assembly to C23 Migration Strategy

### Priority Order for Conversion:
1. **Runtime System (rt.s)** - Core runtime functions
2. **Startup Code (su.s)** - Program initialization 
3. **System Interface (sys*.s)** - OS-specific system calls
4. **Global Definitions (global.s)** - Symbol tables and constants
5. **Generated Code (st.s, blib.s)** - Will be regenerated after core changes

### Conversion Strategy:

#### 1. Runtime System (rt.s) → runtime.c
- Memory management (GETVEC, FREEVEC)
- I/O operations (RDCH, WRCH, etc.)
- String operations (PACKSTRING, UNPACKSTRING)
- File operations
- Stack management

#### 2. Startup System (su.s) → startup.c  
- Program entry point
- Global vector initialization
- Stack setup
- Command line processing
- Cross-platform compatibility

#### 3. System Interface (sys*.s) → platform/*.c
- Linux system calls → platform/linux.c
- FreeBSD system calls → platform/freebsd.c  
- macOS system calls → platform/macos.c (NEW)
- Windows system calls → platform/windows.c (NEW)

#### 4. Generated Assembly Modernization
- Update code generators to emit C23 instead of assembly
- Maintain MASM compatibility for legacy support

## Phase 2: Build System Modernization

### CMake Enhancements:
1. Multi-platform support (Linux, macOS, Windows, FreeBSD)
2. Cross-compilation configuration
3. LLVM integration improvements
4. Testing framework integration
5. Documentation generation

### MASM Integration:
1. 16-bit x86 support (8086/8088)
2. 32-bit x86 support (i386+)  
3. 64-bit x86 support (x86_64)
4. Conditional assembly for different targets

## Phase 3: Documentation Modernization

### Doxygen Updates:
1. Comprehensive API documentation
2. Architecture diagrams
3. Cross-references
4. Examples and tutorials

### Sphinx Integration:
1. User manual
2. Developer guide
3. API reference
4. Cross-platform build instructions

## Implementation Timeline:

### Week 1-2: Runtime System Migration
- [ ] Create runtime.h with C23 function declarations
- [ ] Convert memory management functions
- [ ] Convert I/O operations
- [ ] Convert string operations
- [ ] Unit tests for runtime functions

### Week 3-4: Startup System Migration  
- [ ] Create startup.h with initialization interfaces
- [ ] Convert program entry point
- [ ] Convert global vector setup
- [ ] Convert stack initialization
- [ ] Cross-platform compatibility layer

### Week 5-6: System Interface Migration
- [ ] Create platform abstraction layer
- [ ] Convert Linux system calls
- [ ] Convert FreeBSD system calls
- [ ] Add macOS system calls
- [ ] Add Windows system calls

### Week 7-8: Build System & Documentation
- [ ] Update CMake for multi-platform
- [ ] MASM integration for legacy support
- [ ] Doxygen documentation updates
- [ ] Sphinx documentation integration
- [ ] CI/CD pipeline updates

## Technical Specifications:

### C23 Features to Leverage:
- `typeof` for generic programming
- `_BitInt` for precise integer types
- Enhanced attributes
- Improved type safety
- Better performance optimizations

### Platform Abstraction Design:
```c
// platform/platform.h
typedef struct bcpl_platform {
    int (*sys_read)(int fd, void *buf, size_t count);
    int (*sys_write)(int fd, const void *buf, size_t count);
    int (*sys_open)(const char *path, int flags, mode_t mode);
    int (*sys_close)(int fd);
    void *(*sys_sbrk)(intptr_t increment);
    void (*sys_exit)(int status);
} bcpl_platform_t;

extern const bcpl_platform_t *bcpl_get_platform(void);
```

### Memory Management Modernization:
```c
// runtime/memory.h
typedef struct bcpl_vector {
    size_t size;
    size_t refcount;
    uint32_t data[];
} bcpl_vector_t;

bcpl_vector_t *bcpl_getvec(size_t size);
void bcpl_freevec(bcpl_vector_t *vec);
```

## Success Metrics:
- [ ] 100% assembly code converted to portable C23
- [ ] All platforms build successfully
- [ ] All existing tests pass
- [ ] Performance within 5% of original
- [ ] Documentation coverage >90%
- [ ] Zero compiler warnings
- [ ] Static analysis clean (cppcheck, clang-analyzer)

## Risk Mitigation:
- Maintain assembly versions during transition
- Comprehensive testing at each phase
- Performance benchmarking
- Gradual migration with fallback options
