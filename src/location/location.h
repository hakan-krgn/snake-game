//
// Created by Hakan on 16.11.2022.
//

#ifndef SNAKE_GAME_LOCATION_H
#define SNAKE_GAME_LOCATION_H



class Location {
private:
    int *x;
    int *y;

public:
    Location();

    Location(int *x, int *y);

    Location(int x, int y);

    ~Location();

    int getX();

    int getY();

    void addX(int x);

    void addX(int *x);

    void addY(int y);

    void addY(int *y);

    void setX(int x);

    void setX(int *x);

    void setY(int y);

    void setY(int *y);

    void setPosition(int x, int y);

    void setPosition(int *x, int *y);

    bool operator==(Location &location);

    bool operator==(Location location);

    Location *operator=(Location location);
};



#endif //SNAKE_GAME_LOCATION_H
