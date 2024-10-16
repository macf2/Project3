cmake_minimum_required(VERSION 3.15)
project(Project3)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Project3
        include/AVLTree.hpp
        include/BinarySearchTree.hpp
        include/Cat.hpp
        include/SplayTree.hpp
        main.cpp)
