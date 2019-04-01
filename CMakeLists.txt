cmake_minimum_required(VERSION 3.10)
project(cs372-CPS)

set(CMAKE_CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra")
endif()

include_directories("../CPS")
add_executable(test_cps ./testing/main_test.cpp ./testing/test_shape.cpp cps/compoundshape.cpp cps/compoundshape.hpp cps/shape.cpp cps/shape.hpp)
