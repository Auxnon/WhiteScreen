#!/bin/bash
echo 'compiling...'
g++ -o game ./src/main.cpp ./src/Entity.cpp -lSDL2 -lSDL2_image
echo 'complete!'
./game
