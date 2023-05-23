cmake_minimum_required(VERSION 3.23)
project(sem2)

set(CMAKE_CXX_STANDARD 14)

# add_executable(lab1 main.c matrix.c int.c real.c ring_info.c)
# add_executable(lab1_tests matrix.c int.c real.c ring_info.c test.c)
# add_executable(new_lab1 new_main.c new_matrix.c)

add_executable(time_test time_test.cpp new_matrix.c new_matrix.h int.c real.c ring_info.c ring_info.h)

add_executable(test test.cpp)
