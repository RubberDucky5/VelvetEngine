cmake_minimum_required(VERSION 3.31)

project(VelvetEngine)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(libs/SDL EXCLUDE_FROM_ALL)

# include(ExternalProject)
# ExternalProject_Add(SDL
#   SOURCE_DIR vendored/SDL
#   GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
#   GIT_TAG release-3.4.2
# )

add_executable(VelvetEngine)
target_sources(VelvetEngine
    PRIVATE
        src/main.cpp
)

target_link_libraries(VelvetEngine PRIVATE SDL3::SDL3)

# add_executable(VelvetEditor)