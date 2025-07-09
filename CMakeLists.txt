# =============================================================================
# BCPL Multi-Architecture Compiler - Modern CMake Build System
# =============================================================================

cmake_minimum_required(VERSION 3.20)

project(BCPL_MultiArch
    VERSION 2025.1.0
    DESCRIPTION "Multi-Architecture BCPL Compiler with C23 Runtime"
    HOMEPAGE_URL "https://github.com/eirikr/bcpl-compiler"
    LANGUAGES C CXX ASM
)

# =============================================================================
# CMAKE CONFIGURATION
# =============================================================================

# Modern CMake practices
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compile_commands.json for analysis tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use folders for organization in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# =============================================================================
# MODULE PATH AND CONFIGURATION
# =============================================================================

# Add our custom CMake modules
list(APPEND CMAKE_MODULE_PATH 
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
)

# Include our configuration modules in the correct order
include(ArchitectureConfig)    # Architecture configuration and options
include(Options)               # Build options and tooling  
include(PlatformConfig)        # Platform-specific configuration

# =============================================================================
# COMPILER VALIDATION
# =============================================================================

# Ensure we have a supported compiler
if(NOT CMAKE_C_COMPILER_ID MATCHES ".*Clang.*" AND NOT CMAKE_C_COMPILER_ID STREQUAL "GNU")
    message(FATAL_ERROR 
        "Unsupported compiler: ${CMAKE_C_COMPILER_ID}. "
        "BCPL requires Clang or GCC for C23 support."
    )
endif()

# =============================================================================
# BUILD CONFIGURATION
# =============================================================================

# Set base compiler flags
set(BCPL_BASE_C_FLAGS
    -Wall -Wextra -Wpedantic
    -fdiagnostics-color=always
    ${BCPL_ARCH_DEFINES}
    -DBCPL_ARCH_BITS=${BCPL_ARCH_BITS}
    -DBCPL_WORD_SIZE=${BCPL_ARCH_WORD_SIZE}
)

# Debug vs Release flags
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(APPEND BCPL_BASE_C_FLAGS -g3 -O0 -DDEBUG=1 -DBCPL_DEBUG=1)
elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    list(APPEND BCPL_BASE_C_FLAGS -g -O2 -DNDEBUG=1)
else()
    list(APPEND BCPL_BASE_C_FLAGS -O2 -DNDEBUG=1)
endif()

# =============================================================================
# SUBDIRECTORIES
# =============================================================================

# Add subdirectories in logical order
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)

# =============================================================================
# TESTING
# =============================================================================

enable_testing()

# =============================================================================
# ARCHITECTURE SUMMARY
# =============================================================================

message(STATUS "")
message(STATUS "🏗️  ===== BCPL Multi-Architecture Build Configuration =====")
message(STATUS "Project: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "Target Architecture: ${BCPL_RESOLVED_ARCH}")
message(STATUS "Word Size: ${BCPL_ARCH_WORD_SIZE} bytes")
message(STATUS "Features: ${BCPL_ARCH_FEATURES}")
message(STATUS "")
message(STATUS "Options:")
message(STATUS "  Multi-arch support: ${BCPL_ENABLE_MULTI_ARCH}")
message(STATUS "  Cross-compilation: ${BCPL_ENABLE_CROSS_COMPILE}")
message(STATUS "  Universal Binary: ${BCPL_ENABLE_UNIVERSAL_BINARY}")
message(STATUS "  Architecture optimization: ${BCPL_OPTIMIZE_FOR_ARCH}")
message(STATUS "  Native instructions: ${BCPL_USE_NATIVE_INSTRUCTIONS}")
message(STATUS "")
message(STATUS "Enabled Architectures:")
foreach(arch arm64 x86_64 arm32 x86_32 x86_16)
    string(TOUPPER ${arch} ARCH_UPPER)
    if(BCPL_ENABLE_${ARCH_UPPER})
        message(STATUS "  ✓ ${arch}")
    else()
        message(STATUS "  ✗ ${arch}")
    endif()
endforeach()
message(STATUS "====================================================")
message(STATUS "")

# =============================================================================
# LEGACY SCRIPT INTEGRATION (OPTIONAL)
# =============================================================================

# Optional PGO build target
if(ENABLE_PGO)
    message(STATUS "Adding PGO build target")
    add_custom_target(pgo
        COMMAND ${CMAKE_SOURCE_DIR}/build_pgo.sh
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Profile-Guided Optimization build"
    )
endif()

# Optional max performance build target  
if(ENABLE_MAX_PERF)
    message(STATUS "Adding max performance build target")
    add_custom_target(max_performance
        COMMAND ${CMAKE_SOURCE_DIR}/build_max_performance.sh
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Max hardware-specific performance build"
    )
endif()

