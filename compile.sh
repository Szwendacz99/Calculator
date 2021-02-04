#!/bin/bash
echo -n "Where I am :"
pwd
#echo "Checking for previous build and cleaning..."
#build_directory="build"
#if [ -d $build_directory ]
#then
#  echo "removing previous build directory..."
#  rm -r build
#fi

#echo "Making dir "
#mkdir $build_directory
echo "cmake configure..."
#cmake . -B build
cmake ..
echo "cmake compile..."
cmake --build .
