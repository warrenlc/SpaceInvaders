//
// Created by warcr on 2022-12-09.
//

#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Textured.h"
#include "Movable.h"
#include "Global_Values.h"
#include "Shooting.h"
#include "Collides.h"
#include "Lives.h"
#include "Statistics.h"


const sf::Vector2f start_position{width/2, height - 50};


std::shared_ptr<Entity> create_player() {
    std::shared_ptr<Entity> e = std::make_shared<Entity>(start_position, "player.png");
    e->type = Tag::player;
    e->life = 10;
    e->add(make_shared<Textured>(e->image_file));
    e->add(make_shared<Player_Movement>(800.f));
    e->add(make_shared<Player_Shooting>());
    e->add(make_shared<Collides>(Tag::boss_missile));
   // e->add(make_shared<Collides>(Tag::alien_missile));
   // e->add(make_shared<Lives>(Tag::player));
   // e->add(make_shared<Statistics>("Gameplay.ttf"));
    return e;
}
