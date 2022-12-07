//
// Created by albha on 05/12/22.
//
#include "Enemy.h"
#include <iostream>
Enemy::Enemy(sf::Vector2f pos, int hp, float dir_x)
: Moveable_Unit{pos}
, direction_x{dir_x}


, life{hp}{
}




Enemy::~Enemy()  { std::cout << "Enemy destructor called \n";}

void Enemy::shoot() {

}

void Enemy::take_damage() {

}


void Enemy::die() {

}



void Enemy::rebound_sides() {
    direction_x  = -direction_x;
}


