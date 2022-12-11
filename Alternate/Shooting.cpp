//
// Created by warcr on 2022-12-10.
//

#include "Shooting.h"
#include <iostream>

Player_Shooting::Player_Shooting()
: shooting_clock{} {}

bool Player_Shooting::update(sf::Time dt, Entity &e, World &world) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
        && shooting_clock.getElapsedTime().asMilliseconds() >= 400) {
            world.add(create_player_missile(e));
            shooting_clock.restart();
    }
    return true;
}

/*
bool Enemy_Shooting::update(sf::Time, Entity &e, World &world) {

}
*/

/*
Missile_Spawner::Missile_Spawner(sf::Time spawn_interval,
                                 std::function<shared_ptr<Entity>(Entity &)> create)
        : create{create}, spawn_interval{spawn_interval}, time_left{spawn_interval} {}


bool Missile_Spawner::update(sf::Time dt, Entity &entity, World &world) {
    time_left -= dt;
    if (time_left <= sf::Time{}) {
        world.add(create(std::ref(entity)));
        time_left += spawn_interval;
    }
    return true;
}
 */