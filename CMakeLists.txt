cmake_minimum_required(VERSION 3.12.3)
project(BAHM)

set(CMAKE_CXX_STANDARD 11)

add_executable(BAHM main.cpp parser.h Slide.cpp Slide.h)