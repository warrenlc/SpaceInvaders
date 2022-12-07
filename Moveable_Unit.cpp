//
// Created by albha on 01/12/22.
//
#include "Moveable_Unit.h"
#include <iostream>
Moveable_Unit::Moveable_Unit(sf::Vector2f position)
: Unit{position} {
}
Moveable_Unit::~Moveable_Unit(){ std::cout << "Moveable Unit destructor called \n";}

void Moveable_Unit::render(sf::RenderWindow &window) {
    Unit::render(window);
    window.draw(sprite);
}

void Moveable_Unit::update(sf::Time dt) {

}