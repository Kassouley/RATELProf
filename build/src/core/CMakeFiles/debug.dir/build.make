# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lneto/RATELProf/ratelprof

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lneto/RATELProf/ratelprof/build

# Utility rule file for debug.

# Include any custom commands dependencies for this target.
include src/core/CMakeFiles/debug.dir/compiler_depend.make

# Include the progress variables for this target.
include src/core/CMakeFiles/debug.dir/progress.make

src/core/CMakeFiles/debug:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/lneto/RATELProf/ratelprof/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building in debug mode with -DRATELPROF_DEBUG"
	cd /home/lneto/RATELProf/ratelprof/build/src/core && /usr/bin/cmake -E env CXXFLAGS=-DRATELPROF_DEBUG /usr/bin/gmake ratelprof_core

debug: src/core/CMakeFiles/debug
debug: src/core/CMakeFiles/debug.dir/build.make
.PHONY : debug

# Rule to build all files generated by this target.
src/core/CMakeFiles/debug.dir/build: debug
.PHONY : src/core/CMakeFiles/debug.dir/build

src/core/CMakeFiles/debug.dir/clean:
	cd /home/lneto/RATELProf/ratelprof/build/src/core && $(CMAKE_COMMAND) -P CMakeFiles/debug.dir/cmake_clean.cmake
.PHONY : src/core/CMakeFiles/debug.dir/clean

src/core/CMakeFiles/debug.dir/depend:
	cd /home/lneto/RATELProf/ratelprof/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lneto/RATELProf/ratelprof /home/lneto/RATELProf/ratelprof/src/core /home/lneto/RATELProf/ratelprof/build /home/lneto/RATELProf/ratelprof/build/src/core /home/lneto/RATELProf/ratelprof/build/src/core/CMakeFiles/debug.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/core/CMakeFiles/debug.dir/depend

