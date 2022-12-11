//
// Created by warcr on 2022-12-08.
//

#ifndef UNTITLED3_ENTITY_H
#define UNTITLED3_ENTITY_H

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Component.h"

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
};

class Entity {

    /*
     * An Entity in our game is a 'device' or 'object' (entity, actually)
     * which is made up of various components, which can be thought of as
     * attributes or behaviors. For example, a player, boss, and alien all
     * have side to side movement. They all have life. Aliens 'spawn' missiles
     * and a player decides to shoot them. A missile moves, but does not move
     * side to side, etc.
     * */
public:

    Entity(sf::Vector2f center, sf::Vector2f size = {0,0})
    : center{center}
    , size{size}
    , type{Tag::unknown} {}
   // , direction_x{direction_x = 0.f}

    /*, is_moving_right{is_moving_right = false}
    , is_moving_left{is_moving_left = false}
    , is_moving_down{is_moving_down = false}
    , is_moving_up{is_moving_up = false} {}
*/
    /*
     * By center, we really mean the position of the object. center is
     * how we reference the sprite's position.
     * */
    sf::Vector2f center;
    sf::Vector2f size; // we want to keep track of how large these entities are.
   /* bool is_moving_right;
    bool is_moving_left;
    bool is_moving_down;  // Basis for controlling vertical movement of an entity
    bool is_moving_up;
    float direction_x;    // + or - to keep track of direction on x plane.
    float direction_y;*/    // + or - to keep track of direction in y plane.
    Tag type; // A way to keep track of what it is for an entity


    bool update(sf::Time dt, World &world); // An entity must be updated
    void render(sf::RenderWindow &window); // An entity must be drawn
    void add(std::shared_ptr<Component> c); // We add components to an entity

private:

    /*
     * The entity's components
     * */
    std::vector<std::shared_ptr<Component>> components;
};


#endif //UNTITLED3_ENTITY_H
