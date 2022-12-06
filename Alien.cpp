////
// Created by albha on 05/12/22.
//
#include "Alien.h"
#include "Game.h"
#include <iostream>

Alien::Alien(sf::Vector2f pos, int hp, float dir_x)
: Enemy{pos, hp, dir_x}{
    if (!texture.loadFromFile("alien.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
    speed = 1000.f;
    //direction_x = .2f;
}
Alien::~Alien(){ std::cout << "Alien destructor called \n";}


void Alien::update(sf::Time dt) {
    position.x += direction_x * speed * dt.asSeconds();
    if (position.x < -140 || position.x > 770) {

    rebound_sides();

    }
    sprite.setPosition(position);
}

void Alien::change_direction(float new_direction) {
    direction_x = new_direction;
}





// Created by albha on 05/12/22.
//
