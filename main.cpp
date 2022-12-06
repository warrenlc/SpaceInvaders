#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"



int main() {
    sf::RenderWindow window{sf::VideoMode{1980, 1000}, "Space Invaders"};
    Game game;
    game.init();
    game.run(window);

    return 0;
}
