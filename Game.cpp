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
    shooters.clear();
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
        sf::Time time_per_frame = sf::seconds(1.f/60.f);
        sf::Time dt = time_per_frame;
        dt = clock.restart();

        //update();
      process_events(window);
        /*for (const shared_ptr<Moveable_Unit>& x : shooters) {
            x->update(dt);
            std::cout << "updated\n";
            if (x->shoot() == true) {
                shooters.push_back(shared_ptr<Moveable_Unit>(new Missile(x->getPosition(), -2.f, true)));
                std::cout << "shot fired\n";
            }
        }*/



        for (size_t i = 0; i < shooters.size(); i++) {
            shooters[i]->update(dt);
            if (shooters[i]->can_shoot()) {
                shared_ptr<Moveable_Unit> missile(new Missile(shooters[i]->getPosition(), -2.f, true));
                shooters.push_back(missile);
                }
           // else {
           //     shared_ptr<Moveable_Unit> missile(new Missile(shooters[i]->getPosition(), 2.f, false));
           //     shooters.push_back(missile);
           // }
        }


        render(window);
    }
}
void Game::init() {

    buildings.push_back(shared_ptr<Unit>(new Building({0, 625})));
    buildings.push_back(shared_ptr<Unit>(new Building({385, 625})));
    buildings.push_back(shared_ptr<Unit>(new Building({770, 625})));
    shooters.push_back(shared_ptr<Moveable_Unit>(new Boss({450, 10}, 3, .2f, true)));
    //units.push_back(shared_ptr<Missile>(new Missile({450,70}, .2f, false)));
    shooters.push_back(shared_ptr<Moveable_Unit>(new Alien({400, 150}, 1, .2f, true)));
    shooters.push_back(shared_ptr<Moveable_Unit>(new Alien({200, 300}, 1, .3f, true)));
    shooters.push_back(shared_ptr<Moveable_Unit>(new Alien({0, 450}, 1, .2f, true)));
    shooters.push_back(shared_ptr<Moveable_Unit>(new Player({490, 650})));





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
    for (const shared_ptr<Unit>& x : buildings) {
        x->render(window);
    }
    for (const shared_ptr<Unit>& x: shooters) {
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