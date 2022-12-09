//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_ALIEN_H
#define SPACE_INVADERS_ALIEN_H
#include "Enemy.h"
class Alien : public Enemy {
private:
    bool is_moving_right;

public:
   Alien(sf::Vector2f pos, int hp, float dir_x, bool is_moving_right);
    ~Alien();

    void update(sf::Time) override;
    void shoot(sf::Time &dt) override;
    bool can_shoot() override;
};
#endif //SPACE_INVADERS_ALIEN_H
