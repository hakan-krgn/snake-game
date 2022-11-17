//
// Created by Hakan on 16.11.2022.
//

#include <cstdlib>
#include <ctime>
#include "food.h"

Food::Food() {
    this->location = new Location(0, 0);
    this->generate(nullptr);
}

Food::~Food() {
    delete this->location;
}

Location Food::getLocation() {
    return *this->location;
}

void Food::generate(Snake *snake) {
    srand((unsigned) time(nullptr));

    if (snake == nullptr) {
        this->location->setPosition(rand() % 20, rand() % 20);
        return;
    }

    int x = rand() % 20;
    int y = rand() % 20;
    for (int i = 0; i < snake->getLength(); i++) {
        Location tail = snake->getTail(i);
        if (tail.getX() == x && tail.getY() == y) {
            delete &x;
            delete &y;
            this->generate(snake);
            return;
        }
        delete &tail;
    }
    this->location->setPosition(x, y);

    delete &x;
    delete &y;
}
