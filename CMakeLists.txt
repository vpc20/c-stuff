cmake_minimum_required(VERSION 4.0)
project(c_stuff C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c_stuff main.c read_text.c
        )
#add_executable(c_stuff_aoc_tools aoc_tools.c)

add_library(c_stuff_tools_lib tools.c tools.h aoc_tools.c aoc_tools.h)
target_link_libraries(c_stuff c_stuff_tools_lib)
