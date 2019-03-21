cmake_minimum_required(VERSION 3.10)
project(cs372-CPS)

set(CMAKE_CXX_STANDARD 17)


include_directories("../include")
add_executable(test_cps ./CPS/compoundshape.cpp ./CPS/compoundshape.h ./CPS/shape.cpp ./CPS/shape.h)
