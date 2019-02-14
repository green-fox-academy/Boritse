cmake_minimum_required(VERSION 3.13)
project(shelter)

set(CMAKE_CXX_STANDARD 14)

add_executable(shelter main.cpp Animal.cpp Animal.h Cat.cpp Cat.h Dog.cpp Dog.h Parrot.cpp Parrot.h AnimalShelter.cpp AnimalShelter.h)