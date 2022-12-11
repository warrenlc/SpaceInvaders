//
// Created by warcr on 2022-12-09.
//

#include "Component.h"

void Component::added(Entity &){}

bool Component::update(sf::Time, Entity &, World &) { return true; }

void Component::render(sf::RenderWindow &, Entity &) {}

