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
CMAKE_SOURCE_DIR = "D:\sophomore_year\Data structure CC++\C++\ageheightsort"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\sophomore_year\Data structure CC++\C++\ageheightsort\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ageheightsort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ageheightsort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ageheightsort.dir/flags.make

CMakeFiles/ageheightsort.dir/main.cpp.obj: CMakeFiles/ageheightsort.dir/flags.make
CMakeFiles/ageheightsort.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\sophomore_year\Data structure CC++\C++\ageheightsort\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ageheightsort.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ageheightsort.dir\main.cpp.obj -c "D:\sophomore_year\Data structure CC++\C++\ageheightsort\main.cpp"

CMakeFiles/ageheightsort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ageheightsort.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\sophomore_year\Data structure CC++\C++\ageheightsort\main.cpp" > CMakeFiles\ageheightsort.dir\main.cpp.i

CMakeFiles/ageheightsort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ageheightsort.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\sophomore_year\Data structure CC++\C++\ageheightsort\main.cpp" -o CMakeFiles\ageheightsort.dir\main.cpp.s

# Object files for target ageheightsort
ageheightsort_OBJECTS = \
"CMakeFiles/ageheightsort.dir/main.cpp.obj"

# External object files for target ageheightsort
ageheightsort_EXTERNAL_OBJECTS =

ageheightsort.exe: CMakeFiles/ageheightsort.dir/main.cpp.obj
ageheightsort.exe: CMakeFiles/ageheightsort.dir/build.make
ageheightsort.exe: CMakeFiles/ageheightsort.dir/linklibs.rsp
ageheightsort.exe: CMakeFiles/ageheightsort.dir/objects1.rsp
ageheightsort.exe: CMakeFiles/ageheightsort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\sophomore_year\Data structure CC++\C++\ageheightsort\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ageheightsort.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ageheightsort.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ageheightsort.dir/build: ageheightsort.exe

.PHONY : CMakeFiles/ageheightsort.dir/build

CMakeFiles/ageheightsort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ageheightsort.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ageheightsort.dir/clean

CMakeFiles/ageheightsort.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\sophomore_year\Data structure CC++\C++\ageheightsort" "D:\sophomore_year\Data structure CC++\C++\ageheightsort" "D:\sophomore_year\Data structure CC++\C++\ageheightsort\cmake-build-debug" "D:\sophomore_year\Data structure CC++\C++\ageheightsort\cmake-build-debug" "D:\sophomore_year\Data structure CC++\C++\ageheightsort\cmake-build-debug\CMakeFiles\ageheightsort.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ageheightsort.dir/depend

