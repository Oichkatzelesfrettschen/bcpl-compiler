# =============================================================================
# BCPL Multi-Architecture CMake Configuration
# Modern, modular architecture configuration system
# =============================================================================

cmake_minimum_required(VERSION 3.20)

# Guard against multiple inclusion
if(BCPL_ARCHITECTURE_CONFIG_INCLUDED)
    return()
endif()
set(BCPL_ARCHITECTURE_CONFIG_INCLUDED TRUE)

message(STATUS "🏗️  Loading BCPL Architecture Configuration...")

# =============================================================================
# ARCHITECTURE OPTIONS - Proper CMake Cache Variables
# =============================================================================

# Primary architecture selection
set(BCPL_TARGET_ARCH "auto" CACHE STRING 
    "Target architecture (auto, arm64, x86_64, arm32, x86_32, x86_16)")
set_property(CACHE BCPL_TARGET_ARCH PROPERTY STRINGS 
    "auto" "arm64" "x86_64" "arm32" "x86_32" "x86_16")

# Feature options
option(BCPL_ENABLE_MULTI_ARCH "Enable multi-architecture support" OFF)
option(BCPL_ENABLE_UNIVERSAL_BINARY "Enable Universal Binary (macOS only)" OFF)
option(BCPL_ENABLE_CROSS_COMPILE "Enable cross-compilation" OFF)

# Per-architecture enable flags
option(BCPL_ENABLE_ARM64 "Enable ARM64/AArch64 support" ON)
option(BCPL_ENABLE_X86_64 "Enable x86_64/AMD64 support" ON) 
option(BCPL_ENABLE_ARM32 "Enable ARM32 support" OFF)
option(BCPL_ENABLE_X86_32 "Enable x86_32/i386 support" OFF)
option(BCPL_ENABLE_X86_16 "Enable x86_16/8086 support" OFF)

# Optimization options
option(BCPL_OPTIMIZE_FOR_ARCH "Enable architecture-specific optimizations" ON)
option(BCPL_USE_NATIVE_INSTRUCTIONS "Use native CPU instructions (reduces portability)" OFF)
option(BCPL_ENABLE_RUNTIME_DISPATCH "Enable runtime CPU feature detection" ON)

# =============================================================================
# ARCHITECTURE DETECTION AND VALIDATION
# =============================================================================

