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

# Utility rule file for docs_doxygen.

# Include any custom commands dependencies for this target.
include CMakeFiles/docs_doxygen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/docs_doxygen.dir/progress.make

CMakeFiles/docs_doxygen:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating Doxygen documentation"
	/opt/homebrew/bin/doxygen /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit/Doxyfile

CMakeFiles/docs_doxygen.dir/codegen:
.PHONY : CMakeFiles/docs_doxygen.dir/codegen

docs_doxygen: CMakeFiles/docs_doxygen
docs_doxygen: CMakeFiles/docs_doxygen.dir/build.make
.PHONY : docs_doxygen

# Rule to build all files generated by this target.
CMakeFiles/docs_doxygen.dir/build: docs_doxygen
.PHONY : CMakeFiles/docs_doxygen.dir/build

CMakeFiles/docs_doxygen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/docs_doxygen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/docs_doxygen.dir/clean

CMakeFiles/docs_doxygen.dir/depend:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit /Users/eirikr/Documents/GitHub/bcpl-compiler/build_audit/CMakeFiles/docs_doxygen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/docs_doxygen.dir/depend

