cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)

project(LABORATORIES)
add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab-matrixes)
add_subdirectory(lab-hrms)
add_subdirectory(lab-philosophers)