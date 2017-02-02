cmake_minimum_required(VERSION 3.6)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCE_FILES
        main.cpp
        src/AComponent.cpp
        src/Parser.cpp
        src/tree.cpp)

set(INCLUDE_FILES
        include/ICcomponent.hpp
        include/AComponent.hpp
        include/IParser.hpp
        include/tree.hpp
        include/Parser.hpp src/Parser.cpp)

add_executable(nanotekspice ${SOURCE_FILES} ${INCLUDE_FILES})