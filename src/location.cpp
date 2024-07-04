#include <location.h>

Location::Location() = default;

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

int Location::getX() const {
    return this->x;
}

int Location::getY() const {
    return this->y;
}

void Location::addX(int x) {
    this->x += x;
}

void Location::addY(int y) {
    this->y += y;
}

void Location::setX(int x) {
    this->x = x;
}

void Location::setY(int y) {
    this->y = y;
}

void Location::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

bool Location::operator==(const Location *location) const {
    return this->x == location->x && this->y == location->y;
}

bool Location::operator==(const Location &location) const {
    return this->x == location.x && this->y == location.y;
}
