cmake_minimum_required(VERSION 3.13)
project(animalShelter)

set(CMAKE_CXX_STANDARD 14)

add_executable(animalShelter main.cpp animal.cpp animal.h cat.cpp cat.h)