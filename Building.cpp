//
// Created by albha on 01/12/22.
//
#include "Building.h"
#include<iostream>

Building::Building(sf::Vector2f pos)
:Unit{pos}{
    if (!texture.loadFromFile("building.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
}
Building::~Building(){ std::cout << "Building destructor called \n";}

void Building::update(sf::Time) {}

void Building::render(sf::RenderWindow &window){
    Unit::render(window);
   // sprite.setPosition(0, 1.9*sprite.getLocalBounds().height);
    window.draw(sprite);
}