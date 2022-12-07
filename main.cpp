#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"



int main() {
    sf::RenderWindow window{sf::VideoMode{980, 780}, "Space Invaders"};
    Game game;
    game.init();
    game.run(window);

    return 0;
}
