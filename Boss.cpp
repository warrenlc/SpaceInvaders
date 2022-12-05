//
// Created by albha on 05/12/22.
//
#include "Boss.h"
Boss::Boss(sf::Vector2f pos, int hp)
: Enemy{pos, hp}{
    if (!texture.loadFromFile("Boss.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
}

void Boss::move() {}


