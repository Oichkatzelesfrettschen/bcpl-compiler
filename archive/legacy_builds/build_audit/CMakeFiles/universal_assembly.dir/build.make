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
CMAKE_BINARY_DIR = /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit

# Utility rule file for universal_assembly.

# Include any custom commands dependencies for this target.
include CMakeFiles/universal_assembly.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/universal_assembly.dir/progress.make

CMakeFiles/universal_assembly.dir/codegen:
.PHONY : CMakeFiles/universal_assembly.dir/codegen

universal_assembly: CMakeFiles/universal_assembly.dir/build.make
.PHONY : universal_assembly

# Rule to build all files generated by this target.
CMakeFiles/universal_assembly.dir/build: universal_assembly
.PHONY : CMakeFiles/universal_assembly.dir/build

CMakeFiles/universal_assembly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/universal_assembly.dir/cmake_clean.cmake
.PHONY : CMakeFiles/universal_assembly.dir/clean

CMakeFiles/universal_assembly.dir/depend:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit/CMakeFiles/universal_assembly.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/universal_assembly.dir/depend

