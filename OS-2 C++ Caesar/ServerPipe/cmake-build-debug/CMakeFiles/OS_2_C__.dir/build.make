# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /cygdrive/c/Users/DiBoS/.CLion2018.3/system/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/DiBoS/.CLion2018.3/system/cygwin_cmake/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/OS_2_C__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OS_2_C__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OS_2_C__.dir/flags.make

CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.o: CMakeFiles/OS_2_C__.dir/flags.make
CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.o: ../ServerPipe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.o -c "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/ServerPipe.cpp"

CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/ServerPipe.cpp" > CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.i

CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/ServerPipe.cpp" -o CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.s

# Object files for target OS_2_C__
OS_2_C___OBJECTS = \
"CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.o"

# External object files for target OS_2_C__
OS_2_C___EXTERNAL_OBJECTS =

OS_2_C__.exe: CMakeFiles/OS_2_C__.dir/ServerPipe.cpp.o
OS_2_C__.exe: CMakeFiles/OS_2_C__.dir/build.make
OS_2_C__.exe: CMakeFiles/OS_2_C__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OS_2_C__.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OS_2_C__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OS_2_C__.dir/build: OS_2_C__.exe

.PHONY : CMakeFiles/OS_2_C__.dir/build

CMakeFiles/OS_2_C__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OS_2_C__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OS_2_C__.dir/clean

CMakeFiles/OS_2_C__.dir/depend:
	cd "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe" "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe" "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/cmake-build-debug" "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/cmake-build-debug" "/cygdrive/c/Users/DiBoS/Desktop/Labs/OperatingSystems/OS-2 C++ Caesar/ServerPipe/cmake-build-debug/CMakeFiles/OS_2_C__.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/OS_2_C__.dir/depend
