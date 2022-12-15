//
// Created by warcr on 2022-12-10.
//

#ifndef UNTITLED3_SHOOTING_H
#define UNTITLED3_SHOOTING_H

#include "Component.h"
#include "Missile.h"

/**
 * Component that handles player's shooting attribute. 
 */
class Player_Shooting : public Component {
public:
    Player_Shooting();
    bool update(sf::Time, Entity &e, World &world) override;
private:
    sf::Clock shooting_clock;
};

#endif
