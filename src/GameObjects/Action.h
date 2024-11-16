#ifndef ACTION_H
#define ACTION_H

#include<SFML/Graphics.hpp>
#include <string>
#include <vector>

//#include "Character.h"

// for debug
#include <iostream>

class Character;

class Action
{
    public:
        Action(const char* filePath , int frameCount , float frameDuration , void (*animationCallback) ());
        ~Action();

        sf::IntRect getCurrentFrameRect();

        const sf::Texture& getTexture() const;
        
    private:
        //Character* mPtr_character;
        void (*mFunPtr_animationCallback)();

        sf::Texture m_texture;
        int m_frameCount;
        int m_currentFrame;
        float m_frameDuration;
        float m_frameWidth , m_frameHeight;
        //float elapsedTime; 
    private:
        void reset();
};

#endif