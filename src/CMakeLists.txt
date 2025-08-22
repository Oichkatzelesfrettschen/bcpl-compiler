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

# Define assembler preprocessor definitions based on architecture bitness for use in global.S
set(BCPL_ASM_DEFINITION_LIST "") # Initialize as a list
if(BCPL_ARCH_BITS EQUAL 64)
    list(APPEND BCPL_ASM_DEFINITION_LIST "__64BIT__=1")
elseif(BCPL_ARCH_BITS EQUAL 32)
    list(APPEND BCPL_ASM_DEFINITION_LIST "__32BIT__=1")
elseif(BCPL_ARCH_BITS EQUAL 16)
    list(APPEND BCPL_ASM_DEFINITION_LIST "__16BIT__=1")
else()
    message(FATAL_ERROR "Unsupported BCPL_ARCH_BITS for assembler preprocessor: ${BCPL_ARCH_BITS}")
endif()

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
list(APPEND RUNTIME_SOURCES platform/common_io.c)
list(APPEND RUNTIME_SOURCES platform/common_memory.c)

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
    global.S  # Use .S for C preprocessing
)

target_compile_options(bcpl_runtime PRIVATE ${BCPL_C_FLAGS})

# Apply assembler definitions to the target if it has assembly files
# This ensures __xBIT__ flags are defined when global.S is preprocessed
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.18")
    target_compile_definitions(bcpl_runtime PRIVATE
        $<$<COMPILE_LANGUAGE:ASM>:${BCPL_ASM_DEFINITION_LIST}> # Pass the list
    )
else()
    # For older CMake, need to construct the -D flags string for COMPILE_FLAGS
    set(BCPL_ASM_DEFINES_STR "")
    foreach(DEF ${BCPL_ASM_DEFINITION_LIST})
        # Note: This loop might create a leading space if BCPL_ASM_DEFINES_STR is initially empty.
        # However, COMPILE_FLAGS usually tolerate leading/trailing spaces.
        set(BCPL_ASM_DEFINES_STR "${BCPL_ASM_DEFINES_STR} -D${DEF}")
    endforeach()
    set_property(TARGET bcpl_runtime APPEND_STRING PROPERTY COMPILE_FLAGS "${BCPL_ASM_DEFINES_STR}")
endif()

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

# Select OCODE implementation based on architecture
if(BCPL_ARCH_BITS EQUAL 64)
    message(STATUS "Using 64-bit OCODE implementation for ${TARGET_ARCH}")
    set(OCODE_SOURCES oc.c ocode_64bit.c)
    set(OCODE_DEFINES -DBCPL_USE_64BIT_OCODE=1)
else()
    message(STATUS "Using legacy OCODE implementation for ${TARGET_ARCH}")
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

if(BCPL_ARCH_BITS EQUAL 64)
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
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH}
    COMMAND $<TARGET_FILE:cg> -o ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH} < ${CMAKE_CURRENT_SOURCE_DIR}/st.O
    DEPENDS cg ${CMAKE_CURRENT_SOURCE_DIR}/st.O
    COMMENT "Generating symbol table for ${TARGET_ARCH} (using prebuilt OCODE)"
)

add_custom_target(st_gen_${TARGET_ARCH}
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH}
)
# Generate architecture-specific symbol table (disabled in this build)
# add_custom_command(
#     OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH}
#     COMMAND $<TARGET_FILE:cg> -o ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH} < ${CMAKE_CURRENT_SOURCE_DIR}/st.O
#     DEPENDS cg ${CMAKE_CURRENT_SOURCE_DIR}/st.O
#     COMMENT "Generating symbol table for ${TARGET_ARCH} (using prebuilt OCODE)"
# )
#
# add_custom_target(st_gen_${TARGET_ARCH} ALL
#     DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/st_${TARGET_ARCH}
# )

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

    # Enable C++ support only when building the LLVM backend
    enable_language(CXX)
    set(BCPL_CXX_FLAGS
        ${BCPL_BASE_C_FLAGS}
        -std=c++17
        -Woverloaded-virtual
        -Wnon-virtual-dtor
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
