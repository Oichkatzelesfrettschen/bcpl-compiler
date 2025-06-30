# CMake generated Testfile for 
# Source directory: /Users/eirikr/Documents/GitHub/bcpl-compiler
# Build directory: /Users/eirikr/Documents/GitHub/bcpl-compiler/builds/build_unified
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[bcplc_version]=] "/Users/eirikr/Documents/GitHub/bcpl-compiler/src/bcplc" "--version")
set_tests_properties([=[bcplc_version]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;340;add_test;/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;0;")
add_test([=[runtime_linking]=] "/opt/homebrew/bin/cmake" "-E" "echo" "Runtime library: /Users/eirikr/Documents/GitHub/bcpl-compiler/builds/build_unified/src/libbcpl_runtime.a")
set_tests_properties([=[runtime_linking]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;345;add_test;/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;0;")
add_test([=[compile_standard_lib]=] "/Users/eirikr/Documents/GitHub/bcpl-compiler/src/bcplc" "/Users/eirikr/Documents/GitHub/bcpl-compiler/src/st.bcpl")
set_tests_properties([=[compile_standard_lib]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;351;add_test;/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;0;")
add_test([=[tools_test]=] "/Users/eirikr/Documents/GitHub/bcpl-compiler/builds/build_unified/cmpltest")
set_tests_properties([=[tools_test]=] PROPERTIES  DEPENDS "bcpl_tools" _BACKTRACE_TRIPLES "/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;357;add_test;/Users/eirikr/Documents/GitHub/bcpl-compiler/CMakeLists.txt;0;")
subdirs("src")
subdirs("tools")
subdirs("docs")
