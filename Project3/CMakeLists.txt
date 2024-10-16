cmake_minimum_required(VERSION 3.15)
project(Project3)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

add_executable(Project3
        AVLTree.hpp
        BinarySearchTree.hpp
        Cat.hpp
        SplayTree.hpp
        main.cpp)
