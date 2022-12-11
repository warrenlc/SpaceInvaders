//
// Created by warcr on 2022-12-08.
//

#ifndef UNTITLED3_GAME_STATE_H
#define UNTITLED3_GAME_STATE_H

#include "State.h"
#include "World.h"

#include <memory>

/*
 * This is where we will enter the game "world", i.e. where the game is played
 * */

class Game_State : public State {
public:
    Game_State();

    shared_ptr<State> update(sf::Time dt) override;

    void render(sf::RenderWindow &window) override;

private:
    World world;
};


#endif //UNTITLED3_GAME_STATE_H
