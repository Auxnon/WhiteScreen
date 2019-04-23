#!/bin/bash
echo 'compiling...'
if [ "$1" = "linux" ] || [ "$1" = "" ]; then
	echo '64 bit linux binary...'
	g++ -Wall -Wextra -o bin/game64 src/main3d.cpp src/Entity.cpp -lSDL2 -lGLEW -lGL
	if [ $? -eq 0 ]; then
		echo '64 Linux done!'
	fi
fi

if [ "$1" = "arm6" ] || [ "$1" = "" ]; then
	echo '32bit arm6 binary...'
	arm-linux-gnueabihf-g++ -Wl,--unresolved-symbols=ignore-all -Wextra -Iinclude -o bin/gameArm6 src/main.cpp src/Entity.cpp `config/sdl2-config --cflags --libs`
	if [ $? -eq 0 ]; then
		echo '32bit arm6 done!'
	fi
fi

# arm-linux-gnueabihf-g++ -Wall -Wextra -I./include ./src/main.cpp ./src/Entity.cpp -o hellothere `./bin/sdl2-config --cflags --libs`
if [ "$1" = "web" ] || [ "$1" = "" ]; then
	echo 'web assembly binary...'
	emcc src/mainWeb.cpp src/Land.cpp -std=c++11 -s WASM=1 -s USE_SDL=2 -O3 -o web/index.js
	if [ $? -eq 0 ]; then
		echo 'web assembly done!'
	fi
fi
echo 'all binaries complete!'

