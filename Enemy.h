//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_ENEMY_H
#define SPACE_INVADERS_ENEMY_H
#include "Moveable_Unit.h"

class Enemy : public Moveable_Unit {
private:
    int life;

public:
    Enemy(sf::Vector2f pos, int hp);
    ~Enemy();
    void shoot();
    void take_damage();
    void die();


    void rebound_sides();

};
#endif //SPACE_INVADERS_ENEMY_H
