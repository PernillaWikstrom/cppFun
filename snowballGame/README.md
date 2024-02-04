# PreRequisite

Download fonts

```bash
sudo apt install ttf-mscorefonts-installer
```

and find the root folder to the verdana font and, replace the path in l.55 in the entityManager.cpp

# Build

```bash
g++ -std=c++17 background.cpp entity.cpp snowball.cpp snowboard.cpp brick.cpp interactions.cpp entityManager.cpp -c  -lsfml-graphics -lsfml-window -lsfml-system
g++ -std=c++17 background.o entity.o snowball.o snowboard.o brick.o interactions.o entityManager.o main.cpp -o main  -lsfml-graphics -lsfml-window -lsfml-system
```

# Run

```bash
./main
```
