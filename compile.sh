#!/bin/bash
location=`pwd`
echo "Where I am : ${location}"
echo "Files here:"
ls
echo  "Cmake version:"
cmake --version

echo "Checking for previous build and cleaning..."
build_directory="${location}/build"
if [ -d "$build_directory" ]
then
  echo "removing previous build directory..."
  rm -r build
fi

echo "Making dir "
pwd
mkdir $build_directory
echo "cmake configure..."
pwd
cmake $location -B $build_directory
echo "cmake compile..."
pwd
cmake --build $build_directory
