//
// Created by warcr on 2022-12-11.
//

#ifndef UNTITLED3_LIVES_H
#define UNTITLED3_LIVES_H

#include "Component.h"
#include "Entity.h"
#include <map>


using namespace std;

/*
static const map<Tag, int> lives{ {Tag::player, 10}, {Tag::alien, 5},
                                  {Tag::alien_v2, 7}, {Tag::boss, 10},
                                  {Tag::player_missile, 1}, {Tag::boss_missile, 1},
                                  {Tag::alien_missile, 1}, {Tag::static_entity, 0} };
*/

/**
 *Lives is a component that gives the attribute to handle the amount of lives entities have. 
 */

class Lives : public Component {
public:
    Lives(Tag type);
    bool update(sf::Time dt, Entity &entity, World &world);

private:
   // int life;
    Tag type;
    sf::Clock counter;

};


#endif //UNTITLED3_LIVES_H
