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
CMAKE_SOURCE_DIR = "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Exam_Prep.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exam_Prep.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exam_Prep.dir/flags.make

CMakeFiles/Exam_Prep.dir/2020.c.obj: CMakeFiles/Exam_Prep.dir/flags.make
CMakeFiles/Exam_Prep.dir/2020.c.obj: CMakeFiles/Exam_Prep.dir/includes_C.rsp
CMakeFiles/Exam_Prep.dir/2020.c.obj: ../2020.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Exam_Prep.dir/2020.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Exam_Prep.dir\2020.c.obj   -c "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\2020.c"

CMakeFiles/Exam_Prep.dir/2020.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exam_Prep.dir/2020.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\2020.c" > CMakeFiles\Exam_Prep.dir\2020.c.i

CMakeFiles/Exam_Prep.dir/2020.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exam_Prep.dir/2020.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\2020.c" -o CMakeFiles\Exam_Prep.dir\2020.c.s

# Object files for target Exam_Prep
Exam_Prep_OBJECTS = \
"CMakeFiles/Exam_Prep.dir/2020.c.obj"

# External object files for target Exam_Prep
Exam_Prep_EXTERNAL_OBJECTS =

Exam_Prep.exe: CMakeFiles/Exam_Prep.dir/2020.c.obj
Exam_Prep.exe: CMakeFiles/Exam_Prep.dir/build.make
Exam_Prep.exe: CMakeFiles/Exam_Prep.dir/linklibs.rsp
Exam_Prep.exe: CMakeFiles/Exam_Prep.dir/objects1.rsp
Exam_Prep.exe: CMakeFiles/Exam_Prep.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Exam_Prep.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Exam_Prep.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exam_Prep.dir/build: Exam_Prep.exe

.PHONY : CMakeFiles/Exam_Prep.dir/build

CMakeFiles/Exam_Prep.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Exam_Prep.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Exam_Prep.dir/clean

CMakeFiles/Exam_Prep.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\cmake-build-debug" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\cmake-build-debug" "C:\Users\riddh\OneDrive - University of Toronto\First Year\1W\ESC190\C\Exam Prep\cmake-build-debug\CMakeFiles\Exam_Prep.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Exam_Prep.dir/depend

