//
// Created by Hakan on 16.11.2022.
//

#include "location.h"

Location::Location() = default;

Location::Location(int x, int y) {
    this->x = x;
    this->y = y;
}

Location::~Location() {
    delete &this->x;
    delete &this->y;
}

int Location::getX() const {
    return this->x;
}

int Location::getY() const {
    return this->y;
}

void Location::addX(int lX) {
    this->x += lX;
}

void Location::addX(const int *lX) {
    this->x += *lX;
}

void Location::addY(int lY) {
    this->y += lY;
}

void Location::addY(const int *lY) {
    this->y += *lY;
}

void Location::setX(int lX) {
    this->x = lX;
}

void Location::setX(const int *lX) {
    this->x = *lX;
}

void Location::setY(int lY) {
    this->y = lY;
}

void Location::setY(const int *lY) {
    this->y = *lY;
}

void Location::setPosition(int lX, int lY) {
    this->x = lX;
    this->y = lY;
}

void Location::setPosition(const int *lX, const int *lY) {
    this->x = *lX;
    this->y = *lY;
}

bool Location::operator==(Location &location) const {
    return this->x == location.x && this->y == location.y;
}

bool Location::operator==(Location location) const {
    return this->x == location.x && this->y == location.y;
}

bool Location::operator==(Location *location) const {
    return this->x == location->x && this->y == location->y;
}

Location &Location::operator=(Location location) {
    this->x = location.x;
    this->y = location.y;
    return *this;
}
