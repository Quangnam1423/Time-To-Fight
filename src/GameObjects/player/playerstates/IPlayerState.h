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

#ifndef IPLAYERSTATE_H
#define IPLAYERSTATE_H

#include <SFML/Graphics.hpp>
#include "PlayerConfigState.h"

class Character;

class IPlayerState
{
public:
    IPlayerState(Character* character, 
                const char* texturePath, 
                sf::Vector2i frameCount, 
                float timeFrame
        );


    virtual ~IPlayerState() = default;
    virtual void update(float deltaTime);                   // update state 
    virtual void setStateAtTheEndFrame();
    virtual void handlingEvent(sf::Event& event);           // handling event for current player state

    sf::IntRect getCurrentFrame();                          // get current frame
    void reset();
    void resetDurationTime();
    void CalculateNextFrame();                              // calculate m_currentFrame
    void CalculateFrameSize();
    bool checkEndFrame();

    sf::Texture& getTexture();

protected:
    Character* m_character;

    enum STATE m_playerState;

    sf::Texture m_texture;

    sf::Vector2i m_frameCount;
    sf::Vector2i m_currentFrame;
    sf::Vector2f m_frameSize;
    sf::Vector2i m_textUV;
    sf::IntRect m_intRect;
    float m_timeFrame;
    float m_durationTime;
    bool m_modeStopAtTheEndFrame;   
};


#endif