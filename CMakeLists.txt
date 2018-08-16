cmake_minimum_required(VERSION 3.10)
project(masterpiece)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core HINTS ~/Qt/5.11.1/gcc_64/)

add_executable(masterpiece main.cpp Worker.cpp Worker.h Map.cpp Map.h)

target_link_libraries(masterpiece Qt5::Core)

