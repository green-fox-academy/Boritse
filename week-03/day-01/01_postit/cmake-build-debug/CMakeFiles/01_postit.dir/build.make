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
CMAKE_SOURCE_DIR = C:\GREENFOX\Boritse\week-03\day-01\01_postit

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GREENFOX\Boritse\week-03\day-01\01_postit\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/01_postit.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/01_postit.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/01_postit.dir/flags.make

CMakeFiles/01_postit.dir/main.cpp.obj: CMakeFiles/01_postit.dir/flags.make
CMakeFiles/01_postit.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-01\01_postit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/01_postit.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\01_postit.dir\main.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-01\01_postit\main.cpp

CMakeFiles/01_postit.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01_postit.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-01\01_postit\main.cpp > CMakeFiles\01_postit.dir\main.cpp.i

CMakeFiles/01_postit.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01_postit.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-01\01_postit\main.cpp -o CMakeFiles\01_postit.dir\main.cpp.s

CMakeFiles/01_postit.dir/postit.cpp.obj: CMakeFiles/01_postit.dir/flags.make
CMakeFiles/01_postit.dir/postit.cpp.obj: ../postit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-01\01_postit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/01_postit.dir/postit.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\01_postit.dir\postit.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-01\01_postit\postit.cpp

CMakeFiles/01_postit.dir/postit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01_postit.dir/postit.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-01\01_postit\postit.cpp > CMakeFiles\01_postit.dir\postit.cpp.i

CMakeFiles/01_postit.dir/postit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01_postit.dir/postit.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-01\01_postit\postit.cpp -o CMakeFiles\01_postit.dir\postit.cpp.s

# Object files for target 01_postit
01_postit_OBJECTS = \
"CMakeFiles/01_postit.dir/main.cpp.obj" \
"CMakeFiles/01_postit.dir/postit.cpp.obj"

# External object files for target 01_postit
01_postit_EXTERNAL_OBJECTS =

01_postit.exe: CMakeFiles/01_postit.dir/main.cpp.obj
01_postit.exe: CMakeFiles/01_postit.dir/postit.cpp.obj
01_postit.exe: CMakeFiles/01_postit.dir/build.make
01_postit.exe: CMakeFiles/01_postit.dir/linklibs.rsp
01_postit.exe: CMakeFiles/01_postit.dir/objects1.rsp
01_postit.exe: CMakeFiles/01_postit.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GREENFOX\Boritse\week-03\day-01\01_postit\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 01_postit.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\01_postit.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/01_postit.dir/build: 01_postit.exe

.PHONY : CMakeFiles/01_postit.dir/build

CMakeFiles/01_postit.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\01_postit.dir\cmake_clean.cmake
.PHONY : CMakeFiles/01_postit.dir/clean

CMakeFiles/01_postit.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GREENFOX\Boritse\week-03\day-01\01_postit C:\GREENFOX\Boritse\week-03\day-01\01_postit C:\GREENFOX\Boritse\week-03\day-01\01_postit\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-01\01_postit\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-01\01_postit\cmake-build-debug\CMakeFiles\01_postit.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/01_postit.dir/depend

