# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anshulb3/cs225git/rduquet2-rahuls9-apramey2-anshulb3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anshulb3/cs225git/rduquet2-rahuls9-apramey2-anshulb3

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake3 --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anshulb3/cs225git/rduquet2-rahuls9-apramey2-anshulb3/CMakeFiles /home/anshulb3/cs225git/rduquet2-rahuls9-apramey2-anshulb3/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/anshulb3/cs225git/rduquet2-rahuls9-apramey2-anshulb3/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test-parsing

# Build rule for target.
test-parsing: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test-parsing
.PHONY : test-parsing

# fast build rule for target.
test-parsing/fast:
	$(MAKE) $(MAKESILENT) -f parsing/CMakeFiles/test-parsing.dir/build.make parsing/CMakeFiles/test-parsing.dir/build
.PHONY : test-parsing/fast

#=============================================================================
# Target rules for targets named main-parsing

# Build rule for target.
main-parsing: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main-parsing
.PHONY : main-parsing

# fast build rule for target.
main-parsing/fast:
	$(MAKE) $(MAKESILENT) -f parsing/CMakeFiles/main-parsing.dir/build.make parsing/CMakeFiles/main-parsing.dir/build
.PHONY : main-parsing/fast

#=============================================================================
# Target rules for targets named ParsingLib

# Build rule for target.
ParsingLib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 ParsingLib
.PHONY : ParsingLib

# fast build rule for target.
ParsingLib/fast:
	$(MAKE) $(MAKESILENT) -f parsing/CMakeFiles/ParsingLib.dir/build.make parsing/CMakeFiles/ParsingLib.dir/build
.PHONY : ParsingLib/fast

#=============================================================================
# Target rules for targets named test-algorithm

# Build rule for target.
test-algorithm: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test-algorithm
.PHONY : test-algorithm

# fast build rule for target.
test-algorithm/fast:
	$(MAKE) $(MAKESILENT) -f algorithm/CMakeFiles/test-algorithm.dir/build.make algorithm/CMakeFiles/test-algorithm.dir/build
.PHONY : test-algorithm/fast

#=============================================================================
# Target rules for targets named main-algorithm

# Build rule for target.
main-algorithm: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main-algorithm
.PHONY : main-algorithm

# fast build rule for target.
main-algorithm/fast:
	$(MAKE) $(MAKESILENT) -f algorithm/CMakeFiles/main-algorithm.dir/build.make algorithm/CMakeFiles/main-algorithm.dir/build
.PHONY : main-algorithm/fast

#=============================================================================
# Target rules for targets named algorithmLib

# Build rule for target.
algorithmLib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 algorithmLib
.PHONY : algorithmLib

# fast build rule for target.
algorithmLib/fast:
	$(MAKE) $(MAKESILENT) -f algorithm/CMakeFiles/algorithmLib.dir/build.make algorithm/CMakeFiles/algorithmLib.dir/build
.PHONY : algorithmLib/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... ParsingLib"
	@echo "... algorithmLib"
	@echo "... main-algorithm"
	@echo "... main-parsing"
	@echo "... test-algorithm"
	@echo "... test-parsing"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

