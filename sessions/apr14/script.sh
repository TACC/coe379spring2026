#!/bin/bash

# include the next line
# set -x
rm -rf build
mkdir build
cd build
CC=icx CXX=icpx cmake -D CMAKE_VERBOSE_MAKEFILE=ON -D CMAKE_BUILD_TYPE=Debug ../c
make V=1
