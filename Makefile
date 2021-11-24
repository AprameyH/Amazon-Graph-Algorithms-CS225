# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /home/brownie/Coding/CS_225/final_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brownie/Coding/CS_225/final_project

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/brownie/Coding/CS_225/final_project/CMakeFiles /home/brownie/Coding/CS_225/final_project//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/brownie/Coding/CS_225/final_project/CMakeFiles 0
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
# Target rules for targets named test-adder

# Build rule for target.
test-adder: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test-adder
.PHONY : test-adder

# fast build rule for target.
test-adder/fast:
	$(MAKE) $(MAKESILENT) -f adder/CMakeFiles/test-adder.dir/build.make adder/CMakeFiles/test-adder.dir/build
.PHONY : test-adder/fast

#=============================================================================
# Target rules for targets named main-adder

# Build rule for target.
main-adder: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 main-adder
.PHONY : main-adder

# fast build rule for target.
main-adder/fast:
	$(MAKE) $(MAKESILENT) -f adder/CMakeFiles/main-adder.dir/build.make adder/CMakeFiles/main-adder.dir/build
.PHONY : main-adder/fast

#=============================================================================
# Target rules for targets named AdderLib

# Build rule for target.
AdderLib: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 AdderLib
.PHONY : AdderLib

# fast build rule for target.
AdderLib/fast:
	$(MAKE) $(MAKESILENT) -f adder/CMakeFiles/AdderLib.dir/build.make adder/CMakeFiles/AdderLib.dir/build
.PHONY : AdderLib/fast

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... AdderLib"
	@echo "... ParsingLib"
	@echo "... main-adder"
	@echo "... main-parsing"
	@echo "... test-adder"
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
