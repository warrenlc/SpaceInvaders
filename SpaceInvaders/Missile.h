//
// Created by warcr on 2022-12-10.
//

#ifndef UNTITLED3_MISSILE_H
#define UNTITLED3_MISSILE_H
#include "Entity.h"
#include <functional>

  /**
   *Returns a pointer to an entity where it creates a bullet with it's special attributes when it is fired from the player. 
   */
std::shared_ptr<Entity> create_player_missile(Entity &p);
/**
   *Returns a pointer to an entity where it creates a bullet with it's special attributes when it is fired from an alien. 
   */
std::shared_ptr<Entity> create_alien_missile(Entity &a);
/**
   *Returns a pointer to an entity where it creates a bullet with it's special attributes when it is fired from the boss. 
   */
std::shared_ptr<Entity> create_boss_missile(Entity &b);

/**
 *Missile spawner handles the spawning of missiles in a time interval when boss and alien attacks. 
 */

class Missile_Spawner : public Component {
public:

    Missile_Spawner(sf::Time spawn_interval, std::function<shared_ptr<Entity>(Entity &)> create);

    bool update(sf::Time, Entity &entity, World &world) override;

private:
    std::function<shared_ptr<Entity>(Entity &)> create;
    sf::Time spawn_interval;
    sf::Time time_left;
};
#endif //UNTITLED3_MISSILE_H
