//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_MISSILE_H
#define SPACE_INVADERS_MISSILE_H
#include "Moveable_Unit.h"
class Missile : public Moveable_Unit{
private:
    bool is_from_player;
    float direction_y;

public:
    Missile(sf::Vector2f position,float dir_y, bool is_from_player);
    ~Missile();
    void do_damage();
    void update(sf::Time dt) ;

    //void collide();

};

#endif //SPACE_INVADERS_MISSILE_H
