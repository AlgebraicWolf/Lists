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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DoublyLinkedListDed.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DoublyLinkedListDed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DoublyLinkedListDed.dir/flags.make

CMakeFiles/DoublyLinkedListDed.dir/main.cpp.o: CMakeFiles/DoublyLinkedListDed.dir/flags.make
CMakeFiles/DoublyLinkedListDed.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DoublyLinkedListDed.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DoublyLinkedListDed.dir/main.cpp.o -c /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/main.cpp

CMakeFiles/DoublyLinkedListDed.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DoublyLinkedListDed.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/main.cpp > CMakeFiles/DoublyLinkedListDed.dir/main.cpp.i

CMakeFiles/DoublyLinkedListDed.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DoublyLinkedListDed.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/main.cpp -o CMakeFiles/DoublyLinkedListDed.dir/main.cpp.s

# Object files for target DoublyLinkedListDed
DoublyLinkedListDed_OBJECTS = \
"CMakeFiles/DoublyLinkedListDed.dir/main.cpp.o"

# External object files for target DoublyLinkedListDed
DoublyLinkedListDed_EXTERNAL_OBJECTS =

DoublyLinkedListDed: CMakeFiles/DoublyLinkedListDed.dir/main.cpp.o
DoublyLinkedListDed: CMakeFiles/DoublyLinkedListDed.dir/build.make
DoublyLinkedListDed: libStackLibrary.a
DoublyLinkedListDed: libMurMurHash3.a
DoublyLinkedListDed: CMakeFiles/DoublyLinkedListDed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DoublyLinkedListDed"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DoublyLinkedListDed.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DoublyLinkedListDed.dir/build: DoublyLinkedListDed

.PHONY : CMakeFiles/DoublyLinkedListDed.dir/build

CMakeFiles/DoublyLinkedListDed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DoublyLinkedListDed.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DoublyLinkedListDed.dir/clean

CMakeFiles/DoublyLinkedListDed.dir/depend:
	cd /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug/CMakeFiles/DoublyLinkedListDed.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DoublyLinkedListDed.dir/depend
