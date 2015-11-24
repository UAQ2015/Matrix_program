cmake_minimum_required(VERSION 3.3)
project(Matrix_program)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp
    Matrix_input.cpp
    Matrix_input.h)

add_executable(Matrix_program ${SOURCE_FILES})