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
CMAKE_SOURCE_DIR = "D:\sophomore_year\Data structure CC++\08Graph7"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\sophomore_year\Data structure CC++\08Graph7\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/08Graph7.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/08Graph7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/08Graph7.dir/flags.make

CMakeFiles/08Graph7.dir/main.cpp.obj: CMakeFiles/08Graph7.dir/flags.make
CMakeFiles/08Graph7.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\sophomore_year\Data structure CC++\08Graph7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/08Graph7.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\08Graph7.dir\main.cpp.obj -c "D:\sophomore_year\Data structure CC++\08Graph7\main.cpp"

CMakeFiles/08Graph7.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/08Graph7.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\sophomore_year\Data structure CC++\08Graph7\main.cpp" > CMakeFiles\08Graph7.dir\main.cpp.i

CMakeFiles/08Graph7.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/08Graph7.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\sophomore_year\Data structure CC++\08Graph7\main.cpp" -o CMakeFiles\08Graph7.dir\main.cpp.s

# Object files for target 08Graph7
08Graph7_OBJECTS = \
"CMakeFiles/08Graph7.dir/main.cpp.obj"

# External object files for target 08Graph7
08Graph7_EXTERNAL_OBJECTS =

08Graph7.exe: CMakeFiles/08Graph7.dir/main.cpp.obj
08Graph7.exe: CMakeFiles/08Graph7.dir/build.make
08Graph7.exe: CMakeFiles/08Graph7.dir/linklibs.rsp
08Graph7.exe: CMakeFiles/08Graph7.dir/objects1.rsp
08Graph7.exe: CMakeFiles/08Graph7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\sophomore_year\Data structure CC++\08Graph7\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 08Graph7.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\08Graph7.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/08Graph7.dir/build: 08Graph7.exe

.PHONY : CMakeFiles/08Graph7.dir/build

CMakeFiles/08Graph7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\08Graph7.dir\cmake_clean.cmake
.PHONY : CMakeFiles/08Graph7.dir/clean

CMakeFiles/08Graph7.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\sophomore_year\Data structure CC++\08Graph7" "D:\sophomore_year\Data structure CC++\08Graph7" "D:\sophomore_year\Data structure CC++\08Graph7\cmake-build-debug" "D:\sophomore_year\Data structure CC++\08Graph7\cmake-build-debug" "D:\sophomore_year\Data structure CC++\08Graph7\cmake-build-debug\CMakeFiles\08Graph7.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/08Graph7.dir/depend

