////
// Created by albha on 05/12/22.
//
#include "Alien.h"

#include "Game.h"q
#include <iostream>

Alien::Alien(sf::Vector2f pos, int hp, float dir_x, bool is_moving_right)
: Enemy{pos, hp, dir_x}, is_moving_right{is_moving_right} {
    if (!texture.loadFromFile("alien.png")) {
        throw std::logic_error ("Failed to load texture");
    }

    sprite.setTexture(texture);
    //background.setSize({1024, 768});
    sprite.setPosition(pos);
    speed = 3000.f;
    //direction_x = .2f;
}
Alien::~Alien(){ std::cout << "Alien destructor called \n";}

void Alien::shoot(sf::Time &dt) {

    if (shooting_clock.getElapsedTime().asSeconds() >= 2) {
        std::cout << "shoot\n";
        shooting_clock.restart();
        shooting = true;
    } else
    {
        shooting = false;
    }
}

bool Alien::can_shoot() {
    return shooting;
}


void Alien::update(sf::Time dt) {
    position.x += direction_x * speed * dt.asSeconds();
    if (position.x <= 0){
        if (!is_moving_right){
            rebound_sides();
        }
        is_moving_right = true;
    } else if (position.x >= 880) {
        if (is_moving_right){
            rebound_sides();
        }
        is_moving_right = false;
    }
    shoot(dt);
    sprite.setPosition(position);
}





// Created by albha on 05/12/22.
//
