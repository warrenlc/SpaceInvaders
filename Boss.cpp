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
: Enemy{pos, hp, dir_x}{
    if (!texture.loadFromFile("Boss.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(0.f,0.f);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
    speed = 1000.f;
    //direction_x = -.2f;
}
Boss::~Boss(){ }


void Boss::update(sf::Time dt) {
    //position.x = 0;
    if (random_int(0, 100) < 50) {
        std::shared_ptr<Missile> (new Missile(position,2.f, false));
    }
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
    sprite.setPosition(position);

}
    /*if ((position.x <= 1) || (position.x >= 850)) {

    rebound_sides();

    }
    sprite.setPosition(position);
    std::cout << position.x << std::endl;
*/





