//
// Created by warcr on 2022-12-11.
//

#include "Static_Entity.h"
#include "Textured.h"
#include "Collides.h"

std::shared_ptr<Entity> create_static_entity(sf::Vector2f start_position) {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(sf::Vector2f{start_position});
    e->type = Tag::static_entity;
    e->add(make_shared<Textured>("building.png"));
    //e->add(make_shared<Collides>(Tag::player_missile));
    //e->add(make_shared<Collides>(Tag::alien_missile));
    //e->add(make_shared<Collides>(Tag::boss_missile));
    return e;
}