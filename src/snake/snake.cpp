//
// Created by Hakan on 16.11.2022.
//

#include <iostream>
#include "snake.h"

Snake::Snake() {
    this->direction = RIGHT;
    this->length = new int(1);
    this->tail[0] = Location(new int(0), new int(0));
}

Snake::~Snake() {
    delete this->length;
    delete &this->direction;
    delete[] &this->tail;
}

int Snake::getLength() {
    return *this->length;
}

Direction Snake::getDirection() {
    return this->direction;
}

Location Snake::getHead() {
    return this->tail[0];
}

Location Snake::getTail(int index) {
    return this->tail[index];
}

void Snake::setDirection(Direction dir) {
    this->direction = dir;
}

void Snake::eatFood() {
    (*this->length)++;
    this->tail[*this->length - 1] = Location(new int(-2), new int(-2));
}

void Snake::move() {
    int x = this->tail[0].getX();
    int y = this->tail[0].getY();

    switch (this->direction) {
        case UP:
            this->tail[0].addY(-1);
            break;
        case DOWN:
            this->tail[0].addY(1);
            break;
        case LEFT:
            this->tail[0].addX(-1);
            break;
        case RIGHT:
            this->tail[0].addX(1);
            break;
    }

    for (int i = 1; i < *this->length; i++) {
        int tempX = this->tail[i].getX();
        int tempY = this->tail[i].getY();

        this->tail[i].setPosition(x, y);

        x = tempX;
        y = tempY;

        delete &tempX;
        delete &tempY;
    }

    delete &x;
    delete &y;
}
