#ifndef SNAKE_GAME_SNAKE_H
#define SNAKE_GAME_SNAKE_H


#include <vector>
#include <location.h>

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

class Snake {
    int length;
    Direction direction;
    std::vector<Location> tail;

public:
    Snake();

    int getLength() const;

    Location &getHead();

    Location &getTail(int index);

    Direction &getDirection();

    std::vector<Location> &getTails();

    void setDirection(Direction dir);


    void eatFood();

    void move();
};


#endif
