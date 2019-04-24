cmake_minimum_required(VERSION 3.13)
project(zoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(zoo main.cpp animal.cpp animal.h mammal.cpp mammal.h reptile.cpp reptile.h bird.cpp bird.h)