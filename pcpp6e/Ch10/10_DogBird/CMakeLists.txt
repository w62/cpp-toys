cmake_minimum_required(VERSION 4.1)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
project(Weather)
add_subdirectory(Bird)
add_subdirectory(Dog)
add_executable(test test.cpp)
target_link_libraries(test LIB_Dog LIB_Bird)

