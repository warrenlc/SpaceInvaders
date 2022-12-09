//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_ENEMY_H
#define SPACE_INVADERS_ENEMY_H
#include "Moveable_Unit.h"
#include "Missile.h"
#include <memory>
class Enemy : public Moveable_Unit {
private:
    int life;

protected:
    sf::Clock shooting_clock;

public:
    Enemy(sf::Vector2f pos, int hp, float direction_x);
    virtual ~Enemy();
    void shoot(sf::Time &dt) override;
    void take_damage();
    void die();

    virtual //bool shooting_open();
    bool can_shoot() override;


    void rebound_sides();

    //
    float direction_x;
};
#endif //SPACE_INVADERS_ENEMY_H
