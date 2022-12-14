#include <iostream>
#include "Menu_State.h"


int main() {
    sf::RenderWindow window(sf::VideoMode{1024, 768}, "Space Invaders --");
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);

    State::run(window, std::make_shared<Menu_State>(nullptr));

    return 0;
}
