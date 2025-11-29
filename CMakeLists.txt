cmake_minimum_required(VERSION 4.0)
project(c_stuff C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c_stuff read_text.c)

add_library(c_stuff_tools_lib tools.c tools.h)

target_link_libraries(c_stuff c_stuff_tools_lib)
