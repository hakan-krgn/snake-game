# Snake Game

## Description

This is a simple console snake game made in C++. The game is played in the console and the snake is controlled by the
arrow keys. The objective of the game is to eat the food that appears on the screen and grow the snake as long as
possible without hitting the walls or the snake's body.

## How to build

To build the game you need to have a C++ compiler and CMake installed on your machine. You can use the following command
to build the game:

```shell
cd snake-game
cmake -S . -B build
cmake --build build
```

Then you can see the executable file in the `build` directory named `snake-game`.
