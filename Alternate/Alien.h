//
// Created by warcr on 2022-12-10.
//

#ifndef UNTITLED3_ALIEN_H
#define UNTITLED3_ALIEN_H

#include "Entity.h"

std::shared_ptr<Entity> create_alien(sf::Vector2f start_position);
std::shared_ptr<Entity> create_alien_v2(sf::Vector2f start_position);

#endif //UNTITLED3_ALIEN_H
