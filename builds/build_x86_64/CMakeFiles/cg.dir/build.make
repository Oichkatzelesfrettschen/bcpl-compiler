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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eirikr/Documents/GitHub/bcpl-compiler/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64

# Include any dependencies generated for this target.
include CMakeFiles/cg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cg.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cg.dir/flags.make

CMakeFiles/cg.dir/codegen:
.PHONY : CMakeFiles/cg.dir/codegen

CMakeFiles/cg.dir/cg.c.o: CMakeFiles/cg.dir/flags.make
CMakeFiles/cg.dir/cg.c.o: /Users/eirikr/Documents/GitHub/bcpl-compiler/src/cg.c
CMakeFiles/cg.dir/cg.c.o: CMakeFiles/cg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cg.dir/cg.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cg.dir/cg.c.o -MF CMakeFiles/cg.dir/cg.c.o.d -o CMakeFiles/cg.dir/cg.c.o -c /Users/eirikr/Documents/GitHub/bcpl-compiler/src/cg.c

CMakeFiles/cg.dir/cg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cg.dir/cg.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/eirikr/Documents/GitHub/bcpl-compiler/src/cg.c > CMakeFiles/cg.dir/cg.c.i

CMakeFiles/cg.dir/cg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cg.dir/cg.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/eirikr/Documents/GitHub/bcpl-compiler/src/cg.c -o CMakeFiles/cg.dir/cg.c.s

CMakeFiles/cg.dir/oc.c.o: CMakeFiles/cg.dir/flags.make
CMakeFiles/cg.dir/oc.c.o: /Users/eirikr/Documents/GitHub/bcpl-compiler/src/oc.c
CMakeFiles/cg.dir/oc.c.o: CMakeFiles/cg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cg.dir/oc.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/cg.dir/oc.c.o -MF CMakeFiles/cg.dir/oc.c.o.d -o CMakeFiles/cg.dir/oc.c.o -c /Users/eirikr/Documents/GitHub/bcpl-compiler/src/oc.c

CMakeFiles/cg.dir/oc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/cg.dir/oc.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/eirikr/Documents/GitHub/bcpl-compiler/src/oc.c > CMakeFiles/cg.dir/oc.c.i

CMakeFiles/cg.dir/oc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/cg.dir/oc.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/eirikr/Documents/GitHub/bcpl-compiler/src/oc.c -o CMakeFiles/cg.dir/oc.c.s

# Object files for target cg
cg_OBJECTS = \
"CMakeFiles/cg.dir/cg.c.o" \
"CMakeFiles/cg.dir/oc.c.o"

# External object files for target cg
cg_EXTERNAL_OBJECTS =

cg: CMakeFiles/cg.dir/cg.c.o
cg: CMakeFiles/cg.dir/oc.c.o
cg: CMakeFiles/cg.dir/build.make
cg: libbcpl_runtime.a
cg: CMakeFiles/cg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable cg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cg.dir/build: cg
.PHONY : CMakeFiles/cg.dir/build

CMakeFiles/cg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cg.dir/clean

CMakeFiles/cg.dir/depend:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eirikr/Documents/GitHub/bcpl-compiler/src /Users/eirikr/Documents/GitHub/bcpl-compiler/src /Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64 /Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64 /Users/eirikr/Documents/GitHub/bcpl-compiler/build_x86_64/CMakeFiles/cg.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cg.dir/depend

