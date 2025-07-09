# Multi-Architecture BCPL Compiler Configuration
# Supports ARM64, x86_64, ARM32, x86_32, and x86_16

cmake_minimum_required(VERSION 3.20)

# =============================================================================
# MULTI-ARCHITECTURE OPTIONS
# =============================================================================

# Architecture options
option(ENABLE_ARM64 "Enable ARM64 (AArch64) support" ON)
option(ENABLE_X86_64 "Enable x86_64 support" ON)
option(ENABLE_ARM32 "Enable ARM32 support" OFF)
option(ENABLE_X86_32 "Enable x86_32 support" OFF)
option(ENABLE_X86_16 "Enable x86_16 (8086/80286) support" OFF)

# Cross-compilation support
option(ENABLE_CROSS_COMPILE "Enable cross-compilation for multiple targets" OFF)

# =============================================================================
# ARCHITECTURE DETECTION AND CONFIGURATION
# =============================================================================

# Detect host architecture
if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
    set(HOST_ARCH "arm64")
    set(HOST_BITS 64)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|amd64")
    set(HOST_ARCH "x86_64")
    set(HOST_BITS 64)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
    set(HOST_ARCH "arm32")
    set(HOST_BITS 32)
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i386|i686|x86")
    set(HOST_ARCH "x86_32")
    set(HOST_BITS 32)
else()
    set(HOST_ARCH "unknown")
    set(HOST_BITS 64)
    message(WARNING "Unknown host architecture: ${CMAKE_SYSTEM_PROCESSOR}")
endif()

message(STATUS "Host architecture: ${HOST_ARCH} (${HOST_BITS}-bit)")

# Target architecture selection
if(NOT DEFINED TARGET_ARCH)
    set(TARGET_ARCH ${HOST_ARCH})
    message(STATUS "No target architecture specified, using host: ${TARGET_ARCH}")
else()
    message(STATUS "Target architecture: ${TARGET_ARCH}")
endif()

# =============================================================================
# ARCHITECTURE-SPECIFIC CONFIGURATIONS
# =============================================================================

function(configure_target_arch ARCH)
    if(ARCH STREQUAL "arm64")
        set(ARCH_BITS 64)
        set(ARCH_FLAGS -march=armv8-a)
        set(ARCH_DEFINES -DBCPL_ARM64=1 -DBCPL_AARCH64=1)
        set(ARCH_SOURCES arch/arm64/runtime_arm64.c)
        
    elseif(ARCH STREQUAL "x86_64")
        set(ARCH_BITS 64)
        set(ARCH_FLAGS -march=x86-64)
        set(ARCH_DEFINES -DBCPL_X86_64=1 -DBCPL_AMD64=1)
        set(ARCH_SOURCES arch/x86_64/runtime_x86_64.c)
        
    elseif(ARCH STREQUAL "arm32")
        set(ARCH_BITS 32)
        set(ARCH_FLAGS -march=armv7-a -mfpu=neon)
        set(ARCH_DEFINES -DBCPL_ARM32=1 -DBCPL_ARM=1)
        set(ARCH_SOURCES arch/arm32/runtime_arm32.c)
        
    elseif(ARCH STREQUAL "x86_32")
        set(ARCH_BITS 32)
        set(ARCH_FLAGS -march=i686 -m32)
        set(ARCH_DEFINES -DBCPL_X86_32=1 -DBCPL_I386=1)
        set(ARCH_SOURCES arch/x86_32/runtime_x86_32.c)
        
    elseif(ARCH STREQUAL "x86_16")
        set(ARCH_BITS 16)
        set(ARCH_FLAGS -march=i286 -m16)
        set(ARCH_DEFINES -DBCPL_X86_16=1 -DBCPL_I8086=1)
        set(ARCH_SOURCES arch/x86_16/runtime_x86_16.c)
        
    else()
        message(FATAL_ERROR "Unsupported architecture: ${ARCH}")
    endif()
    
    # Export to parent scope
    set(BCPL_ARCH_BITS ${ARCH_BITS} PARENT_SCOPE)
    set(BCPL_ARCH_FLAGS ${ARCH_FLAGS} PARENT_SCOPE)
    set(BCPL_ARCH_DEFINES ${ARCH_DEFINES} PARENT_SCOPE)
    set(BCPL_ARCH_SOURCES ${ARCH_SOURCES} PARENT_SCOPE)
    
    message(STATUS "Configured ${ARCH} (${ARCH_BITS}-bit)")
