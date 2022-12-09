//
// Created by albha on 01/12/22.
//

#ifndef SPACE_INVADERS_PLAYER_H
#define SPACE_INVADERS_PLAYER_H
#include "Moveable_Unit.h"
#include "Missile.h"

class Player : public Moveable_Unit {
private:
    int life;
    sf::Clock shooting_clock;

public:
    Player(sf::Vector2f pos);
    ~Player() = default;

    void shoot(sf::Time &dt) override;
    bool can_shoot() override;
    //bool check_space_press();
    void take_damage();
    void die();
    void move_left();
    void move_right();
    void stop_right();
    void stop_left();
    sf::Vector2f find_direction(sf::Time);
    void update(sf::Time) override;


};

#endif //SPACE_INVADERS_PLAYER_H
