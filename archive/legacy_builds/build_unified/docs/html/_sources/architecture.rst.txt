Architecture Overview
===================

The BCPL compiler is structured as a multi-pass compiler with clear separation
between frontend, intermediate representation, and backend components.

.. _architecture-diagram:

Compilation Pipeline
-------------------

.. code-block:: text

    BCPL Source
         |
         v
    [ST Frontend] ──> OCODE (Intermediate Representation)
         |                    |
         |                    v
         |               [CG Backend] ──> x86 Assembly
         |                    |
         |                    v
         |               [OP Optimizer] ──> Optimized Assembly
         |                    |
         |                    v
         |               [AS Assembler] ──> Object Code
         |                    |
         |                    v
         |               [LD Linker] ──> Executable
         |
         v
    [LLCG Backend] ──> LLVM IR ──> [LLVM] ──> Optimized Code

Frontend Components
------------------

Scanner/Translator (ST)
~~~~~~~~~~~~~~~~~~~~~~

The ST component is the main compiler frontend, written in BCPL itself.
It performs:

* **Lexical Analysis**: Tokenization of BCPL source code
* **Syntax Analysis**: Parsing using recursive descent
* **Semantic Analysis**: Type checking and scope resolution  
* **OCODE Generation**: Production of intermediate representation

The frontend is self-hosting, demonstrating BCPL's capability for
systems programming.

OCODE Intermediate Representation
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

OCODE is a stack-based intermediate representation that abstracts
BCPL language constructs into a simpler instruction set:

* **Platform Independent**: OCODE is target-neutral
* **Stack-Based**: Uses a virtual stack for computations
* **Typed Operations**: Each operation has well-defined semantics
* **Optimization Friendly**: Suitable for analysis and transformation

Backend Components  
------------------

Code Generator (CG)
~~~~~~~~~~~~~~~~~~

The primary backend generates x86 assembly from OCODE:

* **Multi-Architecture**: Supports x86-16, x86-32, and x86-64
* **Register Allocation**: Efficient use of x86 registers
* **Load Stack**: Tracks values for optimization
* **GNU Assembler Output**: Compatible with standard tools

Optimizer (OP)
~~~~~~~~~~~~~~

A peephole optimizer that improves generated assembly:

* **Pattern Matching**: Recognizes inefficient instruction sequences
* **Dead Code Elimination**: Removes unused operations
* **Instruction Combining**: Merges related operations
* **Size Optimization**: Reduces code size

LLVM Backend (LLCG)
~~~~~~~~~~~~~~~~~~

An experimental backend targeting LLVM IR:

* **Modern Infrastructure**: Leverages LLVM's optimization passes
* **Multiple Targets**: Can target any LLVM-supported architecture
* **Future-Proof**: Provides path to modern code generation
* **Proof of Concept**: Currently implements minimal OCODE subset

Runtime System
--------------

The BCPL runtime provides essential services:

Memory Management
~~~~~~~~~~~~~~~~

* **BCPL Stack**: Separate from system stack
* **Global Vector**: Inter-module communication
* **Static Storage**: Compile-time allocated data
* **Dynamic Allocation**: Runtime memory management

Standard Library
~~~~~~~~~~~~~~~

* **I/O Functions**: Character and string operations
* **Numeric Functions**: Number formatting and parsing
* **Utility Functions**: Common programming constructs
* **System Interface**: OS interaction primitives

System Interface
~~~~~~~~~~~~~~~

Platform-specific components handle OS interaction:

* **System Calls**: File I/O, process control
* **Startup Code**: Program initialization  
* **Exception Handling**: Error recovery
* **Platform Abstraction**: Portable interfaces

Build System
-----------

The compiler supports both traditional and modern build systems:

Make-based Build
~~~~~~~~~~~~~~~

* **Traditional Makefiles**: Compatible with standard make
* **Cross-compilation**: Support for target architecture selection
* **Dependency Tracking**: Automatic rebuild on changes
* **Installation**: Standard install targets

CMake Build  
~~~~~~~~~~

* **Modern Build System**: CMake-based configuration
* **IDE Integration**: Support for various development environments
* **Testing Integration**: Automated test execution
* **Package Detection**: Automatic dependency resolution

Driver Scripts
~~~~~~~~~~~~~

* **Unified Interface**: Single command for complete compilation
* **Option Processing**: Compatible with standard compiler interfaces
* **Tool Coordination**: Manages multi-pass compilation
* **Error Handling**: Comprehensive error reporting
