#!/bin/bash

# To compile with clang instead of gcc run with parameter "clang"
compiler="gcc"
if [ $# -eq 1 ]
then
  if [ "$1" == "clang" ]
  then
    compiler="clang++"
  fi
fi

 echo "Compiler set to $compiler"

location=`pwd`
echo "Current location: ${location}"
echo "Files here:"
ls
echo  "Cmake version:"
cmake --version

echo  "Compiler version:"
$compiler --version

echo "Checking for previous build and cleaning..."
build_directory="${location}/build"
if [ -d "$build_directory" ]
then
  echo "removing previous build directory..."
  rm -r build
fi

echo "Making dir "
mkdir "$build_directory"
echo "entering $build_directory"
cd "$build_directory" || return
pwd
echo "cmake configure..."
cmake .. -D CMAKE_CXX_COMPILER=$compiler
echo "cmake compile..."
cmake --build .
