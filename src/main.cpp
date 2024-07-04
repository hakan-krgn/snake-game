#include <game.h>
#include <iostream>

int main() {
    int area_size;

    std::cout << "Please enter an area size: ";
    std::cin >> area_size;
    std::cout << std::endl;

    Game game(area_size);
    game.start();

    return 0;
}
