//
// Created by albha on 01/12/22.
//
#ifndef SPACE_INVADERS_MOVEABLE_UNIT_H
#define SPACE_INVADERS_MOVEABLE_UNIT_H
#include "Unit.h"


class Moveable_Unit : public Unit {
public:
    Moveable_Unit(sf::Vector2f position);
    virtual void move() = 0;
    void render(sf::RenderWindow &window) override;
};




#endif //SPACE_INVADERS_MOVEABLE_UNIT_H
