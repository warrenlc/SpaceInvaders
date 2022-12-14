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
     /*   if (entities[i]->type == Tag::player) {
            player_alive = true;
        }*/
    }
   /* if (!player_alive) {
        return false;
    }*/

}

void World::render(sf::RenderWindow &window) {
    for (auto &x : entities) {
        x->render(window);
    }
   /* if (!player_alive) {

        font.loadFromFile("Gameplay.ttf");
        text.setFont(font);
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(45);
        text.setPosition(100, height/2);
        ss << "Game Over!\nPress 'Esc' to return to Menu!";
        text.setString(ss.str());
        window.draw(text);
    }*/
}

void World::add(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

/*
 * Check if two entities collide with each other.
 * */
static bool collides(Entity &a, Entity &b) {
    auto distance{a.center - b.center};
    auto lengthSq = std::pow(distance.x, 2) + std::pow(distance.y, 2);
    return lengthSq <= std::pow(a.size.x/2 + b.size.x/2, 2);
}

std::vector<std::shared_ptr<Entity>> World::collides_with(Entity &me) const {
    std::vector<std::shared_ptr<Entity>> result;

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

