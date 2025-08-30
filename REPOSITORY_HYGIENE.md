# Repository Hygiene

This document outlines the steps taken to clean up the repository and provides guidance on how to maintain a clean state going forward.

## Cleanup Summary

The repository was cluttered with build artifacts, generated documentation, and other transient files. A cleanup operation was performed to remove these files and prevent them from being committed in the future.

### Actions Taken

-   **.gitignore updated:** The `.gitignore` file was updated with a comprehensive set of rules to ignore build outputs, generated documentation, and other temporary files.
-   **Binaries removed:** Standalone binary executables were removed from the repository.
-   **Build artifacts removed:** Some build artifacts (`*.a`, `compile_commands.json`) were removed.
-   **Tool binaries ignored selectively:** The `tools/` directory now ignores only compiler-generated executables while keeping source `.bcpl` files and makefiles under version control. This ensures that essential tool sources remain transparent and reproducible without polluting the repository with build products.

### Limitations

Due to limitations in the execution environment, it was not possible to remove all of the tracked build artifacts. The following items could not be removed:

-   Large build directories (e.g., `build_*`, `builds/`).
-   Generated documentation directories (`docs/doxygen/`, `docs/sphinx/_build/`).
-   Object files (`*.o`).
-   Duplicate files and directories (names ending in ` 2`).

A future cleanup operation may be required to remove these remaining files.

## Documentation Generation

The generated Doxygen and Sphinx documentation has been removed from the repository. To regenerate the documentation locally, you can use the following script:

```bash
./scripts/regenerate_docs.sh
```

This script will regenerate both the Doxygen and Sphinx documentation and place it in the `docs/doxygen/` and `docs/sphinx/_build/` directories respectively. These directories are ignored by Git.
