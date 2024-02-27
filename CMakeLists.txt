cmake_minimum_required(VERSION 3.27)
project(DataStructures)

set(CMAKE_CXX_STANDARD 23)

add_executable(echo Exercises/echo/main.cpp Exercises/echo/echo_application.cpp)
add_executable(stringstream Exercises/stringstream/main.cpp)
add_executable(command_line Exercises/command_line/main.cpp)
add_executable(vector Exercises/vector/main.cpp)
add_executable(dynamic_array Exercises/dynamic_array/main.cpp)
add_executable(pointers Exercises/pointers/main.cpp)
add_executable(linked_lists Exercises/linked_lists/main.cpp)
add_executable(smart_pointer Exercises/smart_pointer/main.cpp)
add_executable(iterator Exercises/iterator/main.cpp)
add_executable(queues Exercises/queues/main.cpp)
add_executable(stack Exercises/stack/main.cpp)
add_executable(palindrome Exercises/palindrome/main.cpp)
add_executable(binary_tree Exercises/binary_search_tree/main.cpp)

add_executable(text_editor Completed_Assignments/Assignment_1-Text_Editor/main.cpp
                Completed_Assignments/Assignment_1-Text_Editor/text_editor.cpp
                Completed_Assignments/Assignment_1-Text_Editor/linked_list.cpp)