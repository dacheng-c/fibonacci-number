cmake_minimum_required(VERSION 3.10)
project(fibonacci_number C)

set(CMAKE_C_STANDARD 11)

add_executable(fibonacci_number main.c)
target_link_libraries(fibonacci_number pthread)