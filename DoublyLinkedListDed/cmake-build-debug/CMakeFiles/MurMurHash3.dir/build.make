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
include CMakeFiles/MurMurHash3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MurMurHash3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MurMurHash3.dir/flags.make

CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.o: CMakeFiles/MurMurHash3.dir/flags.make
CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.o: ../MurMurHash3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.o -c /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/MurMurHash3.cpp

CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/MurMurHash3.cpp > CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.i

CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/MurMurHash3.cpp -o CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.s

# Object files for target MurMurHash3
MurMurHash3_OBJECTS = \
"CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.o"

# External object files for target MurMurHash3
MurMurHash3_EXTERNAL_OBJECTS =

libMurMurHash3.a: CMakeFiles/MurMurHash3.dir/MurMurHash3.cpp.o
libMurMurHash3.a: CMakeFiles/MurMurHash3.dir/build.make
libMurMurHash3.a: CMakeFiles/MurMurHash3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libMurMurHash3.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MurMurHash3.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MurMurHash3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MurMurHash3.dir/build: libMurMurHash3.a

.PHONY : CMakeFiles/MurMurHash3.dir/build

CMakeFiles/MurMurHash3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MurMurHash3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MurMurHash3.dir/clean

CMakeFiles/MurMurHash3.dir/depend:
	cd /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug /home/alexey/Programming/MIPT_1sem_programming_homework/DoublyLinkedListDed/cmake-build-debug/CMakeFiles/MurMurHash3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MurMurHash3.dir/depend
