# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/wen/Desktop/CPP/Course Project"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug"

# Include any dependencies generated for this target.
include MyTest/lib/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include MyTest/lib/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include MyTest/lib/googletest/CMakeFiles/gtest.dir/flags.make

MyTest/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: MyTest/lib/googletest/CMakeFiles/gtest.dir/flags.make
MyTest/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../MyTest/lib/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object MyTest/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest" && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c "/Users/wen/Desktop/CPP/Course Project/MyTest/lib/googletest/src/gtest-all.cc"

MyTest/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wen/Desktop/CPP/Course Project/MyTest/lib/googletest/src/gtest-all.cc" > CMakeFiles/gtest.dir/src/gtest-all.cc.i

MyTest/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wen/Desktop/CPP/Course Project/MyTest/lib/googletest/src/gtest-all.cc" -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtestd.a: MyTest/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtestd.a: MyTest/lib/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtestd.a: MyTest/lib/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtestd.a"
	cd "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
MyTest/lib/googletest/CMakeFiles/gtest.dir/build: lib/libgtestd.a

.PHONY : MyTest/lib/googletest/CMakeFiles/gtest.dir/build

MyTest/lib/googletest/CMakeFiles/gtest.dir/clean:
	cd "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : MyTest/lib/googletest/CMakeFiles/gtest.dir/clean

MyTest/lib/googletest/CMakeFiles/gtest.dir/depend:
	cd "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/wen/Desktop/CPP/Course Project" "/Users/wen/Desktop/CPP/Course Project/MyTest/lib/googletest" "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug" "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest" "/Users/wen/Desktop/CPP/Course Project/cmake-build-debug/MyTest/lib/googletest/CMakeFiles/gtest.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : MyTest/lib/googletest/CMakeFiles/gtest.dir/depend

