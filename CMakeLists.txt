cmake_minimum_required(VERSION 3.27)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

include_directories(echo)

add_executable(DataStructures
        echo/main.cpp
        echo/echo_application.h
        echo/echo_application.cpp)
