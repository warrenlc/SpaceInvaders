//
// Created by albha on 01/12/22.
//
#include "Moveable_Unit.h"
Moveable_Unit::Moveable_Unit(sf::Vector2f position)
: Unit{position} {
    if (!texture.loadFromFile("Boss.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(position);
}



void Moveable_Unit::update() {}

void Moveable_Unit::render(sf::RenderWindow &window) {
    window.draw(sprite);
}