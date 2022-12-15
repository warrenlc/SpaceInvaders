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

void Entity::add(std::shared_ptr<Component> component) {
    component->added(*this);
    components.push_back(std::move(component));
}

float Entity::get_top() {
    return center.y - (size.y / 2);
}

float Entity::get_bottom() {
    return center.y + (size.y / 2);
}

float Entity::get_left() {
    return center.x - (size.x / 2) ;
}

float Entity::get_right() {
    return center.x + (size.x / 2);
}


