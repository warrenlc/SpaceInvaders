//
// Created by albha on 01/12/22.
//


#include "Unit.h"


#ifndef SPACE_INVADERS_BUILDING_H
#define SPACE_INVADERS_BUILDING_H

class Building : public Unit {
public:
    Building(sf::Vector2f pos);
    void update(sf::Time) override;
    void render(sf::RenderWindow &window) override;
};

#endif //SPACE_INVADERS_BUILDING_H
