Introduction
============

The BCPL Compiler is a complete implementation of the BCPL (Basic Combined Programming Language) 
programming language, originally designed by Martin Richards at Cambridge University in 1966. 
BCPL was influential in the development of the C programming language and Unix.

What is BCPL?
-------------

BCPL is a systems programming language that emphasizes simplicity and portability. Key features include:

* Simple, recursive-descent syntax
* Single data type (word)
* Powerful pointer manipulation
* Block structure with lexical scoping
* Coroutine support
* Machine-independent design

This Implementation
-------------------

This BCPL compiler implementation provides:

* Complete BCPL language support according to the original specification
* Multiple backend targets (x86, LLVM)
* Peephole optimization
* Standard library implementation
* Development tools and utilities

The compiler is written primarily in C with the BCPL standard library implemented in BCPL itself,
demonstrating the self-hosting capabilities of the language.

History
-------

BCPL influenced many later languages and systems:

* B language (precursor to C)
* Early Unix utilities
* Portable systems programming concepts
* Virtual machine and bytecode concepts

Getting Started
---------------

To start using the BCPL compiler, see the :doc:`building-installing` guide for installation
instructions and basic usage examples.
