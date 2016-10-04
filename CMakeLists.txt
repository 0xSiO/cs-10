cmake_minimum_required(VERSION 3.6)
project(CS10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES
        "src/*.cpp"
        )

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
