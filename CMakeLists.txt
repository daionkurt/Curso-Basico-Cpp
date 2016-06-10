cmake_minimum_required(VERSION 3.5)
project(Curso_C__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

set(SOURCE_FILES main.cpp)
add_executable(Curso_C__ ${SOURCE_FILES})