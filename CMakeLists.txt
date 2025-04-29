cmake_minimum_required(VERSION 3.27)
project(untitled14)

set(CMAKE_CXX_STANDARD 20)

set(GCC_COVERAGE_COMPILE_FLAGS "-g -Wall -Wextra -pedantic -std=c++20")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../)

add_executable(project1.out src/Image.cpp src/Image.h src/main.cpp)