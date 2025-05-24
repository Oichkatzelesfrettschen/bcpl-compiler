cmake_minimum_required(VERSION 3.10)
project(bcplc C)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

option(BOOTSTRAP "Regenerate st.s using built cg/op" OFF)

add_subdirectory(src)
add_subdirectory(util)
add_subdirectory(doc)
