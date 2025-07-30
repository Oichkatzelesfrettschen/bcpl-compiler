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

# Test 1: Runtime modernization validation
add_executable(test_runtime_modernization
    test_runtime.c
    test_platform_abstraction.c
    test_memory_safety.c
)

target_include_directories(test_runtime_modernization PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/src/runtime
)

target_link_libraries(test_runtime_modernization PRIVATE
    bcpl_runtime
)

target_compile_definitions(test_runtime_modernization PRIVATE
    BCPL_TEST_BUILD=1
    BCPL_MODERNIZED=1
)

# Test 2: Cross-platform compatibility
add_executable(test_cross_platform
    test_cross_platform.c
)

target_include_directories(test_cross_platform PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(test_cross_platform PRIVATE
    bcpl_runtime
)

add_executable(test_architecture
    test_architecture.c
)

target_include_directories(test_architecture PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(test_architecture PRIVATE
    bcpl_runtime
)

# Test 3: Performance validation
add_executable(test_performance
    test_performance.c
)

target_include_directories(test_performance PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(test_performance PRIVATE
    bcpl_runtime
)

# Test 4: Assembly elimination validation
add_executable(test_no_assembly
    test_assembly_elimination.c
)

target_include_directories(test_no_assembly PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(test_no_assembly PRIVATE
    bcpl_runtime
)

# Apply tooling flags to each test executable
apply_tooling_flags(test_runtime_modernization)
apply_tooling_flags(test_cross_platform)
apply_tooling_flags(test_architecture)
apply_tooling_flags(test_performance)
apply_tooling_flags(test_no_assembly)

# ============================================================================
# TEST EXECUTION
# ============================================================================

# Register all tests with CTest
add_test(NAME runtime_modernization
         COMMAND test_runtime_modernization)

add_test(NAME cross_platform
         COMMAND test_cross_platform)

add_test(NAME architecture_validation
         COMMAND test_architecture)

add_test(NAME performance_validation 
         COMMAND test_performance)

add_test(NAME assembly_elimination 
         COMMAND test_no_assembly)

# ============================================================================
# INTEGRATION TESTS
# ============================================================================

# Test the complete compiler build
add_test(NAME compiler_integration
         COMMAND ${CMAKE_COMMAND} 
                 --build ${CMAKE_BINARY_DIR} 
                 --target all)

# Test BCPL compilation with modernized runtime
if(EXISTS ${CMAKE_SOURCE_DIR}/test_hello.bcpl)
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


# Testing configuration for BCPL Compiler

# Collect all test sources
set(TEST_SOURCES
    test_runtime.c
    test_platform_abstraction.c
    test_memory_safety.c
    test_architecture.c
    test_cross_platform.c
    test_performance.c
    test_assembly_elimination.c
)

add_executable(bcpl_tests ${TEST_SOURCES})

# Tests depend on the runtime library built in src/
# Include directories to access internal headers

target_include_directories(bcpl_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_SOURCE_DIR}/src/runtime
)

target_link_libraries(bcpl_tests PRIVATE bcpl_runtime)

target_compile_definitions(bcpl_tests PRIVATE BCPL_TEST_BUILD=1)
target_compile_options(bcpl_tests PRIVATE
    ${BCPL_BASE_C_FLAGS}
    ${BCPL_ARCH_FLAGS}
    -DBITS=${BCPL_ARCH_BITS}
    -DBCPL_PLATFORM_${BCPL_PLATFORM}=1
    -DTARGET_ARCH_${TARGET_ARCH}=1
)

# Apply optional tooling flags
apply_tooling_flags(bcpl_tests)

# Register with CTest
add_test(NAME bcpl_tests COMMAND bcpl_tests)
