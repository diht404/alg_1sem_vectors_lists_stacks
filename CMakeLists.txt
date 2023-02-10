cmake_minimum_required(VERSION 3.24)
project(task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(vectorTest vector_test.cpp vector.cpp)
add_executable(listTest list_test.cpp list.cpp)
