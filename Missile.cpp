//
// Created by albha on 01/12/22.
//
#include "Missile.h"

Missile::Missile(sf::Vector2f position, bool is_from_player)
    : Moveable_Unit{position}, is_from_player{is_from_player} {}

Missile::~Missile(){}

void Missile::do_damage(){}

void Missile::update(sf::Time dt) {


}


