//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_BOSS_H
#define SPACE_INVADERS_BOSS_H
#include "Enemy.h"
class Boss : public Enemy {
private:

public:
    Boss(sf::Vector2f pos, int hp);
    void move() override;

    void move_left() override;
    void move_right() override;
    void stop_left() override;
    void stop_right() override;
    void update(sf::Time) override;
    void rebound_sides();

};
#endif //SPACE_INVADERS_BOSS_H
