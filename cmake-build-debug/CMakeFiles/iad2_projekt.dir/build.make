# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/pobi/Downloads/clion-2017.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/pobi/Downloads/clion-2017.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pobi/Downloads/Perceptron

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pobi/Downloads/Perceptron/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/iad2_projekt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/iad2_projekt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/iad2_projekt.dir/flags.make

CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o: CMakeFiles/iad2_projekt.dir/flags.make
CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o: ../project/src/Aplikacja.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o -c /home/pobi/Downloads/Perceptron/project/src/Aplikacja.cpp

CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/Downloads/Perceptron/project/src/Aplikacja.cpp > CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.i

CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/Downloads/Perceptron/project/src/Aplikacja.cpp -o CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.s

CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.requires:

.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.requires

CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.provides: CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.requires
	$(MAKE) -f CMakeFiles/iad2_projekt.dir/build.make CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.provides.build
.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.provides

CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.provides.build: CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o


CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o: CMakeFiles/iad2_projekt.dir/flags.make
CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o: ../project/src/Funkcja.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o -c /home/pobi/Downloads/Perceptron/project/src/Funkcja.cpp

CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/Downloads/Perceptron/project/src/Funkcja.cpp > CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.i

CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/Downloads/Perceptron/project/src/Funkcja.cpp -o CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.s

CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.requires:

.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.requires

CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.provides: CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.requires
	$(MAKE) -f CMakeFiles/iad2_projekt.dir/build.make CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.provides.build
.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.provides

CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.provides.build: CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o


CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o: CMakeFiles/iad2_projekt.dir/flags.make
CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o: ../project/src/Dane.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o -c /home/pobi/Downloads/Perceptron/project/src/Dane.cpp

CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/Downloads/Perceptron/project/src/Dane.cpp > CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.i

CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/Downloads/Perceptron/project/src/Dane.cpp -o CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.s

CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.requires:

.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.requires

CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.provides: CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.requires
	$(MAKE) -f CMakeFiles/iad2_projekt.dir/build.make CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.provides.build
.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.provides

CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.provides.build: CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o


CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o: CMakeFiles/iad2_projekt.dir/flags.make
CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o: ../project/src/Warstwa.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o -c /home/pobi/Downloads/Perceptron/project/src/Warstwa.cpp

CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/Downloads/Perceptron/project/src/Warstwa.cpp > CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.i

CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/Downloads/Perceptron/project/src/Warstwa.cpp -o CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.s

CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.requires:

.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.requires

CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.provides: CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.requires
	$(MAKE) -f CMakeFiles/iad2_projekt.dir/build.make CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.provides.build
.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.provides

CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.provides.build: CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o


CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o: CMakeFiles/iad2_projekt.dir/flags.make
CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o: ../project/src/Siec.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o -c /home/pobi/Downloads/Perceptron/project/src/Siec.cpp

CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/Downloads/Perceptron/project/src/Siec.cpp > CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.i

CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/Downloads/Perceptron/project/src/Siec.cpp -o CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.s

CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.requires:

.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.requires

CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.provides: CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.requires
	$(MAKE) -f CMakeFiles/iad2_projekt.dir/build.make CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.provides.build
.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.provides

CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.provides.build: CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o


CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o: CMakeFiles/iad2_projekt.dir/flags.make
CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o: ../project/src/Losowanie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o -c /home/pobi/Downloads/Perceptron/project/src/Losowanie.cpp

CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pobi/Downloads/Perceptron/project/src/Losowanie.cpp > CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.i

CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pobi/Downloads/Perceptron/project/src/Losowanie.cpp -o CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.s

CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.requires:

.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.requires

CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.provides: CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.requires
	$(MAKE) -f CMakeFiles/iad2_projekt.dir/build.make CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.provides.build
.PHONY : CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.provides

CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.provides.build: CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o


# Object files for target iad2_projekt
iad2_projekt_OBJECTS = \
"CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o" \
"CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o" \
"CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o" \
"CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o" \
"CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o" \
"CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o"

# External object files for target iad2_projekt
iad2_projekt_EXTERNAL_OBJECTS =

iad2_projekt: CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o
iad2_projekt: CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o
iad2_projekt: CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o
iad2_projekt: CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o
iad2_projekt: CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o
iad2_projekt: CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o
iad2_projekt: CMakeFiles/iad2_projekt.dir/build.make
iad2_projekt: CMakeFiles/iad2_projekt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable iad2_projekt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iad2_projekt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/iad2_projekt.dir/build: iad2_projekt

.PHONY : CMakeFiles/iad2_projekt.dir/build

CMakeFiles/iad2_projekt.dir/requires: CMakeFiles/iad2_projekt.dir/project/src/Aplikacja.cpp.o.requires
CMakeFiles/iad2_projekt.dir/requires: CMakeFiles/iad2_projekt.dir/project/src/Funkcja.cpp.o.requires
CMakeFiles/iad2_projekt.dir/requires: CMakeFiles/iad2_projekt.dir/project/src/Dane.cpp.o.requires
CMakeFiles/iad2_projekt.dir/requires: CMakeFiles/iad2_projekt.dir/project/src/Warstwa.cpp.o.requires
CMakeFiles/iad2_projekt.dir/requires: CMakeFiles/iad2_projekt.dir/project/src/Siec.cpp.o.requires
CMakeFiles/iad2_projekt.dir/requires: CMakeFiles/iad2_projekt.dir/project/src/Losowanie.cpp.o.requires

.PHONY : CMakeFiles/iad2_projekt.dir/requires

CMakeFiles/iad2_projekt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/iad2_projekt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/iad2_projekt.dir/clean

CMakeFiles/iad2_projekt.dir/depend:
	cd /home/pobi/Downloads/Perceptron/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pobi/Downloads/Perceptron /home/pobi/Downloads/Perceptron /home/pobi/Downloads/Perceptron/cmake-build-debug /home/pobi/Downloads/Perceptron/cmake-build-debug /home/pobi/Downloads/Perceptron/cmake-build-debug/CMakeFiles/iad2_projekt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/iad2_projekt.dir/depend

