//
// Created by warcr on 2022-12-09.
//
#include "Movable.h"
#include "World.h"
#include "Entity.h"
#include "Global_Values.h"
#include <iostream>

const int margin(Entity &e) { return (e.size.x/2) + 5; }

Player_Movement::Player_Movement(float speed)
:speed{speed} {}

sf::Vector2f find_direction() {
    sf:: Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction.x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
        || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction.x += 1;
    }
    return direction;
}

bool Player_Movement::update(sf::Time dt, Entity &entity, World &world) {

    sf::Vector2f direction = find_direction();
    entity.center += direction * speed * dt.asSeconds();
    if (entity.center.x <= margin(entity)) {
        entity.center.x = margin(entity);
    }
    if (entity.center.x >= width - margin(entity)) {
        entity.center.x = width - margin(entity);
    }
    return true;
}

bool Remove_Outside::update(sf::Time, Entity &entity, World &world) {
    if (entity.type != Tag::player) {
        if (entity.center.y < margin) {
            return false;
        }
        if (entity.center.y > height + margin) {
            return false;
        }
        return true;
    }
    return true;
}

/*
bool Remove_After_Impact::update(sf::Time, Entity &entity, World &world) {
    if (w)
}
*/

void Sideways_Movement::rebound_sides() {
    direction_x = -direction_x;
}

bool Sideways_Movement::update(sf::Time dt, Entity &entity, World &world) {
    // Entity moving sideways cannot be moved outside the screen

    entity.center.x += direction_x * speed * dt.asMicroseconds() / 1000000.0f;
    if (entity.center.x <= margin(entity)) {
        if (!is_moving_right) {
            rebound_sides();
        }
        is_moving_right = true;
    } else if (entity.center.x >= width - margin(entity)) {
        if (is_moving_right) {
            rebound_sides();
        }
        is_moving_right = false;
    }
    return true;
}

bool Vertical_Movement::update(sf::Time dt, Entity &e, World &world) {
    e.center.y += direction_y * speed * dt.asSeconds();
    return true;
}

Perimeter_Movement::Perimeter_Movement(float speed, float upper_b, float lower_b, float left_b, float right_b)
        : speed{speed}
        , direction_x{direction_x = .38f}
        , direction_y{direction_y = -.38f}
        , is_moving_right{is_moving_right = true}
        , is_moving_down{is_moving_down = false}
        , is_moving_left{is_moving_left = false}
        , is_moving_up{is_moving_up = false}
        , upper_b{upper_b}
        , lower_b{lower_b}
        , left_b{left_b}
        , right_b{right_b} {}

bool Perimeter_Movement::update(sf::Time dt, Entity &entity, World &world) {
    if (is_moving_right) {
        entity.center.x +=
                direction_x *
                speed * dt.asSeconds();
    }
    else if (is_moving_down) {
        entity.center.y +=
                direction_y *
                speed * dt.asSeconds();
    }
    else if (is_moving_left) {
        entity.center.x +=
                direction_x *
                speed * dt.asSeconds();
    }

    else if (is_moving_up) {
        entity.center.y +=
                direction_y *
                speed * dt.asSeconds();
    }

    if (entity.center.x >= right_b && is_moving_right) {
        move_down(entity);
    }
    if (entity.center.y >= lower_b && is_moving_down) {
        move_left(entity);
    }
    if (entity.center.x <= left_b && is_moving_left) {
        move_up(entity);
    }
    if (entity.center.y <= upper_b && is_moving_up) {
        move_right(entity);
    }
    return true;
}

void Perimeter_Movement::move_down(Entity &entity) {
    entity.center.x = right_b;
    direction_y = -direction_y;
    is_moving_right = false;
    is_moving_down = true;
}

void Perimeter_Movement::move_left(Entity &entity) {
    entity.center.y = lower_b;
    direction_x = -direction_x;
    is_moving_down = false;
    is_moving_left = true;
}

void Perimeter_Movement::move_up(Entity &entity) {
    entity.center.x = left_b;
    direction_y = -direction_y;
    is_moving_left = false;
    is_moving_up = true;
}

void Perimeter_Movement::move_right(Entity &entity) {
    entity.center.y = upper_b;
    direction_x = -direction_x;
    is_moving_up = false;
    is_moving_right = true;
}
