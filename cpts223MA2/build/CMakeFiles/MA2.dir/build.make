# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/CPTS223_assignments/cpts223MA2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/CPTS223_assignments/cpts223MA2/build

# Include any dependencies generated for this target.
include CMakeFiles/MA2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MA2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MA2.dir/flags.make

CMakeFiles/MA2.dir/main.cpp.o: CMakeFiles/MA2.dir/flags.make
CMakeFiles/MA2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CPTS223_assignments/cpts223MA2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MA2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MA2.dir/main.cpp.o -c /workspaces/CPTS223_assignments/cpts223MA2/main.cpp

CMakeFiles/MA2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MA2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CPTS223_assignments/cpts223MA2/main.cpp > CMakeFiles/MA2.dir/main.cpp.i

CMakeFiles/MA2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MA2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CPTS223_assignments/cpts223MA2/main.cpp -o CMakeFiles/MA2.dir/main.cpp.s

# Object files for target MA2
MA2_OBJECTS = \
"CMakeFiles/MA2.dir/main.cpp.o"

# External object files for target MA2
MA2_EXTERNAL_OBJECTS =

MA2: CMakeFiles/MA2.dir/main.cpp.o
MA2: CMakeFiles/MA2.dir/build.make
MA2: CMakeFiles/MA2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/CPTS223_assignments/cpts223MA2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MA2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MA2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MA2.dir/build: MA2

.PHONY : CMakeFiles/MA2.dir/build

CMakeFiles/MA2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MA2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MA2.dir/clean

CMakeFiles/MA2.dir/depend:
	cd /workspaces/CPTS223_assignments/cpts223MA2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/CPTS223_assignments/cpts223MA2 /workspaces/CPTS223_assignments/cpts223MA2 /workspaces/CPTS223_assignments/cpts223MA2/build /workspaces/CPTS223_assignments/cpts223MA2/build /workspaces/CPTS223_assignments/cpts223MA2/build/CMakeFiles/MA2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MA2.dir/depend

