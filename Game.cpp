//
// Created by albha on 02/12/22.
//
#include "Game.h"
Game::~Game() {

}

void Game::create_objects(int level) {

}

sf::RenderWindow Game::build_world() {
    sf::RenderWindow window{sf::VideoMode{1050, 600}, "Demo"};
    return window;
}