# Function to detect host architecture
function(bcpl_detect_host_architecture)
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
        set(BCPL_HOST_ARCH "arm64" PARENT_SCOPE)
        set(BCPL_HOST_BITS 64 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|amd64")
        set(BCPL_HOST_ARCH "x86_64" PARENT_SCOPE)
        set(BCPL_HOST_BITS 64 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm.*")
        set(BCPL_HOST_ARCH "arm32" PARENT_SCOPE)
        set(BCPL_HOST_BITS 32 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i[3-6]86|x86")
        set(BCPL_HOST_ARCH "x86_32" PARENT_SCOPE)
        set(BCPL_HOST_BITS 32 PARENT_SCOPE)
    else()
        set(BCPL_HOST_ARCH "unknown" PARENT_SCOPE)
        set(BCPL_HOST_BITS 64 PARENT_SCOPE)
        message(WARNING "Unknown host architecture: ${CMAKE_SYSTEM_PROCESSOR}")
    endif()
endfunction()

# Function to resolve target architecture
function(bcpl_resolve_target_architecture)
    if(BCPL_TARGET_ARCH STREQUAL "auto")
        bcpl_detect_host_architecture()
        set(BCPL_RESOLVED_ARCH ${BCPL_HOST_ARCH} PARENT_SCOPE)
        message(STATUS "Auto-detected target architecture: ${BCPL_HOST_ARCH}")
    else()
        set(BCPL_RESOLVED_ARCH ${BCPL_TARGET_ARCH} PARENT_SCOPE)
        message(STATUS "User-specified target architecture: ${BCPL_TARGET_ARCH}")
    endif()
endfunction()

# Function to validate architecture support
function(bcpl_validate_architecture ARCH)
    set(VALID_ARCHS "arm64" "x86_64" "arm32" "x86_32" "x86_16")
    if(NOT ARCH IN_LIST VALID_ARCHS)
        message(FATAL_ERROR "Unsupported architecture: ${ARCH}. Supported: ${VALID_ARCHS}")
    endif()
    
    # Check if architecture is enabled
    string(TOUPPER ${ARCH} ARCH_UPPER)
    if(NOT BCPL_ENABLE_${ARCH_UPPER})
        message(FATAL_ERROR "Architecture ${ARCH} is not enabled. Set BCPL_ENABLE_${ARCH_UPPER}=ON")
    endif()
endfunction()

# =============================================================================
# ARCHITECTURE CONFIGURATION DATABASE
# =============================================================================

# Function to configure architecture properties
function(bcpl_configure_architecture ARCH)
    # Reset all architecture variables
    unset(BCPL_ARCH_BITS PARENT_SCOPE)
    unset(BCPL_ARCH_FLAGS PARENT_SCOPE)
    unset(BCPL_ARCH_DEFINES PARENT_SCOPE)
    unset(BCPL_ARCH_SOURCES PARENT_SCOPE)
    unset(BCPL_ARCH_LINKER_FLAGS PARENT_SCOPE)
    unset(BCPL_ARCH_FEATURES PARENT_SCOPE)
    
    if(ARCH STREQUAL "arm64")
        set(BCPL_ARCH_BITS 64 PARENT_SCOPE)
        set(BCPL_ARCH_WORD_SIZE 8 PARENT_SCOPE)
        set(BCPL_ARCH_DEFINES 
            -DBCPL_ARM64=1 
            -DBCPL_AARCH64=1 
            -DBCPL_64BIT=1 
            PARENT_SCOPE)
        set(BCPL_ARCH_FEATURES "neon" "crypto" "crc" PARENT_SCOPE)
        
        if(BCPL_OPTIMIZE_FOR_ARCH)
            set(BCPL_ARCH_FLAGS -march=armv8-a PARENT_SCOPE)
            if(BCPL_USE_NATIVE_INSTRUCTIONS)
                list(APPEND BCPL_ARCH_FLAGS -mcpu=native)
                set(BCPL_ARCH_FLAGS ${BCPL_ARCH_FLAGS} PARENT_SCOPE)
            endif()
        endif()
        
    elseif(ARCH STREQUAL "x86_64")
        set(BCPL_ARCH_BITS 64 PARENT_SCOPE)
        set(BCPL_ARCH_WORD_SIZE 8 PARENT_SCOPE)
        set(BCPL_ARCH_DEFINES 
            -DBCPL_X86_64=1 
            -DBCPL_AMD64=1 
            -DBCPL_64BIT=1 
            PARENT_SCOPE)
        set(BCPL_ARCH_FEATURES "sse2" "sse3" "sse4_1" "sse4_2" PARENT_SCOPE)
        
        if(BCPL_OPTIMIZE_FOR_ARCH)
            set(BCPL_ARCH_FLAGS -march=x86-64 -mtune=generic PARENT_SCOPE)
            if(BCPL_USE_NATIVE_INSTRUCTIONS)
                list(APPEND BCPL_ARCH_FLAGS -march=native)
                set(BCPL_ARCH_FLAGS ${BCPL_ARCH_FLAGS} PARENT_SCOPE)
            endif()
        endif()
        
    elseif(ARCH STREQUAL "arm32")
        set(BCPL_ARCH_BITS 32 PARENT_SCOPE)
        set(BCPL_ARCH_WORD_SIZE 4 PARENT_SCOPE)
        set(BCPL_ARCH_DEFINES 
            -DBCPL_ARM32=1 
            -DBCPL_ARM=1 
            -DBCPL_32BIT=1 
            PARENT_SCOPE)
        set(BCPL_ARCH_FEATURES "vfp" "neon" PARENT_SCOPE)
        
        if(BCPL_OPTIMIZE_FOR_ARCH)
            set(BCPL_ARCH_FLAGS -march=armv7-a -mfpu=neon PARENT_SCOPE)
        endif()
        
    elseif(ARCH STREQUAL "x86_32")
        set(BCPL_ARCH_BITS 32 PARENT_SCOPE)
        set(BCPL_ARCH_WORD_SIZE 4 PARENT_SCOPE)
        set(BCPL_ARCH_DEFINES 
            -DBCPL_X86_32=1 
            -DBCPL_I386=1 
            -DBCPL_32BIT=1 
            PARENT_SCOPE)
        set(BCPL_ARCH_FEATURES "mmx" "sse" PARENT_SCOPE)
        
        if(BCPL_OPTIMIZE_FOR_ARCH)
            set(BCPL_ARCH_FLAGS -march=i686 -m32 PARENT_SCOPE)
        endif()
        
    elseif(ARCH STREQUAL "x86_16")
        set(BCPL_ARCH_BITS 16 PARENT_SCOPE)
        set(BCPL_ARCH_WORD_SIZE 2 PARENT_SCOPE)
        set(BCPL_ARCH_DEFINES 
            -DBCPL_X86_16=1 
            -DBCPL_I8086=1 
            -DBCPL_16BIT=1 
            PARENT_SCOPE)
        set(BCPL_ARCH_FEATURES PARENT_SCOPE)  # No special features
        
        if(BCPL_OPTIMIZE_FOR_ARCH)
            set(BCPL_ARCH_FLAGS -march=i8086 -m16 PARENT_SCOPE)
        endif()
    endif()
    
    # Add architecture-specific runtime sources
    set(ARCH_RUNTIME_FILE "${CMAKE_CURRENT_SOURCE_DIR}/arch/${ARCH}/runtime_${ARCH}.c")
    if(EXISTS ${ARCH_RUNTIME_FILE})
        set(BCPL_ARCH_SOURCES ${ARCH_RUNTIME_FILE} PARENT_SCOPE)
    endif()
    
    message(STATUS "Configured ${ARCH}: ${BCPL_ARCH_BITS}-bit, features: ${BCPL_ARCH_FEATURES}")
endfunction()

# =============================================================================
# CROSS-COMPILATION SUPPORT
# =============================================================================

# Function to setup cross-compilation toolchain
function(bcpl_setup_cross_compilation TARGET_ARCH HOST_ARCH)
    if(NOT BCPL_ENABLE_CROSS_COMPILE)
        return()
    endif()
    
    if(TARGET_ARCH STREQUAL HOST_ARCH)
        return()  # Native compilation
    endif()
    
    message(STATUS "Setting up cross-compilation: ${HOST_ARCH} -> ${TARGET_ARCH}")
    
    if(TARGET_ARCH STREQUAL "arm64" AND HOST_ARCH STREQUAL "x86_64")
        if(APPLE)
            set(CMAKE_OSX_ARCHITECTURES "arm64" PARENT_SCOPE)
        elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
            find_program(AARCH64_GCC aarch64-linux-gnu-gcc)
            if(AARCH64_GCC)
                set(CMAKE_C_COMPILER ${AARCH64_GCC} PARENT_SCOPE)
                set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++ PARENT_SCOPE)
            else()
                message(FATAL_ERROR "Cross-compiler for ARM64 not found. Install: apt install gcc-aarch64-linux-gnu")
            endif()
        endif()
        
    elseif(TARGET_ARCH STREQUAL "x86_64" AND HOST_ARCH STREQUAL "arm64")
        if(APPLE)
            set(CMAKE_OSX_ARCHITECTURES "x86_64" PARENT_SCOPE)
        endif()
        
    elseif(TARGET_ARCH STREQUAL "arm32")
        find_program(ARM_GCC arm-linux-gnueabihf-gcc)
        if(ARM_GCC)
            set(CMAKE_C_COMPILER ${ARM_GCC} PARENT_SCOPE)
            set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++ PARENT_SCOPE)
        else()
            message(FATAL_ERROR "Cross-compiler for ARM32 not found. Install: apt install gcc-arm-linux-gnueabihf")
        endif()
        
    elseif(TARGET_ARCH STREQUAL "x86_16")
        find_program(I8086_GCC i8086-linux-gcc)
        if(I8086_GCC)
            set(CMAKE_C_COMPILER ${I8086_GCC} PARENT_SCOPE)
        else()
            message(FATAL_ERROR "Cross-compiler for x86_16 not found. Install ia16-elf-gcc")
        endif()
    endif()
endfunction()

# =============================================================================
# UNIVERSAL BINARY SUPPORT (macOS)
# =============================================================================

# Function to setup Universal Binary
function(bcpl_setup_universal_binary)
    if(NOT APPLE OR NOT BCPL_ENABLE_UNIVERSAL_BINARY)
        return()
    endif()
    
    set(UNIVERSAL_ARCHS)
    if(BCPL_ENABLE_ARM64)
        list(APPEND UNIVERSAL_ARCHS "arm64")
    endif()
    if(BCPL_ENABLE_X86_64)
        list(APPEND UNIVERSAL_ARCHS "x86_64")
    endif()
    
    if(UNIVERSAL_ARCHS)
        set(CMAKE_OSX_ARCHITECTURES ${UNIVERSAL_ARCHS} PARENT_SCOPE)
        message(STATUS "Universal Binary enabled: ${UNIVERSAL_ARCHS}")
    endif()
endfunction()

# =============================================================================
# MAIN CONFIGURATION LOGIC
# =============================================================================

# Initialize architecture detection and configuration
bcpl_detect_host_architecture()
bcpl_resolve_target_architecture()
bcpl_validate_architecture(${BCPL_RESOLVED_ARCH})

# Configure the resolved architecture
bcpl_configure_architecture(${BCPL_RESOLVED_ARCH})

# Setup cross-compilation if needed
bcpl_setup_cross_compilation(${BCPL_RESOLVED_ARCH} ${BCPL_HOST_ARCH})

# Setup Universal Binary if enabled
bcpl_setup_universal_binary()

# Export final configuration for use by other CMake files
set(BCPL_TARGET_ARCHITECTURE ${BCPL_RESOLVED_ARCH})

message(STATUS "🎯 Architecture configured: ${BCPL_RESOLVED_ARCH} (${BCPL_ARCH_BITS}-bit)")
message(STATUS "✅ BCPL Architecture Configuration complete.")

message(STATUS "=== BCPL Multi-Architecture Configuration ===")
message(STATUS "Host Architecture: ${BCPL_HOST_ARCH} (${BCPL_HOST_BITS}-bit)")
message(STATUS "Target Architecture: ${BCPL_TARGET_ARCHITECTURE} (${BCPL_ARCH_BITS}-bit)")
message(STATUS "Word Size: ${BCPL_ARCH_WORD_SIZE} bytes")
message(STATUS "Features: ${BCPL_ARCH_FEATURES}")
message(STATUS "Cross-compilation: ${BCPL_ENABLE_CROSS_COMPILE}")
message(STATUS "Universal Binary: ${BCPL_ENABLE_UNIVERSAL_BINARY}")
if(DEFINED CMAKE_OSX_ARCHITECTURES)
    message(STATUS "macOS Architectures: ${CMAKE_OSX_ARCHITECTURES}")
endif()
message(STATUS "==============================================")
