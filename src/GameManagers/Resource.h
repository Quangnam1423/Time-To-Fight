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
#include <filesystem>
#include <unordered_map>

#include "Singleton.h"

#define _PATH_RESOURCE "resource/"
#define _PATH_TEXTURE_FIGHTER "resource/Fighter/"
#define _PATH_TEXTURE_SAMURAI "resource/Samurai/"
#define _PATH_TEXTURE_SHINOBI "resource/Shinobi/"
#define _PATH_TEXTURE_LARGE_BUTTON "resource/largebuttons/coloredlargebuttons"
#define _PATH_TEXTURE_SQUARE_BUTTON "resource/squarebuttons/"

#define _PATH_FONT "resource/fonts/"
#define _PATH_SOUND_CHARACTER "resource/sounds/character/"
#define _PATH_SOUND_EFFECT "resource/sounds/effect/"

enum ResourceType
{
    TEXTURE = 0,
    FONT = 1, 
    ICON = 2,
    MUSIC = 3,
    FONT = 4,
    SOUND_EFFECT = 5
};


struct TexturePath
{
    enum ResourceType resourceType;
    char* texturePath;
    sf::Vector2i frameCount;
};

struct SoundPath
{
    enum ResourceType resourceType;
    char* soundPath;
    float lengthSound;
};

struct FontPath
{
    enum ResourceType resourceType;
    char* fontPath;
};

class Resource
{
public:
    Resource();
    ~Resource();
    sf::Sound* getSound(std::string soundName);
    sf::Texture* getTexture(std::string textureName);
    sf::Font* getFont(std::string fontName);

    void addSound(sf::Sound* sound, std::string soundPath);
    void addTexture(sf::Texture* texture, std::string texturePath);
    void addFont(sf::Font* font, std::string fontPath);

private:
    void init();
private:
    std::unordered_map<std::string, sf::Texture*> _TEXTURE_MAP;
    std::unordered_map<std::string, sf::Font*> _FONT_MAP;
    std::unordered_map<std::string, sf::Sound*> _SOUND_MAP;

};

#endif