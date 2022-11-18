//
// Created by Hakan on 16.11.2022.
//

#ifndef SNAKE_GAME_GAME_H
#define SNAKE_GAME_GAME_H



#include "../snake/snake.h"
#include "../food/food.h"

class Game {
private:
    Food *food;
    Snake *snake;
    bool *active;
    int *area_size;

public:
    explicit Game(int area_size);

    ~Game();

    void start();

    void stop();

    void update();

    void checkWin();

    void checkFood();

    void checkCollision();

    void directionInput();

    void draw();
};



#endif //SNAKE_GAME_GAME_H
