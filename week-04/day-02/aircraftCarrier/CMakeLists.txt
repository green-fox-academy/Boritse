cmake_minimum_required(VERSION 3.13)
project(aircraftCarrier)

set(CMAKE_CXX_STANDARD 14)

add_executable(aircraftCarrier main.cpp aircrafts.cpp aircrafts.h carrier.cpp carrier.h)