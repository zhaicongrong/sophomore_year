# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\sophomore_year\Data structure CC++\07Graph4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\sophomore_year\Data structure CC++\07Graph4\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/07Graph4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/07Graph4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/07Graph4.dir/flags.make

CMakeFiles/07Graph4.dir/main.c.obj: CMakeFiles/07Graph4.dir/flags.make
CMakeFiles/07Graph4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\sophomore_year\Data structure CC++\07Graph4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/07Graph4.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\07Graph4.dir\main.c.obj   -c "D:\sophomore_year\Data structure CC++\07Graph4\main.c"

CMakeFiles/07Graph4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/07Graph4.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\sophomore_year\Data structure CC++\07Graph4\main.c" > CMakeFiles\07Graph4.dir\main.c.i

CMakeFiles/07Graph4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/07Graph4.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\sophomore_year\Data structure CC++\07Graph4\main.c" -o CMakeFiles\07Graph4.dir\main.c.s

# Object files for target 07Graph4
07Graph4_OBJECTS = \
"CMakeFiles/07Graph4.dir/main.c.obj"

# External object files for target 07Graph4
07Graph4_EXTERNAL_OBJECTS =

07Graph4.exe: CMakeFiles/07Graph4.dir/main.c.obj
07Graph4.exe: CMakeFiles/07Graph4.dir/build.make
07Graph4.exe: CMakeFiles/07Graph4.dir/linklibs.rsp
07Graph4.exe: CMakeFiles/07Graph4.dir/objects1.rsp
07Graph4.exe: CMakeFiles/07Graph4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\sophomore_year\Data structure CC++\07Graph4\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 07Graph4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\07Graph4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/07Graph4.dir/build: 07Graph4.exe

.PHONY : CMakeFiles/07Graph4.dir/build

CMakeFiles/07Graph4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\07Graph4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/07Graph4.dir/clean

CMakeFiles/07Graph4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\sophomore_year\Data structure CC++\07Graph4" "D:\sophomore_year\Data structure CC++\07Graph4" "D:\sophomore_year\Data structure CC++\07Graph4\cmake-build-debug" "D:\sophomore_year\Data structure CC++\07Graph4\cmake-build-debug" "D:\sophomore_year\Data structure CC++\07Graph4\cmake-build-debug\CMakeFiles\07Graph4.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/07Graph4.dir/depend

