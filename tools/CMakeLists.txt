cmake_minimum_required(VERSION 3.10)

# This CMakeLists builds BCPL tools using the just-built compiler
# We depend on the complete BCPL toolchain being built first

# Ensure that we have the required tools from the src build
set(ST_TARGET "st_gen_${BCPL_RESOLVED_ARCH}")
if(NOT TARGET cg OR NOT TARGET op OR NOT TARGET ${ST_TARGET})
    message(FATAL_ERROR "cg, op, and symbol table must be built before tools")
endif()

# Use the bcplc script directly but set PREFIX to point to our src build directory
# The bcplc script checks for PREFIX environment variable first
set(BCPLC_SCRIPT "${CMAKE_SOURCE_DIR}/src/bcplc")
set(BFLAGS -O)

function(add_bcpl_program name)
    add_custom_command(
        OUTPUT ${name}
        COMMAND env PREFIX="${CMAKE_BINARY_DIR}/src" ${BCPLC_SCRIPT} ${BFLAGS} ${CMAKE_CURRENT_SOURCE_DIR}/${name}.bcpl
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.bcpl cg op ${ST_TARGET}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        VERBATIM
    )
    add_custom_target(${name} ALL DEPENDS ${name})
endfunction()

add_bcpl_program(cmpltest)
add_bcpl_program(xref)
add_bcpl_program(gpm)

# Install the built utilities alongside the compiler runtime
install(
    PROGRAMS
        ${CMAKE_CURRENT_BINARY_DIR}/cmpltest
        ${CMAKE_CURRENT_BINARY_DIR}/xref
        ${CMAKE_CURRENT_BINARY_DIR}/gpm
    DESTINATION bin
)

# Optional test target (renamed from "test" to avoid CTest conflict)
add_custom_target(test_utilities
    COMMAND ./cmpltest
    DEPENDS cmpltest
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
