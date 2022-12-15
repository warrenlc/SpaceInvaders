//
// Created by warcr on 2022-12-08.
//
#ifndef UNTITLED3_MENU_STATE_H
#define UNTITLED3_MENU_STATE_H

#include <functional>

#include "State.h"

class Menu_State : public State {
public:
  /**
     * In Menu state we can quit or resume. 
     * Resume initialised to nullptr
     * */
    Menu_State(const shared_ptr<State>& resume = nullptr);

  /**
     * Update the state continuously
     * */
    shared_ptr<State> update(sf::Time dt) override;

  /**
     * Handle key presses
     * */
    void on_key_press(sf::Keyboard::Key key) override;

  /**
     * Draw our Menu
     * */
    void render(sf::RenderWindow &window) override;

private:
  /**
    * A wrapper for a function. We take an action
    * based on user input in the Menu State (quit or resume)
    */
    using Action = std::function<shared_ptr<State>()>;

    struct Entry{
        sf::Text text;
        /*
         *  Change color when selecting a menu item
         * */
        float color;
        /*
         * What we do
         * */
        Action action;
    };
    sf::Font font;
    /*
     * A container of our entries
     * */
    vector<Entry> entries;

    /*
     * Which key (in the vector) is selected? use size_t because we compare with
     * size of vector
     * */
    size_t selected;

    /*
     * Has the user hit "enter"?
     * */
    bool enter_pressed;

    /*
     * delay for transitions
     * */
    sf::Time delay;

    /*
     * Keep track of the game background.
     * */
    shared_ptr<State> background;
    /*
     * Expand our menu by adding menu items, actions to take, i.e. quit or resume
     * */
    void add(const string &text, Action action);
};


#endif //UNTITLED3_MENU_STATE_H
