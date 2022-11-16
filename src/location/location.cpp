//
// Created by Hakan on 16.11.2022.
//

#include <iostream>
#include "location.h"

Location::Location() {

}

Location::Location(int *x, int *y) {
    this->x = x;
    this->y = y;
}

Location::Location(int x, int y) {
    this->x = new int(x);
    this->y = new int(y);
}

Location::~Location() {
    delete &this->x;
    delete &this->y;
}

int Location::getX() {
    return *this->x;
}

int Location::getY() {
    return *this->y;
}

void Location::addX(int lX) {
    *this->x += lX;
}

void Location::addY(int lY) {
    *this->y += lY;
}

void Location::setX(int lX) {
    *this->x = lX;
}

void Location::setY(int lY) {
    *this->y = lY;
}

void Location::setPosition(int lX, int lY) {
    this->setX(lX);
    this->setY(lY);
}

bool Location::operator==(Location &location) {
    return *this->x == *location.x && *this->y == *location.y;
}

bool Location::operator==(Location location) {
    return *this->x == *location.x && *this->y == *location.y;
}

Location *Location::operator=(Location location) {
    this->x = location.x;
    this->y = location.y;
    return this;
}
