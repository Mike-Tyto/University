#!/bin/bash

cd build/

cmake .. -DCMAKE_BUILD_TYPE=Debug

cmake --build .

cd ..

# valgrind ./build/main

valgrind ./build/queue