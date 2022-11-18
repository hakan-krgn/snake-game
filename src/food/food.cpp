//
// Created by Hakan on 16.11.2022.
//

#include <cstdlib>
#include <ctime>
#include <string>
#include "food.h"

Food::Food(Snake *snake, int *area_size) {
    srand((unsigned) time(nullptr));

    this->snake = snake;
    this->area_size = area_size;
    this->location = new Location(0, 0);
    this->generate();
}

Food::~Food() {
    delete this->location;
}

Location Food::getLocation() {
    return *this->location;
}

void Food::generate() {
    int x = rand() % (*this->area_size - 1);
    int y = rand() % (*this->area_size - 1);

    for (const Location &tail: this->snake->getTail()) {
        if (tail.getX() == x && tail.getY() == y) {
            delete &x;
            delete &y;

            this->generate();
            return;
        }
    }

    this->location->setPosition(x, y);

    delete &x;
    delete &y;
}
