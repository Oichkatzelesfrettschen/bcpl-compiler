# 🚀 MODERNIZED BCPL COMPILER TEST SUITE
# Complete Validation of Tech Debt Elimination
# Copyright (c) 2025 BCPL Modernization Team

cmake_minimum_required(VERSION 3.20)

message(STATUS "🧪 Building comprehensive modernization test suite...")

# ============================================================================
# TEST CONFIGURATION
# ============================================================================

# Include test framework
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_check_modules(CHECK check)
endif()

if(NOT CHECK_FOUND)
    message(STATUS "📦 Installing minimal test framework...")
    # Use minimal built-in testing approach
    set(TEST_FRAMEWORK "minimal")
else()
    set(TEST_FRAMEWORK "check")
    message(STATUS "✅ Using libcheck test framework")
endif()

# Include centralized options
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
include(Options)

# ============================================================================
# MODERNIZATION VALIDATION TESTS
# ============================================================================

# Consolidated test executable built from all unit test sources
set(TEST_SOURCES
    bcpl_tests.c
    test_architecture.c
    test_assembly_elimination.c
    test_memory.c          # Vector allocation and refcount tests
    test_memory_safety.c
    test_performance.c
    test_platform_abstraction.c
    test_runtime.c
)

add_executable(bcpl_tests ${TEST_SOURCES})

target_include_directories(bcpl_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/src/runtime
)

target_link_libraries(bcpl_tests PRIVATE bcpl_runtime)

target_compile_definitions(bcpl_tests PRIVATE
    BCPL_TEST_BUILD=1
    BCPL_MODERNIZED=1
    BCPL_C23_RUNTIME=1
    BCPL_NO_ASSEMBLY=1
    BCPL_UNIVERSAL_PLATFORM=1
    BCPL_SINGLE_BINARY=1
)
target_compile_options(bcpl_tests PRIVATE
    ${BCPL_BASE_C_FLAGS}
    ${BCPL_ARCH_FLAGS}
    -DBITS=${BCPL_ARCH_BITS}
    -DBCPL_PLATFORM_${BCPL_PLATFORM}=1
    -DTARGET_ARCH_${TARGET_ARCH}=1
)

# Apply optional tooling flags
apply_tooling_flags(bcpl_tests)

# ============================================================================
# TEST EXECUTION
# ============================================================================

add_test(NAME bcpl_tests COMMAND bcpl_tests)

# ============================================================================
# INTEGRATION TESTS
# ============================================================================

# Test the complete compiler build
add_test(NAME compiler_integration
         COMMAND ${CMAKE_COMMAND} 
                 --build ${CMAKE_BINARY_DIR} 
                 --target all)

# Test BCPL compilation with modernized runtime
if(EXISTS ${CMAKE_SOURCE_DIR}/test_hello.bcpl AND EXISTS ${CMAKE_BINARY_DIR}/src/bcplc)
    add_test(NAME bcpl_compilation
             COMMAND ${CMAKE_BINARY_DIR}/src/bcplc
                     ${CMAKE_SOURCE_DIR}/test_hello.bcpl
             WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

    set_tests_properties(bcpl_compilation PROPERTIES
        DEPENDS compiler_integration)
endif()

# ============================================================================
# SUCCESS REPORTING
# ============================================================================

message(STATUS "")
message(STATUS "🎯 Test Suite Configuration Complete!")
message(STATUS "✅ Runtime modernization tests")
message(STATUS "✅ Platform compatibility tests") 
message(STATUS "✅ Performance validation tests")
message(STATUS "✅ Assembly elimination tests")
message(STATUS "✅ Integration tests")
message(STATUS "")
message(STATUS "Run tests with: make test")
message(STATUS "")

