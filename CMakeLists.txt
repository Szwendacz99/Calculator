cmake_minimum_required(VERSION 3.14)
project(calculator)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include/calculator ./src ./tests)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(calculator src/Main.cpp
        src/Calculator.cpp src/MainWindow.cpp )

add_executable(test src/Calculator.cpp tests/test.cpp
                tests/test_calculating.cpp )

target_link_libraries(calculator Qt5::Core Qt5::Widgets Qt5::Quick)
target_link_libraries(test gtest gtest_main Qt5::Core pthread)
