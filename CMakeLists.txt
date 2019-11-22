cmake_minimum_required(VERSION 3.10)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c display.c jacobi.c testMatrice.c gs.c testing.c)
target_link_libraries(untitled m)