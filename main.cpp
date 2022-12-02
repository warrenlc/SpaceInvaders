#include <iostream>
#include <SFML/Graphics.hpp>
#include "point.h"
#include "Moving_Object.h"
#include "Player.h"

const size_t width = 1024;
const size_t height = 768;

sf::Vector2f find_direction() {
    sf::Vector2f direction;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction.x += 1;

    return normalize(direction);
}


int main() {
    sf::RenderWindow window{sf::VideoMode{width, height}, "Demo"};
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
/*
    sf::Texture player_texture;
    player_texture.loadFromFile("player.png");
*/
    sf::Texture alien_texture;
    alien_texture.loadFromFile("alien.png");
/*
    sf::Vector2f player_texture_size{player_texture.getSize()};
    sf::RectangleShape player{player_texture_size};
    player.setTexture(&player_texture);
    player.setOrigin(player_texture_size / 2.0f);
    sf::Vector2f playerLocation{550, 750};
*/
    sf::Vector2f alien_texture_size{alien_texture.getSize()};
    sf::RectangleShape alien{alien_texture_size};
    alien.setTexture(&alien_texture);
    alien.setOrigin(alien_texture_size / 2.0f);
    sf::Vector2f alienLocation{460, 100};


    Player player{{550, 750}};

    sf::Clock clock;

    bool quit = false;
    while (!quit) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    quit = true;
                    break;
                default:
                    break;
            }
        }

        if (quit)
            break;

        sf::Vector2f direction = find_direction();

        auto delta = clock.restart();
        {
            float distance = 250.0f * delta.asSeconds();
            //playerLocation += direction * distance;
        }

        window.clear();
        alien.setPosition(alienLocation);
        //player.setPosition(playerLocation);
        window.draw(player);
        window.draw(alien);
        window.display();
    }


    return 0;
}
