//
// Created by warcr on 2022-12-08.
//

#ifndef UNTITLED3_STATE_H
#define UNTITLED3_STATE_H

#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;

class State : public enable_shared_from_this<State> {
    /* From cpp Reference:
     * std::enable_shared_from_this allows an object t that
     * is currently managed by a std::shared_ptr named pt to
     * safely generate additional std::shared_ptr instances
     * pt1, pt2, ... that all share ownership of t with pt.
     *
     * Publicly inheriting from std::enable_shared_from_this<T>
     * provides the type T with a member function shared_from_this.
     * If an object t of type T is managed by a std::shared_ptr<T>
     * named pt, then calling T::shared_from_this will return a
     * new std::shared_ptr<T> that shares ownership of t with pt.
     *
     * Ger oss ett enkelt sätt att ha olika instanser av State att peka på State...
     * Tror jag...
     * */

public:
    /*
     * Create a state of the game
     * */
    State();

    /*
     * Destroy a state of the game
     * */
    virtual ~State();

    /*
     * Do something when a key is pressed.
     * */
    virtual void on_key_press(sf::Keyboard::Key key);

    /*
     * Do something when a key is release.
     * */
    virtual void on_key_release(sf::Keyboard::Key key);

    /*
     * Update the game state, return a pointer to a state.
     * */
    virtual shared_ptr<State> update(sf::Time dt) = 0;

    /*
     * For displaying our game window
     * */
    virtual void render(sf::RenderWindow &window) = 0;

    /*
     * Given a window reference and a pointer to
     * a state of the game, "run" that state
     * */
    static void run(sf::RenderWindow &window, shared_ptr<State> state);
};

class Exit_State : public State {
    /*
     * An exit state is what we use to leave a state safely.
     * It is a child of the more general State class.
     * */

public:

    /*
     * Given a timestamp, return a nullptr to a state.
     * */
    shared_ptr<State> update(sf::Time) { return nullptr; }

    /*
     * Given a reference to a window, draw this window.
     * */
    void render(sf::RenderWindow& ){}


};


#endif //UNTITLED3_STATE_H
