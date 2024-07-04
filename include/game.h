#ifndef SNAKE_GAME_GAME_H
#define SNAKE_GAME_GAME_H


#include <snake.h>

class Game {
    bool active;
    int area_size;
    Snake snake;
    Location food;

public:
    explicit Game(int area_size);


    void start();

    void stop();

    void tick();


    void checkWin();

    void checkFood();

    void checkCollision();


    void generateFood();

    void listenDirection();


    void draw();
};


#endif
