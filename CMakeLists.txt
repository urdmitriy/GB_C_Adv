cmake_minimum_required(VERSION 3.24)
project(GB_C_adv C)

set(CMAKE_C_STANDARD 23)


include_directories(LIB)
link_libraries(${CMAKE_SOURCE_DIR}/LIB/mylib.a)
add_executable(GB_C_adv main.c LIB/test.h)
