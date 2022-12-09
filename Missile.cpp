//
// Created by albha on 01/12/22.
//
#include "Missile.h"

Missile::Missile(sf::Vector2f position, float dir_y, bool is_from_player)
    : Moveable_Unit{position}, is_from_player{is_from_player}, direction_y{dir_y}{
    if (!texture.loadFromFile("Bullet.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(0.f,0.f);
    //background.setSize({1024, 768});
    sprite.setPosition(position);
    speed = 600.f;
}

Missile::~Missile(){}

void Missile::do_damage(){}

bool Missile::can_shoot(){return false;}

void Missile::update(sf::Time dt) {

    position.y += direction_y * speed * dt.asSeconds();
    sprite.setPosition(position);
    if (is_from_player == false) {
        direction_y = -direction_y;
    }

}
void Missile::shoot(sf::Time &dt){}; // { return false; }

