//
// Created by warcr on 2022-12-09.
//

#ifndef UNTITLED3_MOVABLE_H
#define UNTITLED3_MOVABLE_H

#include "Component.h"
#include <functional>
#include <cmath>

/*
 * Here we have child classes of Component class
 * These different "components" represent
 * different movement patterns for entitites
 * in our game.
 * */

const int margin(Entity &e);

/**
 *Component for movement of the player. 
 */
class Player_Movement : public Component {
public:
  /**
     * The speed of the player
     * */
    Player_Movement(float speed);

    bool update(sf::Time time, Entity &e, World &world) override;

private:
    float speed;
};

/**
 * Applies to entities reaching the edge of the screen vertically.
 * Entities that go into the sky disappear. Entities that
 * crash into the ground are destroyed.
 * Entities that touch the sides cannot leave the sides.
 * */
class Remove_Outside : public Component {
public:
    Remove_Outside(float margin = 0.1f) : margin{margin} {}

    bool update(sf::Time time, Entity &e, World &world) override;

private:
    float margin;
};

/*
class Remove_After_Impact : public Component {
public:
    Remove_After_Impact() = default;
    bool update(sf::Time time, Entity &e, World &world) override;
};
*/

/**
 * Component for sideways movement of entities
 * */
class Sideways_Movement : public Component {
public:
    Sideways_Movement(float speed)
    : speed{speed}
    , direction_x{direction_x = .38f}
    , is_moving_right{is_moving_right = true} {}

    void rebound_sides();

    bool update(sf::Time, Entity &e, World &world) override;

private:
    float speed;
    float direction_x;
    bool is_moving_right;
};


/**
 * Component for downward movement of entities
 * */
class Vertical_Movement : public Component {
public:
    Vertical_Movement(float speed, float direction_y)
    : speed{speed}, direction_y{direction_y} {}

    bool update(sf::Time, Entity &e, World &world) override;

private:
    float speed;
    float direction_y;
};

/**
 * Another movement pattern that moves in a perimeter around a
 * rectangular pre-defined boundary.
 * */
class Perimeter_Movement : public Component {
public:
    Perimeter_Movement(float speed, float upper_b, float lower_b, float left_b, float right_b);
    bool update(sf::Time, Entity &e, World &world) override;
    void move_down(Entity &e);
    void move_right(Entity&);
    void move_left(Entity&);
    void move_up(Entity&);

private:
    float speed;
    float direction_x;
    float direction_y;
    float upper_b;
    float lower_b;
    float left_b;
    float right_b;
    bool is_moving_right;
    bool is_moving_down;
    bool is_moving_left;
    bool is_moving_up;

};

#endif //UNTITLED3_MOVABLE_H
