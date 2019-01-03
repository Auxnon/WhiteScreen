#!/bin/bash
echo 'compiling...'
g++ -Wall -Wextra -o bin/game64 src/main.cpp src/Entity.cpp -lSDL2
# src/main.cpp src/Entity.cpp
# arm-linux-gnueabihf-g++ -Wall -Wextra -I./include ./src/main.cpp ./src/Entity.cpp -o hellothere `./bin/sdl2-config --cflags --libs`
echo 'done!'

