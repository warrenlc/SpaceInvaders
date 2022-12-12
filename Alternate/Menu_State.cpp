//
// Created by warcr on 2022-12-08.
//
#include "Menu_State.h"
#include "Game_State.h"

#include <utility>

Menu_State::Menu_State(const shared_ptr<State>& resume)
    : selected(0), enter_pressed(false), delay(sf::milliseconds(100)) {
    font.loadFromFile("Gameplay.ttf");

    if (resume) {
        /*
         * below is a lambda expression. We pass along the pointer
         * and add an entry to the "entries" vector referenced below (see void add()
         * */
        add("Resume", [resume]() { return resume; });
        background = resume;
    }
    /*
     * Add "new game" and "exit" 'Actions' to our menu 'entries'
     * */

    add("New game", []() {return std::make_shared<Game_State>(); });
    add("Exit", []() { return std::make_shared<Exit_State>(); });

}

void Menu_State::add(const string& text, Action action) {
    entries.push_back({ sf::Text{text, font, 60},
                        0.0f, std::move(action)});
}

void Menu_State::on_key_press(sf::Keyboard::Key key) {
    /*
     * Handle our keyboard inputs depending on which keys are pressed.
     * */
    switch(key) {
        case sf::Keyboard::Down:
            if (selected + 1 < entries.size()) {
                selected++;
            }
            break;
        case sf::Keyboard::Up:
            if (selected > 0) {
                selected --;
            }
            break;
        case sf::Keyboard::Return:
            enter_pressed = true;
            break;
        default:
            break;
    }
}

shared_ptr<State> Menu_State::update(sf::Time time) {
    float dt = float(time.asMicroseconds()) / float(delay.asMicroseconds());

    for (size_t i{0}; i < entries.size(); i++) {
        // A reference to an entry
        Entry &e = entries[i];

        // if we are at the selected entry
        //handle the color fading
        if (i == selected) {
            e.color += dt;
            if (e.color > 1.0f) {
                e.color = 1.0f;
            }
        } else {
            e.color -= dt;
            if (e.color < 0.0f) {
                e.color = 0.0f;
            }
        }
    }
    if (enter_pressed) {
        return entries[selected].action();
    }
    else {
        return nullptr;
    }
}

void Menu_State::render(sf::RenderWindow &window) {
    if (background) {
        background->render(window);
    }

    float y{100};

    auto windowSize{window.getSize()};

    /*
     * The loop below adjusts the text and color to fit generally
     * for most screens. We don't need to reinvent this everytime.
     * */
    for (auto &e : entries) {
        auto bounds = e.text.getLocalBounds();
        e.text.setPosition((windowSize.x - bounds.width) / 2, y);
        y += bounds.height * 2.0f;

        int state = static_cast<int>(255 * e.color);
        e.text.setFillColor(sf::Color(state, 255, state));
        window.draw(e.text);
    }
}