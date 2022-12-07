//
// Created by albha on 01/12/22.
//
#include "Unit.h"
#include <iostream>
Unit::Unit(sf::Vector2f pos)
: position{pos}
, sprite()
, texture(){}

Unit::~Unit() {
    std::cout << "Unit destructor called \n";
}//= default;

void Unit::render(sf::RenderWindow &window)  {
    sf::RectangleShape rect({sprite.getLocalBounds().width, sprite.getLocalBounds().height});
    rect.setPosition(sprite.getPosition());
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(2.0f);
    window.draw(rect);
}



//void Unit::update(std::vector) {


