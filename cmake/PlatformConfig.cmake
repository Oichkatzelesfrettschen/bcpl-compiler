# BCPL Compiler - Platform Detection and Bootstrap Support
# This file provides platform-specific configuration and bootstrap file handling

# =============================================================================
# BOOTSTRAP FILE RESTORATION
# =============================================================================

# Function to restore bootstrap files from git history
function(restore_bootstrap_files)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/src/st.O" OR NOT EXISTS "${CMAKE_SOURCE_DIR}/src/blib.O")
        message(STATUS "Bootstrap OCODE files missing, attempting to restore...")
        
        find_program(GIT_EXECUTABLE git)
        if(GIT_EXECUTABLE AND EXISTS "${CMAKE_SOURCE_DIR}/.git")
            # Find commit with bootstrap files
            execute_process(
                COMMAND ${GIT_EXECUTABLE} rev-list --all
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                OUTPUT_VARIABLE ALL_COMMITS
                OUTPUT_STRIP_TRAILING_WHITESPACE
            )
            
            string(REPLACE "\n" ";" COMMITS_LIST "${ALL_COMMITS}")
            
            foreach(COMMIT ${COMMITS_LIST})
                execute_process(
                    COMMAND ${GIT_EXECUTABLE} ls-tree -r ${COMMIT}
                    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                    OUTPUT_VARIABLE TREE_OUTPUT
                    ERROR_QUIET
                )
                
                if(TREE_OUTPUT MATCHES "st\\.O")
                    message(STATUS "Found bootstrap files in commit: ${COMMIT}")
                    
                    # Restore st.O
                    execute_process(
                        COMMAND ${GIT_EXECUTABLE} show ${COMMIT}:src/st.O
                        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                        OUTPUT_FILE "${CMAKE_SOURCE_DIR}/src/st.O"
                        ERROR_QUIET
                    )
                    
                    # Restore blib.O
                    execute_process(
                        COMMAND ${GIT_EXECUTABLE} show ${COMMIT}:src/blib.O
                        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                        OUTPUT_FILE "${CMAKE_SOURCE_DIR}/src/blib.O"
                        ERROR_QUIET
                    )
                    
                    if(EXISTS "${CMAKE_SOURCE_DIR}/src/st.O" AND EXISTS "${CMAKE_SOURCE_DIR}/src/blib.O")
                        message(STATUS "Bootstrap files restored successfully")
                        break()
                    endif()
                endif()
            endforeach()
            
            if(NOT EXISTS "${CMAKE_SOURCE_DIR}/src/st.O" OR NOT EXISTS "${CMAKE_SOURCE_DIR}/src/blib.O")
                message(FATAL_ERROR "Could not restore bootstrap files from git history")
            endif()
        else()
            message(FATAL_ERROR "Bootstrap files missing and git not available")
        endif()
    else()
        message(STATUS "Bootstrap files found")
    endif()
endfunction()

# =============================================================================
# PLATFORM-SPECIFIC CONFIGURATION
# =============================================================================

