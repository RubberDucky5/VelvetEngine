cmake_minimum_required(VERSION 3.31)

project(VelvetEngine)

# SDL Build Setup
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)

# Library
add_library(MathUtil)
target_sources(MathUtil
  PRIVATE
    src/mathutil.cpp

  PUBLIC
    FILE_SET HEADERS
    TYPE HEADERS
    BASE_DIRS
      src
    FILES
      src/mathutil.h
)

add_library(SDLUtil)
target_sources(SDLUtil
  PRIVATE
    src/sdlutil.cpp

  PUBLIC
    FILE_SET HEADERS
    TYPE HEADERS
    BASE_DIRS
      src
    FILES
      src/sdlutil.h
)

add_library(Renderer)
target_sources(Renderer
  PRIVATE
    src/renderer.cpp

  PUBLIC
    FILE_SET HEADERS
    TYPE HEADERS
    BASE_DIRS
      src
    FILES
      src/renderer.h
)

# Main Executable
add_executable(VelvetEngine)
target_sources(VelvetEngine
    PRIVATE
        src/main.cpp
)
target_link_libraries(VelvetEngine PRIVATE SDL3::SDL3)
target_link_libraries(Renderer PRIVATE SDL3::SDL3)
target_link_libraries(VelvetEngine PRIVATE Renderer)
target_link_libraries(VelvetEngine PRIVATE MathUtil)
target_link_libraries(VelvetEngine PRIVATE SDLUtil)

# add_executable(VelvetEditor)