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
    virtual void move() = 0;
    void render(sf::RenderWindow &window) override;
    void update(sf::Time dt) override;

    virtual void move_left() = 0;
    virtual void move_right() = 0;
    virtual void stop_left() = 0;
    virtual void stop_right() = 0;

};




#endif //SPACE_INVADERS_MOVEABLE_UNIT_H
