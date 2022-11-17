//
// Created by Hakan on 16.11.2022.
//

#include <iostream>
#include <conio.h>
#include <synchapi.h>
#include "game.h"

Game::Game() {
    this->food = new Food();
    this->snake = new Snake();
    this->active = new bool(true);
}

Game::~Game() {
    delete &this->food;
    delete &this->snake;
    delete &this->active;
}

void Game::start() {
    system("MODE con cols=23 lines=25");
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

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
}

void Game::checkFood() {
    if (this->snake->getHead() == this->food->getLocation()) {
        this->snake->eatFood();
        this->food->generate(this->snake);
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

    if (this->snake->getHead().getX() < 0 || this->snake->getHead().getX() > 20 ||
        this->snake->getHead().getY() < 0 || this->snake->getHead().getY() > 20) {
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

    for (int i = 0; i < 23; ++i)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < 21; i++) {
        for (int j = -1; j < 22; j++) {
            if (j == -1 || j == 21) {
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

                if (!printed)
                    std::cout << " ";
            }
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < 23; ++i)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << (this->snake->getLength() - 1) * 10 << std::endl;
}
