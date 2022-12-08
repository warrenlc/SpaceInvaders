//
// Created by albha on 01/12/22.
//
#ifndef SPACE_INVADERS_MOVEABLE_UNIT_H
#define SPACE_INVADERS_MOVEABLE_UNIT_H
#include "Unit.h"


class Moveable_Unit : public Unit {
protected:
    float speed;
    bool is_moving_right = false;
    bool is_moving_left = false;
    float direction_x;
    float direction_y;

public:
    Moveable_Unit(sf::Vector2f position);
    virtual ~Moveable_Unit() ;
    void render(sf::RenderWindow &window) override;
    void update(sf::Time dt) override;
    virtual bool shoot() = 0;

};




#endif //SPACE_INVADERS_MOVEABLE_UNIT_H
