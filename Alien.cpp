////
// Created by albha on 05/12/22.
//
#include "Alien.h"
#include "Game.h"
#include <iostream>

Alien::Alien(sf::Vector2f pos, int hp)
: Enemy{pos, hp}{
    if (!texture.loadFromFile("alien.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
    speed = 800.f;
    direction_x = .2f;
}
Alien::~Alien(){}


void Alien::update(sf::Time dt) {
    position.x += direction_x * speed * dt.asSeconds();
    if (position.x < -140|| position.x > 770) {

    this->rebound_sides();

    }
    sprite.setPosition(position);
}






// Created by albha on 05/12/22.
//
