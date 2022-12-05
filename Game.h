//
// Created by albha on 02/12/22.
//

#ifndef SPACE_INVADERS_GAME_H
#define SPACE_INVADERS_GAME_H
#include <vector>
#include "Unit.h"
#include "Building.h"
#include "Moveable_Unit.h"
#include "Enemy.h"
#include "Boss.h"
#include "Alien.h"
#include <memory>

//#include "Unit.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    ~Game();
    void run();
    void init();
    //void quit();
private:
    std::vector<std::shared_ptr<Unit>> units;
    sf::Texture texture;
    sf::Sprite background;


    void process_events();
    void handle_player_input(sf::Keyboard::Key key, bool is_pressed);
    //void update();
    void render();

    sf::RenderWindow window;


};





#endif //SPACE_INVADERS_GAME_H
