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
include CMakeFiles/SPL3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SPL3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SPL3.dir/flags.make

CMakeFiles/SPL3.dir/src/echoClient.cpp.o: CMakeFiles/SPL3.dir/flags.make
CMakeFiles/SPL3.dir/src/echoClient.cpp.o: ../src/echoClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SPL3.dir/src/echoClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPL3.dir/src/echoClient.cpp.o -c /home/sean1605/CLionProjects/SPL3CLIENT/src/echoClient.cpp

CMakeFiles/SPL3.dir/src/echoClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3.dir/src/echoClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean1605/CLionProjects/SPL3CLIENT/src/echoClient.cpp > CMakeFiles/SPL3.dir/src/echoClient.cpp.i

CMakeFiles/SPL3.dir/src/echoClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3.dir/src/echoClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean1605/CLionProjects/SPL3CLIENT/src/echoClient.cpp -o CMakeFiles/SPL3.dir/src/echoClient.cpp.s

CMakeFiles/SPL3.dir/src/connectionHandler.cpp.o: CMakeFiles/SPL3.dir/flags.make
CMakeFiles/SPL3.dir/src/connectionHandler.cpp.o: ../src/connectionHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SPL3.dir/src/connectionHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPL3.dir/src/connectionHandler.cpp.o -c /home/sean1605/CLionProjects/SPL3CLIENT/src/connectionHandler.cpp

CMakeFiles/SPL3.dir/src/connectionHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3.dir/src/connectionHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean1605/CLionProjects/SPL3CLIENT/src/connectionHandler.cpp > CMakeFiles/SPL3.dir/src/connectionHandler.cpp.i

CMakeFiles/SPL3.dir/src/connectionHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3.dir/src/connectionHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean1605/CLionProjects/SPL3CLIENT/src/connectionHandler.cpp -o CMakeFiles/SPL3.dir/src/connectionHandler.cpp.s

CMakeFiles/SPL3.dir/src/IOThread.cpp.o: CMakeFiles/SPL3.dir/flags.make
CMakeFiles/SPL3.dir/src/IOThread.cpp.o: ../src/IOThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SPL3.dir/src/IOThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPL3.dir/src/IOThread.cpp.o -c /home/sean1605/CLionProjects/SPL3CLIENT/src/IOThread.cpp

CMakeFiles/SPL3.dir/src/IOThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3.dir/src/IOThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean1605/CLionProjects/SPL3CLIENT/src/IOThread.cpp > CMakeFiles/SPL3.dir/src/IOThread.cpp.i

CMakeFiles/SPL3.dir/src/IOThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3.dir/src/IOThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean1605/CLionProjects/SPL3CLIENT/src/IOThread.cpp -o CMakeFiles/SPL3.dir/src/IOThread.cpp.s

CMakeFiles/SPL3.dir/src/BookClub.cpp.o: CMakeFiles/SPL3.dir/flags.make
CMakeFiles/SPL3.dir/src/BookClub.cpp.o: ../src/BookClub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SPL3.dir/src/BookClub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPL3.dir/src/BookClub.cpp.o -c /home/sean1605/CLionProjects/SPL3CLIENT/src/BookClub.cpp

CMakeFiles/SPL3.dir/src/BookClub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3.dir/src/BookClub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean1605/CLionProjects/SPL3CLIENT/src/BookClub.cpp > CMakeFiles/SPL3.dir/src/BookClub.cpp.i

CMakeFiles/SPL3.dir/src/BookClub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3.dir/src/BookClub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean1605/CLionProjects/SPL3CLIENT/src/BookClub.cpp -o CMakeFiles/SPL3.dir/src/BookClub.cpp.s

CMakeFiles/SPL3.dir/src/ServerThread.cpp.o: CMakeFiles/SPL3.dir/flags.make
CMakeFiles/SPL3.dir/src/ServerThread.cpp.o: ../src/ServerThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SPL3.dir/src/ServerThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPL3.dir/src/ServerThread.cpp.o -c /home/sean1605/CLionProjects/SPL3CLIENT/src/ServerThread.cpp

CMakeFiles/SPL3.dir/src/ServerThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3.dir/src/ServerThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean1605/CLionProjects/SPL3CLIENT/src/ServerThread.cpp > CMakeFiles/SPL3.dir/src/ServerThread.cpp.i

CMakeFiles/SPL3.dir/src/ServerThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3.dir/src/ServerThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean1605/CLionProjects/SPL3CLIENT/src/ServerThread.cpp -o CMakeFiles/SPL3.dir/src/ServerThread.cpp.s

CMakeFiles/SPL3.dir/src/Frame.cpp.o: CMakeFiles/SPL3.dir/flags.make
CMakeFiles/SPL3.dir/src/Frame.cpp.o: ../src/Frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SPL3.dir/src/Frame.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SPL3.dir/src/Frame.cpp.o -c /home/sean1605/CLionProjects/SPL3CLIENT/src/Frame.cpp

CMakeFiles/SPL3.dir/src/Frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SPL3.dir/src/Frame.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean1605/CLionProjects/SPL3CLIENT/src/Frame.cpp > CMakeFiles/SPL3.dir/src/Frame.cpp.i

CMakeFiles/SPL3.dir/src/Frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SPL3.dir/src/Frame.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean1605/CLionProjects/SPL3CLIENT/src/Frame.cpp -o CMakeFiles/SPL3.dir/src/Frame.cpp.s

# Object files for target SPL3
SPL3_OBJECTS = \
"CMakeFiles/SPL3.dir/src/echoClient.cpp.o" \
"CMakeFiles/SPL3.dir/src/connectionHandler.cpp.o" \
"CMakeFiles/SPL3.dir/src/IOThread.cpp.o" \
"CMakeFiles/SPL3.dir/src/BookClub.cpp.o" \
"CMakeFiles/SPL3.dir/src/ServerThread.cpp.o" \
"CMakeFiles/SPL3.dir/src/Frame.cpp.o"

# External object files for target SPL3
SPL3_EXTERNAL_OBJECTS =

SPL3: CMakeFiles/SPL3.dir/src/echoClient.cpp.o
SPL3: CMakeFiles/SPL3.dir/src/connectionHandler.cpp.o
SPL3: CMakeFiles/SPL3.dir/src/IOThread.cpp.o
SPL3: CMakeFiles/SPL3.dir/src/BookClub.cpp.o
SPL3: CMakeFiles/SPL3.dir/src/ServerThread.cpp.o
SPL3: CMakeFiles/SPL3.dir/src/Frame.cpp.o
SPL3: CMakeFiles/SPL3.dir/build.make
SPL3: CMakeFiles/SPL3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable SPL3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SPL3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SPL3.dir/build: SPL3

.PHONY : CMakeFiles/SPL3.dir/build

CMakeFiles/SPL3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SPL3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SPL3.dir/clean

CMakeFiles/SPL3.dir/depend:
	cd /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sean1605/CLionProjects/SPL3CLIENT /home/sean1605/CLionProjects/SPL3CLIENT /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug /home/sean1605/CLionProjects/SPL3CLIENT/cmake-build-debug/CMakeFiles/SPL3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SPL3.dir/depend
