//
// Created by Hakan on 16.11.2022.
//

#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H



#include "../location/location.h"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
private:
    int *length;
    Location tail[441];
    Direction direction;

public:
    Snake();

    ~Snake();

    int getLength();

    Direction getDirection();

    Location getHead();

    Location getTail(int index);

    void eatFood();

    void setDirection(Direction dir);

    void move();
};



#endif //SNAKE_GAME_SNAKE_H
