cmake_minimum_required(VERSION 3.8)

add_executable(Util src/mazoi.cpp include/mazoi.h include/StackQueue.h)

target_include_directories(Util PUBLIC include/)
