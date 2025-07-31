# =============================================================================
# Xerox Alto BCPL Compiler - Modern Build Configuration
# =============================================================================

cmake_minimum_required(VERSION 3.20)

project(XeroxAltoBCPL
    VERSION 1.0.0
    DESCRIPTION "Modernized Xerox Alto BCPL Compiler"
    LANGUAGES C CXX
)

# =============================================================================
# CMAKE CONFIGURATION
# =============================================================================

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# =============================================================================
# PROJECT STRUCTURE
# =============================================================================

set(XEROX_BCPL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/xerox-alto-bcpl/modernized")
set(XEROX_BCPL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/xerox-alto-bcpl/include")
set(XEROX_BCPL_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/xerox-alto-bcpl/runtime")

# Create include directory for modern headers
file(MAKE_DIRECTORY ${XEROX_BCPL_INCLUDE_DIR})
file(MAKE_DIRECTORY ${XEROX_BCPL_RUNTIME_DIR})

# =============================================================================
# COMPILER CONFIGURATION
# =============================================================================

# Use our BCPL compiler if available, otherwise build runtime for analysis
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/build/src/bcplc")
    set(BCPL_COMPILER "${CMAKE_CURRENT_SOURCE_DIR}/build/src/bcplc")
    set(HAVE_BCPL_COMPILER TRUE)
else()
    set(HAVE_BCPL_COMPILER FALSE)
    message(STATUS "BCPL compiler not found - will build C runtime analysis only")
endif()

# =============================================================================
# INCLUDE DIRECTORIES
# =============================================================================

include_directories(
    ${XEROX_BCPL_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src/runtime
)

# =============================================================================
# SOURCE FILE ORGANIZATION
# =============================================================================

# BCPL source files organized by component
set(BCPL_MAIN_SOURCES
    ${XEROX_BCPL_SOURCE_DIR}/BCPL0.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BCPL1.bcpl
)

set(BCPL_CAE_SOURCES
    ${XEROX_BCPL_SOURCE_DIR}/BCAE0.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BCAE1.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BCAE2.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BCAE3.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BCAE4.bcpl
)

set(BCPL_LEX_SOURCES
    ${XEROX_BCPL_SOURCE_DIR}/BLEX0.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BLEX0A.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BLEX1.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BLEX2.bcpl
)

set(BCPL_SAE_SOURCES
    ${XEROX_BCPL_SOURCE_DIR}/BSAE0.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BSAE1.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BSAE2.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BSAE3.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BSAE4.bcpl
)

set(BCPL_TRN_SOURCES
    ${XEROX_BCPL_SOURCE_DIR}/BTRN0.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BTRN1.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BTRN2.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BTRN3.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BTRN4.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BTRN5.bcpl
)

set(BCPL_NCG_SOURCES
    ${XEROX_BCPL_SOURCE_DIR}/BNCG0.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG1.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG2.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG3.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG4.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG5.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG6.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG7.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BNCG8.bcpl
)

set(BCPL_PLATFORM_SOURCES
    ${XEROX_BCPL_SOURCE_DIR}/BCPLALTO.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BCPLDOS.bcpl
    ${XEROX_BCPL_SOURCE_DIR}/BCPLRDOS.bcpl
)

set(BCPL_HEADER_FILES
    ${XEROX_BCPL_SOURCE_DIR}/BCPLX
    ${XEROX_BCPL_SOURCE_DIR}/BCAEX
    ${XEROX_BCPL_SOURCE_DIR}/BLEXX
    ${XEROX_BCPL_SOURCE_DIR}/BSAEX
    ${XEROX_BCPL_SOURCE_DIR}/BTRNX
    ${XEROX_BCPL_SOURCE_DIR}/BNCGX
    ${XEROX_BCPL_SOURCE_DIR}/BCPLIOX
)

set(ALL_BCPL_SOURCES
    ${BCPL_MAIN_SOURCES}
    ${BCPL_CAE_SOURCES}
    ${BCPL_LEX_SOURCES}
    ${BCPL_SAE_SOURCES}
    ${BCPL_TRN_SOURCES}
    ${BCPL_NCG_SOURCES}
    ${BCPL_PLATFORM_SOURCES}
)

# =============================================================================
# CUSTOM TARGETS FOR ANALYSIS
# =============================================================================

# Create target to validate BCPL sources
add_custom_target(xerox_bcpl_analysis
    COMMENT "Analyzing Xerox Alto BCPL source files"
    SOURCES ${ALL_BCPL_SOURCES} ${BCPL_HEADER_FILES}
)

# Create individual component targets for organization
add_custom_target(xerox_bcpl_main SOURCES ${BCPL_MAIN_SOURCES})
add_custom_target(xerox_bcpl_cae SOURCES ${BCPL_CAE_SOURCES})
add_custom_target(xerox_bcpl_lex SOURCES ${BCPL_LEX_SOURCES})
add_custom_target(xerox_bcpl_sae SOURCES ${BCPL_SAE_SOURCES})
add_custom_target(xerox_bcpl_trn SOURCES ${BCPL_TRN_SOURCES})
add_custom_target(xerox_bcpl_ncg SOURCES ${BCPL_NCG_SOURCES})
add_custom_target(xerox_bcpl_platform SOURCES ${BCPL_PLATFORM_SOURCES})
add_custom_target(xerox_bcpl_headers SOURCES ${BCPL_HEADER_FILES})

# =============================================================================
# BCPL COMPILATION SUPPORT
# =============================================================================

if(HAVE_BCPL_COMPILER)
    # Function to compile BCPL sources
    function(compile_bcpl_file source_file output_file)
        add_custom_command(
            OUTPUT ${output_file}
            COMMAND ${BCPL_COMPILER} ${source_file} -o ${output_file}
            DEPENDS ${source_file} ${BCPL_COMPILER}
            COMMENT "Compiling BCPL: ${source_file}"
        )
    endfunction()
    
    # Compile main BCPL program
    set(XEROX_BCPL_MAIN_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/xerox_bcpl_main")
    compile_bcpl_file("${XEROX_BCPL_SOURCE_DIR}/BCPL0.bcpl" "${XEROX_BCPL_MAIN_OUTPUT}")
    
    add_custom_target(xerox_bcpl_build
        DEPENDS ${XEROX_BCPL_MAIN_OUTPUT}
        COMMENT "Building Xerox Alto BCPL Compiler"
    )
else()
    message(STATUS "BCPL compiler not available - creating analysis targets only")
endif()

# =============================================================================
# C RUNTIME FOR ANALYSIS
# =============================================================================

# Create C analysis program to examine BCPL structure
add_executable(xerox_bcpl_analyzer
    xerox-alto-bcpl/runtime/analyzer.c
    xerox-alto-bcpl/runtime/bcpl_runtime.c
)

target_compile_features(xerox_bcpl_analyzer PRIVATE c_std_23)
target_compile_options(xerox_bcpl_analyzer PRIVATE
    $<$<C_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<C_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    $<$<C_COMPILER_ID:MSVC>:/W4>
)

# =============================================================================
# INSTALL CONFIGURATION
# =============================================================================

install(DIRECTORY ${XEROX_BCPL_SOURCE_DIR}/
    DESTINATION share/xerox-alto-bcpl/sources
    FILES_MATCHING PATTERN "*.bcpl" PATTERN "*X"
)

install(TARGETS xerox_bcpl_analyzer
    RUNTIME DESTINATION bin
)

# =============================================================================
# TESTING
# =============================================================================

enable_testing()

add_test(NAME xerox_bcpl_analyzer_test
    COMMAND xerox_bcpl_analyzer --validate
)

# =============================================================================
# DOCUMENTATION
# =============================================================================

find_package(Doxygen QUIET)
if(DOXYGEN_FOUND)
    set(DOXYGEN_PROJECT_NAME "Xerox Alto BCPL Compiler")
    set(DOXYGEN_PROJECT_BRIEF "Modernized Xerox PARC Alto BCPL Compiler")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/docs")
    
    doxygen_add_docs(xerox_bcpl_docs
        ${XEROX_BCPL_SOURCE_DIR}
        xerox-alto-bcpl/runtime
        COMMENT "Generating Xerox Alto BCPL documentation"
    )
endif()

# =============================================================================
# SUMMARY
# =============================================================================

message(STATUS "=== Xerox Alto BCPL Compiler Configuration ===")
message(STATUS "Source files: ${CMAKE_CURRENT_LIST_DIR}/xerox-alto-bcpl/modernized")
message(STATUS "BCPL Compiler available: ${HAVE_BCPL_COMPILER}")
message(STATUS "Build targets:")
message(STATUS "  - xerox_bcpl_analysis: Analyze source structure")
message(STATUS "  - xerox_bcpl_analyzer: C runtime analyzer")
if(HAVE_BCPL_COMPILER)
    message(STATUS "  - xerox_bcpl_build: Compile with BCPL")
endif()
if(DOXYGEN_FOUND)
    message(STATUS "  - xerox_bcpl_docs: Generate documentation")
endif()
message(STATUS "==============================================")
