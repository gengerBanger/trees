cmake_minimum_required(VERSION 3.25)
project(bin_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(bin_tree main.cpp bin_tree.cpp bin_tree.h tests.h tree.h RedBlack_tree.cpp RedBlack_tree.h AVL_tree.cpp AVL_tree.h)
