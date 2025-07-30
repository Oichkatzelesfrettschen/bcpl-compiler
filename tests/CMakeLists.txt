# 🚀 MODERNIZED BCPL COMPILER TEST SUITE
# Complete Validation of Tech Debt Elimination
# Copyright (c) 2025 BCPL Modernization Team

cmake_minimum_required(VERSION 3.20)

# Ensure tests use the same native architecture as the main build
if(APPLE AND CMAKE_SYSTEM_PROCESSOR MATCHES "arm64")
    message(STATUS "🏗️ Building tests for native ARM64 architecture")
    # No architecture forcing - use native ARM64 for full modernization
endif()

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

# Build the runtime library when invoked stand-alone
if(NOT TARGET bcpl_runtime)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../src ${CMAKE_BINARY_DIR}/src)
endif()

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
add_executable(test_platform_compatibility
    test_cross_platform.c
    test_architecture.c
)

target_include_directories(test_platform_compatibility PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(test_platform_compatibility PRIVATE
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
apply_tooling_flags(test_platform_compatibility)
apply_tooling_flags(test_performance)
apply_tooling_flags(test_no_assembly)

# ============================================================================
# TEST EXECUTION
# ============================================================================

# Register all tests with CTest
add_test(NAME runtime_modernization 
         COMMAND test_runtime_modernization)

add_test(NAME platform_compatibility 
         COMMAND test_platform_compatibility)

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
