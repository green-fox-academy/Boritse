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
CMAKE_SOURCE_DIR = C:\Projects\favnumb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\favnumb\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/favnumb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/favnumb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/favnumb.dir/flags.make

CMakeFiles/favnumb.dir/main.cpp.obj: CMakeFiles/favnumb.dir/flags.make
CMakeFiles/favnumb.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\favnumb\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/favnumb.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\favnumb.dir\main.cpp.obj -c C:\Projects\favnumb\main.cpp

CMakeFiles/favnumb.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/favnumb.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\favnumb\main.cpp > CMakeFiles\favnumb.dir\main.cpp.i

CMakeFiles/favnumb.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/favnumb.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\favnumb\main.cpp -o CMakeFiles\favnumb.dir\main.cpp.s

# Object files for target favnumb
favnumb_OBJECTS = \
"CMakeFiles/favnumb.dir/main.cpp.obj"

# External object files for target favnumb
favnumb_EXTERNAL_OBJECTS =

favnumb.exe: CMakeFiles/favnumb.dir/main.cpp.obj
favnumb.exe: CMakeFiles/favnumb.dir/build.make
favnumb.exe: CMakeFiles/favnumb.dir/linklibs.rsp
favnumb.exe: CMakeFiles/favnumb.dir/objects1.rsp
favnumb.exe: CMakeFiles/favnumb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\favnumb\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable favnumb.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\favnumb.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/favnumb.dir/build: favnumb.exe

.PHONY : CMakeFiles/favnumb.dir/build

CMakeFiles/favnumb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\favnumb.dir\cmake_clean.cmake
.PHONY : CMakeFiles/favnumb.dir/clean

CMakeFiles/favnumb.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\favnumb C:\Projects\favnumb C:\Projects\favnumb\cmake-build-debug C:\Projects\favnumb\cmake-build-debug C:\Projects\favnumb\cmake-build-debug\CMakeFiles\favnumb.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/favnumb.dir/depend

