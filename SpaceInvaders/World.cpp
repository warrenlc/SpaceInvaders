//
// Created by warcr on 2022-12-08.
//

#include "World.h"
#include "Global_Values.h"

#include <algorithm>
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
    
    auto is_player = [](shared_ptr<Entity> e){ return e->type == Tag::player; };
    auto player_found = std::find_if(begin(entities), end(entities), is_player);
    if (player_found == std::end(entities)) {
        player_alive = false;
    }
//
 /*   auto is_enemy = [](shared_ptr<Entity> e)
        { return (e->type == Tag::boss) 
                    || (e->type == Tag::alien)
                    || (e->type == Tag::alien_v2) ; };
    auto enemies_left = std::find_if(begin(entities), end(entities), is_enemy);
   // if (enemies_left == std::end(entities)) {
   //     enemies_dead = true;
  //  }*/

}

void World::render(sf::RenderWindow &window) {
    for (auto &x : entities) {
        x->render(window);
    }
    if (!player_alive) {
        std::stringstream ss;
        ss << "Game Over!\n" 
        << "You Lost!\nPress 'Esc' " 
        << "to return to Menu";
        text.setString(ss.str());
        window.draw(text);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            ss.flush();
        }
        
    }
   /* if (player_alive && enemies_dead) {
        std::stringstream ss;
        ss << "You Won!\nPress 'Esc' "
           << "to return to Menu";
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

