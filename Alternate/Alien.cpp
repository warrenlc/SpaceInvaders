//
// Created by warcr on 2022-12-10.
//
#include "Alien.h"
#include <SFML/Graphics.hpp>
#include "Textured.h"
#include "Movable.h"
#include "Missile.h"
#include "Collides.h"
#include "Lives.h"

std::shared_ptr<Entity> create_alien(sf::Vector2f start_position) {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(sf::Vector2f {start_position});
    e->type = Tag::alien;
    e->add(make_shared<Textured>("alien.png"));
    e->add(make_shared<Perimeter_Movement>(750.f, 200, 400, 50, 900));
    e->add(make_shared<Missile_Spawner>(sf::seconds(2), &create_alien_missile));
    e->add(make_shared<Collides>(Tag::player_missile));
    //e->add(make_shared<Lives>(Tag::alien));
    return e;
}

std::shared_ptr<Entity> create_alien_v2(sf::Vector2f start_position) {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(sf::Vector2f {start_position});
    e->type = Tag::alien_v2;
    e->life = 4;
    e->add(make_shared<Textured>("alien_v2.png"));
    e->add(make_shared<Perimeter_Movement>(1200.f, 150, 350, 100, 700));
    e->add(make_shared<Missile_Spawner>(sf::seconds(1), &create_alien_missile));
    e->add(make_shared<Collides>(Tag::player_missile));
    e->add(make_shared<Lives>(Tag::alien_v2));
    return e;
}