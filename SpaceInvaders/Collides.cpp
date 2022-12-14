//
// Created by warcr on 2022-12-11.
//

#include "Collides.h"

Collides::Collides(Tag collides_with)
: collides_with{collides_with}, clock{} {
    damage.setFillColor(sf::Color::Transparent);
}

bool Collides::update(sf::Time dt, Entity &entity, World &world) {
    damage_visible -= dt;
    bool hit{false};
    if (damage_visible <= sf::Time{}) {
        damage_visible = sf::Time{};
    }
    for (auto &collision: world.collides_with(entity)) {
        if (collision->type == collides_with) {
           damage_visible = sf::milliseconds(900);
            hit = true;
            if ((collision->type == Tag::static_entity && entity.type == Tag::boss_missile)
                || (collision->type == Tag::static_entity && entity.type == Tag::alien_missile)
                || collision->type == Tag::static_entity && entity.type == Tag::player_missile) {
                return false;
            }

        }
        if (hit && clock.getElapsedTime() >= damage_visible) {
            entity.life--;
            clock.restart();
        }
    }
    return true;

}

void Collides::render(sf::RenderWindow &window, Entity &entity) {
    if (damage_visible > sf::Time{}) {
        if (entity.type == Tag::player) {
            damage.setFillColor(sf::Color(19, 246, 223, 208));
        }
        else if (entity.type == Tag::boss) {
            damage.setFillColor(sf::Color(255, 175, 14, 208));
        }
        else if (entity.type == Tag::alien
                 || entity.type  == Tag::alien_v2) {
            damage.setFillColor(sf::Color(255, 102, 255, 208));
        }
        damage.setRadius(20);
        damage.setOrigin(entity.size.x / 2, entity.size.y / 2);
        damage.setPosition(entity.center.x + 10, entity.center.y - 18);
        window.draw(damage);
    }
}