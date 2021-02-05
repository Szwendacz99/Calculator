#!/bin/bash

# to change compiler specify two parameters when starting script:
compilercpp="g++"
compilerc="gcc"
if [ $# -eq 2 ]
then
    compilercpp=$1
    compilerc=$2
fi

location=$(pwd)
echo "Current location: ${location}"
echo "Files here:"
ls
echo  "Cmake version:"
cmake --version

echo  "Compiler version:"
$compilercpp --version
$compilerc --version

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
cmake -D CMAKE_CXX_COMPILER="$compilercpp" -D CMAKE_C_COMPILER="$compilerc" -B "$build_directory" -S "$location"
echo "cmake compile..."
cmake --build "$build_directory"
