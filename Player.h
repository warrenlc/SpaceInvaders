//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_PLAYER_H
#define SPACE_INVADERS_PLAYER_H
#include "Moving_Object.h"
class Player : public Moving_Object {
private:
    int life;
public:
    Player(sf::Vector2f pos, int life);
    ~Player() = default;

    void shoot();
    void take_damage();
    void move() override;
    void die();
};

#endif //SPACE_INVADERS_PLAYER_H
