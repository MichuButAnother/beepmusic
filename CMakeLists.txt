cmake_minimum_required(VERSION 3.10)

project(beepmusic VERSION 1.0)

set(beepmusic_NOGRAPHICS 0) # Compile without visual animation

configure_file(config.h.in config.h)

add_executable(beepmusic main.cpp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
