cmake_minimum_required(VERSION 3.13)
project(flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(flyable main.cpp flyable.cpp vehicle.cpp helicopter.cpp helicopter.h bird.cpp animal.cpp)