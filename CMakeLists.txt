cmake_minimum_required(VERSION 3.10)
project(masterpiece)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets HINTS ~/Qt/5.11.1/gcc_64/)


add_executable(masterpiece main.cpp Thinker.cpp Thinker.h MapStore.cpp MapStore.h Worker.cpp Worker.h)

target_link_libraries(masterpiece Qt5::Core)

