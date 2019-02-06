cmake_minimum_required(VERSION 3.13)
project(flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(flyable main.cpp flyable.cpp flyable.h vehicle.cpp vehicle.h helicopter.cpp helicopter.h animals.cpp animals.h Bird.cpp Bird.h)