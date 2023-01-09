cmake_minimum_required(VERSION 3.8)

add_executable(Util src/main.cpp include/main.h)

target_include_directories(Util PUBLIC include/)
