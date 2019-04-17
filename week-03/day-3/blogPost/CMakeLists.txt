cmake_minimum_required(VERSION 3.13)
project(blogPost)

set(CMAKE_CXX_STANDARD 14)

add_executable(blogPost main.cpp BlogPost.cpp BlogPost.h)