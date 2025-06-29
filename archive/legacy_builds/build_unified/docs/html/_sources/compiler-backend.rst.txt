Compiler Backend
================

The BCPL compiler backend handles code generation, optimization, and output generation.
It supports multiple target architectures and includes sophisticated optimization passes.

Code Generation
---------------

The compiler provides multiple backend implementations:

**x86 Code Generator (cg.c)**
   Native x86 assembly generation:
   
   * Direct register allocation
   * Efficient instruction selection
   * Platform-specific optimizations
   * Support for 16-bit, 32-bit, and 64-bit targets

**LLVM Backend (llcg.c)**
   LLVM IR generation:
   
   * Modern optimization infrastructure
   * Portable code generation
   * Advanced optimization passes
   * Multiple target architecture support

Translation Phases
------------------

**TRN0 Section** (st.bcpl)
   Translation initialization:
   
   * Symbol table setup
   * Code generation preparation
   * Target architecture selection

**TRN1-TRN2 Sections** (st.bcpl)
   Intermediate code generation:
   
   * Syntax tree traversal
   * OCODE instruction generation
   * Symbol resolution and binding
   * Control flow analysis

OCODE Intermediate Representation
---------------------------------

The compiler uses OCODE as its intermediate representation:

**Instruction Set**
   Core OCODE operations defined in ``oc.h``:
   
   .. code-block:: c
   
      // Data movement
      OP_LOAD, OP_STORE    // Memory operations
      OP_LOADK             // Load constant
      
      // Arithmetic
      OP_ADD, OP_SUB       // Basic arithmetic
      OP_MUL, OP_DIV       // Multiplication/division
      
      // Control flow  
      OP_JUMP, OP_JUMPF    // Unconditional/conditional jumps
      OP_CALL, OP_RETURN   // Procedure calls
      
      // Comparison
      OP_EQ, OP_NE         // Equality testing
      OP_LT, OP_LE         // Relational operations

**Attributes** (oc.c)
   Each OCODE instruction has attributes:
   
   * Operand count and types
   * Stack effect (push/pop behavior)
   * Optimization hints
   * Target-specific properties

Optimization
------------

**Peephole Optimization** (op.c, pt.c)
   Pattern-based local optimizations:
   
   * Instruction combining
   * Dead code elimination
   * Strength reduction
   * Redundancy elimination
   
   Example patterns:
   
   .. code-block:: asm
   
      # Before optimization
      movl $2,%ecx
      imull %ecx
      
      # After optimization  
      shll $1,%eax

**Global Optimizations**
   Cross-basic-block optimizations:
   
   * Constant propagation
   * Common subexpression elimination
   * Register allocation improvements
   * Control flow optimization

Register Allocation
-------------------

The compiler uses different strategies based on the backend:

**x86 Backend**
   Simple but effective allocation:
   
   * Stack-based expression evaluation
   * Register caching for frequently used values
   * Spill code generation when needed

**LLVM Backend**  
   Leverages LLVM's allocation:
   
   * SSA-based register allocation
   * Graph coloring algorithms
   * Advanced spilling strategies

Target Support
--------------

**x86 Family**
   * 16-bit (8086/80286)
   * 32-bit (i386 and later)
   * 64-bit (x86-64)

**Operating Systems**
   * Linux
   * FreeBSD
   * Custom bare-metal targets

**Instruction Selection**
   Platform-specific optimizations:
   
   * Use of specialized instructions
   * Addressing mode optimization
   * Calling convention compliance

Output Generation
-----------------

The backend generates:

* **Assembly code**: Human-readable assembly files
* **Object files**: Native object code (via assembler)
* **Executables**: Linked final programs
* **Debug information**: Debugging symbols and metadata

Runtime Interface
-----------------

The backend coordinates with the runtime system:

* **Calling conventions**: Parameter passing and return values
* **Memory layout**: Stack frame organization
* **System calls**: Operating system interface
* **Error handling**: Runtime error reporting

Backend Integration
-------------------

The backend integrates with:

* **Frontend**: Receives syntax trees and symbol tables
* **Optimizer**: Applies optimization passes
* **Assembler**: Generates final machine code
* **Linker**: Combines with runtime and libraries
