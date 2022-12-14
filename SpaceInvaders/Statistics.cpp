//
// Created by warcr on 2022-12-11.
//

#include "Statistics.h"
#include <sstream>
#include "Lives.h"

Statistics::Statistics(std::string font_file)
: font_file{font_file} {
    if (!font.loadFromFile(font_file)) {
        throw logic_error("Failed to load the font file!\n");
    }
    stats.setFont(font);
    stats.setCharacterSize(45);
    stats.setFillColor(sf::Color::Blue);
    stats.setPosition(20, 20);
}

bool Statistics::update(sf::Time, Entity &me, World &world) {
    std::stringstream ss;
    ss << "Lives left: " << me.life;
    stats.setString(ss.str());
    return true;
}

void Statistics::render(sf::RenderWindow &window, Entity &entity) {
    window.draw(stats);
}