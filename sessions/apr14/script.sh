#!/bin/bash

rm -rf build
mkdir build
cd build
cmake -D CMAKE_VERBOSE_MAKEFILE=ON -D CMAKE_BUILD_TYPE=RelWithDebInfo ../c
make V=1
