cmake_minimum_required(VERSION 3.10)
project(cs372-CPS)

set(CMAKE_CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif()

include_directories("../CPS")

set(CPS
    ./cps/shape.cpp
    ./cps/shape.hpp
    ./cps/compoundshape.cpp
    ./cps/compoundshape.hpp)

set(TEST
    ./testing/main_test.cpp
    ./testing/test_shape.cpp
    ${CPS})

set(EXAMPLE
    ./docs/examples/example.cpp
    ${CPS})

add_executable(test_cps ${TEST})

add_executable(example_cps ${EXAMPLE})

add_executable(visual_test ${CPS} ./testing/visual_test.cpp)

add_executable(hw5 ${CPS} ./testing/hw5.cpp)