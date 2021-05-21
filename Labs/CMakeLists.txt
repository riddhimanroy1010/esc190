cmake_minimum_required(VERSION 3.17)
project(Labs C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Labs
        lab7.c
        lab7.h "Lab 8/avl_bag.c" "Lab 8/bag.h" "Lab 8/main.c")
