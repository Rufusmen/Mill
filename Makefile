# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rufus/Dokumenty/WdPC/Mill

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rufus/Dokumenty/WdPC/Mill

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rufus/Dokumenty/WdPC/Mill/CMakeFiles /home/rufus/Dokumenty/WdPC/Mill/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rufus/Dokumenty/WdPC/Mill/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named mill

# Build rule for target.
mill: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 mill
.PHONY : mill

# fast build rule for target.
mill/fast:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/build
.PHONY : mill/fast

board.o: board.c.o

.PHONY : board.o

# target to build an object file
board.c.o:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/board.c.o
.PHONY : board.c.o

board.i: board.c.i

.PHONY : board.i

# target to preprocess a source file
board.c.i:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/board.c.i
.PHONY : board.c.i

board.s: board.c.s

.PHONY : board.s

# target to generate assembly for a file
board.c.s:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/board.c.s
.PHONY : board.c.s

fifo.o: fifo.c.o

.PHONY : fifo.o

# target to build an object file
fifo.c.o:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/fifo.c.o
.PHONY : fifo.c.o

fifo.i: fifo.c.i

.PHONY : fifo.i

# target to preprocess a source file
fifo.c.i:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/fifo.c.i
.PHONY : fifo.c.i

fifo.s: fifo.c.s

.PHONY : fifo.s

# target to generate assembly for a file
fifo.c.s:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/fifo.c.s
.PHONY : fifo.c.s

logger.o: logger.c.o

.PHONY : logger.o

# target to build an object file
logger.c.o:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/logger.c.o
.PHONY : logger.c.o

logger.i: logger.c.i

.PHONY : logger.i

# target to preprocess a source file
logger.c.i:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/logger.c.i
.PHONY : logger.c.i

logger.s: logger.c.s

.PHONY : logger.s

# target to generate assembly for a file
logger.c.s:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/logger.c.s
.PHONY : logger.c.s

main.o: main.c.o

.PHONY : main.o

# target to build an object file
main.c.o:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/main.c.o
.PHONY : main.c.o

main.i: main.c.i

.PHONY : main.i

# target to preprocess a source file
main.c.i:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/main.c.i
.PHONY : main.c.i

main.s: main.c.s

.PHONY : main.s

# target to generate assembly for a file
main.c.s:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/main.c.s
.PHONY : main.c.s

my_button.o: my_button.c.o

.PHONY : my_button.o

# target to build an object file
my_button.c.o:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/my_button.c.o
.PHONY : my_button.c.o

my_button.i: my_button.c.i

.PHONY : my_button.i

# target to preprocess a source file
my_button.c.i:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/my_button.c.i
.PHONY : my_button.c.i

my_button.s: my_button.c.s

.PHONY : my_button.s

# target to generate assembly for a file
my_button.c.s:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/my_button.c.s
.PHONY : my_button.c.s

player.o: player.c.o

.PHONY : player.o

# target to build an object file
player.c.o:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/player.c.o
.PHONY : player.c.o

player.i: player.c.i

.PHONY : player.i

# target to preprocess a source file
player.c.i:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/player.c.i
.PHONY : player.c.i

player.s: player.c.s

.PHONY : player.s

# target to generate assembly for a file
player.c.s:
	$(MAKE) -f CMakeFiles/mill.dir/build.make CMakeFiles/mill.dir/player.c.s
.PHONY : player.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... mill"
	@echo "... board.o"
	@echo "... board.i"
	@echo "... board.s"
	@echo "... fifo.o"
	@echo "... fifo.i"
	@echo "... fifo.s"
	@echo "... logger.o"
	@echo "... logger.i"
	@echo "... logger.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... my_button.o"
	@echo "... my_button.i"
	@echo "... my_button.s"
	@echo "... player.o"
	@echo "... player.i"
	@echo "... player.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

