//
// Created by Hakan on 16.11.2022.
//

#ifndef SNAKE_GAME_FOOD_H
#define SNAKE_GAME_FOOD_H



#include "../location/location.h"
#include "../snake/snake.h"

class Food {
private:
    Snake *snake;
    Location *location;
    int *area_size;

public:
    Food(Snake *snake, int *area_size);

    ~Food();

    Location getLocation();

    void generate();
};



#endif //SNAKE_GAME_FOOD_H
