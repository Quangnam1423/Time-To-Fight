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

IPlayerState::IPlayerState(Character *character, 
                           const char *texturePath, 
                           sf::Vector2i frameCount, 
                           float timeFrame) :
                                    m_character(character), 
                                    m_frameCount(frameCount), 
                                    m_timeFrame(timeFrame)
{
    if (!m_texture.loadFromFile(texturePath))
    {
        throw std::runtime_error("can't load texture");
    }
    m_currentFrame = sf::Vector2i(0 , 0);
    m_durationTime = 0.0f;
    CalculateFrameSize();
}

void IPlayerState::update(float deltaTime)
{

}

void IPlayerState::setStateAtTheEndFrame()
{
}

void IPlayerState::handlingEvent(sf::Event &event)
{
    
}

sf::IntRect IPlayerState::getCurrentFrame()
{
    m_textUV.x = m_currentFrame.x * m_frameSize.x;
    m_textUV.y = m_currentFrame.y * m_frameSize.y;
    m_intRect = sf::IntRect(m_textUV , (sf::Vector2i)m_frameSize);
    return m_intRect;
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



void IPlayerState::CalculateFrameSize()
{
    m_frameSize.x = m_texture.getSize().x / (m_frameCount.x + 1);
    m_frameSize.y = m_texture.getSize().y / (m_frameCount.y + 1);
    return;
}

bool IPlayerState::checkEndFrame()
{
    if (m_currentFrame == m_frameCount)
        return true;
    return false;
}


sf::Texture &IPlayerState::getTexture()
{
    return this->m_texture;
}
