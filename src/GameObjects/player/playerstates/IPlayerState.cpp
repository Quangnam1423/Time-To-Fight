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

#include "IPlayerState.h"
#include "../../../GameManagers/ResourceManager.h"
#include "../../../GameManagers/WindowManager.h"
#include "../../../GameManagers/GameManager.h"

IPlayerState::IPlayerState(Character *character, 
                           const char *texturePath, 
                           sf::Vector2i frameCount, 
                           float timeFrame) :
                                    m_character(character), 
                                    m_frameCount(frameCount), 
                                    m_timeFrame(timeFrame)
{

    m_texture = *DATA->getTexture(texturePath);
    m_currentFrame = sf::Vector2i(0 , 0);
    m_durationTime = 0.0f;
    m_state = STATE::NULLST;
}

void IPlayerState::update(float deltaTime)
{

}

void IPlayerState::setStateAtTheEndFrame()
{
}

void IPlayerState::handleEvent(sf::Event &event)
{
    
}

sf::IntRect IPlayerState::getCurrentFrame()
{
    return m_frameHitboxes[m_currentFrame.x + m_currentFrame.y * (m_frameCount.x + 1)];
}

void IPlayerState::reset()
{
    m_currentFrame = sf::Vector2i(0 , 0);
}

void IPlayerState::resetDurationTime()
{
    m_durationTime = 0.0f;
}

void IPlayerState::CalculateNextFrame()
{
    if (m_currentFrame.x == m_frameCount.x)
    {
        if (m_currentFrame.y != m_frameCount.y)
        {
            m_currentFrame.y++;
            m_currentFrame.x = 0;
        }
    }
    else
    {
        m_currentFrame.x++;
    }
}

bool IPlayerState::checkEndFrame()
{
    if (m_currentFrame == m_frameCount)
        return true;
    return false;
}

void IPlayerState::setState(STATE state)
{
    m_state = state;
}

STATE IPlayerState::getState()
{
    return m_state;
}

void IPlayerState::setFrameHitboxes(std::vector<sf::IntRect>& Hitboxes)
{
    m_frameHitboxes = Hitboxes;
}


sf::Texture &IPlayerState::getTexture()
{
    return m_texture;
}
