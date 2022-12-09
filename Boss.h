//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_BOSS_H
#define SPACE_INVADERS_BOSS_H
#include "Enemy.h"
class Boss : public Enemy {
private:
    bool is_moving_right;
    sf::Clock shooting_clock;

public:
    Boss(sf::Vector2f pos, int hp, float dir_x, bool is_moving_right);
    ~Boss();
    void shoot(sf::Time &dt) override;
    bool can_shoot() override;
    void update(sf::Time) override;
    //void shoot(sf::Time &dt);
    //bool can_shoot() override;
    //bool can_shoot() override;
    //void shoot(sf::Time& dt) override;
};
#endif //SPACE_INVADERS_BOSS_H
