cmake_minimum_required(VERSION 4.1.0)
project(myproj CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_COMPILER "clang++")
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_SCAN_FOR_MODULES ON)


add_library(math)
target_sources(math PUBLIC FILE_SET CXX_MODULES FILES math.cppm)
set_target_properties(math PROPERTIES CXX_EXTENSIONS OFF)

# set(CMAKE_CXX_MODULE_STD 1)

add_executable(myproj main.cpp)
target_link_libraries( myproj PRIVATE math)
