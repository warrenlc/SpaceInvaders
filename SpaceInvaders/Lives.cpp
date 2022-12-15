//
// Created by warcr on 2022-12-11.
//

#include "Lives.h"
#include "Collides.h"
#include "World.h"

#include <iostream>

Lives::Lives()
: counter{} {}

bool Lives::update(sf::Time, Entity &entity, World&) {
    if (entity.life == 0) {
        return false;
    }
    return true;
}
