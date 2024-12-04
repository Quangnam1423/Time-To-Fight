#ifndef RESOURCE_H
#define RESOURCE_H

#include <SFML/Graphics.hpp>

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

#endif