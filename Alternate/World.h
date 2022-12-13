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
    void add(shared_ptr<Entity> entity);

  /**
     * A unit checks if another unit collides with itself
     * */
    vector<shared_ptr<Entity>> collides_with(Entity &me) const;
private:
    /*
     * We need a vector of all units in the game
     * */

    vector<shared_ptr<Entity>> entities;

};


#endif //UNTITLED3_WORLD_H
