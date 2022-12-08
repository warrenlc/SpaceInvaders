//
// Created by albha on 01/12/22.
//
#include <SFML/Graphics.hpp>
#ifndef SPACE_INVADERS_OBJECT_H
#define SPACE_INVADERS_OBJECT_H



class Unit{

protected:
    sf::Vector2f position;
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Unit(sf::Vector2f pos);
    virtual ~Unit();
    virtual void update(sf::Time) = 0;
    virtual void render(sf::RenderWindow &window);
   // virtual bool shoot();
    virtual sf::Vector2f getPosition() {
        return position;
    }
};

#endif //SPACE_INVADERS_OBJECT_H
