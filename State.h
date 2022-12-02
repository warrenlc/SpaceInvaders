//
// Created by albha on 02/12/22.
//

#ifndef SPACE_INVADERS_STATE_H
#define SPACE_INVADERS_STATE_H
#include <memory>
#include <SFML/Graphics.hpp>
using std::shared_ptr;

class State : public std::enable_shared_from_this<State> {
public:
    /**
     * Default creation.
     */
    State();

    /**
     * Make sure the destructor is virtual.
     */
    virtual ~State();

    /**
     * Called when a key is pressed.
     */
    virtual void on_key_press(sf::Keyboard::Key key);

    /**
     * Called when a key is released.
     */
    virtual void on_key_release(sf::Keyboard::Key key);

    /**
     * Called before each screen refresh. May switch states.
     */
    virtual shared_ptr<State> tick(sf::Time time) = 0;

    /**
     * Called to draw the screen.
     */
    virtual void render(sf::RenderWindow &to) = 0;

    /**
     * Run a state, handling state-switches, until completion.
     */
    static void run(sf::RenderWindow &window, shared_ptr<State> state);
};

/**
 * Special state used to indicate that we should exit.
 */
class Exit_State : public State {
public:
    shared_ptr<State> tick(sf::Time) { return nullptr; }
    void render(sf::RenderWindow &) {}
};


#endif //SPACE_INVADERS_STATE_H
