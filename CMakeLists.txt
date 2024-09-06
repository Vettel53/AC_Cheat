cmake_minimum_required(VERSION 3.27)
project(AC_Cheat C)

set(CMAKE_C_STANDARD 11)

add_executable(AC_Cheat main.c
        process.c
        includes.h)
