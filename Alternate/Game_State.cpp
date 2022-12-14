//
// Created by warcr on 2022-12-08.
//

#include "Game_State.h"
#include "Menu_State.h"
#include "Player.h"
#include "Alien.h"
#include "Boss.h"
#include "Global_Values.h"
#include "Static_Entity.h"

#include<fstream>


Game_State::Game_State(std::string level_file) {
    /*
     * A player, with a given position, is in the game upon initialization
     * */

    world.add(create_player());
    // Add a group of aliens
    std::ifstream ifs{level_file};
    std::string entity_type;
    std::string sprite_image;
    float x_coord;
    float y_coord;
    if (ifs) {
        while (ifs) {
            ifs >> entity_type >> sprite_image
                >> x_coord >> y_coord;
            if (entity_type == "alien") {
                for (int i{1}; i < 8; i++) {
                    world.add(create_alien({float(i * x_coord), width * y_coord}, sprite_image));
                }
            }
            if (entity_type == "alien2") {
                int coord{1};
                while (coord <= 6) {
                    world.add(create_alien_v2({float(coord * x_coord), float(coord * y_coord)}, sprite_image));
                    coord += 1;
                }
            }
            if (entity_type == "static_entity") {
                world.add(create_static_entity({width*x_coord, height*y_coord}, sprite_image));
            }
        }

    }

    /*
     * Add Aliens in a row:
     * */
/*
    for (int i{1}; i < 8; i++) {
        world.add(create_alien({float(i*120), width*0.4f}));
    }*/
    /*
     * Add aliens in a diagonal:
     * */

    /*
    int coord{1};
    while (coord <= 4) {
        world.add(create_alien_v2({float(coord*100), float(coord* 100)}));
        coord += 1;
    }
*/
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

   world.update(dt);

    // Handle pause requests from the user
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        return std::make_shared<Menu_State>(shared_from_this());

    return nullptr;
}

void Game_State::render(sf::RenderWindow &window) {
    world.render(window);
}