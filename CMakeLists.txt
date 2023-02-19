cmake_minimum_required(VERSION 3.24)
project(programmingQuiz5)

set(CMAKE_CXX_STANDARD 17)

add_executable(programmingQuiz5 ItemType.h ItemType.cpp testDriver.cpp sorted.cpp sorted.h)
