//
// Created by albha on 02/12/22.
//

#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H
#include <vector>
#include "Game_Object.h"
#include <SFML/Graphics.hpp>

class Game {
private:
    int level;
    bool is_running;
public:
    Game() = default;
    ~Game();
    std::vector<Game_Object*> units;
    std::vector<sf::Sprite*> unit_graphics;
    void create_objects();
    void update_game();
    void render();
    bool check_run();
    sf::RenderWindow build_world();
    void quit();

};





#endif //SPACE_INVADERS_GAME_H
