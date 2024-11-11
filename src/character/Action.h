#ifndef ACTION_H
#define ACTION_H

#include<SFML/Graphics.hpp>
#include <string>
#include <vector>

// for debug
#include <iostream>




class Action
{
public:
    Action(const std::string& filePath , int frameCount , float frameDuration);
private:
    sf::Texture m_texture;
    int m_frameCount;
    int m_currentFrame;
    float m_frameDuration;
    float m_frameSize;
    float 

}

#endif