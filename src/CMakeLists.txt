# =============================================================================
# BCPL Multi-Architecture Source Build Configuration
# =============================================================================

cmake_minimum_required(VERSION 3.20)

# This file expects architecture variables to be set by ArchitectureConfig.cmake
# Variables used: BCPL_RESOLVED_ARCH, BCPL_ARCH_BITS, BCPL_ARCH_SOURCES, etc.

message(STATUS "🔧 Configuring BCPL source build for ${BCPL_RESOLVED_ARCH}")

# =============================================================================
# PLATFORM CONFIGURATION
# =============================================================================

# Map architecture to TARGET_ARCH variable for compatibility
set(TARGET_ARCH ${BCPL_RESOLVED_ARCH})

# Platform-specific settings
if(APPLE)
    set(BCPL_PLATFORM "MACOS")
    set(BCPL_PLATFORM_SOURCES platform/macos.c)
    
    # Enable Universal Binary support if requested
    if(DEFINED CMAKE_OSX_ARCHITECTURES)
        message(STATUS "Universal Binary: ${CMAKE_OSX_ARCHITECTURES}")
    elseif(TARGET_ARCH STREQUAL "arm64")
        set(CMAKE_OSX_ARCHITECTURES "arm64")
    elseif(TARGET_ARCH STREQUAL "x86_64")
        set(CMAKE_OSX_ARCHITECTURES "x86_64")
    endif()
    
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
    ${BCPL_BASE_C_FLAGS}  # From main CMakeLists.txt
    ${BCPL_ARCH_FLAGS}    # From ArchitectureConfig.cmake
    -DBITS=${BCPL_ARCH_BITS}
    -DBCPL_PLATFORM_${BCPL_PLATFORM}=1
    -DTARGET_ARCH_${TARGET_ARCH}=1
)

# Add platform-specific flags
if(APPLE)
    list(APPEND BCPL_C_FLAGS -D_DARWIN_C_SOURCE)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    list(APPEND BCPL_C_FLAGS -D_GNU_SOURCE)
endif()

# =============================================================================
# ARCHITECTURE-SPECIFIC RUNTIME SOURCES
# =============================================================================

# Use architecture-specific runtime if available
set(RUNTIME_SOURCES)
set(ARCH_RUNTIME_FILE "${CMAKE_CURRENT_SOURCE_DIR}/arch/${TARGET_ARCH}/runtime_${TARGET_ARCH}.c")
if(EXISTS ${ARCH_RUNTIME_FILE})
    list(APPEND RUNTIME_SOURCES ${ARCH_RUNTIME_FILE})
    message(STATUS "Using architecture-specific runtime: ${ARCH_RUNTIME_FILE}")
else()
    # Fallback to generic runtime
    list(APPEND RUNTIME_SOURCES runtime/generic_runtime.c)
    message(STATUS "Using generic runtime (arch-specific not found)")
endif()

