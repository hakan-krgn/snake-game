//
// Created by Hakan on 16.11.2022.
//

#ifndef SNAKE_GAME_LOCATION_H
#define SNAKE_GAME_LOCATION_H



#include <string>

class Location {
private:
    int x{};
    int y{};

public:
    Location();

    Location(int x, int y);

    ~Location();

    int getX() const;

    int getY() const;

    void addX(int x);

    void addX(const int *x);

    void addY(int y);

    void addY(const int *y);

    void setX(int x);

    void setX(const int *x);

    void setY(int y);

    void setY(const int *y);

    void setPosition(int x, int y);

    void setPosition(const int *x, const int *y);

    bool operator==(const Location &location) const;

    bool operator==(Location *location) const;
};



#endif //SNAKE_GAME_LOCATION_H
