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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.3_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/StopingProton.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/StopingProton.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/StopingProton.dir/flags.make

examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o: examples/CMakeFiles/StopingProton.dir/flags.make
examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o: ../examples/Proton_stop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StopingProton.dir/Proton_stop.cpp.o -c /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples/Proton_stop.cpp

examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StopingProton.dir/Proton_stop.cpp.i"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples/Proton_stop.cpp > CMakeFiles/StopingProton.dir/Proton_stop.cpp.i

examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StopingProton.dir/Proton_stop.cpp.s"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples/Proton_stop.cpp -o CMakeFiles/StopingProton.dir/Proton_stop.cpp.s

examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.requires:

.PHONY : examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.requires

examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.provides: examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/StopingProton.dir/build.make examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.provides.build
.PHONY : examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.provides

examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.provides.build: examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o


# Object files for target StopingProton
StopingProton_OBJECTS = \
"CMakeFiles/StopingProton.dir/Proton_stop.cpp.o"

# External object files for target StopingProton
StopingProton_EXTERNAL_OBJECTS =

../bin/StopingProton: examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o
../bin/StopingProton: examples/CMakeFiles/StopingProton.dir/build.make
../bin/StopingProton: ../lib/libBabyMINDUnpack.dylib
../bin/StopingProton: examples/CMakeFiles/StopingProton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/StopingProton"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StopingProton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/StopingProton.dir/build: ../bin/StopingProton

.PHONY : examples/CMakeFiles/StopingProton.dir/build

examples/CMakeFiles/StopingProton.dir/requires: examples/CMakeFiles/StopingProton.dir/Proton_stop.cpp.o.requires

.PHONY : examples/CMakeFiles/StopingProton.dir/requires

examples/CMakeFiles/StopingProton.dir/clean:
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/StopingProton.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/StopingProton.dir/clean

examples/CMakeFiles/StopingProton.dir/depend:
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2 /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples/CMakeFiles/StopingProton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/StopingProton.dir/depend

