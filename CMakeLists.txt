cmake_minimum_required(VERSION 3.20)
project(BCPL VERSION 0.1 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(Options)
include(ArchitectureConfig)
include(PlatformConfig)

add_subdirectory(src)
add_subdirectory(tools)
add_subdirectory(docs)
add_subdirectory(tests)
