cmake_minimum_required(VERSION 3.6)
project(CS10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

add_executable(A6.1 src/a6_1.cpp)

add_executable(A7.1 src/a7_1.cpp)

add_executable(A8.1 src/a8_1.cpp)

add_executable(A9.1 src/a9_1.cpp)

add_executable(A10.1 src/a10_1.cpp)

add_executable(A11.1 src/a11_1.cpp)

add_executable(A12.1 src/a12_1.cpp)

add_executable(A13.1 src/a13_1.cpp src/fraction.cpp)

add_executable(A14.1 src/a14_1.cpp src/boolMatrix.cpp)
