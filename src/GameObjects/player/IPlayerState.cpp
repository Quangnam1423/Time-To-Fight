#include "IPlayerState.h"

IPlayerState::IPlayerState(Character *character, 
                           const char *texturePath, 
                           sf::Vector2i frameCount, 
                           float timeFrame) :
            m_character(character), m_frameCount(frameCount), m_timeFrame(timeFrame)
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

void IPlayerState::handleEvent(sf::Event &event)
{
    
}

sf::IntRect IPlayerState::getCurrentFrame()
{
    m_textUV.x = m_currentFrame.x * m_frameSize.x;
    m_textUV.y = m_currentFrame.y * m_frameSize.y;
    m_intRect = sf::IntRect(m_textUV , (sf::Vector2i)m_frameSize);
    //CalculateNextFrame();
    return m_intRect;
}

void IPlayerState::reset()
{
    m_currentFrame = sf::Vector2i(0 , 0);
    m_durationTime = 0.0f;
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

sf::Texture &IPlayerState::getTexture()
{
    return this->m_texture;
}
