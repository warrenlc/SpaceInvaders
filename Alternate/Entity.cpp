//
// Created by warcr on 2022-12-08.
//

#include "Entity.h"
#include "Component.h"

bool Entity::update(sf::Time dt, World &world) {
    bool alive = true;
    for (auto &x : components) {
        alive &= x->update(dt, *this, world);
    }
    return alive; // return if the entity is alive or dead
};

void Entity::render(sf::RenderWindow &window) {
    for (auto &x : components) {
        x->render(window, *this);
    }
}

void Entity::add(shared_ptr<Component> component) {
    component->added(*this);
    components.push_back(std::move(component));
}



