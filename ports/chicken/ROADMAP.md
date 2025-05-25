# BCPL to Chicken Scheme Porting Roadmap

This document outlines a proposed path for porting the BCPL compiler and runtime to [Chicken Scheme](https://call-cc.org/).  The intent is to leverage Chicken's compiler toolchain and egg ecosystem to provide a Scheme-based implementation that mirrors the original C codebase while enabling exploratory research into alternative representations and optimizations.

## Goals

1. **Functional Parity** – The Chicken port should eventually compile existing BCPL sources and execute the standard test suite.
2. **Incremental Translation** – Components will be rewritten in Scheme gradually, maintaining interoperability with the existing C code via foreign function interfaces (FFI).
3. **Portability** – Generated binaries should run on any platform supported by Chicken Scheme.
4. **Maintainability** – Scheme modules should be documented and structured to encourage contributions from the community.

## Phases

### 1. Bootstrapping
- Establish a minimal driver in Scheme (`main.scm`) that mimics the behaviour of the native `bcplc` wrapper.
- Provide build instructions using `csc` to generate an executable.
- Validate that the stub can invoke the existing runtime written in C.

### 2. Lexer and Parser
- Translate the lexical analyser (`pt.c`) and parser components into Scheme.
- Implement parsing utilities using Chicken's pattern matching and macro facilities.
- Ensure compatibility with the original syntax and semantics by running the regression tests.

### 3. Intermediate Representation
- Recreate the OCODE representation and associated transformation passes.
- Investigate using hygienic macros for improved safety while preserving the original algorithms.
- Document the correspondence between the C structures and their Scheme counterparts.

### 4. Code Generation
- Reimplement `cg.c` and associated backend pieces in Scheme.
- Explore generating C or assembly via Chicken's foreign-code facilities for performance‑critical paths.

### 5. Runtime System
- Translate essential runtime support (`rt.s`, `su.s`, etc.) into Scheme libraries where feasible.
- Interface with remaining assembly components using FFI calls or inline assembly.
- Provide hooks for future enhancements such as tracing or instrumentation.

### 6. Packaging and Distribution
- Create a Chicken "egg" for the compiler so that users can install the port with `chicken-install`.
- Integrate tests with the standard `make test` workflow.
- Document cross‑compilation options and environment requirements.

## Contributing

Contributions are welcome in the form of pull requests or issue reports.  Please include unit tests for any new Scheme modules and follow the style of the existing code.  Refer to this roadmap when proposing substantial changes so that the overall direction remains coherent.

