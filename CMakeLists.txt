cmake_minimum_required(VERSION 3.11)
project(BAHM)

set(CMAKE_CXX_STANDARD 11)

add_executable(
  bahm
  main.cpp
  parser.h
  Slide.cpp
  Slide.h
  evaluation.h
  evaluation.cpp
  photo.h
  photo.cpp
        output.h
)
