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
CMAKE_SOURCE_DIR = "D:\sophomore_year\Data structure CC++\C++\templateproject"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\sophomore_year\Data structure CC++\C++\templateproject\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/templateproject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/templateproject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/templateproject.dir/flags.make

CMakeFiles/templateproject.dir/main.cpp.obj: CMakeFiles/templateproject.dir/flags.make
CMakeFiles/templateproject.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\sophomore_year\Data structure CC++\C++\templateproject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/templateproject.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\templateproject.dir\main.cpp.obj -c "D:\sophomore_year\Data structure CC++\C++\templateproject\main.cpp"

CMakeFiles/templateproject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/templateproject.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\sophomore_year\Data structure CC++\C++\templateproject\main.cpp" > CMakeFiles\templateproject.dir\main.cpp.i

CMakeFiles/templateproject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/templateproject.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\sophomore_year\Data structure CC++\C++\templateproject\main.cpp" -o CMakeFiles\templateproject.dir\main.cpp.s

# Object files for target templateproject
templateproject_OBJECTS = \
"CMakeFiles/templateproject.dir/main.cpp.obj"

# External object files for target templateproject
templateproject_EXTERNAL_OBJECTS =

templateproject.exe: CMakeFiles/templateproject.dir/main.cpp.obj
templateproject.exe: CMakeFiles/templateproject.dir/build.make
templateproject.exe: CMakeFiles/templateproject.dir/linklibs.rsp
templateproject.exe: CMakeFiles/templateproject.dir/objects1.rsp
templateproject.exe: CMakeFiles/templateproject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\sophomore_year\Data structure CC++\C++\templateproject\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable templateproject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\templateproject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/templateproject.dir/build: templateproject.exe

.PHONY : CMakeFiles/templateproject.dir/build

CMakeFiles/templateproject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\templateproject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/templateproject.dir/clean

CMakeFiles/templateproject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\sophomore_year\Data structure CC++\C++\templateproject" "D:\sophomore_year\Data structure CC++\C++\templateproject" "D:\sophomore_year\Data structure CC++\C++\templateproject\cmake-build-debug" "D:\sophomore_year\Data structure CC++\C++\templateproject\cmake-build-debug" "D:\sophomore_year\Data structure CC++\C++\templateproject\cmake-build-debug\CMakeFiles\templateproject.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/templateproject.dir/depend

