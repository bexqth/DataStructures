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
CMAKE_SOURCE_DIR = "/Users/terka/Documents/Data structures/DataStructures"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug"

# Include any dependencies generated for this target.
include complexities/CMakeFiles/complexities.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include complexities/CMakeFiles/complexities.dir/compiler_depend.make

# Include the progress variables for this target.
include complexities/CMakeFiles/complexities.dir/progress.make

# Include the compile flags for this target's objects.
include complexities/CMakeFiles/complexities.dir/flags.make

complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.o: complexities/CMakeFiles/complexities.dir/flags.make
complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.o: /Users/terka/Documents/Data\ structures/DataStructures/complexities/complexity_analyzer.cpp
complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.o: complexities/CMakeFiles/complexities.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.o"
	cd "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.o -MF CMakeFiles/complexities.dir/complexity_analyzer.cpp.o.d -o CMakeFiles/complexities.dir/complexity_analyzer.cpp.o -c "/Users/terka/Documents/Data structures/DataStructures/complexities/complexity_analyzer.cpp"

complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/complexities.dir/complexity_analyzer.cpp.i"
	cd "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/terka/Documents/Data structures/DataStructures/complexities/complexity_analyzer.cpp" > CMakeFiles/complexities.dir/complexity_analyzer.cpp.i

complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/complexities.dir/complexity_analyzer.cpp.s"
	cd "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/terka/Documents/Data structures/DataStructures/complexities/complexity_analyzer.cpp" -o CMakeFiles/complexities.dir/complexity_analyzer.cpp.s

# Object files for target complexities
complexities_OBJECTS = \
"CMakeFiles/complexities.dir/complexity_analyzer.cpp.o"

# External object files for target complexities
complexities_EXTERNAL_OBJECTS =

complexities/libcomplexities.a: complexities/CMakeFiles/complexities.dir/complexity_analyzer.cpp.o
complexities/libcomplexities.a: complexities/CMakeFiles/complexities.dir/build.make
complexities/libcomplexities.a: complexities/CMakeFiles/complexities.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libcomplexities.a"
	cd "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities" && $(CMAKE_COMMAND) -P CMakeFiles/complexities.dir/cmake_clean_target.cmake
	cd "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/complexities.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
complexities/CMakeFiles/complexities.dir/build: complexities/libcomplexities.a
.PHONY : complexities/CMakeFiles/complexities.dir/build

complexities/CMakeFiles/complexities.dir/clean:
	cd "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities" && $(CMAKE_COMMAND) -P CMakeFiles/complexities.dir/cmake_clean.cmake
.PHONY : complexities/CMakeFiles/complexities.dir/clean

complexities/CMakeFiles/complexities.dir/depend:
	cd "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/terka/Documents/Data structures/DataStructures" "/Users/terka/Documents/Data structures/DataStructures/complexities" "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug" "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities" "/Users/terka/Documents/Data structures/DataStructures/cmake-build-debug/complexities/CMakeFiles/complexities.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : complexities/CMakeFiles/complexities.dir/depend

