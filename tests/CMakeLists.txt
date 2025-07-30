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

set(TEST_SOURCES
    test_runtime.c
    test_platform_abstraction.c
    test_memory_safety.c
    test_cross_platform.c
    test_architecture.c
    test_performance.c
    test_assembly_elimination.c
)

foreach(src ${TEST_SOURCES})
    get_filename_component(test_name ${src} NAME_WE)
    add_executable(${test_name} ${src})
    target_include_directories(${test_name} PRIVATE
        ${CMAKE_SOURCE_DIR}/src/include
        ${CMAKE_SOURCE_DIR}/src/runtime
    )
    target_compile_definitions(${test_name} PRIVATE
        BCPL_TEST_BUILD=1
        BCPL_MODERNIZED=1
    )
    target_link_libraries(${test_name} PRIVATE bcpl_runtime)
    apply_tooling_flags(${test_name})
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()

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
