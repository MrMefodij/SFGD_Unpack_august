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
include examples/CMakeFiles/ufe-monitor.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/ufe-monitor.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/ufe-monitor.dir/flags.make

examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o: examples/CMakeFiles/ufe-monitor.dir/flags.make
examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o: ../examples/ufe_monitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o -c /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples/ufe_monitor.cpp

examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.i"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples/ufe_monitor.cpp > CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.i

examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.s"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples/ufe_monitor.cpp -o CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.s

examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.requires:

.PHONY : examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.requires

examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.provides: examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.requires
	$(MAKE) -f examples/CMakeFiles/ufe-monitor.dir/build.make examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.provides.build
.PHONY : examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.provides

examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.provides.build: examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o


# Object files for target ufe-monitor
ufe__monitor_OBJECTS = \
"CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o"

# External object files for target ufe-monitor
ufe__monitor_EXTERNAL_OBJECTS =

../bin/ufe-monitor: examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o
../bin/ufe-monitor: examples/CMakeFiles/ufe-monitor.dir/build.make
../bin/ufe-monitor: ../lib/libBabyMINDUnpack.dylib
../bin/ufe-monitor: examples/CMakeFiles/ufe-monitor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/ufe-monitor"
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ufe-monitor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/ufe-monitor.dir/build: ../bin/ufe-monitor

.PHONY : examples/CMakeFiles/ufe-monitor.dir/build

examples/CMakeFiles/ufe-monitor.dir/requires: examples/CMakeFiles/ufe-monitor.dir/ufe_monitor.cpp.o.requires

.PHONY : examples/CMakeFiles/ufe-monitor.dir/requires

examples/CMakeFiles/ufe-monitor.dir/clean:
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples && $(CMAKE_COMMAND) -P CMakeFiles/ufe-monitor.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/ufe-monitor.dir/clean

examples/CMakeFiles/ufe-monitor.dir/depend:
	cd /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2 /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/examples /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples /Volumes/DriveGenius/CERN/beamTest_SFGD/Unpacking_august_v2.2/build/examples/CMakeFiles/ufe-monitor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/ufe-monitor.dir/depend

