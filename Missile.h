//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_MISSILE_H
#define SPACE_INVADERS_MISSILE_H
#include "Moveable_Unit.h"
class Missile : public Moveable_Unit{

public:
    Missile(sf::Vector2f position);
    void do_damage();
    void move() override;
    void collide();

};

#endif //SPACE_INVADERS_MISSILE_H
