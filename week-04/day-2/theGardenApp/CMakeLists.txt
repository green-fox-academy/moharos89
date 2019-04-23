cmake_minimum_required(VERSION 3.13)
project(theGardenApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(theGardenApp main.cpp Plant.cpp Plant.h Flower.cpp Flower.h Tree.cpp Tree.h Garden.cpp Garden.h)