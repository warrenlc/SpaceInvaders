//
// Created by warcr on 2022-12-09.
//
#ifndef UNTITLED3_TEXTURE_MANAGER_H
#define UNTITLED3_TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

/*
 * Manages our textures, so they are loaded only once.
 * */

using namespace std;

class Texture_Manager {
public:
    // We load a texture
    static sf::Texture *get(const string &name);

private:
    
    Texture_Manager() = default;
    /*
    * We want only one instance of this class
    * */
    static Texture_Manager instance;

    /*
     *  A container for our textures, with a name of the texture to
     *  be loaded and a pointer to this texture.
     *  Use a unique_ptr to disallow copying or anything else
     *  pointing to this
     *  */
    std::map<string, std::unique_ptr<sf::Texture>> textures;
};

#endif //UNTITLED3_TEXTURE_MANAGER_H
