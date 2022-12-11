//
// Created by warcr on 2022-12-08.
//

#include "Game_State.h"
#include "Menu_State.h"
#include "Player.h"
#include "Alien.h"
#include "Boss.h"
#include "Missile.h"
#include "Global_Values.h"


Game_State::Game_State() {
    /*
     * A player, with a given position, is in the game upon initialization
     * */
    // Here is where we will load our stage as well...I think
    world.add(create_player());
    // Add a group of aliens

    /*
     * Add Aliens in a row:
     * */
    for (int i{0}; i < 7; i++) {
        world.add(create_alien({float(i*120), width*0.4f}));
    }
    /*
     * Add aliens in a diagonal:
     * */

    int coord{1};
    while (coord <= 4) {
        world.add(create_alien_v2({float(coord*100), float(coord* 100)}));
        coord += 1;
    }

    /* Can do a grid pattern as well, but then must handle them colliding with each other.
    for (int x{1}; x <= 4;  x++) {
        for (int y{1}; y <= 4; y++) {
            world.add(create_alien({float(x*100), float(y*100)}));
        }
    }
     */

    /*
     * Add a boss
     * */
    world.add(create_boss({width/2, height/15}));
}

shared_ptr<State> Game_State::update(sf::Time dt) {

    // We can have our aliens shoot missiles at the player from time to time.
    world.update(dt);

    // Handle pause requests from the user
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        return std::make_shared<Menu_State>(shared_from_this());

    return nullptr;
}

void Game_State::render(sf::RenderWindow &window) {
    world.render(window);
}