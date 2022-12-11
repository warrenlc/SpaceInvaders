//
// Created by warcr on 2022-12-09.
//

#ifndef UNTITLED3_COMPONENT_H
#define UNTITLED3_COMPONENT_H

#include "World.h"
#include "Entity.h"

class Entity;
class World;

class Component {
public:
    /*
     * Component interface. All virtual methods/destructor
     * */
    virtual ~Component() = default;

    /*
     * Why do we need this? what does it do?
     * */
    virtual void added(Entity &e);

    /*
     * update the activity of components
     * */
    virtual bool update(sf::Time dt, Entity &entity, World &world);

    /*
     * Render these functionalities
     * */
    virtual void render(sf::RenderWindow &window, Entity &entity);
};


#endif //UNTITLED3_COMPONENT_H
