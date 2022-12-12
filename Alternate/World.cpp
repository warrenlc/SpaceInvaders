//
// Created by warcr on 2022-12-08.
//

#include "World.h"
#include "Global_Values.h"

#include <iostream>

void World::update(sf::Time dt) {
    /*
     * use iterators so we can add new entities while iterating
     * */


    for (size_t i{0}; i < entities.size(); i++) {
        if (!entities[i] -> update(dt, *this)) {
            entities.erase(entities.begin() + i);
            i--;
        }
    }

}

void World::render(sf::RenderWindow &window) {
    for (auto &x : entities) {
        x->render(window);
    }
}

void World::add(shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

/*
 * Check if two entities collide with each other.
 * */
static bool collides(Entity &a, Entity &b) {
    auto distance{a.center - b.center};
    auto lengthSq = std::pow(distance.x, 2) + pow(distance.y, 2);
    return lengthSq <= pow(a.size.x/2 + b.size.x/2, 2);
}

vector<shared_ptr<Entity>> World::collides_with(Entity &me) const {
    vector<shared_ptr<Entity>> result;

    for (auto &x: entities) {
        if (x.get() == &me) {
            continue; // A unit cannot collide with itself
        }
        if (collides(*x, me)) {
            result.push_back(x);
        }
    }
    return result;
}

