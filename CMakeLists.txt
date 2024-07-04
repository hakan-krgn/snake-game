cmake_minimum_required(VERSION 3.27.8)
project(snake-game VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXE_LINKER_FLAGS "-static")

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
add_executable(snake-game ${SOURCE_FILES})

target_include_directories(snake-game PUBLIC include)
