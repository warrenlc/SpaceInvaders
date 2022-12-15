//
// Created by warcr on 2022-12-09.
//

#ifndef UNTITLED3_TEXTURED_H
#define UNTITLED3_TEXTURED_H

#include "Component.h"


/**
 * Textured is a component for entities that
 * have a 'texture' (image). 
 */

class Textured : public Component {
public:
    Textured(const std::string& texture_name);

    void added(Entity &e) override;
    void render(sf::RenderWindow &window, Entity &e) override;

private:
    /*
     * We use sprites for our game.
     * */
    sf::Sprite sprite;
};






#endif //UNTITLED3_TEXTURED_H
