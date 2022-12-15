//
// Created by warcr on 2022-12-10.
//

#include "Shooting.h"


Player_Shooting::Player_Shooting()
: shooting_clock{} {}

bool Player_Shooting::update(sf::Time, Entity &e, World &world) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        && shooting_clock.getElapsedTime().asMilliseconds() >= 400) {
            world.add(create_player_missile(e));
            shooting_clock.restart();
    }
    return true;
}
