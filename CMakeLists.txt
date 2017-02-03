cmake_minimum_required(VERSION 3.6)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

set(SOURCE_FILES
        main.cpp
        src/AComponent.cpp
        src/Parser.cpp
        src/tree.cpp
        src/Component4001.cpp
        src/Component4011.cpp
        src/Gate.cpp)

set(INCLUDE_FILES
        include/ICcomponent.hpp
        include/AComponent.hpp
        include/IParser.hpp
        include/tree.hpp
        include/Parser.hpp
        src/Parser.cpp
        include/Component4001.hpp
        include/Component4011.hpp
        include/Gate.hpp)

add_executable(nanotekspice ${SOURCE_FILES} ${INCLUDE_FILES})