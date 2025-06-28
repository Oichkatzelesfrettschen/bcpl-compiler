# CMakeLists.txt for Modern BCPL Code Generator
# Comprehensive build system for the modernized architecture

cmake_minimum_required(VERSION 3.20)
project(bcpl_modern_compiler 
    VERSION 1.0.0
    DESCRIPTION "Modern C23 BCPL Compiler"
    LANGUAGES C CXX
)

# =============================================================================
# INCLUDE CUSTOM MODULES
# =============================================================================

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(Options)

# =============================================================================
# MODULAR PROJECT LAYOUT
# =============================================================================

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)

# =============================================================================
# ENABLE TESTING
# =============================================================================

enable_testing()

# =============================================================================
# WORKFLOW WRAPPERS (external scripts)
# =============================================================================
if(ENABLE_PGO)
  message(STATUS "Adding PGO build target via build_pgo.sh")
  add_custom_target(pgo
    COMMAND ${CMAKE_SOURCE_DIR}/build_pgo.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Profile-Guided Optimization build"
  )
endif()
if(ENABLE_MAX_PERF)
  message(STATUS "Adding max performance build target via build_max_performance.sh")
  add_custom_target(max_performance
    COMMAND ${CMAKE_SOURCE_DIR}/build_max_performance.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Max hardware-specific performance build"
  )
endif()
if(ENABLE_PORTABLE_PERF)
  message(STATUS "Adding portable performance build target via build_portable_optimized.sh")
  add_custom_target(portable_performance
    COMMAND ${CMAKE_SOURCE_DIR}/build_portable_optimized.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Portable performance baseline build"
  )
endif()
if(ENABLE_VALGRIND)
  # valgrind target defined in Options.cmake via valgrind custom target for tests
endif()
if(ENABLE_COVERAGE)
  # coverage target defined in Options.cmake via coverage custom target
endif()

# =============================================================================
# ORCHESTRATION AND MODULAR INCLUSION
# =============================================================================

# Entire monolithic build logic moved into src/, tests/, docs/
# Monolithic sections removed as per new project structure

return()  # End root CMake processing after including subdirectories
