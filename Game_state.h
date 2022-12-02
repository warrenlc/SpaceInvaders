//
// Created by albha on 02/12/22.
//

#ifndef SPACE_INVADERS_GAME_STATE_H
#define SPACE_INVADERS_GAME_STATE_H
#include "State.h"
#include "world.h"

class Game_State : public State {
public:
    /**
     * Create it.
     */
    Game_State();

    /**
     * Tick all game elements.
     */
    shared_ptr<State> tick(sf::Time delta) override;

    /**
     * Draw all game elements.
     */
    void render(sf::RenderWindow &to) override;

private:
    /**
     * The game world.
     */
    World world;
};



#endif //SPACE_INVADERS_GAME_STATE_H
