//
// Created by warcr on 2022-12-10.
//
#include "Boss.h"
#include "Movable.h"
#include "Textured.h"
#include "Missile.h"
#include "Collides.h"
#include "Lives.h"

std::shared_ptr<Entity> create_boss(sf::Vector2f start_position) {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(sf::Vector2f {start_position}, "Boss.png");
    e->type = Tag::boss;
    e->life = 5;
    e->add(make_shared<Textured>(e->image_file));
    e->add(make_shared<Sideways_Movement>(550.f));
    e->add(make_shared<Missile_Spawner>(sf::seconds(2), &create_boss_missile));
    e->add(make_shared<Collides>(Tag::player_missile));
    e->add(make_shared<Lives>(Tag::boss));
    return e;
}
