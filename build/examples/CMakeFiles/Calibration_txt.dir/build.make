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
CMAKE_SOURCE_DIR = /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build

# Include any dependencies generated for this target.
include examples/CMakeFiles/Calibration_txt.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/Calibration_txt.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/Calibration_txt.dir/flags.make

examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o: examples/CMakeFiles/Calibration_txt.dir/flags.make
examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o: ../examples/Calibration_txt.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o -c /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/examples/Calibration_txt.cpp

examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.i"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/examples/Calibration_txt.cpp > CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.i

examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.s"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/examples/Calibration_txt.cpp -o CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.s

examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.requires:

.PHONY : examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.requires

examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.provides: examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/Calibration_txt.dir/build.make examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.provides.build
.PHONY : examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.provides

examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.provides.build: examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o


# Object files for target Calibration_txt
Calibration_txt_OBJECTS = \
"CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o"

# External object files for target Calibration_txt
Calibration_txt_EXTERNAL_OBJECTS =

../bin/Calibration_txt: examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o
../bin/Calibration_txt: examples/CMakeFiles/Calibration_txt.dir/build.make
../bin/Calibration_txt: ../lib/libBabyMINDUnpack.dylib
../bin/Calibration_txt: examples/CMakeFiles/Calibration_txt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/Calibration_txt"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Calibration_txt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/Calibration_txt.dir/build: ../bin/Calibration_txt

.PHONY : examples/CMakeFiles/Calibration_txt.dir/build

examples/CMakeFiles/Calibration_txt.dir/requires: examples/CMakeFiles/Calibration_txt.dir/Calibration_txt.cpp.o.requires

.PHONY : examples/CMakeFiles/Calibration_txt.dir/requires

examples/CMakeFiles/Calibration_txt.dir/clean:
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/Calibration_txt.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/Calibration_txt.dir/clean

examples/CMakeFiles/Calibration_txt.dir/depend:
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1 /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/examples /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/examples /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.1/build/examples/CMakeFiles/Calibration_txt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/Calibration_txt.dir/depend