# Add platform sources
if(BCPL_PLATFORM_SOURCES AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${BCPL_PLATFORM_SOURCES}")
    list(APPEND RUNTIME_SOURCES ${BCPL_PLATFORM_SOURCES})
endif()

# =============================================================================
# BCPL RUNTIME LIBRARY
# =============================================================================

add_library(bcpl_runtime STATIC
    ${RUNTIME_SOURCES}
    runtime/bcpl_runtime.c
    runtime/memory.c
    runtime/io.c
    runtime/strings.c
    runtime/vectors.c
    runtime/startup.c
    runtime/rt.c
)

target_compile_options(bcpl_runtime PRIVATE ${BCPL_C_FLAGS})
target_include_directories(bcpl_runtime PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/arch/${TARGET_ARCH}
)

# Set output name with architecture suffix
set_target_properties(bcpl_runtime PROPERTIES 
    OUTPUT_NAME "bcpl_runtime_${TARGET_ARCH}"
    VERSION ${PROJECT_VERSION}
)

# Apply tooling flags from Options.cmake
apply_tooling_flags(bcpl_runtime)

# =============================================================================
# BCPL CODE GENERATOR
# =============================================================================

# Allow the user to override the OCODE implementation. 64-bit OCODE is
# recommended for 64-bit targets, but the legacy 32-bit OCODE is still
# required for bootstrapping with the prebuilt `st.O` file. The option below
# lets developers switch between the two implementations explicitly.

# By default we build using the legacy 32‑bit OCODE implementation because
# the prebuilt `st.O` file shipped with the sources is generated for that
# format.  The 64‑bit OCODE implementation requires regenerating `st.O` with
# a 64‑bit capable compiler which is not available in this environment.
# Developers can explicitly enable the modern 64‑bit OCODE by toggling the
# option below once a matching `st.O` has been produced.
option(BCPL_USE_64BIT_OCODE "Build with the 64-bit OCODE implementation" OFF)

if(BCPL_USE_64BIT_OCODE)
    message(STATUS "Using 64-bit OCODE implementation for ${TARGET_ARCH}")
    set(OCODE_SOURCES oc.c ocode_64bit.c)
    set(OCODE_DEFINES -DBCPL_USE_64BIT_OCODE=1)
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    set(ST_64_FILE ${CMAKE_CURRENT_SOURCE_DIR}/st_64.O)
    if(NOT EXISTS ${ST_64_FILE})
        add_custom_command(
            OUTPUT ${ST_64_FILE}
            COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/convert_to_64bit_ocode.py ${CMAKE_CURRENT_SOURCE_DIR}/st.O ${ST_64_FILE}
            DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/st.O ${PROJECT_SOURCE_DIR}/scripts/convert_to_64bit_ocode.py
            COMMENT "Converting st.O to 64-bit format"
        )
    endif()
    add_custom_target(st64_gen DEPENDS ${ST_64_FILE})
else()
    message(STATUS "Using legacy 32-bit OCODE implementation for ${TARGET_ARCH}")
    set(OCODE_SOURCES oc.c)
    set(OCODE_DEFINES -DBCPL_USE_64BIT_OCODE=0)
endif()

add_executable(cg cg.c ${OCODE_SOURCES})
target_compile_options(cg PRIVATE ${BCPL_C_FLAGS} ${OCODE_DEFINES})
target_link_libraries(cg PRIVATE bcpl_runtime)
apply_tooling_flags(cg)
set_target_properties(cg PROPERTIES OUTPUT_NAME "cg_${TARGET_ARCH}")

# =============================================================================
# BCPL OPTIMIZER
# =============================================================================

add_executable(op op.c pt.c)
target_compile_options(op PRIVATE ${BCPL_C_FLAGS})
target_link_libraries(op PRIVATE bcpl_runtime)
apply_tooling_flags(op)
set_target_properties(op PROPERTIES OUTPUT_NAME "op_${TARGET_ARCH}")

# =============================================================================
# 64-BIT OCODE TEST PROGRAM
# =============================================================================

if(BCPL_ARCH_BITS EQUAL 64 AND BCPL_USE_64BIT_OCODE)
    add_executable(test_ocode_64bit test_ocode_64bit.c ${OCODE_SOURCES})
    target_compile_options(test_ocode_64bit PRIVATE ${BCPL_C_FLAGS} ${OCODE_DEFINES})
    target_link_libraries(test_ocode_64bit PRIVATE bcpl_runtime)
    apply_tooling_flags(test_ocode_64bit)
    set_target_properties(test_ocode_64bit PROPERTIES OUTPUT_NAME "test_ocode_64bit_${TARGET_ARCH}")
endif()

# =============================================================================
# SYMBOL TABLE GENERATION
# =============================================================================

# Generate architecture-specific symbol table
set(ST_OCODE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/st.O)
if(BCPL_USE_64BIT_OCODE)
    set(ST_OCODE_FILE ${ST_64_FILE})
endif()

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH}
    COMMAND $<TARGET_FILE:cg> -o ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH} < ${ST_OCODE_FILE}
    DEPENDS cg ${ST_OCODE_FILE}
    COMMENT "Generating symbol table for ${TARGET_ARCH} (using prebuilt OCODE)"
)

add_custom_target(st_gen_${TARGET_ARCH} ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH}
)

if(BCPL_USE_64BIT_OCODE)
    add_dependencies(st_gen_${TARGET_ARCH} st64_gen)
endif()

# =============================================================================
# LLVM BACKEND (OPTIONAL)
# =============================================================================

find_package(LLVM QUIET CONFIG)
if(LLVM_FOUND)
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION} - enabling LLVM backend")
    
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
    set_target_properties(llcg PROPERTIES OUTPUT_NAME "llcg_${TARGET_ARCH}")
    set(LLVM_AVAILABLE ON)
else()
    set(LLVM_AVAILABLE OFF)
    message(STATUS "LLVM not found - LLVM backend disabled")
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

# Install the symbol table with architecture suffix
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH} DESTINATION bin)

# Install architecture-neutral wrapper script as bcplc
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/bcplc)
    install(PROGRAMS bcplc DESTINATION bin)
endif()

# Install headers
install(DIRECTORY include/ DESTINATION include/bcpl)

# Install architecture-specific headers
install(FILES 
    arch/${TARGET_ARCH}/runtime_${TARGET_ARCH}.c
    DESTINATION include/bcpl/arch/${TARGET_ARCH}
    OPTIONAL
)

# =============================================================================
# BUILD SUMMARY
# =============================================================================

message(STATUS "")
message(STATUS "🏗️  ===== BCPL Source Build Configuration =====")
message(STATUS "Target Architecture: ${TARGET_ARCH} (${BCPL_ARCH_BITS}-bit)")
message(STATUS "Platform: ${BCPL_PLATFORM}")
message(STATUS "C Compiler: ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "Runtime Sources: ${RUNTIME_SOURCES}")
message(STATUS "LLVM Backend: ${LLVM_AVAILABLE}")
message(STATUS "Output Binaries:")
message(STATUS "  - cg_${TARGET_ARCH}")
message(STATUS "  - op_${TARGET_ARCH}")
message(STATUS "  - bcpl_runtime_${TARGET_ARCH}")
if(LLVM_AVAILABLE)
    message(STATUS "  - llcg_${TARGET_ARCH}")
endif()
message(STATUS "===============================================")
message(STATUS "")
