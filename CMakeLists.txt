cmake_minimum_required(VERSION 3.6)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        src/ICcomponent.cpp
        src/parser.cpp
        src/tree.cpp)

include_directories(include)

add_executable(nanotekspice ${SOURCE_FILES})