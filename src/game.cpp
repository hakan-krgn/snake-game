#include <cmath>
#include <game.h>
#include <thread>
#include <iostream>
#include <termios.h>

Game::Game(const int area_size) {
    this->active = true;
    this->snake = Snake();
    this->area_size = area_size;
    this->generateFood();
}


void Game::start() {
    std::thread thr([this] { listenDirection(); });
    srand(static_cast<unsigned>(time(nullptr)));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (this->active) {
        this->tick();
        this->draw();

        if (!this->active)
            exit(0);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void Game::stop() {
    this->active = false;
}

void Game::tick() {
    this->snake.move();
    this->checkCollision();
    this->checkFood();
    this->checkWin();
}


void Game::checkWin() {
    if (this->snake.getLength() == std::pow(this->area_size, 2)) {
        std::cout << "You win!" << std::endl;
        this->stop();
    }
}

void Game::checkFood() {
    if (this->snake.getHead() == this->food) {
        this->snake.eatFood();
        this->generateFood();
    }
}

void Game::checkCollision() {
    for (int i = 1; i < this->snake.getLength(); i++) {
        if (this->snake.getHead() == this->snake.getTail(i)) {
            std::cout << "Game Over!" << std::endl;
            this->stop();
            break;
        }
    }

    if (this->snake.getHead().getX() < 0 || this->snake.getHead().getX() >= this->area_size ||
        this->snake.getHead().getY() < 0 || this->snake.getHead().getY() >= this->area_size) {
        std::cout << "Game Over!" << std::endl;
        this->stop();
    }
}


void Game::generateFood() {
    const int x = rand() % this->area_size;
    const int y = rand() % this->area_size;

    for (const Location &tail: this->snake.getTails()) {
        if (tail.getX() == x && tail.getY() == y) {
            this->generateFood();
            return;
        }
    }

    this->food = Location(x, y);
}

void Game::listenDirection() {
    termios new_termios{};
    tcgetattr(0, &new_termios);
    new_termios.c_lflag &= ~ICANON;
    new_termios.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new_termios);

    while (true) {
        switch (getchar()) {
            case 'w':
                if (this->snake.getDirection() != DOWN)
                    this->snake.setDirection(UP);
                break;
            case 's':
                if (this->snake.getDirection() != UP)
                    this->snake.setDirection(DOWN);
                break;
            case 'a':
                if (this->snake.getDirection() != RIGHT)
                    this->snake.setDirection(LEFT);
                break;
            case 'd':
                if (this->snake.getDirection() != LEFT)
                    this->snake.setDirection(RIGHT);
                break;
            case 'x':
                this->stop();
                break;
            default: break;
        }
    }
}


void Game::draw() {
    std::cout << "\033[0;0H";

    for (int i = 0; i < this->area_size + 2; ++i)
        std::cout << "#";
    std::cout << std::endl;

    for (int i = 0; i < this->area_size; i++) {
        for (int j = -1; j < this->area_size + 1; j++) {
            if (j == -1 || j == this->area_size) {
                std::cout << "#";
            } else if (this->snake.getHead().getX() == j && this->snake.getHead().getY() == i) {
                std::cout << "@";
            } else if (this->food.getX() == j && this->food.getY() == i) {
                std::cout << "X";
            } else {
                bool printed = false;

                for (int k = 0; k < this->snake.getLength(); k++) {
                    if (this->snake.getTail(k).getX() == j && this->snake.getTail(k).getY() == i) {
                        std::cout << "O";
                        printed = true;
                    }
                }

                if (!printed) std::cout << " ";
            }
        }

        std::cout << std::endl;
    }

    for (int i = 0; i < this->area_size + 2; ++i)
        std::cout << "#";
    std::cout << std::endl;

    std::cout << "Score: " << (this->snake.getLength() - 1) * 10 << std::endl;
}
