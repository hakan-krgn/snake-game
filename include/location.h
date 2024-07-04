#ifndef SNAKE_GAME_LOCATION_H
#define SNAKE_GAME_LOCATION_H


class Location {
    int x{};
    int y{};

public:
    Location();

    Location(int x, int y);

    int getX() const;

    int getY() const;

    void addX(int x);

    void addY(int y);

    void setX(int x);

    void setY(int y);

    void setPosition(int x, int y);

    bool operator==(const Location *location) const;

    bool operator==(const Location &location) const;
};


#endif
