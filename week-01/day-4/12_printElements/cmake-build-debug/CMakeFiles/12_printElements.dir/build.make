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
CMAKE_SOURCE_DIR = C:\GREENFOX\Boritse\week-01\day-4\12_printElements

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GREENFOX\Boritse\week-01\day-4\12_printElements\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/12_printElements.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/12_printElements.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/12_printElements.dir/flags.make

CMakeFiles/12_printElements.dir/main.cpp.obj: CMakeFiles/12_printElements.dir/flags.make
CMakeFiles/12_printElements.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-01\day-4\12_printElements\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/12_printElements.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\12_printElements.dir\main.cpp.obj -c C:\GREENFOX\Boritse\week-01\day-4\12_printElements\main.cpp

CMakeFiles/12_printElements.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/12_printElements.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-01\day-4\12_printElements\main.cpp > CMakeFiles\12_printElements.dir\main.cpp.i

CMakeFiles/12_printElements.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/12_printElements.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-01\day-4\12_printElements\main.cpp -o CMakeFiles\12_printElements.dir\main.cpp.s

# Object files for target 12_printElements
12_printElements_OBJECTS = \
"CMakeFiles/12_printElements.dir/main.cpp.obj"

# External object files for target 12_printElements
12_printElements_EXTERNAL_OBJECTS =

12_printElements.exe: CMakeFiles/12_printElements.dir/main.cpp.obj
12_printElements.exe: CMakeFiles/12_printElements.dir/build.make
12_printElements.exe: CMakeFiles/12_printElements.dir/linklibs.rsp
12_printElements.exe: CMakeFiles/12_printElements.dir/objects1.rsp
12_printElements.exe: CMakeFiles/12_printElements.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GREENFOX\Boritse\week-01\day-4\12_printElements\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 12_printElements.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\12_printElements.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/12_printElements.dir/build: 12_printElements.exe

.PHONY : CMakeFiles/12_printElements.dir/build

CMakeFiles/12_printElements.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\12_printElements.dir\cmake_clean.cmake
.PHONY : CMakeFiles/12_printElements.dir/clean

CMakeFiles/12_printElements.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GREENFOX\Boritse\week-01\day-4\12_printElements C:\GREENFOX\Boritse\week-01\day-4\12_printElements C:\GREENFOX\Boritse\week-01\day-4\12_printElements\cmake-build-debug C:\GREENFOX\Boritse\week-01\day-4\12_printElements\cmake-build-debug C:\GREENFOX\Boritse\week-01\day-4\12_printElements\cmake-build-debug\CMakeFiles\12_printElements.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/12_printElements.dir/depend

