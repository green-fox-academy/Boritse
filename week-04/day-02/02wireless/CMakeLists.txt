cmake_minimum_required(VERSION 3.13)
project(02wireless)

set(CMAKE_CXX_STANDARD 14)

add_executable(02wireless main.cpp device.cpp device.h usbDevice.cpp usbDevice.h networkdevice.cpp networkdevice.h adapter.cpp adapter.h)