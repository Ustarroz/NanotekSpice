cmake_minimum_required(VERSION 3.6)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 11)
SET( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

include_directories(include)

set(SOURCE_FILES
        main.cpp
        src/AComponent.cpp
        src/Parser.cpp
        src/Component4001.cpp
        src/Component4008.cpp
        src/Component4011.cpp
        src/Component4030.cpp
        src/Component4069.cpp
        src/Component4071.cpp
        src/Component4081.cpp
        src/ASubComponent.cpp
        src/GateOr.cpp
        src/GateAnd.cpp
        src/GateNot.cpp
        src/GateXor.cpp
        src/GateNOr.cpp
        src/GateNAnd.cpp
        src/GateNXor.cpp
        src/ComponentClock.cpp
        src/ComponentInput.cpp
        src/ComponentOutput.cpp
        src/ComponentTrue.cpp
        src/ComponentFalse.cpp
        src/Error.cpp)

set(INCLUDE_FILES
        include/ICcomponent.hpp
        include/AComponent.hpp
        include/IParser.hpp
        include/Parser.hpp
        include/Component4001.hpp
        include/Component4008.hpp
        include/Component4011.hpp
        include/Component4030.hpp
        include/Component4069.hpp
        include/Component4071.hpp
        include/Component4081.hpp
        include/ASubComponent.hpp
        include/GateOr.hpp
        include/GateAnd.hpp
        include/GateNot.hpp
        include/GateXor.hpp
        include/GateNOr.hpp
        include/GateNAnd.hpp
        include/GateNXor.hpp
        include/ComponentClock.hpp
        include/ComponentInput.hpp
        include/ComponentOutput.hpp
        include/ComponentTrue.hpp
        include/ComponentFalse.hpp include/Circuit.hpp src/Circuit.cpp
        include/Error.hpp)

add_executable(nanotekspice ${SOURCE_FILES} ${INCLUDE_FILES})
