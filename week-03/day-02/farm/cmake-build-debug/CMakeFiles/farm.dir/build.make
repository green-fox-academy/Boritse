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
CMAKE_SOURCE_DIR = C:\GREENFOX\Boritse\week-03\day-02\farm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/farm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/farm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/farm.dir/flags.make

CMakeFiles/farm.dir/main.cpp.obj: CMakeFiles/farm.dir/flags.make
CMakeFiles/farm.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/farm.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\farm.dir\main.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-02\farm\main.cpp

CMakeFiles/farm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/farm.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-02\farm\main.cpp > CMakeFiles\farm.dir\main.cpp.i

CMakeFiles/farm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/farm.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-02\farm\main.cpp -o CMakeFiles\farm.dir\main.cpp.s

CMakeFiles/farm.dir/Farm.cpp.obj: CMakeFiles/farm.dir/flags.make
CMakeFiles/farm.dir/Farm.cpp.obj: ../Farm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/farm.dir/Farm.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\farm.dir\Farm.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-02\farm\Farm.cpp

CMakeFiles/farm.dir/Farm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/farm.dir/Farm.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-02\farm\Farm.cpp > CMakeFiles\farm.dir\Farm.cpp.i

CMakeFiles/farm.dir/Farm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/farm.dir/Farm.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-02\farm\Farm.cpp -o CMakeFiles\farm.dir\Farm.cpp.s

CMakeFiles/farm.dir/Animal.cpp.obj: CMakeFiles/farm.dir/flags.make
CMakeFiles/farm.dir/Animal.cpp.obj: ../Animal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/farm.dir/Animal.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\farm.dir\Animal.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-02\farm\Animal.cpp

CMakeFiles/farm.dir/Animal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/farm.dir/Animal.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-02\farm\Animal.cpp > CMakeFiles\farm.dir\Animal.cpp.i

CMakeFiles/farm.dir/Animal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/farm.dir/Animal.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-02\farm\Animal.cpp -o CMakeFiles\farm.dir\Animal.cpp.s

# Object files for target farm
farm_OBJECTS = \
"CMakeFiles/farm.dir/main.cpp.obj" \
"CMakeFiles/farm.dir/Farm.cpp.obj" \
"CMakeFiles/farm.dir/Animal.cpp.obj"

# External object files for target farm
farm_EXTERNAL_OBJECTS =

farm.exe: CMakeFiles/farm.dir/main.cpp.obj
farm.exe: CMakeFiles/farm.dir/Farm.cpp.obj
farm.exe: CMakeFiles/farm.dir/Animal.cpp.obj
farm.exe: CMakeFiles/farm.dir/build.make
farm.exe: CMakeFiles/farm.dir/linklibs.rsp
farm.exe: CMakeFiles/farm.dir/objects1.rsp
farm.exe: CMakeFiles/farm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable farm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\farm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/farm.dir/build: farm.exe

.PHONY : CMakeFiles/farm.dir/build

CMakeFiles/farm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\farm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/farm.dir/clean

CMakeFiles/farm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GREENFOX\Boritse\week-03\day-02\farm C:\GREENFOX\Boritse\week-03\day-02\farm C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-02\farm\cmake-build-debug\CMakeFiles\farm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/farm.dir/depend

