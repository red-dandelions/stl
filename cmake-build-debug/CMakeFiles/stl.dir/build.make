# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vanilla/CLionProjects/stl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vanilla/CLionProjects/stl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stl.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/stl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stl.dir/flags.make

CMakeFiles/stl.dir/main.cpp.o: CMakeFiles/stl.dir/flags.make
CMakeFiles/stl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/vanilla/CLionProjects/stl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stl.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stl.dir/main.cpp.o -c /Users/vanilla/CLionProjects/stl/main.cpp

CMakeFiles/stl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stl.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vanilla/CLionProjects/stl/main.cpp > CMakeFiles/stl.dir/main.cpp.i

CMakeFiles/stl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stl.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vanilla/CLionProjects/stl/main.cpp -o CMakeFiles/stl.dir/main.cpp.s

# Object files for target stl
stl_OBJECTS = \
"CMakeFiles/stl.dir/main.cpp.o"

# External object files for target stl
stl_EXTERNAL_OBJECTS =

stl: CMakeFiles/stl.dir/main.cpp.o
stl: CMakeFiles/stl.dir/build.make
stl: /usr/local/lib/libgtest.a
stl: CMakeFiles/stl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/vanilla/CLionProjects/stl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stl.dir/build: stl
.PHONY : CMakeFiles/stl.dir/build

CMakeFiles/stl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stl.dir/clean

CMakeFiles/stl.dir/depend:
	cd /Users/vanilla/CLionProjects/stl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vanilla/CLionProjects/stl /Users/vanilla/CLionProjects/stl /Users/vanilla/CLionProjects/stl/cmake-build-debug /Users/vanilla/CLionProjects/stl/cmake-build-debug /Users/vanilla/CLionProjects/stl/cmake-build-debug/CMakeFiles/stl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stl.dir/depend

