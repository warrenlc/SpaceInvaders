//
// Created by warcr on 2022-12-10.
//

#include "Missile.h"
#include "Movable.h"
#include "Textured.h"
#include "Collides.h"
#include "Lives.h"



std::shared_ptr<Entity> create_player_missile(Entity &player) {
    std::shared_ptr<Entity> e
    = std::make_shared<Entity>(sf::Vector2f
            {player.center.x, player.center.y - (player.size.y / 2) - 10});
    e->type = Tag::player_missile;
    e->life = 1;
    e-> add(make_shared<Textured>("Bullet.png"));
    e-> add(make_shared<Vertical_Movement>(1000.f, -1.8f));
    e-> add(make_shared<Remove_Outside>());
    e->add(make_shared<Lives>(Tag::player_missile));
    return e;
}

std::shared_ptr<Entity> create_alien_missile(Entity &enemy) {
    std::shared_ptr<Entity> e
    = std::make_shared<Entity>(sf::Vector2f
            {enemy.center.x, enemy.center.y + 10});
    e->type = Tag::alien_missile;
    e->life = 1;
    e->add(make_shared<Textured>("Bullet.png"));
    e->add(make_shared<Vertical_Movement>(200.f, 1.8f));
    e->add(make_shared<Remove_Outside>());
    e->add(make_shared<Collides>(Tag::player));
    e->add(make_shared<Lives>(Tag::alien_missile));
    return e;
}

std::shared_ptr<Entity> create_boss_missile(Entity &boss) {
    std::shared_ptr<Entity> e
    = std::make_shared<Entity>(sf::Vector2f
            {boss.center.x, boss.center.y + (boss.center.y / 2) + 10});
    e->type = Tag::boss_missile;
    e->life = 1;
    e->add(make_shared<Textured>("Bullet.png"));
    e->add(make_shared<Vertical_Movement>(600.f, 1.8f));
    e->add(make_shared<Remove_Outside>());

    e->add(make_shared<Lives>(Tag::boss_missile));
    return e;
}


Missile_Spawner::Missile_Spawner(sf::Time spawn_interval,
                                 std::function<shared_ptr<Entity>(Entity &)> create)
        : create{create}, spawn_interval{spawn_interval}, time_left{spawn_interval} {}


bool Missile_Spawner::update(sf::Time dt, Entity &entity, World &world) {
    time_left -= dt;
    if (time_left <= sf::Time{}) {
        world.add(create(std::ref(entity)));
        time_left += spawn_interval;
    }
    return true;
}
