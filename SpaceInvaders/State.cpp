//
// Created by warcr on 2022-12-08.
//
#include "State.h"

State::State()= default;

State::~State()= default;

void State::on_key_press(sf::Keyboard::Key key) {}
void State::on_key_release(sf::Keyboard::Key key) {}
void State::run(sf::RenderWindow &window, shared_ptr<State> state) {
    sf::Clock clock;

    while (state) { // while a state is not nullptr
        sf::Event event;
        while (window.pollEvent(event)) { // while our window is checking for events that occur
            switch (event.type) {
                case sf::Event::Closed: // Exit the function if the window closes
                    return;
                case sf::Event::KeyPressed: // Process the event of a certain key being pressed
                    state->on_key_press(event.key.code);
                    break;
                case sf::Event::KeyReleased: // Process the event of a certain key being released
                    state->on_key_release(event.key.code);
                    break;
                default:
                    break;
            }
        }
        window.clear(); // Clear the window to change states
        if (auto new_state = state->update(clock.restart())) {
            if (std::dynamic_pointer_cast<Exit_State>(new_state)) { //
                // use dynamic_pointer_cast because new_state might be nullptr (exit the state)
                return;
            } else { // or make a new state
                state = new_state;
            }
            continue;
        }
        // Render the window for the current state and display.
        state->render(window);
        window.display();
    }
}
