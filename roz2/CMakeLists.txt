cmake_minimum_required(VERSION 3.5)
project(roz2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libgcc -static-libstdc++")

set(SOURCE_FILES main.cpp)
add_executable(roz2 ${SOURCE_FILES})