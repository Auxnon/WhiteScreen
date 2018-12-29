#!/bin/bash
echo 'compiling...'
echo '64 bit linux binary...'
g++ -Wall -Wextra -o bin/gamex86_64 src/main.cpp src/Entity.cpp -lSDL2
echo 'done!'

echo '32bit armv6 binary...'
arm-linux-gnueabihf-g++ -Wl,--unresolved-symbols=ignore-all -Wextra -Iinclude -o bin/gameArm6 src/main.cpp src/Entity.cpp `bin/sdl2-config --cflags --libs`

# arm-linux-gnueabihf-g++ -Wall -Wextra -I./include ./src/main.cpp ./src/Entity.cpp -o hellothere `./bin/sdl2-config --cflags --libs`
echo 'done!'
echo 'all binaries complete!'