endfunction()

# Configure the target architecture
configure_target_arch(${TARGET_ARCH})

# =============================================================================
# UNIVERSAL BINARY SUPPORT (macOS)
# =============================================================================

if(APPLE AND ENABLE_CROSS_COMPILE)
    # Check if we can build universal binaries
    if(ENABLE_ARM64 AND ENABLE_X86_64)
        set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
        message(STATUS "Configuring Universal Binary (arm64 + x86_64)")
        set(BCPL_UNIVERSAL_BINARY ON)
    endif()
endif()

# =============================================================================
# CROSS-COMPILATION TOOLCHAIN SETUP
# =============================================================================

function(setup_cross_toolchain ARCH)
    if(ENABLE_CROSS_COMPILE AND NOT ARCH STREQUAL HOST_ARCH)
        message(STATUS "Setting up cross-compilation for ${ARCH}")
        
        if(ARCH STREQUAL "arm64" AND HOST_ARCH STREQUAL "x86_64")
            # Cross-compile from x86_64 to ARM64
            if(APPLE)
                # Use Xcode's built-in cross-compilation
                set(CMAKE_OSX_ARCHITECTURES "arm64" PARENT_SCOPE)
            elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
                # Use aarch64-linux-gnu toolchain
                find_program(CROSS_CC aarch64-linux-gnu-gcc)
                if(CROSS_CC)
                    set(CMAKE_C_COMPILER ${CROSS_CC} PARENT_SCOPE)
                    set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++ PARENT_SCOPE)
                else()
                    message(WARNING "Cross-compiler for ARM64 not found")
                endif()
            endif()
            
        elseif(ARCH STREQUAL "x86_64" AND HOST_ARCH STREQUAL "arm64")
            # Cross-compile from ARM64 to x86_64
            if(APPLE)
                set(CMAKE_OSX_ARCHITECTURES "x86_64" PARENT_SCOPE)
            endif()
            
        elseif(ARCH STREQUAL "arm32")
            # Cross-compile to ARM32
            find_program(CROSS_CC arm-linux-gnueabihf-gcc)
            if(CROSS_CC)
                set(CMAKE_C_COMPILER ${CROSS_CC} PARENT_SCOPE)
                set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++ PARENT_SCOPE)
            else()
                message(WARNING "Cross-compiler for ARM32 not found")
            endif()
            
        elseif(ARCH STREQUAL "x86_32")
            # 32-bit x86 compilation
            list(APPEND BCPL_ARCH_FLAGS -m32)
            
        elseif(ARCH STREQUAL "x86_16")
            # 16-bit x86 (requires special toolchain)
            find_program(CROSS_CC i8086-linux-gcc)
            if(CROSS_CC)
                set(CMAKE_C_COMPILER ${CROSS_CC} PARENT_SCOPE)
            else()
                message(WARNING "Cross-compiler for x86_16 not found")
                message(STATUS "You may need to install ia16-elf-gcc or similar")
            endif()
        endif()
    endif()
endfunction()

# Set up cross-compilation if needed
setup_cross_toolchain(${TARGET_ARCH})

# =============================================================================
# ARCHITECTURE-SPECIFIC BUILD TARGETS
# =============================================================================

