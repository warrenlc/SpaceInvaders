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

}



//void Unit::update(std::vector) {


