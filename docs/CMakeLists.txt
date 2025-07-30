cmake_minimum_required(VERSION 3.20)

# Documentation build configuration

if(NOT ENABLE_DOCS)
    message(STATUS "Documentation generation disabled")
    return()
endif()

find_package(Doxygen REQUIRED)
find_package(Sphinx REQUIRED)

# Doxygen configuration
set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/Doxyfile)
set(DOXYGEN_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR}/doxygen)

add_custom_target(doc_doxygen
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
)

# Sphinx configuration
set(SPHINX_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/sphinx)
set(SPHINX_BUILD  ${CMAKE_CURRENT_BINARY_DIR}/sphinx)

add_custom_target(doc_sphinx
    COMMAND ${SPHINX_EXECUTABLE} -b html ${SPHINX_SOURCE} ${SPHINX_BUILD}/html
    DEPENDS doc_doxygen
    COMMENT "Generating developer documentation with Sphinx"
)

add_custom_target(doc ALL DEPENDS doc_doxygen doc_sphinx)
