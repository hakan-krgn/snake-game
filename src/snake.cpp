#include <snake.h>

Snake::Snake() {
    this->length = 1;
    this->direction = RIGHT;
    this->tail = std::vector<Location>();
    this->tail.emplace_back(0, 0);
}

int Snake::getLength() const {
    return this->length;
}

Location& Snake::getHead() {
    return this->tail.at(0);
}

Location &Snake::getTail(int index) {
    return this->tail.at(index);
}

Direction &Snake::getDirection() {
    return this->direction;
}

std::vector<Location> &Snake::getTails() {
    return this->tail;
}

void Snake::setDirection(Direction dir) {
    this->direction = dir;
}


void Snake::eatFood() {
    this->length++;
    this->tail.emplace_back(-2, -2);
}

void Snake::move() {
    int x = this->getHead().getX();
    int y = this->getHead().getY();

    switch (this->direction) {
        case UP:
            this->getHead().addY(-1);
            break;
        case DOWN:
            this->getHead().addY(1);
            break;
        case LEFT:
            this->getHead().addX(-1);
            break;
        case RIGHT:
            this->getHead().addX(1);
            break;
    }

    for (int i = 1; i < this->length; i++) {
        int tempX = this->getTail(i).getX();
        int tempY = this->getTail(i).getY();

        this->tail.at(i).setPosition(x, y);

        x = tempX;
        y = tempY;
    }
}
