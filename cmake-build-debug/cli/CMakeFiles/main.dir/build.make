# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/terka/Documents/Data structures/AUS-CMake"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug"

# Include any dependencies generated for this target.
include cli/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include cli/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include cli/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include cli/CMakeFiles/main.dir/flags.make

cli/CMakeFiles/main.dir/main.cpp.o: cli/CMakeFiles/main.dir/flags.make
cli/CMakeFiles/main.dir/main.cpp.o: /Users/terka/Documents/Data\ structures/AUS-CMake/cli/main.cpp
cli/CMakeFiles/main.dir/main.cpp.o: cli/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object cli/CMakeFiles/main.dir/main.cpp.o"
	cd "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/cli" && /opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT cli/CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c "/Users/terka/Documents/Data structures/AUS-CMake/cli/main.cpp"

cli/CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	cd "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/cli" && /opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/terka/Documents/Data structures/AUS-CMake/cli/main.cpp" > CMakeFiles/main.dir/main.cpp.i

cli/CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	cd "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/cli" && /opt/homebrew/bin/g++-13 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/terka/Documents/Data structures/AUS-CMake/cli/main.cpp" -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

cli/main: cli/CMakeFiles/main.dir/main.cpp.o
cli/main: cli/CMakeFiles/main.dir/build.make
cli/main: tests/libtests.a
cli/main: complexities/libcomplexities.a
cli/main: cli/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main"
	cd "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/cli" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
cli/CMakeFiles/main.dir/build: cli/main
.PHONY : cli/CMakeFiles/main.dir/build

cli/CMakeFiles/main.dir/clean:
	cd "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/cli" && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : cli/CMakeFiles/main.dir/clean

cli/CMakeFiles/main.dir/depend:
	cd "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/terka/Documents/Data structures/AUS-CMake" "/Users/terka/Documents/Data structures/AUS-CMake/cli" "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug" "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/cli" "/Users/terka/Documents/Data structures/AUS-CMake/cmake-build-debug/cli/CMakeFiles/main.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : cli/CMakeFiles/main.dir/depend

