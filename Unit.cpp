//
// Created by albha on 01/12/22.
//
#include "Unit.h"
Unit::Unit(sf::Vector2f pos)
: position{pos}
, sprite()
, texture(){
    if (!texture.loadFromFile("Building.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
}
Unit::~Unit() {

}
void Unit::render(sf::RenderWindow &window)  {
    window.draw(sprite);
}

//void Unit::update(std::vector) {


