cmake_minimum_required(VERSION 3.10)

# Include centralized options
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)
include(Options)

# Only generate docs if enabled
if(NOT ENABLE_DOCS)
    return()
endif()

# Doxygen
find_package(Doxygen REQUIRED)
if(DOXYGEN_FOUND)
    message(STATUS "Generating Doxygen documentation...")
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/../Doxyfile)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)
    add_custom_target(doxygen
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Doxygen API docs"
    )
endif()

# Sphinx
find_program(SPHINX_EXECUTABLE NAMES sphinx-build)
if(SPHINX_EXECUTABLE)
    message(STATUS "Generating Sphinx HTML documentation...")
    add_custom_target(sphinx-docs
        COMMAND ${SPHINX_EXECUTABLE} -b html ${CMAKE_CURRENT_SOURCE_DIR}/sphinx ${CMAKE_CURRENT_BINARY_DIR}/sphinx_html
        COMMENT "Sphinx docs"
    )
endif()

# Install docs
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc/BCPL)
