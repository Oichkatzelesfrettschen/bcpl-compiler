# Repository Hygiene

This document captures conventions for keeping the repository free from unwanted
build artifacts while retaining source files that describe tooling. Binaries
produced during the build of BCPL tools can clutter history and lead to
unnecessary conflicts. They are generated deterministically from the `bcplc`
compiler and therefore do not need to be tracked.

The `.gitignore` file now ignores only the compiled executables in `tools/`
(`cmpltest`, `xref` and `gpm`) and their object files. The sources and
`Makefile` remain version-controlled so that the build remains reproducible.
