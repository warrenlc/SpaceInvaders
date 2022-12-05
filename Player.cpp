//
// Created by albha on 01/12/22.
//
#include "Player.h"
#include "Missile.h"
#include "point.h"

Player::Player(sf::Vector2f pos)
: Moveable_Unit(pos){
    //position = {550, 750};
    life = 3;
    sf::Texture player_texture;
    player_texture.loadFromFile("player.png");
    sf::Vector2f player_texture_size{player_texture.getSize()};
    sf::RectangleShape player{player_texture_size};
    player.setTexture(&player_texture);
    player.setOrigin(player_texture_size / 2.0f);

}

void Player::shoot() {
    Missile *missile = new Missile{position};
}

void Player::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        position.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        position.x += 1;

    normalize(position);
}

