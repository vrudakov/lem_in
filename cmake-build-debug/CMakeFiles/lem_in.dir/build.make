# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mf840/lem_in

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mf840/lem_in/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lem_in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lem_in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lem_in.dir/flags.make

CMakeFiles/lem_in.dir/main.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mf840/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lem_in.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/main.c.o   -c /Users/mf840/lem_in/main.c

CMakeFiles/lem_in.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mf840/lem_in/main.c > CMakeFiles/lem_in.dir/main.c.i

CMakeFiles/lem_in.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mf840/lem_in/main.c -o CMakeFiles/lem_in.dir/main.c.s

CMakeFiles/lem_in.dir/main.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/main.c.o.requires

CMakeFiles/lem_in.dir/main.c.o.provides: CMakeFiles/lem_in.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/main.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/main.c.o.provides

CMakeFiles/lem_in.dir/main.c.o.provides.build: CMakeFiles/lem_in.dir/main.c.o


CMakeFiles/lem_in.dir/checkers.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/checkers.c.o: ../checkers.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mf840/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lem_in.dir/checkers.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/checkers.c.o   -c /Users/mf840/lem_in/checkers.c

CMakeFiles/lem_in.dir/checkers.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/checkers.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mf840/lem_in/checkers.c > CMakeFiles/lem_in.dir/checkers.c.i

CMakeFiles/lem_in.dir/checkers.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/checkers.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mf840/lem_in/checkers.c -o CMakeFiles/lem_in.dir/checkers.c.s

CMakeFiles/lem_in.dir/checkers.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/checkers.c.o.requires

CMakeFiles/lem_in.dir/checkers.c.o.provides: CMakeFiles/lem_in.dir/checkers.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/checkers.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/checkers.c.o.provides

CMakeFiles/lem_in.dir/checkers.c.o.provides.build: CMakeFiles/lem_in.dir/checkers.c.o


CMakeFiles/lem_in.dir/serve.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/serve.c.o: ../serve.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mf840/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lem_in.dir/serve.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/serve.c.o   -c /Users/mf840/lem_in/serve.c

CMakeFiles/lem_in.dir/serve.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/serve.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mf840/lem_in/serve.c > CMakeFiles/lem_in.dir/serve.c.i

CMakeFiles/lem_in.dir/serve.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/serve.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mf840/lem_in/serve.c -o CMakeFiles/lem_in.dir/serve.c.s

CMakeFiles/lem_in.dir/serve.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/serve.c.o.requires

CMakeFiles/lem_in.dir/serve.c.o.provides: CMakeFiles/lem_in.dir/serve.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/serve.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/serve.c.o.provides

CMakeFiles/lem_in.dir/serve.c.o.provides.build: CMakeFiles/lem_in.dir/serve.c.o


CMakeFiles/lem_in.dir/algo.c.o: CMakeFiles/lem_in.dir/flags.make
CMakeFiles/lem_in.dir/algo.c.o: ../algo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mf840/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lem_in.dir/algo.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lem_in.dir/algo.c.o   -c /Users/mf840/lem_in/algo.c

CMakeFiles/lem_in.dir/algo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lem_in.dir/algo.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mf840/lem_in/algo.c > CMakeFiles/lem_in.dir/algo.c.i

CMakeFiles/lem_in.dir/algo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lem_in.dir/algo.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mf840/lem_in/algo.c -o CMakeFiles/lem_in.dir/algo.c.s

CMakeFiles/lem_in.dir/algo.c.o.requires:

.PHONY : CMakeFiles/lem_in.dir/algo.c.o.requires

CMakeFiles/lem_in.dir/algo.c.o.provides: CMakeFiles/lem_in.dir/algo.c.o.requires
	$(MAKE) -f CMakeFiles/lem_in.dir/build.make CMakeFiles/lem_in.dir/algo.c.o.provides.build
.PHONY : CMakeFiles/lem_in.dir/algo.c.o.provides

CMakeFiles/lem_in.dir/algo.c.o.provides.build: CMakeFiles/lem_in.dir/algo.c.o


# Object files for target lem_in
lem_in_OBJECTS = \
"CMakeFiles/lem_in.dir/main.c.o" \
"CMakeFiles/lem_in.dir/checkers.c.o" \
"CMakeFiles/lem_in.dir/serve.c.o" \
"CMakeFiles/lem_in.dir/algo.c.o"

# External object files for target lem_in
lem_in_EXTERNAL_OBJECTS =

lem_in: CMakeFiles/lem_in.dir/main.c.o
lem_in: CMakeFiles/lem_in.dir/checkers.c.o
lem_in: CMakeFiles/lem_in.dir/serve.c.o
lem_in: CMakeFiles/lem_in.dir/algo.c.o
lem_in: CMakeFiles/lem_in.dir/build.make
lem_in: ../libft/libft.a
lem_in: CMakeFiles/lem_in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mf840/lem_in/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable lem_in"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lem_in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lem_in.dir/build: lem_in

.PHONY : CMakeFiles/lem_in.dir/build

CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/main.c.o.requires
CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/checkers.c.o.requires
CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/serve.c.o.requires
CMakeFiles/lem_in.dir/requires: CMakeFiles/lem_in.dir/algo.c.o.requires

.PHONY : CMakeFiles/lem_in.dir/requires

CMakeFiles/lem_in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lem_in.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lem_in.dir/clean

CMakeFiles/lem_in.dir/depend:
	cd /Users/mf840/lem_in/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mf840/lem_in /Users/mf840/lem_in /Users/mf840/lem_in/cmake-build-debug /Users/mf840/lem_in/cmake-build-debug /Users/mf840/lem_in/cmake-build-debug/CMakeFiles/lem_in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lem_in.dir/depend

