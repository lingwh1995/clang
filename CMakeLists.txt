cmake_minimum_required(VERSION 3.28)
project(clang C)

set(CMAKE_C_STANDARD 23)

add_library(clang STATIC
        000_练习题/src/main.c)