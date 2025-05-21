cmake_minimum_required(VERSION 3.10)
project(bcplc C)

option(BOOTSTRAP "Regenerate st.s using built cg/op" OFF)

add_subdirectory(src)
add_subdirectory(util)
add_subdirectory(doc)
