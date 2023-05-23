#!/bin/bash

cd build/

cmake .. -DCMAKE_BUILD_TYPE=Debug

cmake --build . 

cd ..

./build/time_test