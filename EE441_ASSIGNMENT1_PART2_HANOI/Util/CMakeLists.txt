cmake_minimum_required(VERSION 3.8)

add_executable(Util src/benchmark.cpp include/hanoi.h include/print_backwards.h include/nth_prime.h)

target_include_directories(Util PUBLIC include/)
