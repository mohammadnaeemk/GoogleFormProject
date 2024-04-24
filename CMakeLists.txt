cmake_minimum_required(VERSION 3.27)
project(GoogleFormProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(GoogleFormProject main.cpp
        Master.cpp
        Student.h
        Student.cpp)
