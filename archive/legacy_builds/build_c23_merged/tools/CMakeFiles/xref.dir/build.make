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
CMAKE_BINARY_DIR = /Users/eirikr/Documents/GitHub/bcpl-compiler/build_c23

# Utility rule file for xref.

# Include any custom commands dependencies for this target.
include tools/CMakeFiles/xref.dir/compiler_depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/xref.dir/progress.make

tools/CMakeFiles/xref:

tools/CMakeFiles/xref.dir/codegen:
.PHONY : tools/CMakeFiles/xref.dir/codegen

xref: tools/CMakeFiles/xref
xref: tools/CMakeFiles/xref.dir/build.make
.PHONY : xref

# Rule to build all files generated by this target.
tools/CMakeFiles/xref.dir/build: xref
.PHONY : tools/CMakeFiles/xref.dir/build

tools/CMakeFiles/xref.dir/clean:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_c23/tools && $(CMAKE_COMMAND) -P CMakeFiles/xref.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/xref.dir/clean

tools/CMakeFiles/xref.dir/depend:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_c23 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler/tools /Users/eirikr/Documents/GitHub/bcpl-compiler/build_c23 /Users/eirikr/Documents/GitHub/bcpl-compiler/build_c23/tools /Users/eirikr/Documents/GitHub/bcpl-compiler/build_c23/tools/CMakeFiles/xref.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tools/CMakeFiles/xref.dir/depend

