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
CMAKE_BINARY_DIR = /Users/eirikr/Documents/GitHub/bcpl-compiler/build_optimized

# Utility rule file for ARMTargetParserTableGen.

# Include any custom commands dependencies for this target.
include src/CMakeFiles/ARMTargetParserTableGen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/ARMTargetParserTableGen.dir/progress.make

src/CMakeFiles/ARMTargetParserTableGen.dir/codegen:
.PHONY : src/CMakeFiles/ARMTargetParserTableGen.dir/codegen

ARMTargetParserTableGen: src/CMakeFiles/ARMTargetParserTableGen.dir/build.make
.PHONY : ARMTargetParserTableGen

# Rule to build all files generated by this target.
src/CMakeFiles/ARMTargetParserTableGen.dir/build: ARMTargetParserTableGen
.PHONY : src/CMakeFiles/ARMTargetParserTableGen.dir/build

src/CMakeFiles/ARMTargetParserTableGen.dir/clean:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_optimized/src && $(CMAKE_COMMAND) -P CMakeFiles/ARMTargetParserTableGen.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/ARMTargetParserTableGen.dir/clean

src/CMakeFiles/ARMTargetParserTableGen.dir/depend:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_optimized && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler/src /Users/eirikr/Documents/GitHub/bcpl-compiler/build_optimized /Users/eirikr/Documents/GitHub/bcpl-compiler/build_optimized/src /Users/eirikr/Documents/GitHub/bcpl-compiler/build_optimized/src/CMakeFiles/ARMTargetParserTableGen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/ARMTargetParserTableGen.dir/depend

