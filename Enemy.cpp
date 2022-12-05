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

void Enemy::shoot() {

}

void Enemy::take_damage() {

}

void Enemy::move() {

}

void Enemy::die() {

}


void Enemy::move_left(){}
void Enemy::move_right(){}
void Enemy::stop_left(){}
void Enemy::stop_right(){}
