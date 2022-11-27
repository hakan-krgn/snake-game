//
// Created by Hakan on 16.11.2022.
//

#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H



#include <vector>
#include "../location/location.h"

typedef std::vector<Location> Tail;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class Snake {
private:
    int *length;
    Tail *tail;
    Direction direction;

public:
    Snake();

    ~Snake();

    int getLength();

    Location getHead();

    Tail getTail();

    Location getTail(int index);

    Direction getDirection();

    void eatFood();

    void setDirection(Direction dir);

    void move();
};



#endif //SNAKE_GAME_SNAKE_H
