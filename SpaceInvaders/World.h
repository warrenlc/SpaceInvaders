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
 * World builds the world with the entities that get added 
 * and updates the entities. 
 */

class World {
public:

    World() {
        font.loadFromFile("Gameplay.ttf");
        text.setFont(font);
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(45);
        text.setPosition(100, height*0.33);
    }

    bool player_alive = true;;    

    void update(sf::Time dt);

    void render(sf::RenderWindow &window);

  /**
     * Add an entity to our world
     * */
    void add(std::shared_ptr<Entity> entity);

  /**
     * An entity checks if another entity collides with itself
     * */
    std::vector<std::shared_ptr<Entity>> collides_with(Entity &me) const;
private:
    /*
     * We need a vector of all entities in the game
     * */
    std::vector<std::shared_ptr<Entity>> entities;
    
    //bool player_alive = true;
    bool boss_alive = true;
    bool aliens_alive = true;
    sf::Text text;
    sf::Font font;
};


#endif //UNTITLED3_WORLD_H
