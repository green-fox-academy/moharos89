cmake_minimum_required(VERSION 3.13)
project(farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(farm main.cpp Animal.cpp Farm.cpp Farm.h)