# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\riddh\Desktop\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\riddh\Desktop\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Final_Prep.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Final_Prep.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Final_Prep.dir/flags.make

CMakeFiles/Final_Prep.dir/Q1.c.obj: CMakeFiles/Final_Prep.dir/flags.make
CMakeFiles/Final_Prep.dir/Q1.c.obj: ../Q1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Final_Prep.dir/Q1.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Final_Prep.dir\Q1.c.obj   -c "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\Q1.c"

CMakeFiles/Final_Prep.dir/Q1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Final_Prep.dir/Q1.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\Q1.c" > CMakeFiles\Final_Prep.dir\Q1.c.i

CMakeFiles/Final_Prep.dir/Q1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Final_Prep.dir/Q1.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\Q1.c" -o CMakeFiles\Final_Prep.dir\Q1.c.s

# Object files for target Final_Prep
Final_Prep_OBJECTS = \
"CMakeFiles/Final_Prep.dir/Q1.c.obj"

# External object files for target Final_Prep
Final_Prep_EXTERNAL_OBJECTS =

Final_Prep.exe: CMakeFiles/Final_Prep.dir/Q1.c.obj
Final_Prep.exe: CMakeFiles/Final_Prep.dir/build.make
Final_Prep.exe: CMakeFiles/Final_Prep.dir/linklibs.rsp
Final_Prep.exe: CMakeFiles/Final_Prep.dir/objects1.rsp
Final_Prep.exe: CMakeFiles/Final_Prep.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Final_Prep.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Final_Prep.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Final_Prep.dir/build: Final_Prep.exe

.PHONY : CMakeFiles/Final_Prep.dir/build

CMakeFiles/Final_Prep.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Final_Prep.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Final_Prep.dir/clean

CMakeFiles/Final_Prep.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\cmake-build-debug" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\cmake-build-debug" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Final Prep\cmake-build-debug\CMakeFiles\Final_Prep.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Final_Prep.dir/depend

