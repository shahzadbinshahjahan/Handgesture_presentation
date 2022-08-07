#!/bin/bash

echo "Compiling Program ..."
g++ src/main.cpp src/read_images.cpp -o build/main $(pkg-config --cflags --libs opencv4)
echo "Compilation Completed ..."
echo "Running Program ... "
./build/main
