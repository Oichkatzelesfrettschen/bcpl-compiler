cmake_minimum_required(VERSION 3.20)

# Modern BCPL Compiler Build System
project(BCPL 
    VERSION 2025.1.0
    DESCRIPTION "Modernized BCPL Compiler with C23 Runtime"
    LANGUAGES C ASM
)

# Compiler Requirements - Accept AppleClang and Clang
if(NOT CMAKE_C_COMPILER_ID MATCHES ".*Clang.*")
    message(FATAL_ERROR "Clang is required to build the modernized BCPL compiler")
endif()

# C23 Standard with Enhanced Features
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Build Configuration
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =============================================================================
# PLATFORM AND ARCHITECTURE DETECTION
# =============================================================================

if(NOT DEFINED BITS)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(BITS 64)
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(BITS 32)
    else()
        set(BITS 16)
    endif()
endif()

message(STATUS "Building BCPL for ${BITS}-bit architecture on ${CMAKE_SYSTEM_NAME}")

# Platform-specific settings
if(APPLE)
    set(BCPL_PLATFORM "MACOS")
    set(BCPL_PLATFORM_SOURCES platform/macos.c)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(BCPL_PLATFORM "LINUX")
    set(BCPL_PLATFORM_SOURCES platform/linux.c)
elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
    set(BCPL_PLATFORM "FREEBSD")
    set(BCPL_PLATFORM_SOURCES platform/freebsd.c)
else()
    set(BCPL_PLATFORM "GENERIC")
    set(BCPL_PLATFORM_SOURCES platform/generic.c)
endif()

# Include directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# =============================================================================
# COMPILER FLAGS
# =============================================================================

set(BCPL_C_FLAGS
    -std=c23
    -Wall -Wextra -Wpedantic
    -DBITS=${BITS}
    -DBCPL_PLATFORM_${BCPL_PLATFORM}=1
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    list(APPEND BCPL_C_FLAGS -g3 -O0 -DDEBUG=1)
else()
    list(APPEND BCPL_C_FLAGS -O2 -g)
endif()

# =============================================================================
# MODERNIZED BCPL RUNTIME LIBRARY
# =============================================================================

set(BCPL_RUNTIME_SOURCES
    runtime/bcpl_runtime.c
    runtime/universal_startup.c
    runtime/memory.c
    runtime/io.c
    runtime/strings.c
    runtime/vectors.c
    runtime/startup.c
    runtime/rt.c
    ${BCPL_PLATFORM_SOURCES}
)

# Create the modern runtime library
add_library(bcpl_runtime STATIC ${BCPL_RUNTIME_SOURCES})
target_compile_options(bcpl_runtime PRIVATE ${BCPL_C_FLAGS})
apply_tooling_flags(bcpl_runtime)

# =============================================================================
# COMPILER BACKEND TOOLS
# =============================================================================

# Code Generator
add_executable(cg cg.c oc.c)
target_compile_options(cg PRIVATE ${BCPL_C_FLAGS})
target_link_libraries(cg PRIVATE bcpl_runtime)
apply_tooling_flags(cg)

# Optimizer
add_executable(op op.c pt.c)
target_compile_options(op PRIVATE ${BCPL_C_FLAGS})
target_link_libraries(op PRIVATE bcpl_runtime)
apply_tooling_flags(op)

# =============================================================================
# BCPL COMPILER FRONT-END (st) - SIMPLIFIED C BOOTSTRAP
# =============================================================================

# Use a C-based bootstrap approach that works on all platforms
message(STATUS "Building BCPL compiler front-end with C bootstrap")

# Generate assembly from OCODE using cg and op
add_custom_command(
    OUTPUT st.s
    COMMAND $<TARGET_FILE:cg> < ${CMAKE_CURRENT_SOURCE_DIR}/st.O | $<TARGET_FILE:op> > st.s
    DEPENDS cg op
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Compiling BCPL compiler front-end from OCODE"
    VERBATIM
)

# Assemble the BCPL-generated code (using C compiler as assembler)
add_custom_command(
    OUTPUT st_bcpl.o
    COMMAND ${CMAKE_C_COMPILER} -c -o st_bcpl.o st.s
    DEPENDS st.s
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Assembling BCPL compiler front-end"
    VERBATIM
)

# Create the st executable by linking BCPL object with C bootstrap and runtime
add_executable(st_tmp bootstrap_main.c)
target_compile_options(st_tmp PRIVATE ${BCPL_C_FLAGS})
target_link_libraries(st_tmp PRIVATE bcpl_runtime)
apply_tooling_flags(st_tmp)

# Create the final st executable with both C bootstrap and BCPL code
add_custom_command(
    OUTPUT st
    COMMAND ${CMAKE_C_COMPILER} ${CMAKE_CURRENT_SOURCE_DIR}/bootstrap_main.c st_bcpl.o -I${CMAKE_CURRENT_SOURCE_DIR}/include -L${CMAKE_CURRENT_BINARY_DIR} -lbcpl_runtime -o st
    DEPENDS st_bcpl.o bcpl_runtime bootstrap_main.c
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Creating BCPL compiler executable"
    VERBATIM
)

# Create a target that other targets can depend on
add_custom_target(st_executable ALL DEPENDS st)

# =============================================================================
# ENHANCED LLVM BACKEND
# =============================================================================

find_package(LLVM QUIET CONFIG)
if(LLVM_FOUND)
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    
    include_directories(${LLVM_INCLUDE_DIRS})
    separate_arguments(LLVM_DEFINITIONS_LIST UNIX_COMMAND "${LLVM_DEFINITIONS}")
    add_definitions(${LLVM_DEFINITIONS_LIST})
    
    llvm_map_components_to_libnames(LLCG_LIBS
        core bitwriter native analysis target
    )
    
    add_executable(llcg llcg.cpp)
    target_compile_options(llcg PRIVATE ${BCPL_CXX_FLAGS})
    target_link_libraries(llcg PRIVATE ${LLCG_LIBS} bcpl_runtime)
    apply_tooling_flags(llcg)
endif()

# =============================================================================
# INSTALLATION
# =============================================================================

install(TARGETS cg op bcpl_runtime
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

if(LLVM_AVAILABLE)
    install(TARGETS llcg RUNTIME DESTINATION bin)
endif()

# Install the BCPL compiler components
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/st DESTINATION bin)

# Install the bcplc driver script
install(PROGRAMS bcplc DESTINATION bin)

install(DIRECTORY include/ DESTINATION include/bcpl)

# =============================================================================
# SUMMARY
# =============================================================================

message(STATUS "=== BCPL Compiler Build Configuration ===")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Platform: ${BCPL_PLATFORM}")
message(STATUS "Architecture: ${BITS}-bit")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "LLVM Backend: ${LLVM_AVAILABLE}")
message(STATUS "Runtime: Pure C23 implementation")
message(STATUS "==========================================")
