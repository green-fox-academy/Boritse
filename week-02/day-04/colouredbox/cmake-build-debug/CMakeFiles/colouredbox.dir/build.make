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
CMAKE_SOURCE_DIR = C:\GREENFOX\Boritse\week-02\day-04\colouredbox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GREENFOX\Boritse\week-02\day-04\colouredbox\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/colouredbox.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/colouredbox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/colouredbox.dir/flags.make

CMakeFiles/colouredbox.dir/main.cpp.obj: CMakeFiles/colouredbox.dir/flags.make
CMakeFiles/colouredbox.dir/main.cpp.obj: CMakeFiles/colouredbox.dir/includes_CXX.rsp
CMakeFiles/colouredbox.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GREENFOX\Boritse\week-02\day-04\colouredbox\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/colouredbox.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\colouredbox.dir\main.cpp.obj -c C:\GREENFOX\Boritse\week-02\day-04\colouredbox\main.cpp

CMakeFiles/colouredbox.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/colouredbox.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GREENFOX\Boritse\week-02\day-04\colouredbox\main.cpp > CMakeFiles\colouredbox.dir\main.cpp.i

CMakeFiles/colouredbox.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/colouredbox.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GREENFOX\Boritse\week-02\day-04\colouredbox\main.cpp -o CMakeFiles\colouredbox.dir\main.cpp.s

# Object files for target colouredbox
colouredbox_OBJECTS = \
"CMakeFiles/colouredbox.dir/main.cpp.obj"

# External object files for target colouredbox
colouredbox_EXTERNAL_OBJECTS =

colouredbox.exe: CMakeFiles/colouredbox.dir/main.cpp.obj
colouredbox.exe: CMakeFiles/colouredbox.dir/build.make
colouredbox.exe: C:/GREENFOX/SDL2_windows/SDL2-2.0.8/i686-w64-mingw32/lib/libSDL2main.a
colouredbox.exe: C:/GREENFOX/SDL2_windows/SDL2-2.0.8/i686-w64-mingw32/lib/libSDL2.dll.a
colouredbox.exe: C:/GREENFOX/SDL2_windows/SDL2_image-2.0.3/i686-w64-mingw32/lib/libSDL2_image.dll.a
colouredbox.exe: C:/GREENFOX/SDL2_windows/SDL2_ttf-2.0.14/i686-w64-mingw32/lib/libSDL2_ttf.dll.a
colouredbox.exe: CMakeFiles/colouredbox.dir/linklibs.rsp
colouredbox.exe: CMakeFiles/colouredbox.dir/objects1.rsp
colouredbox.exe: CMakeFiles/colouredbox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GREENFOX\Boritse\week-02\day-04\colouredbox\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable colouredbox.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\colouredbox.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/colouredbox.dir/build: colouredbox.exe

.PHONY : CMakeFiles/colouredbox.dir/build

CMakeFiles/colouredbox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\colouredbox.dir\cmake_clean.cmake
.PHONY : CMakeFiles/colouredbox.dir/clean

CMakeFiles/colouredbox.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GREENFOX\Boritse\week-02\day-04\colouredbox C:\GREENFOX\Boritse\week-02\day-04\colouredbox C:\GREENFOX\Boritse\week-02\day-04\colouredbox\cmake-build-debug C:\GREENFOX\Boritse\week-02\day-04\colouredbox\cmake-build-debug C:\GREENFOX\Boritse\week-02\day-04\colouredbox\cmake-build-debug\CMakeFiles\colouredbox.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/colouredbox.dir/depend

