//
// Created by albha on 01/12/22.
//
#include <SFML/Graphics.hpp>
#ifndef SPACE_INVADERS_OBJECT_H
#define SPACE_INVADERS_OBJECT_H



class Game_Object{

protected:
    sf::Vector2f position;
    Texture* texture;

public:
    Game_Object(sf::Vector2f position, Texture* texture );
    virtual ~Game_Object() = default;
    virtual void update() = 0;
    void render();

};

#endif //SPACE_INVADERS_OBJECT_H
