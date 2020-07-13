cmake_minimum_required(VERSION 3.16)
project(Conway_game_of_life)

set(CMAKE_CXX_STANDARD 14)

add_executable(Conway_game_of_life main.cpp life_board.cpp life_board.h)