# Function to create architecture-specific targets
function(add_arch_target TARGET_NAME ARCH)
    configure_target_arch(${ARCH})
    
    # Create a suffixed target name
    set(ARCH_TARGET "${TARGET_NAME}_${ARCH}")
    
    # Add the target with architecture-specific flags
    add_executable(${ARCH_TARGET} ${ARGN})
    
    target_compile_options(${ARCH_TARGET} PRIVATE
        ${BCPL_ARCH_FLAGS}
        ${BCPL_ARCH_DEFINES}
        -DBITS=${BCPL_ARCH_BITS}
        -DBCPL_ARCH_BITS=${BCPL_ARCH_BITS}
    )
    
    # Create a generic alias if this is the host architecture
    if(ARCH STREQUAL HOST_ARCH)
        add_executable(${TARGET_NAME} ALIAS ${ARCH_TARGET})
    endif()
    
    message(STATUS "Created target: ${ARCH_TARGET}")
endfunction()

# =============================================================================
# MULTI-ARCH BUILD SCRIPT GENERATION
# =============================================================================

function(generate_multi_arch_scripts)
    # Generate build scripts for each architecture
    set(SUPPORTED_ARCHS)
    
    if(ENABLE_ARM64)
        list(APPEND SUPPORTED_ARCHS arm64)
    endif()
    if(ENABLE_X86_64)
        list(APPEND SUPPORTED_ARCHS x86_64)
    endif()
    if(ENABLE_ARM32)
        list(APPEND SUPPORTED_ARCHS arm32)
    endif()
    if(ENABLE_X86_32)
        list(APPEND SUPPORTED_ARCHS x86_32)
    endif()
    if(ENABLE_X86_16)
        list(APPEND SUPPORTED_ARCHS x86_16)
    endif()
    
    # Create a build-all script
    set(BUILD_ALL_SCRIPT "#!/bin/bash\n")
    string(APPEND BUILD_ALL_SCRIPT "# Multi-architecture build script\n")
    string(APPEND BUILD_ALL_SCRIPT "set -e\n\n")
    
    foreach(ARCH ${SUPPORTED_ARCHS})
        string(APPEND BUILD_ALL_SCRIPT "echo \"Building for ${ARCH}...\"\n")
        string(APPEND BUILD_ALL_SCRIPT "mkdir -p build-${ARCH}\n")
        string(APPEND BUILD_ALL_SCRIPT "cd build-${ARCH}\n")
        string(APPEND BUILD_ALL_SCRIPT "cmake -DTARGET_ARCH=${ARCH} ..\n")
        string(APPEND BUILD_ALL_SCRIPT "make -j$(nproc)\n")
        string(APPEND BUILD_ALL_SCRIPT "cd ..\n\n")
    endforeach()
    
    file(WRITE "${CMAKE_SOURCE_DIR}/build_all_archs.sh" ${BUILD_ALL_SCRIPT})
    execute_process(COMMAND chmod +x "${CMAKE_SOURCE_DIR}/build_all_archs.sh")
    
    message(STATUS "Generated multi-architecture build script: build_all_archs.sh")
endfunction()

# Generate scripts if cross-compilation is enabled
if(ENABLE_CROSS_COMPILE)
    generate_multi_arch_scripts()
endif()

# =============================================================================
# SUMMARY
# =============================================================================

message(STATUS "=== Multi-Architecture BCPL Configuration ===")
message(STATUS "Host: ${HOST_ARCH} (${HOST_BITS}-bit)")
message(STATUS "Target: ${TARGET_ARCH} (${BCPL_ARCH_BITS}-bit)")
message(STATUS "Supported architectures:")
if(ENABLE_ARM64)
    message(STATUS "  ✓ ARM64 (AArch64)")
endif()
if(ENABLE_X86_64)
    message(STATUS "  ✓ x86_64 (AMD64)")
endif()
if(ENABLE_ARM32)
    message(STATUS "  ✓ ARM32")
endif()
if(ENABLE_X86_32)
    message(STATUS "  ✓ x86_32 (i386)")
endif()
if(ENABLE_X86_16)
    message(STATUS "  ✓ x86_16 (8086/80286)")
endif()
if(DEFINED BCPL_UNIVERSAL_BINARY)
    message(STATUS "Universal Binary: Yes")
endif()
message(STATUS "Cross-compilation: ${ENABLE_CROSS_COMPILE}")
message(STATUS "============================================")
