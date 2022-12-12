//
// Created by warcr on 2022-12-11.
//

#ifndef UNTITLED3_COLLIDES_H
#define UNTITLED3_COLLIDES_H

#include "Component.h"

class Collides : public Component{

public:
    Collides(Tag collides_with);
    ~Collides() = default;
    bool update(sf::Time, Entity &e, World &world) override;
    void render(sf::RenderWindow &window, Entity &entity) override;

private:
    Tag collides_with;
    sf::CircleShape damage;
    sf::Time damage_visible;
    sf::Clock clock;
};




#endif //UNTITLED3_COLLIDES_H
