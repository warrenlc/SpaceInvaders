//
// Created by albha on 01/12/22.
//
#ifndef SPACE_INVADERS_MOVING_OBJECT_H
#define SPACE_INVADERS_MOVING_OBJECT_H
#include "Game_Object.h"


class Moving_Object : public Game_Object {
public:
    Moving_Object(sf::Vector2f position);
    virtual void move() = 0;
};




#endif //SPACE_INVADERS_MOVING_OBJECT_H
