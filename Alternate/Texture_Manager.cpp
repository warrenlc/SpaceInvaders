//
// Created by warcr on 2022-12-09.
//

#include "Texture_Manager.h"
#include<stdexcept>

using namespace std;

sf::Texture *Texture_Manager::get(const string &name) {
    auto found = instance.textures.find(name);
    if (found != instance.textures.end()) {
        return found->second.get();
    }
    auto *t = new sf::Texture();
    if (!t->loadFromFile(name)) {
        throw logic_error("Failed to load the texture!\n");
    }
    instance.textures.insert(make_pair(name, unique_ptr<sf::Texture>(t)));
    return t;
}

Texture_Manager Texture_Manager::instance;
