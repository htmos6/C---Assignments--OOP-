cmake_minimum_required(VERSION 3.8)

add_executable(Util src/main.cpp include/HashItem.h include/HashTable.h include/Matrix.h include/MatrixFunctions.h include/ReadMatrix.h)

target_include_directories(Util PUBLIC include/)