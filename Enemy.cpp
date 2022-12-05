//
// Created by albha on 05/12/22.
//
#include "Enemy.h"
Enemy::Enemy(sf::Vector2f pos, int hp)
: Moveable_Unit{pos}
, life{hp}{
    if (!texture.loadFromFile("Boss.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
}
Enemy::~Enemy() noexcept {}
void Enemy::shoot() {

}

void Enemy::take_damage() {

}


void Enemy::die() {

}



void Enemy::rebound_sides() {
    direction_x  = -direction_x;
}
