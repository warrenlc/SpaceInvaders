//
// Created by albha on 05/12/22.
//
#include "Boss.h"
#include "Game.h"
#include "Missile.h"
#include "Random.h"
#include <memory>
#include <iostream>

Boss::Boss(sf::Vector2f pos, int hp, float dir_x, bool is_moving_right)
: Enemy{pos, hp, dir_x},shooting_clock{}, is_moving_right{is_moving_right}{
    if (!texture.loadFromFile("Boss.png")) {
        throw std::logic_error ("Failed to load texture");
    }

    sprite.setTexture(texture);
    sprite.setOrigin(0.f,0.f);
    sprite.setPosition(pos);
    speed = 1000.f;
    //direction_x = -.2f;
    //background.setSize({1024, 768});
}
Boss::~Boss(){ }

void Boss::shoot(sf::Time &dt) {

    if (shooting_clock.getElapsedTime().asSeconds() >= 3) {
        std::cout << "shoot\n";
        shooting_clock.restart();
        shooting = true;
    } else
    {
        shooting = false;
    }
}

bool Boss::can_shoot() {
    return shooting;
}

void Boss::update(sf::Time dt) {
    position.x += direction_x * speed * dt.asSeconds();
    if (position.x <= 0){
        if (!is_moving_right){
            rebound_sides();
        }
        is_moving_right = true;
    } else if (position.x >= 850) {
        if (is_moving_right){
            rebound_sides();
        }
        is_moving_right = false;
    }
    shoot(dt);
    sprite.setPosition(position);
}

    /*if ((position.x <= 1) || (position.x >= 850)) {

    rebound_sides();

    }
    sprite.setPosition(position);
    std::cout << position.x << std::endl;
*/





