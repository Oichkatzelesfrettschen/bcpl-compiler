# =============================================================================
# BCPL Compiler - Common Compiler Flags
# Centralizes warning levels and optimization settings used across targets.
# =============================================================================

# Guard against repeated inclusion
if(BCPL_COMPILER_FLAGS_INCLUDED)
    return()
endif()
set(BCPL_COMPILER_FLAGS_INCLUDED TRUE)

message(STATUS "Loading common compiler flags...")

# -----------------------------------------------------------------------------
# Base warning flags and architecture definitions
# -----------------------------------------------------------------------------
set(BCPL_BASE_C_FLAGS
    -Wall -Wextra -Wpedantic          # Standard warning levels
    -fdiagnostics-color=always        # Colorize compiler diagnostics
    -DBCPL_ARCH_BITS=${BCPL_ARCH_BITS}
    -DBCPL_WORD_SIZE=${BCPL_ARCH_WORD_SIZE}
    ${BCPL_ARCH_DEFINES}              # From ArchitectureConfig.cmake
)

# -----------------------------------------------------------------------------
# Optimization levels
#   Debug          : no optimization, full debug info (g3)
#   RelWithDebInfo : moderate optimization (O2) with debug symbols (g)
#   Release        : optimized build (O2) without debug info
# -----------------------------------------------------------------------------
# Normalize build type for single-config generators
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
    # Default to Release if build type is unspecified
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
endif()

string(TOUPPER "${CMAKE_BUILD_TYPE}" _BCPL_BUILD_TYPE)

if(CMAKE_CONFIGURATION_TYPES)
    # Multi-config generator: use generator expressions
    list(APPEND BCPL_BASE_C_FLAGS
        $<$<CONFIG:Debug>:-g3;-O0;-DDEBUG=1;-DBCPL_DEBUG=1>
        $<$<CONFIG:RelWithDebInfo>:-g;-O2;-DNDEBUG=1>
        $<$<CONFIG:Release>:-O2;-DNDEBUG=1>
    )
else()
    if(_BCPL_BUILD_TYPE STREQUAL "DEBUG")
        list(APPEND BCPL_BASE_C_FLAGS
            -g3      # Maximum debug information
            -O0      # Disable optimization for easier debugging
            -DDEBUG=1 -DBCPL_DEBUG=1
        )
    elseif(_BCPL_BUILD_TYPE STREQUAL "RELWITHDEBINFO")
        list(APPEND BCPL_BASE_C_FLAGS
            -g       # Minimal debug information
            -O2      # Balanced optimization level
            -DNDEBUG=1
        )
    else()
        list(APPEND BCPL_BASE_C_FLAGS
            -O2      # Default optimization level for production
            -DNDEBUG=1
        )
    endif()
endif()

# -----------------------------------------------------------------------------
# Architecture tuning
#   BCPL_OPTIMIZE_FOR_ARCH enables use of BCPL_ARCH_FLAGS such as -march/-mcpu.
#   When BCPL_USE_NATIVE_INSTRUCTIONS is also ON these may resolve to 'native'.
# -----------------------------------------------------------------------------
if(BCPL_OPTIMIZE_FOR_ARCH)
    list(APPEND BCPL_BASE_C_FLAGS ${BCPL_ARCH_FLAGS})
endif()

