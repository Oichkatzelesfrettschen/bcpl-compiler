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

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_runtime_modernization.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_runtime_modernization.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_runtime_modernization.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_runtime_modernization.dir/flags.make

tests/CMakeFiles/test_runtime_modernization.dir/codegen:
.PHONY : tests/CMakeFiles/test_runtime_modernization.dir/codegen

tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o: tests/CMakeFiles/test_runtime_modernization.dir/flags.make
tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o: /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_runtime.c
tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o: tests/CMakeFiles/test_runtime_modernization.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o -MF CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o.d -o CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o -c /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_runtime.c

tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_runtime_modernization.dir/test_runtime.c.i"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_runtime.c > CMakeFiles/test_runtime_modernization.dir/test_runtime.c.i

tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_runtime_modernization.dir/test_runtime.c.s"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_runtime.c -o CMakeFiles/test_runtime_modernization.dir/test_runtime.c.s

tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o: tests/CMakeFiles/test_runtime_modernization.dir/flags.make
tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o: /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_platform_abstraction.c
tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o: tests/CMakeFiles/test_runtime_modernization.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o -MF CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o.d -o CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o -c /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_platform_abstraction.c

tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.i"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_platform_abstraction.c > CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.i

tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.s"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_platform_abstraction.c -o CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.s

tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o: tests/CMakeFiles/test_runtime_modernization.dir/flags.make
tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o: /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_memory_safety.c
tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o: tests/CMakeFiles/test_runtime_modernization.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o -MF CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o.d -o CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o -c /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_memory_safety.c

tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.i"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_memory_safety.c > CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.i

tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.s"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/eirikr/Documents/GitHub/bcpl-compiler/tests/test_memory_safety.c -o CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.s

# Object files for target test_runtime_modernization
test_runtime_modernization_OBJECTS = \
"CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o" \
"CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o" \
"CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o"

# External object files for target test_runtime_modernization
test_runtime_modernization_EXTERNAL_OBJECTS =

tests/test_runtime_modernization: tests/CMakeFiles/test_runtime_modernization.dir/test_runtime.c.o
tests/test_runtime_modernization: tests/CMakeFiles/test_runtime_modernization.dir/test_platform_abstraction.c.o
tests/test_runtime_modernization: tests/CMakeFiles/test_runtime_modernization.dir/test_memory_safety.c.o
tests/test_runtime_modernization: tests/CMakeFiles/test_runtime_modernization.dir/build.make
tests/test_runtime_modernization: src/libbcpl_runtime.a
tests/test_runtime_modernization: tests/CMakeFiles/test_runtime_modernization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable test_runtime_modernization"
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_runtime_modernization.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_runtime_modernization.dir/build: tests/test_runtime_modernization
.PHONY : tests/CMakeFiles/test_runtime_modernization.dir/build

tests/CMakeFiles/test_runtime_modernization.dir/clean:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_runtime_modernization.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_runtime_modernization.dir/clean

tests/CMakeFiles/test_runtime_modernization.dir/depend:
	cd /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eirikr/Documents/GitHub/bcpl-compiler /Users/eirikr/Documents/GitHub/bcpl-compiler/tests /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests /Users/eirikr/Documents/GitHub/bcpl-compiler/build_test/tests/CMakeFiles/test_runtime_modernization.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_runtime_modernization.dir/depend

