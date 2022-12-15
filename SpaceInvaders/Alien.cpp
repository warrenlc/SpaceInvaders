//
// Created by warcr on 2022-12-10.
//
#include "Alien.h"
#include "Textured.h"
#include "Movable.h"
#include "Missile.h"
#include "Collides.h"
#include "Lives.h"

std::shared_ptr<Entity> create_alien(sf::Vector2f start_position, std::string image) {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(sf::Vector2f {start_position}, image);
    e->type = Tag::alien;
    e->life = 5;
    e->add(make_shared<Textured>(image));
    e->add(make_shared<Perimeter_Movement>(750.f, 200, 400, 50, 900));
    e->add(make_shared<Missile_Spawner>(sf::milliseconds(1900), &create_alien_missile));
    e->add(make_shared<Collides>(Tag::player_missile));
    e->add(make_shared<Lives>(Tag::alien));
    return e;
}

std::shared_ptr<Entity> create_alien_v2(sf::Vector2f start_position, std::string image) {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(sf::Vector2f {start_position}, image);
    e->type = Tag::alien_v2;
    e->life = 5;
    e->add(make_shared<Textured>(image));
    e->add(make_shared<Perimeter_Movement>(1200.f, 150, 350, 50, 900));
    e->add(make_shared<Missile_Spawner>(sf::milliseconds(1600), &create_alien_missile));
    e->add(make_shared<Collides>(Tag::player_missile));
    e->add(make_shared<Lives>(Tag::alien_v2));
    return e;
}
