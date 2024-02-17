#
Snowball game is a game where the user needs to interact with a few button clicks:
- p: pause/start
- r: reset game
- left arrow: move snowboard to the left
- right arrow: move snowboard to the right
- escape: terminate window

The user have 3 lives and wins if all the bricks are gone. Game over happen when the player lose all 3 lives.

## PreRequisite

Download fonts

```bash
sudo apt install ttf-mscorefonts-installer
```

and find the root folder to the verdana font and, replace the path in l.55 in the entityManager.cpp

## Build

```bash
make
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Run

```bash
./build/Executable
```