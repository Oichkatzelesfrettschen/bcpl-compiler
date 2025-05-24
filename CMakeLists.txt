cmake_minimum_required(VERSION 3.10)
project(bcplc C)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Allow selection of runtime bitness.  The historical runtime is 32 bit
# but the repository defaults to a 64 bit build.  A ``BITS`` cache
# variable mirrors the Makefiles and can be overridden on the command
# line with ``-DBITS=32``.
set(BITS "64" CACHE STRING "Target word size" )
set_property(CACHE BITS PROPERTY STRINGS 32 64)

# Optional prefix for assembler/linker tools when cross compiling.  The
# environment variable of the same name is used as the default to
# maintain compatibility with the traditional Makefiles and driver
# script.
set(CROSS_PREFIX "$ENV{CROSS_PREFIX}" CACHE STRING "Cross compilation tool prefix")

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

option(BOOTSTRAP "Regenerate st.s using built cg/op" ON)

add_subdirectory(src)
add_subdirectory(util)
add_subdirectory(doc)
