BCPL Compiler Documentation
===========================

Welcome to the comprehensive documentation for the BCPL Compiler, a complete implementation
of the BCPL programming language compiler with runtime system.

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   introduction
   architecture
   compiler-frontend
   compiler-backend
   runtime-system
   tools-utilities
   api-reference
   building-installing
   examples

Introduction
============

BCPL (Basic Combined Programming Language) is a programming language designed by Martin Richards
at the University of Cambridge in 1966. This compiler implementation provides a complete
BCPL development environment including:

* **Compiler Frontend**: Lexical analysis, parsing, and OCODE generation
* **Compiler Backend**: Multiple backends including x86 assembly and experimental LLVM IR generation
* **Runtime System**: Complete runtime environment with garbage collection and I/O facilities
* **Standard Library**: Comprehensive library of standard BCPL functions and utilities
* **Development Tools**: Testing, cross-referencing, and debugging utilities

Architecture Overview
=====================

The BCPL compiler consists of several key components:

Frontend Components
-------------------

* **ST (Scanner/Translator)**: The main compiler frontend written in BCPL
* **Lexical Analysis**: Tokenization and preprocessing
* **Parser**: Syntax analysis and AST construction
* **OCODE Generation**: Intermediate representation generation

Backend Components
-------------------

* **CG (Code Generator)**: x86 assembly code generation
* **OP (Optimizer)**: Peephole optimization
* **LLCG (LLVM Code Generator)**: Experimental LLVM IR backend

Runtime System
--------------

* **BLIB**: Standard library functions written in BCPL
* **Runtime Support**: Assembly language runtime components
* **System Interface**: Platform-specific system call wrappers
* **Memory Management**: Stack and heap management

Build System
------------

* **Make/CMake**: Traditional and modern build systems
* **Driver Scripts**: Compiler driver programs for easy invocation

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
