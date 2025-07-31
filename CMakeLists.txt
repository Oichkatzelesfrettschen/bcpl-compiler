cmake_minimum_required(VERSION 3.20)

project(BCPL_Compiler
    VERSION 2025.1.0
    DESCRIPTION "Modernized BCPL Compiler"
    LANGUAGES C ASM)

# Generate compile_commands.json for tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use the C23 standard consistently
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# -----------------------------------------------------------------------------
# CMake module path and configuration
# -----------------------------------------------------------------------------
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

include(ArchitectureConfig)    # Target architecture handling
include(CompilerFlags)         # Common compiler options
include(Options)               # Optional tooling flags
include(PlatformConfig)        # Platform-specific helpers

# Optionally build the unit tests
option(ENABLE_TESTS "Build BCPL test suite" ON)

# -----------------------------------------------------------------------------
# Subdirectories
# -----------------------------------------------------------------------------
add_subdirectory(src)
if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
add_subdirectory(docs)
