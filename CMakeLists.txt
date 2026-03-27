cmake_minimum_required(VERSION 3.31)

project(VelvetEngine)

add_executable(VelvetEngine)
target_sources(VelvetEngine
    PRIVATE
        src/main.cpp
)

# add_executable(VelvetEditor)