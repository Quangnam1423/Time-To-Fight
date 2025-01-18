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

#include "Resource.h"
#include <SFML/Audio/SoundBuffer.hpp>

Resource::Resource()
{
    init();
}

void Resource::init()
{
    std::cout << "Resource created" << std::endl;
    return;
}

Resource::~Resource()
{
    for (auto& pair : _FONT_MAP)
    {
        if (pair.second != nullptr)
            delete pair.second;
    }
    for (auto& pair : _TEXTURE_MAP)
    {
        if (pair.second != nullptr)
            delete pair.second;
    }
    for (auto& pair : _SOUND_MAP)
    {
        if (pair.second !=nullptr)
            delete pair.second;
    }
    return;
}

bool Resource::loadResource(std::string path, enum RESOURCE_TYPE type)
{
    if (type == RESOURCE_TYPE::TEXTURE)
    {
        sf::Texture* texture = new sf::Texture();
        if (!texture->loadFromFile(path))
        {
            throw std::runtime_error("can't load texture from texture path " + path);
            return false;
        }
        addTexture(texture, path);
        return true;
    }
    else if (type == RESOURCE_TYPE::FONT)
    {
        sf::Font* font = new sf::Font();
        if (!font->loadFromFile(path))
        {
            throw std::runtime_error("can't load font from font path " + path);
            return false;
        }
        addFont(font, path);
        return true;
    }
    else if (type == RESOURCE_TYPE::SOUND)
    {
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(path))
        {
            throw std::runtime_error("can't load sound from path " + path);
            return false;
        }
        else
        {
            sf::Sound* sound = new sf::Sound();
            sound->setBuffer(buffer);
            addSound(sound, path);
            return true;
        }
    }
    else if ( type == RESOURCE_TYPE::MUSIC)
    {
        sf::Music* music = new sf::Music();
        if (!music->openFromFile(path))
        {
            throw std::runtime_error("can't open music from path " + path);
            return false;
        }
        addMusic(music, path);
        return true;
    }
    return false;
}

sf::Sound *Resource::getSound(std::string soundName)
{   
    std::string soundPath = _PATH_SOUND_EFFECT + soundName +_POST_SOUND;
    return _SOUND_MAP[soundPath];
}

sf::Texture *Resource::getTexture(std::string textureName, enum TEXTURE_TYPE type)
{
    std::string texturePath = "";
    if (type == TEXTURE_TYPE::BUTTON)
    {
        texturePath = _PATH_BUTTON + textureName + _POST_TEXTURE;
    }
    else if (type == TEXTURE_TYPE::SAMURAI)
    {
        texturePath = _PATH_SAMURAI + textureName + _POST_TEXTURE;
    }
    else if (type == TEXTURE_TYPE::SHINOBI)
    {
        texturePath = _PATH_SHINOBI + textureName + _POST_TEXTURE;
    }
    else if (type == TEXTURE_TYPE::FIGHTER)
    {
        texturePath = _PATH_FIGHTER + textureName + _POST_TEXTURE;
    }
    else if (type == TEXTURE_TYPE::ENEMY)
    {
        texturePath = _PATH_ENEMY + textureName + _POST_TEXTURE;
    }
    else if (type == TEXTURE_TYPE::ENVIROMENT)
    {
        texturePath = _PATH_ENVIROMENT + textureName + _POST_TEXTURE;
    }
    // check if the texture pointer are holded on texture map
    if (_TEXTURE_MAP.find(texturePath) == _TEXTURE_MAP.end())
    {
        if (loadResource(texturePath, RESOURCE_TYPE::TEXTURE))
        {
            std::cout << "loaded texture successfully to resource map" << std::endl;
        }
        else
        {
            std::cout << "can't load texture!" + texturePath << std::endl;
        }
    }
    return _TEXTURE_MAP[texturePath];
}

sf::Font *Resource::getFont(std::string fontName)
{
    std::string path = _PATH_FONT + fontName + _POST_FONT;
    return _FONT_MAP[path];
}

sf::Music* Resource::getMusic(std::string musicName)
{
    std::string musicPath = _PATH_MUSIC + musicName + _POST_MUSIC;
    return _MUSIC_MAP[musicPath];
}

void Resource::addSound(sf::Sound* sound, std::string soundPath)
{
    if (_SOUND_MAP.find(soundPath) == _SOUND_MAP.end())
        _SOUND_MAP[soundPath] = sound;
    else 
        return;
    return;
}

void Resource::addTexture(sf::Texture* texture, std::string texturePath)
{
    if (_TEXTURE_MAP.find(texturePath) == _TEXTURE_MAP.end())
        _TEXTURE_MAP[texturePath] = texture;
    else 
        return;
    return;
}

void Resource::addFont(sf::Font* font, std::string fontPath)
{
    if (_FONT_MAP.find(fontPath) == _FONT_MAP.end())
        _FONT_MAP[fontPath] = font;
    else 
        return;
    return;
}

void Resource::addMusic(sf::Music* music, std::string musicPath)
{
    if (_MUSIC_MAP.find(musicPath) == _MUSIC_MAP.end())
        _MUSIC_MAP[musicPath] = music;
    else
        return;
    return;
}