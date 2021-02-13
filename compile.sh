#!/bin/bash

# to change compiler specify two parameters when starting script after --compiler parameter
# eg. ./compile --compiler gcc g++:

# to specify cmake flags add them after --cmake parameter, they will be listed until end of all arguments
# eg. "--cmake -flagOne --flagTwo"

# for coverage add --coverage parameter
# for debug build add --debug parameter

#default arguments to be overwritten when using parameters
compilerc="gcc"
compilercpp="g++"
cmake_args="-Wall"
cmake_build_type="Release"

while [ $1 ]; do
    if [ $1 == "--compiler" ]
    then
      shift
      compilerc=$1
      shift
      compilercpp=$1
    fi
    if [ $1 == "--debug"  ]; then
      cmake_build_type="Debug"
    fi
    if [ $1 == "--coverage"  ]; then
      cmake_args="$cmake_args -g -O0 -coverage"
    fi
    if [ $1 == "--cmake" ]
    then
      shift
      while [ $1 ]; do
          cmake_args="$cmake_args $1"
          shift
      done
    fi
    shift
done
echo ""
echo "Cmake arguments: $cmake_args"
echo "Cmake build type: $cmake_build_type"
echo ""
location=$(pwd)
echo "Current location: ${location}"
echo "Files here:"
ls
echo  "Cmake version:"
cmake --version

echo  "Compiler version:"
$compilercpp --version
echo ""
$compilerc --version
echo ""

echo "Checking for previous build and cleaning..."
build_directory="${location}/build"
if [ -d "$build_directory" ]
then
  echo "removing previous build directory..."
  rm -r build
fi

echo "Making dir "
mkdir "$build_directory"
echo "cmake configure..."
cmake -D CMAKE_BUILD_TYPE="$cmake_build_type" -D CMAKE_CXX_COMPILER="$compilercpp" -D CMAKE_C_COMPILER="$compilerc" -B "$build_directory" -S "$location" -D CMAKE_CXX_FLAGS="$cmake_args"
echo "cmake compile..."
cmake --build "$build_directory"
