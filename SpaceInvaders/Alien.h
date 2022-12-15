//
// Created by warcr on 2022-12-10.
//

#ifndef UNTITLED3_ALIEN_H
#define UNTITLED3_ALIEN_H

#include "Entity.h"

/*
 * Creates an alien Entity with given
 * start position and image file for
 * creating the sprite.
 * */

std::shared_ptr<Entity> create_alien(sf::Vector2f start_position, std::string image);
std::shared_ptr<Entity> create_alien_v2(sf::Vector2f start_position, std::string image);

#endif //UNTITLED3_ALIEN_H
