# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.21
cmake_policy(SET CMP0009 NEW)

# SOURCE_FILES at CMakeLists.txt:17 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/Users/charlieloveman/Documents/7drl/include/*.hpp")
set(OLD_GLOB
  "/Users/charlieloveman/Documents/7drl/include/BSPRoomGenerator.hpp"
  "/Users/charlieloveman/Documents/7drl/include/BasicRoomGenerator.hpp"
  "/Users/charlieloveman/Documents/7drl/include/Colour.hpp"
  "/Users/charlieloveman/Documents/7drl/include/Components.hpp"
  "/Users/charlieloveman/Documents/7drl/include/Entity.hpp"
  "/Users/charlieloveman/Documents/7drl/include/Event.hpp"
  "/Users/charlieloveman/Documents/7drl/include/FovEvent.hpp"
  "/Users/charlieloveman/Documents/7drl/include/FovManager.hpp"
  "/Users/charlieloveman/Documents/7drl/include/GameMap.hpp"
  "/Users/charlieloveman/Documents/7drl/include/Manager.hpp"
  "/Users/charlieloveman/Documents/7drl/include/MapRenderer.hpp"
  "/Users/charlieloveman/Documents/7drl/include/MovementEvent.hpp"
  "/Users/charlieloveman/Documents/7drl/include/MovementManager.hpp"
  "/Users/charlieloveman/Documents/7drl/include/RandomTunnelGenerator.hpp"
  "/Users/charlieloveman/Documents/7drl/include/RenderEvent.hpp"
  "/Users/charlieloveman/Documents/7drl/include/Renderer.hpp"
  "/Users/charlieloveman/Documents/7drl/include/RoomGenerator.hpp"
  "/Users/charlieloveman/Documents/7drl/include/StaticSingleRenderer.hpp"
  "/Users/charlieloveman/Documents/7drl/include/TunnelGenerator.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/charlieloveman/Documents/7drl/build/CMakeFiles/cmake.verify_globs")
endif()

# SOURCE_FILES at CMakeLists.txt:17 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/Users/charlieloveman/Documents/7drl/src/*.cpp")
set(OLD_GLOB
  "/Users/charlieloveman/Documents/7drl/src/BSPRoomGenerator.cpp"
  "/Users/charlieloveman/Documents/7drl/src/BasicRoomGenerator.cpp"
  "/Users/charlieloveman/Documents/7drl/src/Colour.cpp"
  "/Users/charlieloveman/Documents/7drl/src/Entity.cpp"
  "/Users/charlieloveman/Documents/7drl/src/Event.cpp"
  "/Users/charlieloveman/Documents/7drl/src/FovEvent.cpp"
  "/Users/charlieloveman/Documents/7drl/src/FovManager.cpp"
  "/Users/charlieloveman/Documents/7drl/src/GameMap.cpp"
  "/Users/charlieloveman/Documents/7drl/src/Manager.cpp"
  "/Users/charlieloveman/Documents/7drl/src/MapRenderer.cpp"
  "/Users/charlieloveman/Documents/7drl/src/MovementEvent.cpp"
  "/Users/charlieloveman/Documents/7drl/src/MovementManager.cpp"
  "/Users/charlieloveman/Documents/7drl/src/RandomTunnelGenerator.cpp"
  "/Users/charlieloveman/Documents/7drl/src/RenderEvent.cpp"
  "/Users/charlieloveman/Documents/7drl/src/StaticSingleRenderer.cpp"
  "/Users/charlieloveman/Documents/7drl/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/charlieloveman/Documents/7drl/build/CMakeFiles/cmake.verify_globs")
endif()
