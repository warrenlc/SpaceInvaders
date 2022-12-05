//
// Created by albha on 02/12/22.
//
#include <stdexcept>
#include "Game.h"
#include <iostream>
Game::Game()
    : window(sf::VideoMode (980, 768), "Space Invaders")
    , texture()
    , background() {
    if (!texture.loadFromFile("background.png")) {
        throw std::logic_error ("Failed to load texture");
    }
    background.setTexture(texture);
    //background.setSize({1024, 768});
    background.setPosition(0.f, -10.f);

}
Game::~Game() {

}

void Game::run() {
    sf::Clock clock;
    /*
    sf::Time time_since_last_update = sf::Time::Zero;
    sf::Time time_per_frame = sf::seconds(1.f/60.f);
     */
    while(window.isOpen()) {

        sf::Time dt = clock.restart();

        //update();
        process_events();
        for (Unit* x : units) {
            x->update(dt);
        }
        render();

    }
}
void Game::init() {
    units.push_back(new Building({0, 200}));
    units.push_back(new Building({-400, 200}));
    units.push_back(new Building({-700, 200}));
    units.push_back(new Boss({20, -150}, 3));
}

void Game::process_events() {
    sf::Event event;
    while (window.pollEvent(event)) {
        //switch (event.type) {
           /* case sf::Event::KeyPressed:
                handle_player_input(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handle_player_input(event.key.code, false);
                break;
                */
            //case
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }


void Game::handle_player_input(sf::Keyboard::Key key, bool is_pressed) {
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction.x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction.x += 1;
    }



    /*bool is_moving_left;
    bool is_moving_right;
    if (key == sf::Keyboard::A) {
        is_moving_left = is_pressed;
    } else if (key == sf::Keyboard::D){
        is_moving_right = is_pressed;
    }*/
}

//void Game::update() {}

void Game::render() {

    window.clear();
    window.draw(background);
    for (Unit* x : units) {
        x->render(window);
    }
    window.display();

}
