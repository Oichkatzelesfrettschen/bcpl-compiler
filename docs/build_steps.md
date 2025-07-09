# Build Instructions for bcpl-compiler

This document summarizes the recommended steps for setting up a development environment and building
`bcpl-compiler` from source.  The repository includes a `setup.sh` script that installs
all required packages (compilers, emulators, analysis tools such as `valgrind`,
`trace-cmd`, `strace`, etc.).

1. **Run the setup script**
   ```sh
   sudo ./setup.sh
   ```
   The script enables additional package repositories, installs a wide array of
   developer tools and instrumentations, then configures multi‑architecture
   cross‑compilers.  All output is logged to `setup.log` for later inspection.

2. **Build the compiler**
   ```sh
   ./scripts/makeall.sh
   ./scripts/makeall.sh install
   ```
   By default a 64‑bit runtime is produced.  Use `BITS=32` for a 32‑bit
   build or `BITS=16` for the experimental IA‑16 target.  The `makeall.sh`
   helper verifies required tools before invoking the individual Makefiles.

3. **Run the tests**
   ```sh
   make -C tools test
   ```
   Successful output ends with `119 TESTS COMPLETED, 0 FAILURE(S)`.

4. **Perform a sanitizer-enabled build**
   The `hog_test.sh` helper script rebuilds the compiler with AddressSanitizer
   and UndefinedBehaviorSanitizer enabled.  It cleans the `src` tree, compiles
   with the additional flags and runs the tool tests:

   ```sh
   ./scripts/hog_test.sh
   ```
   Any runtime errors are printed with full sanitizer backtraces.  This is
   useful when tracking elusive crashes.

If the setup script cannot access the network (for example in a restricted
build environment), package installation will fail and some tools may be
missing.  In that case build errors such as segmentation faults can occur
because required runtime components or debugging tools are unavailable.
Consult `setup.log` and verify that tools like `clang`, `as`, `ld`, `valgrind`,
and `strace` are present on the `PATH`.
