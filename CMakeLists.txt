cmake_minimum_required(VERSION 3.27)
project(DataStructures)

set(CMAKE_CXX_STANDARD 23)

add_executable(echo echo/main.cpp echo/echo_application.cpp)
add_executable(stringstream stringstream/main.cpp)
add_executable(command_line command_line/main.cpp)
