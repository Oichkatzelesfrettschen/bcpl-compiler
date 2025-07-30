# BCPL Compiler Development Container

This directory contains the development container configuration for the BCPL Compiler project, providing a consistent Ubuntu 24.04 development environment.

Use `../select-devcontainer.sh ubuntu` from the repository root to ensure the Ubuntu configuration is active.

## What's Included

### Development Tools
- **Build Tools**: GCC, G++, Make, CMake, Ninja, Autotools
- **Debugging**: GDB, Valgrind, Strace, Ltrace
- **Analysis**: Cppcheck, Clang-format, Clang-tidy
- **Documentation**: Doxygen, Graphviz
- **Cross-compilation**: Multilib support for i386

### VS Code Extensions
- C/C++ Extension Pack
- CMake Tools
- CMake Language Support
- Makefile Tools
- GitHub Actions
- GitLens
- JSON support

### Useful Aliases
- `bcpl-build` - Build the BCPL compiler
- `bcpl-test` - Run BCPL tests
- `bcpl-validate` - Validate the build
- `cmake-build` - Build using CMake
- `cmake-clean` - Clean CMake build directory
- Standard Git aliases (`gs`, `ga`, `gc`, etc.)

## Getting Started

1. **Open in VS Code**: Use the "Reopen in Container" prompt or the Command Palette
2. **Wait for Setup**: The container will automatically run the setup script
3. **Start Developing**: All tools are ready to use

## Manual Setup

If you need to run the setup manually:

```bash
bash .devcontainer/setup.sh
```

## Building the Project

Once in the container, you can build the BCPL compiler using any of the provided build scripts:

```bash
# Using the project's build script
./build.sh

# Using CMake directly
mkdir -p build && cd build
cmake ..
make

# Using the provided aliases
cmake-clean
cd build && cmake ..
cmake-build
```

## Testing

Run the test suite:

```bash
./test_bcpl.sh
# or
bcpl-test
```

## Documentation

Generate documentation:

```bash
doxygen
```

## Cross-Platform Development

The container includes cross-compilation tools for building on different architectures. See the project's build scripts for architecture-specific builds.

## Troubleshooting

If you encounter issues:

1. **Rebuild Container**: Use VS Code's "Rebuild Container" command
2. **Check Logs**: Look at the terminal output during container creation
3. **Manual Setup**: Run the setup script manually if needed

## Container Configuration

- **Base Image**: `mcr.microsoft.com/devcontainers/base:ubuntu-24.04`
- **User**: `vscode` (non-root)
- **Workspace**: `/workspace`
- **Shell**: Zsh with Oh My Zsh (fallback to Bash)

The container is configured for optimal C/C++ development with debugging capabilities and cross-platform build support.
