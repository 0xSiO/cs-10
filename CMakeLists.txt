cmake_minimum_required(VERSION 3.6)
project(CS10)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB_RECURSE SOURCE_FILES
        "src/*.cpp"
        )

include_directories(include)

add_executable(A6.1 src/a6_1.cpp)
