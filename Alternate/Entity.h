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

class Entity {

    /*
     * An Entity in our game is a 'device' or 'object' (entity, actually)
     * which is made up of various components, which can be thought of as
     * attributes or behaviors. For example, a player, boss, and alien all move.
     * They all have life. Aliens 'spawn' missiles
     * and a player decides to shoot them. A missile moves, but does not move
     * side to side, etc. A static entity, such as a stone or a building,
     * has no life. All entities have a position in the game. As such, they have
     * a center, a size. All entities have a type.
     * */
public:

    Entity(sf::Vector2f center, sf::Vector2f size = {0,0})
    : center{center}
    , size{size}
    , type{Tag::unknown}
    , life{0} {}

    /*
     * By center, we really mean the position of the object. center is
     * how we reference the sprite's position.
     * */
    sf::Vector2f center;
    sf::Vector2f size; // we want to keep track of how large these entities are.
    Tag type; // A way to keep track of what it is for an entity
    int life;

    bool update(sf::Time dt, World &world); // An entity must be updated
    void render(sf::RenderWindow &window); // An entity must be drawn
    void add(std::shared_ptr<Component> c); // We add components to an entity
    void set_life(int);

    float get_top();
    float get_bottom();
    float get_right();
    float get_left();

    /*
    sf::Vector2f get_top();
    sf::Vector2f get_bottom();
    sf::Vector2f get_left();
    sf::Vector2f get_right();
*/
   // int get_life();

    //std::vector<std::shared_ptr<Component>> get_components();

private:
    /*
     * As every entity has a center and a size,
     * we can find the center of the edges of our entity
     * */
   // int life;
    std::vector<std::shared_ptr<Component>> components;

};


#endif //UNTITLED3_ENTITY_H
