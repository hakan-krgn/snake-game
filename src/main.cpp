#include <iostream>
#include "game/game.h"

int main() {
    std::cout << "Please enter an area size: " << std::endl;

    int *area_size = new int;
    std::cin >> *area_size;


    Game *game = new Game(area_size);
    game->start();


    delete game;
    delete area_size;

    return 0;
}
