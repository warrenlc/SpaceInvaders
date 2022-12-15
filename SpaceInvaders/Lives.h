//
// Created by warcr on 2022-12-11.
//

#ifndef UNTITLED3_LIVES_H
#define UNTITLED3_LIVES_H

#include "Component.h"
#include "Entity.h"
#include <map>


using namespace std;
/**
 *Lives is a component that gives the attribute to 
 handle the amount of lives entities have. 
 */

class Lives : public Component {
public:
    Lives(Tag type);
    bool update(sf::Time dt, Entity &entity, World &world);

private:
    Tag type;
    sf::Clock counter;
};


#endif //UNTITLED3_LIVES_H
