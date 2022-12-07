cmake_minimum_required(VERSION 2.84)
project(LAB7)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")

include_directories(include)

add_executable(main
        src/main.cpp
        )