cmake_minimum_required(VERSION 3.15)
project(calculator)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include/calculator ./src)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(calculator src/main.cpp
               src/calculator.cpp)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

target_link_libraries(calculator Qt5::Core)
target_link_libraries(calculator Qt5::Widgets)
target_link_libraries(calculator Qt5::Quick)