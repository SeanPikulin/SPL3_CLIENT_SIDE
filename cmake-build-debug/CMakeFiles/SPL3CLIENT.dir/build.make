# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sean1605/CLionProjects/SPL3CLIENT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SPL3CLIENT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SPL3CLIENT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPL3CLIENT.dir/flags.make

CMakeFiles/SPL3CLIENT.dir/main.cpp.o: CMakeFiles/SPL3CLIENT.dir/flags.make
CMakeFiles/SPL3CLIENT.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPL3CLIENT.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPL3CLIENT.dir/main.cpp.o -c /home/sean1605/CLionProjects/SPL3CLIENT/main.cpp

CMakeFiles/SPL3CLIENT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3CLIENT.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean1605/CLionProjects/SPL3CLIENT/main.cpp > CMakeFiles/SPL3CLIENT.dir/main.cpp.i

CMakeFiles/SPL3CLIENT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3CLIENT.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean1605/CLionProjects/SPL3CLIENT/main.cpp -o CMakeFiles/SPL3CLIENT.dir/main.cpp.s

# Object files for target SPL3CLIENT
SPL3CLIENT_OBJECTS = \
"CMakeFiles/SPL3CLIENT.dir/main.cpp.o"

# External object files for target SPL3CLIENT
SPL3CLIENT_EXTERNAL_OBJECTS =

SPL3CLIENT: CMakeFiles/SPL3CLIENT.dir/main.cpp.o
SPL3CLIENT: CMakeFiles/SPL3CLIENT.dir/build.make
SPL3CLIENT: CMakeFiles/SPL3CLIENT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SPL3CLIENT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SPL3CLIENT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPL3CLIENT.dir/build: SPL3CLIENT

.PHONY : CMakeFiles/SPL3CLIENT.dir/build

CMakeFiles/SPL3CLIENT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SPL3CLIENT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SPL3CLIENT.dir/clean

CMakeFiles/SPL3CLIENT.dir/depend:
	cd /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sean1605/CLionProjects/SPL3CLIENT /home/sean1605/CLionProjects/SPL3CLIENT /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles/SPL3CLIENT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPL3CLIENT.dir/depend
