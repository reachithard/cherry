# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_SOURCE_DIR = /root/workspace/cherry/deps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/workspace/cherry/deps/build

# Utility rule file for spdlog.

# Include any custom commands dependencies for this target.
include CMakeFiles/spdlog.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/spdlog.dir/progress.make

CMakeFiles/spdlog: CMakeFiles/spdlog-complete

CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-install
CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-mkdir
CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-download
CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-update
CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-patch
CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-configure
CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-build
CMakeFiles/spdlog-complete: spdlog/src/spdlog-stamp/spdlog-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'spdlog'"
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/build/CMakeFiles
	/usr/bin/cmake -E touch /root/workspace/cherry/deps/build/CMakeFiles/spdlog-complete
	/usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-done

spdlog/src/spdlog-stamp/spdlog-build: spdlog/src/spdlog-stamp/spdlog-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing build step for 'spdlog'"
	cd /root/workspace/cherry/deps/build/spdlog/src/spdlog-build && $(MAKE)
	cd /root/workspace/cherry/deps/build/spdlog/src/spdlog-build && /usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-build

spdlog/src/spdlog-stamp/spdlog-configure: spdlog/tmp/spdlog-cfgcmd.txt
spdlog/src/spdlog-stamp/spdlog-configure: spdlog/src/spdlog-stamp/spdlog-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Performing configure step for 'spdlog'"
	cd /root/workspace/cherry/deps/build/spdlog/src/spdlog-build && /usr/bin/cmake -DCMAKE_INSTALL_PREFIX=/root/workspace/cherry/deps/../output -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=/usr/bin/gmake -DCMAKE_C_COMPILE= -DCMAKE_CXX_COMPILE= -DCMAKE_VERBOSE_MAKEFILE=FALSE -DCMAKE_INSTALL_MESSAGE=TRUE "-GUnix Makefiles" /root/workspace/cherry/deps/../third/spdlog
	cd /root/workspace/cherry/deps/build/spdlog/src/spdlog-build && /usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-configure

spdlog/src/spdlog-stamp/spdlog-download: spdlog/src/spdlog-stamp/spdlog-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "No download step for 'spdlog'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-download

spdlog/src/spdlog-stamp/spdlog-install: spdlog/src/spdlog-stamp/spdlog-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing install step for 'spdlog'"
	cd /root/workspace/cherry/deps/build/spdlog/src/spdlog-build && /usr/bin/gmake install
	cd /root/workspace/cherry/deps/build/spdlog/src/spdlog-build && /usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-install

spdlog/src/spdlog-stamp/spdlog-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'spdlog'"
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/../third/spdlog
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/build/spdlog/src/spdlog-build
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/../output
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/build/spdlog/tmp
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/build/spdlog/src
	/usr/bin/cmake -E make_directory /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp
	/usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-mkdir

spdlog/src/spdlog-stamp/spdlog-patch: spdlog/src/spdlog-stamp/spdlog-update
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'spdlog'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-patch

spdlog/src/spdlog-stamp/spdlog-update: spdlog/src/spdlog-stamp/spdlog-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/root/workspace/cherry/deps/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No update step for 'spdlog'"
	/usr/bin/cmake -E echo_append
	/usr/bin/cmake -E touch /root/workspace/cherry/deps/build/spdlog/src/spdlog-stamp/spdlog-update

spdlog: CMakeFiles/spdlog
spdlog: CMakeFiles/spdlog-complete
spdlog: spdlog/src/spdlog-stamp/spdlog-build
spdlog: spdlog/src/spdlog-stamp/spdlog-configure
spdlog: spdlog/src/spdlog-stamp/spdlog-download
spdlog: spdlog/src/spdlog-stamp/spdlog-install
spdlog: spdlog/src/spdlog-stamp/spdlog-mkdir
spdlog: spdlog/src/spdlog-stamp/spdlog-patch
spdlog: spdlog/src/spdlog-stamp/spdlog-update
spdlog: CMakeFiles/spdlog.dir/build.make
.PHONY : spdlog

# Rule to build all files generated by this target.
CMakeFiles/spdlog.dir/build: spdlog
.PHONY : CMakeFiles/spdlog.dir/build

CMakeFiles/spdlog.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spdlog.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spdlog.dir/clean

CMakeFiles/spdlog.dir/depend:
	cd /root/workspace/cherry/deps/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/workspace/cherry/deps /root/workspace/cherry/deps /root/workspace/cherry/deps/build /root/workspace/cherry/deps/build /root/workspace/cherry/deps/build/CMakeFiles/spdlog.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/spdlog.dir/depend

