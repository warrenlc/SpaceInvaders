//
// Created by albha on 02/12/22.
//
#include <stdexcept>
#include "Game.h"
Game::Game()
    : window(sf::VideoMode (980, 768), "SFML Application")
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
    /*sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;
    sf::Time time_per_frame = sf::seconds(1.f/60.f);
     */


    while(window.isOpen()) {
       // process_events();
        //time_since_last_update += clock.restart();
        /*while (time_since_last_update > time_per_frame) {
            time_since_last_update -= time_per_frame;
            process_events();
            update(time_per_frame);
        }*/
        process_events();
        update();
        render();

    }
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

void Game::update() {
    /*bool is_moving_left;
    bool is_moving_right;

    sf::Vector2f movement(0.f, 0.f);

    if (is_moving_left){
        movement.x -= 1.f;
    }
    if (is_moving_right){
        movement.x += 1.f;
    }
    player.move(movement);
*/
}

void Game::render() {
    Building building1 = Building({0,200});
    Building building2 = Building({-400,200});
    Building building3 = Building({-700,200});
    window.clear();
    window.draw(background);
    building1.render(window);
    building2.render(window);
    building3.render(window);
    window.display();

}