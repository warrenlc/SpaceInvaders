//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_ENEMY_H
#define SPACE_INVADERS_ENEMY_H
#include "Moving_Object.h"

class Enemy : public Moving_Object {

    void shoot();
    void take_damage();
    virtual void move() = 0;
    void die();


};
#endif //SPACE_INVADERS_ENEMY_H
