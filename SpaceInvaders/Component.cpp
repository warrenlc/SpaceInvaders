//
// Created by warcr on 2022-12-09.
//

#include "Component.h"

/*
 * Base class for all components entities
 * may have.
 * */
void Component::added(Entity &){}

bool Component::update(sf::Time, Entity &, World &) { return true; }

void Component::render(sf::RenderWindow &, Entity &) {}

