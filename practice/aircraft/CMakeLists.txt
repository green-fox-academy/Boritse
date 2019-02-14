cmake_minimum_required(VERSION 3.13)
project(aircraft)

set(CMAKE_CXX_STANDARD 14)

add_executable(aircraft main.cpp aircraft.cpp aircraft.h F16.cpp F16.h F35.cpp F35.h carrier.cpp carrier.h)