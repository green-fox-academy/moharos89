cmake_minimum_required(VERSION 3.13)
project(FleetOfThings)

set(CMAKE_CXX_STANDARD 14)

add_executable(FleetOfThings main.cpp Fleet.cpp Fleet.h cmake-build-debug/thing.cpp cmake-build-debug/thing.h)