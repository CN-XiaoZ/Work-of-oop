cmake_minimum_required(VERSION 3.7)
project(Nodelist1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Node.h List.cpp List.h)
add_executable(Nodelist1 ${SOURCE_FILES})