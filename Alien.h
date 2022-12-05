//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_ALIEN_H
#define SPACE_INVADERS_ALIEN_H
#include "Enemy.h"
class Alien : public Enemy {
private:
    int life;
public:
    void move() override;
};
#endif //SPACE_INVADERS_ALIEN_H
