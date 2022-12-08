//
// Created by albha on 01/12/22.
//
#include "Player.h"
#include "Missile.h"

#include <memory>
#include <iostream>
Player::Player(sf::Vector2f pos)
: Moveable_Unit(pos){
    //position = {550, 750};
    std::cout << "Creating player\n";
    life = 3;
    if(!texture.loadFromFile("player.png")){
            throw std::logic_error ("Failed to load texture");
    }
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    speed = 800.f;

    //sf::RectangleShape player{player_texture_size};
    //player.setTexture(&player_texture);
    //player.setOrigin(player_texture_size / 2.0f);

}

bool Player::shoot() {
//    Missile *missile = new Missile{position};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        //std::shared_ptr<Unit>(new Missile(this->position, -2.f, true));
        //Missile* m = new Missile(this->position, -2.f, true);
        return true;
    }
    return false;
}
/*
void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        position.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        position.x += 1;

    normalize(position);
}
*/
void Player::move_left() {
    is_moving_left = true;
}

void Player::move_right() {
    is_moving_right = true;
}

void Player::stop_right() {
    is_moving_left = false;
}

void Player::stop_left() {
    is_moving_left = false;
}

sf::Vector2f Player::find_direction(sf::Time dt){
    // Do shit
    //sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        position.x -= speed * dt.asSeconds();
        if (position.x <= 5) {
            position.x = 5;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        position.x += speed * dt.asSeconds();
        if (position.x >= 870) {
            position.x = 870;
        }
    }
    return position;
    }


void move(){

}

void Player::update(sf::Time dt) {
    sf::Vector2f direction = find_direction(dt);
    position = direction;
    bool shot = shoot();

    /*if (is_moving_left) {
        position.x -= speed * dt.asSeconds();
    }
    if (is_moving_right) {
        position.x += speed * dt.asSeconds();
    }*/

    sprite.setPosition(position);
}

