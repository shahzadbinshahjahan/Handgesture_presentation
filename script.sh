#!/bin/bash

echo "Clearing cache ..."
rm main
echo "Compiling Program ..."
g++ src/main.cpp src/read_images.cpp -o main $(pkg-config --cflags --libs opencv4)
echo "Compilation Completed ..."
echo "Running Program ... "
./main