# Enhanced platform detection
function(configure_platform)
    # Detect Solaris variants
    if(CMAKE_SYSTEM_NAME STREQUAL "SunOS")
        if(EXISTS "/etc/release")
            file(READ "/etc/release" RELEASE_INFO)
            if(RELEASE_INFO MATCHES "Oracle Solaris")
                set(BCPL_PLATFORM "SOLARIS" PARENT_SCOPE)
                set(BCPL_PLATFORM_NAME "Oracle Solaris" PARENT_SCOPE)
            elseif(RELEASE_INFO MATCHES "OpenIndiana|illumos")
                set(BCPL_PLATFORM "ILLUMOS" PARENT_SCOPE)
                set(BCPL_PLATFORM_NAME "illumos" PARENT_SCOPE)
            else()
                set(BCPL_PLATFORM "SOLARIS" PARENT_SCOPE)
                set(BCPL_PLATFORM_NAME "Solaris" PARENT_SCOPE)
            endif()
        else()
            set(BCPL_PLATFORM "SOLARIS" PARENT_SCOPE)
            set(BCPL_PLATFORM_NAME "Solaris" PARENT_SCOPE)
        endif()
        
        # Solaris/illumos specific flags
        list(APPEND BCPL_C_FLAGS 
            -D_POSIX_C_SOURCE=200809L
            -D__EXTENSIONS__
        )
        list(APPEND BCPL_LINK_LIBS socket nsl)
        
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
        set(BCPL_PLATFORM "LINUX" PARENT_SCOPE)
        set(BCPL_PLATFORM_NAME "Linux" PARENT_SCOPE)
        list(APPEND BCPL_LINK_LIBS m)
        
    elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        set(BCPL_PLATFORM "MACOS" PARENT_SCOPE)
        set(BCPL_PLATFORM_NAME "macOS" PARENT_SCOPE)
        
    elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
        set(BCPL_PLATFORM "FREEBSD" PARENT_SCOPE)
        set(BCPL_PLATFORM_NAME "FreeBSD" PARENT_SCOPE)
        list(APPEND BCPL_LINK_LIBS m)
        
    elseif(CMAKE_SYSTEM_NAME STREQUAL "NetBSD")
        set(BCPL_PLATFORM "NETBSD" PARENT_SCOPE)
        set(BCPL_PLATFORM_NAME "NetBSD" PARENT_SCOPE)
        list(APPEND BCPL_LINK_LIBS m)
        
    elseif(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
        set(BCPL_PLATFORM "OPENBSD" PARENT_SCOPE)
        set(BCPL_PLATFORM_NAME "OpenBSD" PARENT_SCOPE)
        list(APPEND BCPL_LINK_LIBS m)
        
    else()
        set(BCPL_PLATFORM "GENERIC" PARENT_SCOPE)
        set(BCPL_PLATFORM_NAME "Generic Unix" PARENT_SCOPE)
        list(APPEND BCPL_LINK_LIBS m)
    endif()
    
    # Export flags to parent scope
    set(BCPL_C_FLAGS ${BCPL_C_FLAGS} PARENT_SCOPE)
    set(BCPL_LINK_LIBS ${BCPL_LINK_LIBS} PARENT_SCOPE)
    
    message(STATUS "Platform: ${BCPL_PLATFORM_NAME}")
endfunction()

# =============================================================================
# ARCHITECTURE DETECTION
# =============================================================================

function(configure_architecture)
    # Enhanced architecture detection
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64|amd64")
        set(BCPL_ARCH "x86_64" PARENT_SCOPE)
        set(BCPL_BITS 64 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i386|i686|x86")
        set(BCPL_ARCH "i386" PARENT_SCOPE)
        set(BCPL_BITS 32 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|arm64")
        set(BCPL_ARCH "arm64" PARENT_SCOPE)
        set(BCPL_BITS 64 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm")
        set(BCPL_ARCH "arm" PARENT_SCOPE)
        set(BCPL_BITS 32 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "sparc64")
        set(BCPL_ARCH "sparc64" PARENT_SCOPE)
        set(BCPL_BITS 64 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "sparc")
        set(BCPL_ARCH "sparc" PARENT_SCOPE)
        set(BCPL_BITS 32 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "mips64")
        set(BCPL_ARCH "mips64" PARENT_SCOPE)
        set(BCPL_BITS 64 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "mips")
        set(BCPL_ARCH "mips" PARENT_SCOPE)
        set(BCPL_BITS 32 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "ppc64|powerpc64")
        set(BCPL_ARCH "ppc64" PARENT_SCOPE)
        set(BCPL_BITS 64 PARENT_SCOPE)
    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "ppc|powerpc")
        set(BCPL_ARCH "ppc" PARENT_SCOPE)
        set(BCPL_BITS 32 PARENT_SCOPE)
    else()
        set(BCPL_ARCH "unknown" PARENT_SCOPE)
        set(BCPL_BITS 64 PARENT_SCOPE)  # Default to 64-bit
        message(WARNING "Unknown architecture: ${CMAKE_SYSTEM_PROCESSOR}, defaulting to 64-bit")
    endif()
    
    # Allow override via command line
    if(DEFINED BITS)
        set(BCPL_BITS ${BITS} PARENT_SCOPE)
    endif()
    
    message(STATUS "Architecture: ${BCPL_ARCH} (${BCPL_BITS}-bit)")
endfunction()

# =============================================================================
# COMPILER CONFIGURATION
# =============================================================================

function(configure_compiler)
    # Ensure we have a suitable compiler
    if(CMAKE_C_COMPILER_ID MATCHES ".*Clang.*")
        set(BCPL_COMPILER_TYPE "Clang" PARENT_SCOPE)
    elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU")
        set(BCPL_COMPILER_TYPE "GCC" PARENT_SCOPE)
    else()
        message(WARNING "Unsupported compiler: ${CMAKE_C_COMPILER_ID}")
        set(BCPL_COMPILER_TYPE "Unknown" PARENT_SCOPE)
    endif()
    
    # Set C standard based on compiler support
    if(CMAKE_C_COMPILER_ID MATCHES ".*Clang.*" AND CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL "15.0")
        set(CMAKE_C_STANDARD 23 PARENT_SCOPE)
        message(STATUS "Using C23 standard")
    elseif(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL "13.0")
        set(CMAKE_C_STANDARD 23 PARENT_SCOPE)
        message(STATUS "Using C23 standard")
    else()
        set(CMAKE_C_STANDARD 17 PARENT_SCOPE)
        message(STATUS "Falling back to C17 standard")
    endif()
    
    set(CMAKE_C_STANDARD_REQUIRED ON PARENT_SCOPE)
    set(CMAKE_C_EXTENSIONS OFF PARENT_SCOPE)
endfunction()

# =============================================================================
# RUNTIME CONFIGURATION
# =============================================================================

function(configure_runtime)
    # Determine if we can use assembly runtime or need pure C
    set(USE_ASSEMBLY_RUNTIME OFF)
    
    # Assembly runtime is only available on x86/x86_64 Linux
    if(BCPL_PLATFORM STREQUAL "LINUX" AND BCPL_ARCH MATCHES "x86_64|i386")
        # Check if GNU assembler is available
        find_program(GNU_AS as)
        if(GNU_AS)
            execute_process(
                COMMAND ${GNU_AS} --version
                OUTPUT_VARIABLE AS_VERSION
                ERROR_QUIET
            )
            if(AS_VERSION MATCHES "GNU assembler")
                set(USE_ASSEMBLY_RUNTIME ON)
            endif()
        endif()
    endif()
    
    if(USE_ASSEMBLY_RUNTIME)
        set(BCPL_RUNTIME_TYPE "Assembly" PARENT_SCOPE)
        message(STATUS "Using assembly runtime")
    else()
        set(BCPL_RUNTIME_TYPE "Pure C" PARENT_SCOPE)
        message(STATUS "Using pure C runtime")
    endif()
    
    set(BCPL_USE_ASSEMBLY_RUNTIME ${USE_ASSEMBLY_RUNTIME} PARENT_SCOPE)
endfunction()

# =============================================================================
# MAIN CONFIGURATION FUNCTION
# =============================================================================

function(configure_bcpl_build)
    message(STATUS "=== BCPL Compiler Platform Configuration ===")
    
    # Run all configuration functions
    restore_bootstrap_files()
    configure_platform()
    configure_architecture()
    configure_compiler()
    configure_runtime()
    
    # Set platform definitions
    add_compile_definitions(
        BCPL_PLATFORM_${BCPL_PLATFORM}=1
        BCPL_ARCH_${BCPL_ARCH}=1
        BITS=${BCPL_BITS}
    )
    
    # Export all variables to parent scope
    foreach(VAR 
        BCPL_PLATFORM BCPL_PLATFORM_NAME 
        BCPL_ARCH BCPL_BITS
        BCPL_COMPILER_TYPE BCPL_RUNTIME_TYPE
        BCPL_USE_ASSEMBLY_RUNTIME
        BCPL_C_FLAGS BCPL_LINK_LIBS
    )
        if(DEFINED ${VAR})
            set(${VAR} ${${VAR}} PARENT_SCOPE)
        endif()
    endforeach()
    
    message(STATUS "Platform: ${BCPL_PLATFORM_NAME}")
    message(STATUS "Architecture: ${BCPL_ARCH} (${BCPL_BITS}-bit)")
    message(STATUS "Compiler: ${BCPL_COMPILER_TYPE}")
    message(STATUS "Runtime: ${BCPL_RUNTIME_TYPE}")
    message(STATUS "==========================================")
endfunction()
