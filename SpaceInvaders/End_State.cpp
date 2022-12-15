
#include "End_State.h"
#include "Global_Values.h"
#include <sstream>

End_State::End_State(const shared_ptr<State>& win)
    : enter_pressed(false), delay(sf::milliseconds(100)) {
    font.loadFromFile("Gameplay.ttf");


    if (win) {
        set_entry("YOU WON! return to menu.", [](){ return std::make_shared<Menu_State>(); });
    }
    else {
        set_entry("YOU LOST! return to menu.", [](){ return std::make_shared<Menu_State>(); });
    }
}

void End_State::set_entry(const string& text, Action action) {
    entry = {sf::Text{text, font, 60}, 
            0.0f, std::move(action)};
}

void End_State::on_key_press(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Return) {
        enter_pressed = true;
    }
}

shared_ptr<State> End_State::update(sf::Time time) {
    if (enter_pressed) {
        return entry.go_to_menu();
    }
    return nullptr;
}

void End_State::render(sf::RenderWindow &window) {
    if (background) {
        background->render(window);
    }
    float y{100};
    auto windowSize{window.getSize()};
    auto bounds = entry.text.getLocalBounds();
    entry.text.setPosition((windowSize.x - bounds.width) / 2, y);
    y += bounds.height * 2.0f;

    int state = static_cast<int>(255 * entry.color);
    entry.text.setFillColor(sf::Color(state, 255, state));
    window.draw(entry.text);
}