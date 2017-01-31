cmake_minimum_required(VERSION 3.6)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCE_FILES
        main.cpp
        src/ICcomponent.cpp
        src/parser.cpp
        src/tree.cpp)

set(INCLUDE_FILES
        include/ICcomponent.h
        include/parser.h
        include/tree.h)

add_executable(nanotekspice ${SOURCE_FILES} ${INCLUDE_FILES})