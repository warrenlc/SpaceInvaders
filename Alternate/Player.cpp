//
// Created by warcr on 2022-12-09.
//

#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Textured.h"
#include "Movable.h"
#include "Global_Values.h"
#include "Shooting.h"


const sf::Vector2f start_position{width/2, height - 50};

std::shared_ptr<Entity> create_player() {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(start_position);
    e->type = Tag::player;
    e->add(make_shared<Textured>("player.png"));
    e->add(make_shared<Player_Movement>(800.f));
    e->add(make_shared<Player_Shooting>());
    return e;
}