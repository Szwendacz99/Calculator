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
mkdir $build_directory
echo "entering $build_directory"
cd "$build_directory" || return
pwd
echo "cmake configure..."
cmake ..
echo "cmake compile..."
cmake --build .
