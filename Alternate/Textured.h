//
// Created by warcr on 2022-12-09.
//

#ifndef UNTITLED3_TEXTURED_H
#define UNTITLED3_TEXTURED_H

#include "Component.h"


using namespace std;
/*
 * This file is aollection of various components
 * that deal with visual elements of the game.
 * */

class Textured : public Component {
public:
    Textured(const string& texture_name);

    void added(Entity &e) override;
    void render(sf::RenderWindow &window, Entity &e) override;

private:
    /*
     * We use sprites for our game.
     * */
    sf::Sprite sprite;
};






#endif //UNTITLED3_TEXTURED_H
