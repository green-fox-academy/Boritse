cmake_minimum_required(VERSION 3.13)
project(pirates)

set(CMAKE_CXX_STANDARD 14)

add_executable(pirates main.cpp Pirates.cpp Pirates.h Ship.cpp Ship.h Battle.cpp Battle.h)