# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eirikr/Documents/GitHub/bcpl-compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test

# Utility rule file for cmpltest.

# Include any custom commands dependencies for this target.
include tools/CMakeFiles/cmpltest.dir/compiler_depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/cmpltest.dir/progress.make

tools/CMakeFiles/cmpltest:

tools/CMakeFiles/cmpltest.dir/codegen:
.PHONY : tools/CMakeFiles/cmpltest.dir/codegen

cmpltest: tools/CMakeFiles/cmpltest
cmpltest: tools/CMakeFiles/cmpltest.dir/build.make
.PHONY : cmpltest

# Rule to build all files generated by this target.
tools/CMakeFiles/cmpltest.dir/build: cmpltest
.PHONY : tools/CMakeFiles/cmpltest.dir/build

tools/CMakeFiles/cmpltest.dir/clean:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tools && $(CMAKE_COMMAND) -P CMakeFiles/cmpltest.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/cmpltest.dir/clean

tools/CMakeFiles/cmpltest.dir/depend:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler/tools /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tools /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tools/CMakeFiles/cmpltest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tools/CMakeFiles/cmpltest.dir/depend

