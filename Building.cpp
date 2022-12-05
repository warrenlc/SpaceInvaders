//
// Created by albha on 01/12/22.
//
#include "Building.h"

Building::Building(sf::Vector2f pos)
:Unit{pos}{
    if (!texture.loadFromFile("Building.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
}
Building::~Building(){}

void Building::update(sf::Time) {}

void Building::render(sf::RenderWindow &window) {
    window.draw(sprite);
}