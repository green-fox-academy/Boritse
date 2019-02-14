cmake_minimum_required(VERSION 3.13)
project(stringedinstr)

set(CMAKE_CXX_STANDARD 14)

add_executable(stringedinstr main.cpp instrument.cpp instrument.h stringedInstrument.cpp stringedInstrument.h electricGuitar.cpp electricGuitar.h)