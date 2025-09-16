cmake_minimum_required(VERSION 3.30)
project(CPP_07)

set(CMAKE_CXX_STANDARD 98)


add_executable(CPP_07_ex00
        ex00/Template.cpp
        ex00/main.cpp)

add_executable(CPP_07_ex01
        ex01/Template.cpp
        ex01/main.cpp)

add_executable(CPP_07_ex02
        ex02/Array.hpp
        ex02/Array.cpp
        ex02/Array.tpp
        ex02/main.cpp)
