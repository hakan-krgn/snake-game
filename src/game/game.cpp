//
// Created by Hakan on 16.11.2022.
//

#include <iostream>
#include <conio.h>
#include <synchapi.h>
#include <valarray>
#include "game.h"

Game::Game(int area_size) {
    this->snake = new Snake();
    this->active = new bool(true);
    this->area_size = new int(area_size);
    this->food = new Food(this->snake, this->area_size);
}

Game::~Game() {
    delete this->food;
    delete this->snake;
    delete this->active;
}

void Game::start() {
    std::string input = std::string("MODE con cols=%a% lines=%b%");
    input.replace(input.find("%a%"), 3, std::to_string(*this->area_size + 2));
    input.replace(input.find("%b%"), 3, std::to_string(*this->area_size + 4));
    system(input.c_str());

    std::cout << input << std::endl;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (*this->active) {
        this->directionInput();
        this->update();
        this->draw();

        Sleep(100);
    }
}

void Game::stop() {
    *this->active = false;
}

void Game::update() {
    this->snake->move();
    this->checkCollision();
    this->checkFood();
    this->checkWin();
}

void Game::checkWin() {
    if (this->snake->getLength() == pow(*this->area_size, 2)) {
        std::cout << "You win!" << std::endl;
        this->stop();
    }
}

void Game::checkFood() {
    if (this->snake->getHead() == this->food->getLocation()) {
        this->snake->eatFood();
        this->food->generate();
    }
}

void Game::checkCollision() {
    for (int i = 1; i < this->snake->getLength(); i++) {
        if (this->snake->getHead() == this->snake->getTail(i)) {
            std::cout << "Game Over!" << std::endl;
            this->stop();
            break;
        }
    }


    if (this->snake->getHead().getX() < 0 || this->snake->getHead().getX() >= *this->area_size ||
        this->snake->getHead().getY() < 0 || this->snake->getHead().getY() >= *this->area_size) {
        std::cout << "Game Over!" << std::endl;
        this->stop();
    }
}

void Game::directionInput() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w':
                if (this->snake->getDirection() != DOWN)
                    this->snake->setDirection(UP);
                break;
            case 's':
                if (this->snake->getDirection() != UP)
                    this->snake->setDirection(DOWN);
                break;
            case 'a':
                if (this->snake->getDirection() != RIGHT)
                    this->snake->setDirection(LEFT);
                break;
            case 'd':
                if (this->snake->getDirection() != LEFT)
                    this->snake->setDirection(RIGHT);
                break;
            case 'x':
                this->stop();
                break;
        }
    }
}

void Game::draw() {
    std::cout << "\033[0;0H";

    for (int i = 0; i < *this->area_size + 2; ++i)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < *this->area_size; i++) {
        for (int j = -1; j < *this->area_size + 1; j++) {
            if (j == -1 || j == *this->area_size) {
                std::cout << "#";
            } else if (this->snake->getHead().getX() == j && this->snake->getHead().getY() == i) {
                std::cout << "@";
            } else if (this->food->getLocation().getX() == j && this->food->getLocation().getY() == i) {
                std::cout << "X";
            } else {
                bool printed = false;

                for (int k = 0; k < this->snake->getLength(); k++) {
                    if (this->snake->getTail(k).getX() == j && this->snake->getTail(k).getY() == i) {
                        std::cout << "O";
                        printed = true;
                    }
                }

                if (!printed) std::cout << " ";
            }
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < *this->area_size + 2; ++i)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << (this->snake->getLength() - 1) * 10 << std::endl;
}
