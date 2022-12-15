
#include "End_State.h"
#include "Global_Values.h"
#include <sstream>

End_State::End_State(const shared_ptr<State>& win)
    : enter_pressed(false) { 
    font.loadFromFile("Gameplay.ttf");

    if (win) {
        won = true;
    } else { won = false; }
        set_entry("return to menu.", [](){ return std::make_shared<Menu_State>(); });
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

shared_ptr<State> End_State::update(sf::Time) {
    if (enter_pressed) {
        return entry.go_to_menu();
    }
    return nullptr;
}

void End_State::render(sf::RenderWindow &window) {
    if (background) {
        background->render(window);
    }
    float y{400};
    auto windowSize{window.getSize()};
    auto bounds = entry.text.getLocalBounds();
    stringstream ss;
    headline.setFont(font);
    headline.setCharacterSize(60);
    headline.setFillColor(sf::Color::Yellow);
    headline.setPosition((windowSize.x - bounds.width) /2, (y / 2));
    entry.text.setPosition((windowSize.x - bounds.width) / 2, y);
    y += bounds.height / 2.0f;

    int state = static_cast<int>(255 * entry.color);
    entry.text.setFillColor(sf::Color(state, 255, state));
    if (won) { 
        ss << "YOU WON!\n";
        headline.setString(ss.str());
    }
    else {
        ss << "YOU LOST!\n";
        headline.setString(ss.str());
    }
        ss << "Press Enter to\n";
        headline.setString(ss.str());
    window.draw(entry.text);
    window.draw(headline);

}
