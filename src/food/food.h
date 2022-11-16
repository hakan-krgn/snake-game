//
// Created by Hakan on 16.11.2022.
//

#ifndef SNAKE_GAME_FOOD_H
#define SNAKE_GAME_FOOD_H



#include "../location/location.h"
#include "../snake/snake.h"

class Food {
private:
    Location *location;

public:
    Food();

    ~Food();

    Location getLocation();

    void generate(Snake *snake);
};



#endif //SNAKE_GAME_FOOD_H
