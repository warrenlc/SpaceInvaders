//
// Created by albha on 05/12/22.
//
#include "Boss.h"
#include "Game.h"
#include <iostream>

Boss::Boss(sf::Vector2f pos, int hp, float dir_x)
: Enemy{pos, hp, dir_x}{
    if (!texture.loadFromFile("Boss.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(0.f,0.f);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
    speed = 800.f;
    //direction_x = -.2f;
}
Boss::~Boss(){ }


void Boss::update(sf::Time dt) {
    position.x = 0;
    //position.x += position.x * speed * dt.asSeconds();
    if ((position.x < 0) || (position.x > 530)) {

    rebound_sides();

    }
    sprite.setPosition(position);
    std::cout << position.x << std::endl;
}





