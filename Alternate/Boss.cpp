//
// Created by warcr on 2022-12-10.
//
#include "Boss.h"
#include "Movable.h"
#include "Textured.h"
#include "Missile.h"

std::shared_ptr<Entity> create_boss(sf::Vector2f start_position) {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(sf::Vector2f {start_position});
    e->type = Tag::boss;
   // e->is_moving_right = true;
   // e->direction_x = .18f;
    e->add(make_shared<Textured>("Boss.png"));
    e->add(make_shared<Sideways_Movement>(550.f));
    e->add(make_shared<Missile_Spawner>(sf::seconds(3), &create_boss_missile));
    return e;
}