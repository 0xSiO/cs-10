cmake_minimum_required(VERSION 3.6)
project(CS10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

add_executable(A1.1 src/a1_1.cpp)
add_executable(A1.2 src/a1_2.cpp)

add_executable(A2.1 src/a2_1.cpp)
add_executable(A2.2 src/a2_2.cpp)
add_executable(A2.3 src/a2_3.cpp)

add_executable(A3.1 src/a3_1.cpp)
add_executable(A3.2 src/a3_2.cpp)
add_executable(A3.3 src/a3_3.cpp)
add_executable(A3.4 src/a3_4.cpp)

add_executable(A4.1 src/a4_1.cpp)
add_executable(A4.2 src/a4_2.cpp)
add_executable(A4.3 src/a4_3.cpp)

add_executable(A5.1 src/a5_1.cpp)
add_executable(A5.2 src/a5_2.cpp)
add_executable(A5.3 src/a5_3.cpp)

add_executable(A6.1 src/a6_1.cpp)

add_executable(A7.1 src/a7_1.cpp)

add_executable(A8.1 src/a8_1.cpp)

add_executable(A9.1 src/a9_1.cpp)

add_executable(A10.1 src/a10_1.cpp)

add_executable(A11.1 src/a11_1.cpp)

add_executable(A12.1 src/a12_1.cpp)

add_executable(A13.1 src/a13_1.cpp src/fraction.cpp)

add_executable(A14.1 src/a14_1.cpp src/boolMatrix.cpp)

add_executable(A15 src/a15.cpp src/boolMatrix.cpp)
