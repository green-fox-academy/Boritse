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
CMAKE_SOURCE_DIR = C:\Projects\ketszam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\ketszam\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ketszam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ketszam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ketszam.dir/flags.make

CMakeFiles/ketszam.dir/main.cpp.obj: CMakeFiles/ketszam.dir/flags.make
CMakeFiles/ketszam.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\ketszam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ketszam.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ketszam.dir\main.cpp.obj -c C:\Projects\ketszam\main.cpp

CMakeFiles/ketszam.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ketszam.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\ketszam\main.cpp > CMakeFiles\ketszam.dir\main.cpp.i

CMakeFiles/ketszam.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ketszam.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\ketszam\main.cpp -o CMakeFiles\ketszam.dir\main.cpp.s

# Object files for target ketszam
ketszam_OBJECTS = \
"CMakeFiles/ketszam.dir/main.cpp.obj"

# External object files for target ketszam
ketszam_EXTERNAL_OBJECTS =

ketszam.exe: CMakeFiles/ketszam.dir/main.cpp.obj
ketszam.exe: CMakeFiles/ketszam.dir/build.make
ketszam.exe: CMakeFiles/ketszam.dir/linklibs.rsp
ketszam.exe: CMakeFiles/ketszam.dir/objects1.rsp
ketszam.exe: CMakeFiles/ketszam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\ketszam\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ketszam.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ketszam.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ketszam.dir/build: ketszam.exe

.PHONY : CMakeFiles/ketszam.dir/build

CMakeFiles/ketszam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ketszam.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ketszam.dir/clean

CMakeFiles/ketszam.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\ketszam C:\Projects\ketszam C:\Projects\ketszam\cmake-build-debug C:\Projects\ketszam\cmake-build-debug C:\Projects\ketszam\cmake-build-debug\CMakeFiles\ketszam.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ketszam.dir/depend

