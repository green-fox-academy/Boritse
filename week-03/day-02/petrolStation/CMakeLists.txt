cmake_minimum_required(VERSION 3.13)
project(petrolStation)

set(CMAKE_CXX_STANDARD 14)

add_executable(petrolStation main.cpp station.cpp station.h car.cpp car.h)