//
// Created by albha on 01/12/22.
//
#include <SFML/Graphics.hpp>
#ifndef SPACE_INVADERS_OBJECT_H
#define SPACE_INVADERS_OBJECT_H



class Object {

protected:
    sf::Vector2f position;

public:
    Object(sf::Vector2f position);
    virtual ~Object() = default;

    virtual void update();
};

#endif //SPACE_INVADERS_OBJECT_H
