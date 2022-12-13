//
// Created by warcr on 2022-12-11.
//

#ifndef UNTITLED3_STATISTICS_H
#define UNTITLED3_STATISTICS_H

#include <string>

#include "Component.h"
#include "Entity.h"

/**
 * Display life statistics for an entity on screen
 * */

class Statistics : public Component {
public:
    Statistics(std::string font_file);
    bool update(sf::Time, Entity &e, World &world) override;
    void render(sf::RenderWindow&, Entity &e) override;

private:
    std::string font_file;
    sf::Text stats;
    sf::Font font;
};


#endif //UNTITLED3_STATISTICS_H
