//
// Created by warcr on 2022-12-10.
//

#ifndef UNTITLED3_SHOOTING_H
#define UNTITLED3_SHOOTING_H
#include "Component.h"
#include "Missile.h"

class Player_Shooting : public Component {
public:
    Player_Shooting();
    bool update(sf::Time, Entity &e, World &world) override;
private:
    sf::Clock shooting_clock;
};
/*
class Enemy_Shooting : public Component {
    Enemy_Shooting() = default;
    bool update(sf::Time, Entity &e, World &world) override;
};
*/
/*
 * Component for governance of periodic firing of missiles,
 * as opposed to user-controlled firing of missiles.
 * */

/*
class Missile_Spawner : public Component {
    Missile_Spawner(sf::Time spawn_interval, std::function<shared_ptr<Entity>(Entity &)> create);

    bool update(sf::Time, Entity &entity, World &world) override;

private:
    std::function<shared_ptr<Entity>(Entity &)> create;
    sf::Time spawn_interval;
    sf::Time time_left;
};
*/
#endif //UNTITLED3_SHOOTING_H
