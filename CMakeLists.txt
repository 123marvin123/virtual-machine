cmake_minimum_required(VERSION 3.7)
project(vm)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c stack.c stack.h object.h instructions.c instructions.h)
add_executable(vm ${SOURCE_FILES})