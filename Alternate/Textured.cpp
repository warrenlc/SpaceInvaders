//
// Created by warcr on 2022-12-09.
//
#include "Textured.h"
#include "Entity.h"
#include "World.h"
#include "Texture_Manager.h"
#include "Random.h"
#include<iostream>

Textured::Textured(const std::string &texture_name) {
    sf::Texture *t = Texture_Manager::get(texture_name);
    auto size = t->getSize();
    std::cout << to_string(size.x) << std::endl;

    sprite.setScale(.5f, .5f);
    sprite.setTexture(*t);
    sprite.setOrigin(size.x / 2, size.y / 2);
}

void Textured::added(Entity &e) {
    auto size = sprite.getTexture()->getSize();
    e.size.x = max(size.y, size.x) / 2.0f;
}


void Textured::render(sf::RenderWindow &window, Entity &e) {
    sprite.setPosition(e.center);
    window.draw(sprite);
   /*
    sf::RectangleShape rect({sprite.getLocalBounds().width, sprite.getLocalBounds().height});

    rect.setPosition(sprite.getPosition());
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::Red);
    rect.setOutlineThickness(2.0f);
    window.draw(rect);
*/
}

