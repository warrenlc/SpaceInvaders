//
// Created by albha on 05/12/22.
//
#include "Boss.h"
#include "Game.h"
#include <iostream>

Boss::Boss(sf::Vector2f pos, int hp)
: Enemy{pos, hp}{
    if (!texture.loadFromFile("Boss.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
    speed = 800.f;
    direction_x = -.2f;
}
Boss::~Boss(){}


void Boss::update(sf::Time dt) {
    position.x += direction_x * speed * dt.asSeconds();
    if (position.x < -320 || position.x > 530) {

    this->rebound_sides();

    }
    sprite.setPosition(position);
}




