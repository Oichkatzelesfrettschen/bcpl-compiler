# BCPL Compiler Development Containers

This directory holds multiple devcontainer configurations for VS Code. Use the
`select-devcontainer.sh` script in the repository root to switch between the
available setups.

- **Ubuntu 24.04** – stable development environment.
- **Debian Sid** – bleeding-edge toolchain for experimentation.

The script updates the symlinks `Dockerfile`, `setup.sh` and
`devcontainer.json` to point at the chosen variant files.
