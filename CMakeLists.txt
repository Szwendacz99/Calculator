cmake_minimum_required(VERSION 3.14)
project(calculator)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include/calculator ./src ./tests)

# if under windows, specify location of Qt libraries
# and download google test library from git , and put to /lib/googletest-lib
if (WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.10\\5.12.10\\mingw73_64")
    add_subdirectory(lib/googletest-lib)
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wl,--subsystem,windows")
endif (WIN32)
# to export under windows, use windeployqt.exe tool from "C:\\Qt\\Qt5.12.10\\5.12.10\\mingw73_64"
# in case of error copy manually and overwrite files:
# libstdc++-6.dll
# libwinpthread-1.dll
# libgcc_s_seh-1.dll

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)

add_executable(calculator src/Main.cpp
        src/Calculator.cpp src/MainWindow.cpp )

add_executable(test src/Calculator.cpp tests/test.cpp
                tests/test_calculating.cpp)

target_link_libraries(calculator Qt5::Core Qt5::Widgets )
target_link_libraries(test gtest gtest_main Qt5::Core Qt5::Widgets pthread )
