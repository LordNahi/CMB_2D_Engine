# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nathan/Documents/projects/game_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nathan/Documents/projects/game_engine/build

# Include any dependencies generated for this target.
include CMakeFiles/main_engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main_engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_engine.dir/flags.make

CMakeFiles/main_engine.dir/src/Game.cpp.o: CMakeFiles/main_engine.dir/flags.make
CMakeFiles/main_engine.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathan/Documents/projects/game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_engine.dir/src/Game.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_engine.dir/src/Game.cpp.o -c /home/nathan/Documents/projects/game_engine/src/Game.cpp

CMakeFiles/main_engine.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_engine.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathan/Documents/projects/game_engine/src/Game.cpp > CMakeFiles/main_engine.dir/src/Game.cpp.i

CMakeFiles/main_engine.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_engine.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathan/Documents/projects/game_engine/src/Game.cpp -o CMakeFiles/main_engine.dir/src/Game.cpp.s

CMakeFiles/main_engine.dir/src/Main.cpp.o: CMakeFiles/main_engine.dir/flags.make
CMakeFiles/main_engine.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathan/Documents/projects/game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main_engine.dir/src/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_engine.dir/src/Main.cpp.o -c /home/nathan/Documents/projects/game_engine/src/Main.cpp

CMakeFiles/main_engine.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_engine.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathan/Documents/projects/game_engine/src/Main.cpp > CMakeFiles/main_engine.dir/src/Main.cpp.i

CMakeFiles/main_engine.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_engine.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathan/Documents/projects/game_engine/src/Main.cpp -o CMakeFiles/main_engine.dir/src/Main.cpp.s

CMakeFiles/main_engine.dir/src/Window.cpp.o: CMakeFiles/main_engine.dir/flags.make
CMakeFiles/main_engine.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathan/Documents/projects/game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main_engine.dir/src/Window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main_engine.dir/src/Window.cpp.o -c /home/nathan/Documents/projects/game_engine/src/Window.cpp

CMakeFiles/main_engine.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_engine.dir/src/Window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathan/Documents/projects/game_engine/src/Window.cpp > CMakeFiles/main_engine.dir/src/Window.cpp.i

CMakeFiles/main_engine.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_engine.dir/src/Window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathan/Documents/projects/game_engine/src/Window.cpp -o CMakeFiles/main_engine.dir/src/Window.cpp.s

# Object files for target main_engine
main_engine_OBJECTS = \
"CMakeFiles/main_engine.dir/src/Game.cpp.o" \
"CMakeFiles/main_engine.dir/src/Main.cpp.o" \
"CMakeFiles/main_engine.dir/src/Window.cpp.o"

# External object files for target main_engine
main_engine_EXTERNAL_OBJECTS =

bin/main_engine: CMakeFiles/main_engine.dir/src/Game.cpp.o
bin/main_engine: CMakeFiles/main_engine.dir/src/Main.cpp.o
bin/main_engine: CMakeFiles/main_engine.dir/src/Window.cpp.o
bin/main_engine: CMakeFiles/main_engine.dir/build.make
bin/main_engine: /home/nathan/.conan/data/sfml/2.5.1/bincrafters/stable/package/1d45e316e71aa76e122414be8f4c0d6688deabd4/lib/libsfml-graphics-s.a
bin/main_engine: /home/nathan/.conan/data/sfml/2.5.1/bincrafters/stable/package/1d45e316e71aa76e122414be8f4c0d6688deabd4/lib/libsfml-window-s.a
bin/main_engine: /home/nathan/.conan/data/sfml/2.5.1/bincrafters/stable/package/1d45e316e71aa76e122414be8f4c0d6688deabd4/lib/libsfml-network-s.a
bin/main_engine: /home/nathan/.conan/data/sfml/2.5.1/bincrafters/stable/package/1d45e316e71aa76e122414be8f4c0d6688deabd4/lib/libsfml-audio-s.a
bin/main_engine: /home/nathan/.conan/data/sfml/2.5.1/bincrafters/stable/package/1d45e316e71aa76e122414be8f4c0d6688deabd4/lib/libsfml-system-s.a
bin/main_engine: /home/nathan/.conan/data/freetype/2.10.1/_/_/package/1381eb533150a52ee50820711faa223d436deba1/lib/libfreetype.a
bin/main_engine: /home/nathan/.conan/data/libpng/1.6.37/_/_/package/1e8b7ff23bd5e7932ba7e8874349125fdf8e91ec/lib/libpng16.a
bin/main_engine: /home/nathan/.conan/data/zlib/1.2.11/_/_/package/6b7ff26bfd4c2cf2ccba522bfba2d2e7820e40da/lib/libz.a
bin/main_engine: /home/nathan/.conan/data/bzip2/1.0.8/_/_/package/ff2ff6bb41ed84283a6634bada252c37f13eb93c/lib/libbz2.a
bin/main_engine: /home/nathan/.conan/data/openal/1.19.1/_/_/package/395a697543c6d91c9cea7263a9a7a1fd3e6ce3fd/lib/libopenal.a
bin/main_engine: /home/nathan/.conan/data/libalsa/1.2.4/_/_/package/847849d4cc4b6352c8023780ae6930933f613ad9/lib/libasound.a
bin/main_engine: /home/nathan/.conan/data/flac/1.3.3/_/_/package/18e127a3cdb0f6639b6def6067ba912bdf1053a3/lib/libFLAC++.a
bin/main_engine: /home/nathan/.conan/data/flac/1.3.3/_/_/package/18e127a3cdb0f6639b6def6067ba912bdf1053a3/lib/libFLAC.a
bin/main_engine: /home/nathan/.conan/data/vorbis/1.3.6/_/_/package/b64f670df847327ead52ac5bfa3722faedc2edc3/lib/libvorbisenc.a
bin/main_engine: /home/nathan/.conan/data/vorbis/1.3.6/_/_/package/b64f670df847327ead52ac5bfa3722faedc2edc3/lib/libvorbisfile.a
bin/main_engine: /home/nathan/.conan/data/vorbis/1.3.6/_/_/package/b64f670df847327ead52ac5bfa3722faedc2edc3/lib/libvorbis.a
bin/main_engine: /home/nathan/.conan/data/ogg/1.3.4/_/_/package/6b7ff26bfd4c2cf2ccba522bfba2d2e7820e40da/lib/libogg.a
bin/main_engine: /home/nathan/.conan/data/fmt/7.1.3/_/_/package/f54287fc3dbd09590f968b580bebb565ea4a4b17/lib/libfmt.a
bin/main_engine: CMakeFiles/main_engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nathan/Documents/projects/game_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable bin/main_engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_engine.dir/build: bin/main_engine

.PHONY : CMakeFiles/main_engine.dir/build

CMakeFiles/main_engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_engine.dir/clean

CMakeFiles/main_engine.dir/depend:
	cd /home/nathan/Documents/projects/game_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nathan/Documents/projects/game_engine /home/nathan/Documents/projects/game_engine /home/nathan/Documents/projects/game_engine/build /home/nathan/Documents/projects/game_engine/build /home/nathan/Documents/projects/game_engine/build/CMakeFiles/main_engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_engine.dir/depend

