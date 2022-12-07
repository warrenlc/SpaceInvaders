//
// Created by albha on 02/12/22.
//
#include <stdexcept>
#include "Game.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

Game::Game()
    : texture()
    , background() {
    if (!texture.loadFromFile("background.png")) {
      throw std::logic_error ("Failed to load texture");
    }
    background.setTexture(texture);
    //background.setSize({1024, 768});
    background.setOrigin(0,10);



    background.setPosition(0, 0);

}
Game::~Game() {
    units.clear();
    std::cout << "Game destructor called\n";
}//= default;

//std::vector

void Game::run(sf::RenderWindow &window) {
    sf::Clock clock;
    /*
    sf::Time time_since_last_update = sf::Time::Zero;
    sf::Time time_per_frame = sf::seconds(1.f/60.f);
     */
    while(window.isOpen()) {

        sf::Time dt = clock.restart();

        //update();
      process_events(window);
        for (const shared_ptr<Unit>& x : units) {
            x->update(dt);
        }
        render(window);

    }
}
void Game::init() {
    units.push_back(shared_ptr<Unit>(new Building({0, 625})));
    units.push_back(shared_ptr<Unit>(new Building({385, 625})));
    units.push_back(shared_ptr<Unit>(new Building({770, 625})));
    units.push_back(shared_ptr<Unit>(new Boss({450, 10}, 3, .2f, true)));
    units.push_back(shared_ptr<Unit>(new Alien({400, 150}, 1, .2f, true)));
    units.push_back(shared_ptr<Unit>(new Alien({200, 300}, 1, .3f, true)));
    units.push_back(shared_ptr<Unit>(new Alien({0, 450}, 1, .2f, true)));
    units.push_back(shared_ptr<Unit>(new Player({0, 650})));
}

void Game::process_events(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

    }
}
/*
void Game::handle_player_input(sf::Keyboard::Key key, bool is_pressed, Player& player) {
    sf::Vector2f direction;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        direction.x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction.x += 1;
    }



    if (key == sf::Keyboard::A) {
       ;
    } else if (key == sf::Keyboard::D) {
        is_pressed = player.move_right() ;
    }
}
*/
//void Game::update() {}

void Game::render(sf::RenderWindow &window) {

    window.clear();
    window.draw(background);
    for (const shared_ptr<Unit>& x : units) {
        x->render(window);
    }
    window.display();

}
/*
void Game::quit() {
    for (Unit* x : units) {
        delete x;
    }
}
 */