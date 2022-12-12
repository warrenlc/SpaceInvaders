//
// Created by warcr on 2022-12-11.
//

#include "Collides.h"

Collides::Collides(Tag collides_with)
: collides_with{collides_with}, clock{} {
    damage.setFillColor(sf::Color(255, 178, 104, 208));
}

bool Collides::update(sf::Time dt, Entity &entity, World &world) {
    damage_visible -= dt;
    bool hit{false};
    if (damage_visible <= sf::Time{}) {
        damage_visible = sf::Time{};
    }
    for (auto &collision : world.collides_with(entity)) {
        if (collision->type == collides_with) {
            damage_visible = sf::milliseconds(1200);
            hit = true;
        }
    }
    if (hit && clock.getElapsedTime() >= damage_visible) {
        entity.life --;
        clock.restart();
    }
    return true;
}

void Collides::render(sf::RenderWindow &window, Entity &entity) {
    if (damage_visible > sf::Time{}) {
        if (entity.type == Tag::player) {
            damage.setFillColor(sf::Color::Cyan);
        }
        else if (entity.type == Tag::boss) {
            damage.setFillColor(sf::Color::Red);
        }
        else if (entity.type == Tag::alien
                 || entity.type  == Tag::alien_v2) {
            damage.setFillColor(sf::Color::Magenta);
        }
        damage.setRadius(60);
        damage.setOrigin(entity.size.x - 5,46);
        damage.setPosition(entity.center);
        window.draw(damage);
    }
}