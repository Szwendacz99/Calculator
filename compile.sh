#!/bin/bash

rm -r build
mkdir build
cmake . -B build
cmake --build build
