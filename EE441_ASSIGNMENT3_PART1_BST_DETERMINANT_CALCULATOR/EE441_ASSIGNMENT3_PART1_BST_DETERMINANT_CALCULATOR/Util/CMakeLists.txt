cmake_minimum_required(VERSION 3.8)

add_executable(Util src/main.cpp include/BinarySearchTree.h include/Matrix.h include/MatrixFunctions.h include/ReadMatrix.h) # Add files that can be executed.

target_include_directories(Util PUBLIC include/)