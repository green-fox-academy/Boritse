# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\GREENFOX\Boritse\week-03\day-03\fibonacci

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GREENFOX\Boritse\week-03\day-03\fibonacci\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fibonacci.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fibonacci.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fibonacci.dir/flags.make

CMakeFiles/fibonacci.dir/main.cpp.obj: CMakeFiles/fibonacci.dir/flags.make
CMakeFiles/fibonacci.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-03\fibonacci\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fibonacci.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\fibonacci.dir\main.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-03\fibonacci\main.cpp

CMakeFiles/fibonacci.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fibonacci.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-03\fibonacci\main.cpp > CMakeFiles\fibonacci.dir\main.cpp.i

CMakeFiles/fibonacci.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fibonacci.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-03\fibonacci\main.cpp -o CMakeFiles\fibonacci.dir\main.cpp.s

# Object files for target fibonacci
fibonacci_OBJECTS = \
"CMakeFiles/fibonacci.dir/main.cpp.obj"

# External object files for target fibonacci
fibonacci_EXTERNAL_OBJECTS =

fibonacci.exe: CMakeFiles/fibonacci.dir/main.cpp.obj
fibonacci.exe: CMakeFiles/fibonacci.dir/build.make
fibonacci.exe: CMakeFiles/fibonacci.dir/linklibs.rsp
fibonacci.exe: CMakeFiles/fibonacci.dir/objects1.rsp
fibonacci.exe: CMakeFiles/fibonacci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GREENFOX\Boritse\week-03\day-03\fibonacci\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fibonacci.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fibonacci.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fibonacci.dir/build: fibonacci.exe

.PHONY : CMakeFiles/fibonacci.dir/build

CMakeFiles/fibonacci.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fibonacci.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fibonacci.dir/clean

CMakeFiles/fibonacci.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GREENFOX\Boritse\week-03\day-03\fibonacci C:\GREENFOX\Boritse\week-03\day-03\fibonacci C:\GREENFOX\Boritse\week-03\day-03\fibonacci\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-03\fibonacci\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-03\fibonacci\cmake-build-debug\CMakeFiles\fibonacci.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fibonacci.dir/depend

