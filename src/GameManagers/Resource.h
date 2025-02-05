/*
MIT License

Copyright (c) 2024 Quangnam1423

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <unordered_map>

#include "../Singleton.h"

// path for allr resource
#define _PATH_RESOURCE "resource/"
// path for charater
#define _PATH_CHARACTER "resource/characters/"
// path detail character
#define _PATH_FIGHTER "resource/characters/Fighter/"
#define _PATH_SAMURAI "resource.characters/Samurai/"
#define _PATH_SHINOBI "resource/characters/Shinobi/"

// path for others
#define _PATH_ENEMY "resource/enmies/"
#define _PATH_BUTTON "resource/buttons/"

// path for enviroment
#define _PATH_ENVIROMENT "resource/enviroment/"

// resource for font
#define _PATH_FONT "resource/fonts/"

#define _PATH_SOUND_CHARACTER "resource/soundpacket/character/"
#define _PATH_SOUND_EFFECT "resource/soundpacket/effect/"

// path for music game
#define _PATH_MUSIC "resource/soundpacket/musics/"

#define _POST_MUSIC ".mp3"
#define _POST_TEXTURE ".png"
#define _POST_FONT ".ttf"
#define _POST_SOUND ".mp3"

enum RESOURCE_TYPE
{
    TEXTURE,
    FONT, 
    MUSIC,
    SOUND
};
enum TEXTURE_TYPE
{
    BUTTON,
    SAMURAI, 
    FIGHTER,
    SHINOBI,
    ENEMY,
    ENVIROMENT,
    LOGO
};

// get instance of Resource class 
#define _RM Resource::getInstance()

class Resource : public Singleton<Resource>
{
friend class Singleton<Resource>;

public:
    Resource();
    ~Resource();

    bool loadResource(std::string path, enum RESOURCE_TYPE type);

    sf::Sound* getSound(std::string soundName);
    sf::Texture* getTexture(std::string textureName, enum TEXTURE_TYPE type);
    sf::Font* getFont(std::string fontName);
    sf::Music* getMusic(std::string musicName);

    void addSound(sf::Sound* sound, std::string soundPath);
    void addTexture(sf::Texture* texture, std::string texturePath);
    void addFont(sf::Font* font, std::string fontPath);
    void addMusic(sf::Music* music, std::string musicPath);

private:
    void init();
private:
    std::unordered_map<std::string, sf::Texture*> _TEXTURE_MAP;
    std::unordered_map<std::string, sf::Font*> _FONT_MAP;
    std::unordered_map<std::string, sf::Sound*> _SOUND_MAP;
    std::unordered_map<std::string, sf::Music*> _MUSIC_MAP;
};

#endif