cmake_minimum_required(VERSION 3.20)

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
