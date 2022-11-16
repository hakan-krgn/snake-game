cmake_minimum_required(VERSION 3.23)
project(snake_game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(snake_game
        src/main.cpp
        src/snake/snake.cpp
        src/snake/snake.h
        src/location/location.cpp
        src/location/location.h
        src/game/game.cpp
        src/game/game.h
        src/food/food.cpp
        src/food/food.h)
