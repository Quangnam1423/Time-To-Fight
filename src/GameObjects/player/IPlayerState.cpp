#include "IPlayerState.h"

IPlayerState::IPlayerState(Character *character, 
                           const std::string *texturePath, 
                           sf::Vector2i frameCount, 
                           float timeFrame = 0.1f) :
            m_character(character), m_frameCount(frameCount), m_timeFrame(timeFrame)
{
    if (!m_texture.loadFromFile(*texturePath))
    {
        throw std::runtime_error("can't load texture");
    }
    m_currentFrame = sf::Vector2i(0 , 0);
    CalculateFrameSize();
}

sf::IntRect IPlayerState::getCurrentFrame()
{
    m_textUV.x = m_currentFrame.x * m_frameSize.x;
    m_textUV.y = m_currentFrame.y * m_frameSize.y;
    m_intRect = sf::IntRect(m_textUV , (sf::Vector2i)m_frameSize);
    CalculateNextFrame();
    return m_intRect;
}

void IPlayerState::reset()
{
    m_currentFrame = sf::Vector2i(0 , 0);
}

void IPlayerState::CalculateNextFrame()
{
    if (m_currentFrame.x == m_frameCount.x)
    {
        if (m_currentFrame.y == m_frameCount.y)
            setStateAtTheEndFrame();
        else
        {
            m_currentFrame.y++;
            m_currentFrame.x = 0;
        }
    }
}

void IPlayerState::CalculateFrameSize()
{
    m_frameSize.x = m_texture.getSize().x / (m_frameCount.x + 1);
    m_frameSize.y = m_texture.getSize().y / (m_frameCount.y + 1);
    return;
}

sf::Texture &IPlayerState::getTexture()
{
    return this->m_texture;
}
