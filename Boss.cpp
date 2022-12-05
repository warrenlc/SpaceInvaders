//
// Created by albha on 05/12/22.
//
#include "Boss.h"
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

void Boss::move() {}

void Boss::move_left() {
    is_moving_left = true;
}

void Boss::move_right() {
    is_moving_right = true;
}

void Boss::stop_left() {
    is_moving_left = false;
}

void Boss::stop_right() {
    is_moving_right = false;
}

void Boss::update(sf::Time dt) {
    position.x += direction_x * speed * dt.asSeconds();


    if ((sprite.getGlobalBounds().left <= -300) ||
    (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > 0)) {

    rebound_sides();

    }
    sprite.setPosition(position);
}



void Boss::rebound_sides() {
    direction_x  = -direction_x;

}

