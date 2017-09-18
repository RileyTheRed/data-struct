cmake_minimum_required(VERSION 3.8)
project(work_dir)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        dynarr.h
        main.cpp)

add_executable(work_dir ${SOURCE_FILES})