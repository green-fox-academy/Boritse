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
CMAKE_SOURCE_DIR = C:\GREENFOX\Boritse\week-03\day-01\pokemon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GREENFOX\Boritse\week-03\day-01\pokemon\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pokemon.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pokemon.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pokemon.dir/flags.make

CMakeFiles/pokemon.dir/main.cpp.obj: CMakeFiles/pokemon.dir/flags.make
CMakeFiles/pokemon.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-01\pokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pokemon.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pokemon.dir\main.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-01\pokemon\main.cpp

CMakeFiles/pokemon.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pokemon.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-01\pokemon\main.cpp > CMakeFiles\pokemon.dir\main.cpp.i

CMakeFiles/pokemon.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pokemon.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-01\pokemon\main.cpp -o CMakeFiles\pokemon.dir\main.cpp.s

CMakeFiles/pokemon.dir/pokemon.cpp.obj: CMakeFiles/pokemon.dir/flags.make
CMakeFiles/pokemon.dir/pokemon.cpp.obj: ../pokemon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-03\day-01\pokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pokemon.dir/pokemon.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pokemon.dir\pokemon.cpp.obj -c C:\GREENFOX\Boritse\week-03\day-01\pokemon\pokemon.cpp

CMakeFiles/pokemon.dir/pokemon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pokemon.dir/pokemon.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-03\day-01\pokemon\pokemon.cpp > CMakeFiles\pokemon.dir\pokemon.cpp.i

CMakeFiles/pokemon.dir/pokemon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pokemon.dir/pokemon.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-03\day-01\pokemon\pokemon.cpp -o CMakeFiles\pokemon.dir\pokemon.cpp.s

# Object files for target pokemon
pokemon_OBJECTS = \
"CMakeFiles/pokemon.dir/main.cpp.obj" \
"CMakeFiles/pokemon.dir/pokemon.cpp.obj"

# External object files for target pokemon
pokemon_EXTERNAL_OBJECTS =

pokemon.exe: CMakeFiles/pokemon.dir/main.cpp.obj
pokemon.exe: CMakeFiles/pokemon.dir/pokemon.cpp.obj
pokemon.exe: CMakeFiles/pokemon.dir/build.make
pokemon.exe: CMakeFiles/pokemon.dir/linklibs.rsp
pokemon.exe: CMakeFiles/pokemon.dir/objects1.rsp
pokemon.exe: CMakeFiles/pokemon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GREENFOX\Boritse\week-03\day-01\pokemon\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable pokemon.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pokemon.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pokemon.dir/build: pokemon.exe

.PHONY : CMakeFiles/pokemon.dir/build

CMakeFiles/pokemon.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\pokemon.dir\cmake_clean.cmake
.PHONY : CMakeFiles/pokemon.dir/clean

CMakeFiles/pokemon.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GREENFOX\Boritse\week-03\day-01\pokemon C:\GREENFOX\Boritse\week-03\day-01\pokemon C:\GREENFOX\Boritse\week-03\day-01\pokemon\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-01\pokemon\cmake-build-debug C:\GREENFOX\Boritse\week-03\day-01\pokemon\cmake-build-debug\CMakeFiles\pokemon.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pokemon.dir/depend

