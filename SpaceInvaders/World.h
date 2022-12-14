//
// Created by warcr on 2022-12-08.
//

#ifndef UNTITLED3_WORLD_H
#define UNTITLED3_WORLD_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include<memory>

#include "Entity.h"
#include "Global_Values.h"
#include <sstream>

class Entity;

using namespace std;
/**
 *World builds the world with the units that get added and deals with collisions. 
 */

class World {
public:
    void update(sf::Time dt);

    void render(sf::RenderWindow &window);

  /**
     * Add a unit to our world
     * */
    void add(std::shared_ptr<Entity> entity);

  /**
     * A unit checks if another unit collides with itself
     * */
    std::vector<std::shared_ptr<Entity>> collides_with(Entity &me) const;
private:
    /*
     * We need a vector of all entities in the game
     * */
    std::vector<std::shared_ptr<Entity>> entities;
    bool player_alive = false;
    sf::Text text;
    sf::Font font;
    std::stringstream ss;
};


#endif //UNTITLED3_WORLD_H
