//
// Created by warcr on 2022-12-08.
//

#ifndef UNTITLED3_ENTITY_H
#define UNTITLED3_ENTITY_H

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Component.h"
#include "Global_Values.h"

class World;
class Component;

enum class Tag : size_t {
    unknown,
    player,
    alien,
    boss,
    player_missile,
    alien_missile,
    boss_missile,
    alien_v2,
    static_entity,
};

/**
     * An Entity in our game is a 'device' or 'object' (entity, actually)
     * which is made up of various components, which can be thought of as
     * attributes or behaviors. For example, a player, boss, and alien all move.
     * They all have life. Aliens 'spawn' missiles
     * and a player decides to shoot them. A missile moves, but does not move
     * side to side, etc. A static entity, such as a stone or a building,
     * has no life. All entities have a position in the game. As such, they have
     * a center, a size. All entities have a type.
     * */
class Entity {

   
public:
  
  /**
     * By center, we really mean the position of the object. center is
     * how we reference the sprite's position.
     * */
  
    Entity(sf::Vector2f center, sf::Vector2f size = {0,0})
    : center{center}
    , size{size}
    , type{Tag::unknown}
    , life{0} {}


    sf::Vector2f center;
    sf::Vector2f size; 
    Tag type;
    int life;
  /**
   *An entity must be updated
   */
    bool update(sf::Time dt, World &world);
  /**
   * An entity must be drawn
   */
    void render(sf::RenderWindow &window);
  /**
   *We add components to an entity
   */
    void add(std::shared_ptr<Component> c); 
    void set_life(int);

    float get_top();
    float get_bottom();
    float get_right();
    float get_left();



private:
  /**
     * As every entity has a center and a size,
     * we can find the center of the edges of our entity
     * */
    std::vector<std::shared_ptr<Component>> components;

};


#endif //UNTITLED3_ENTITY_H
