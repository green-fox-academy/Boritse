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
CMAKE_SOURCE_DIR = C:\GREENFOX\Boritse\week-02\day-05\linePlay

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GREENFOX\Boritse\week-02\day-05\linePlay\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linePlay.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linePlay.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linePlay.dir/flags.make

CMakeFiles/linePlay.dir/main.cpp.obj: CMakeFiles/linePlay.dir/flags.make
CMakeFiles/linePlay.dir/main.cpp.obj: CMakeFiles/linePlay.dir/includes_CXX.rsp
CMakeFiles/linePlay.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-02\day-05\linePlay\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linePlay.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\linePlay.dir\main.cpp.obj -c C:\GREENFOX\Boritse\week-02\day-05\linePlay\main.cpp

CMakeFiles/linePlay.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linePlay.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-02\day-05\linePlay\main.cpp > CMakeFiles\linePlay.dir\main.cpp.i

CMakeFiles/linePlay.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linePlay.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-02\day-05\linePlay\main.cpp -o CMakeFiles\linePlay.dir\main.cpp.s

# Object files for target linePlay
linePlay_OBJECTS = \
"CMakeFiles/linePlay.dir/main.cpp.obj"

# External object files for target linePlay
linePlay_EXTERNAL_OBJECTS =

linePlay.exe: CMakeFiles/linePlay.dir/main.cpp.obj
linePlay.exe: CMakeFiles/linePlay.dir/build.make
linePlay.exe: C:/GREENFOX/SDL2_windows/SDL2-2.0.8/i686-w64-mingw32/lib/libSDL2main.a
linePlay.exe: C:/GREENFOX/SDL2_windows/SDL2-2.0.8/i686-w64-mingw32/lib/libSDL2.dll.a
linePlay.exe: C:/GREENFOX/SDL2_windows/SDL2_image-2.0.3/i686-w64-mingw32/lib/libSDL2_image.dll.a
linePlay.exe: C:/GREENFOX/SDL2_windows/SDL2_ttf-2.0.14/i686-w64-mingw32/lib/libSDL2_ttf.dll.a
linePlay.exe: CMakeFiles/linePlay.dir/linklibs.rsp
linePlay.exe: CMakeFiles/linePlay.dir/objects1.rsp
linePlay.exe: CMakeFiles/linePlay.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GREENFOX\Boritse\week-02\day-05\linePlay\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable linePlay.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\linePlay.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linePlay.dir/build: linePlay.exe

.PHONY : CMakeFiles/linePlay.dir/build

CMakeFiles/linePlay.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\linePlay.dir\cmake_clean.cmake
.PHONY : CMakeFiles/linePlay.dir/clean

CMakeFiles/linePlay.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GREENFOX\Boritse\week-02\day-05\linePlay C:\GREENFOX\Boritse\week-02\day-05\linePlay C:\GREENFOX\Boritse\week-02\day-05\linePlay\cmake-build-debug C:\GREENFOX\Boritse\week-02\day-05\linePlay\cmake-build-debug C:\GREENFOX\Boritse\week-02\day-05\linePlay\cmake-build-debug\CMakeFiles\linePlay.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linePlay.dir/depend

