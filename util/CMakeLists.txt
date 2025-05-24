cmake_minimum_required(VERSION 3.10)

# Use BC environment variable or locate bcplc in PATH
if(DEFINED ENV{BC} AND NOT "$ENV{BC}" STREQUAL "")
    set(BC_TOOL "$ENV{BC}")
else()
    find_program(BC_TOOL bcplc)
endif()

if(NOT BC_TOOL)
    message(WARNING "bcplc driver not found. Targets may fail to build")
    set(BC_TOOL bcplc)
endif()

set(BFLAGS -O)

function(add_bcpl_program name)
    add_custom_command(
        OUTPUT ${name}
        COMMAND ${BC_TOOL} ${BFLAGS} ${CMAKE_CURRENT_SOURCE_DIR}/${name}.bcpl
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${name}.bcpl
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        VERBATIM
    )
    add_custom_target(${name} DEPENDS ${name})
endfunction()

add_bcpl_program(cmpltest)
add_bcpl_program(xref)
add_bcpl_program(gpm)

# Optional test target equivalent to "make test" in util
add_custom_target(test
    COMMAND ./cmpltest
    DEPENDS cmpltest
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
