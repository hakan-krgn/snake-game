//
// Created by Hakan on 16.11.2022.
//

#include "snake.h"

Snake::Snake() {
    this->tail = new Tail();
    this->direction = RIGHT;
    this->length = new int(1);
    this->tail->push_back(Location(0, 0));
}

Snake::~Snake() {
    delete this->length;
    delete this->tail;
    delete &this->direction;
}

int Snake::getLength() {
    return *this->length;
}

Location Snake::getHead() {
    return this->tail->at(0);
}

Tail Snake::getTail() {
    return *this->tail;
}

Location Snake::getTail(int index) {
    return this->tail->at(index);
}

Direction Snake::getDirection() {
    return this->direction;
}

void Snake::setDirection(Direction dir) {
    this->direction = dir;
}

void Snake::eatFood() {
    (*this->length)++;
    this->tail->push_back(Location(-2, -2));
}

void Snake::move() {
    int x = this->tail->at(0).getX();
    int y = this->tail->at(0).getY();

    switch (this->direction) {
        case UP:
            this->tail->at(0).addY(-1);
            break;
        case DOWN:
            this->tail->at(0).addY(1);
            break;
        case LEFT:
            this->tail->at(0).addX(-1);
            break;
        case RIGHT:
            this->tail->at(0).addX(1);
            break;
    }

    for (int i = 1; i < *this->length; i++) {
        int tempX = this->tail->at(i).getX();
        int tempY = this->tail->at(i).getY();

        this->tail->at(i).setPosition(x, y);

        x = tempX;
        y = tempY;

        delete &tempX;
        delete &tempY;
    }

    delete &x;
    delete &y;
}
