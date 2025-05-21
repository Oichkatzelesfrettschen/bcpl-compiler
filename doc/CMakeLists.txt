cmake_minimum_required(VERSION 3.10)

add_custom_target(doc ALL)

install(FILES manual.txt standard.txt DESTINATION share/doc/BCPL)
