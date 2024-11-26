#include "JumpState.h"
#include "Character.h"

JumpState::JumpState(const std::string *texturePath, 
                    sf::Vector2i frameCount, 
                    sf::Vector2i frameSize, 
                    float frameTime) :
    m_timeFrame(frameTime) , m_frameSize(frameSize), m_frameCount(frameCount)
{
    if (!m_texture.loadFromFile(*texturePath))
    {
        throw std::runtime_error("can't load texture!");
    }
    m_currentFrame = sf::Vector2i(0 , 0);
}

JumpState::~JumpState()
{

}

sf::IntRect JumpState::getCurrentFrame()
{
    m_textUV.x = m_currentFrame.x * m_frameSize.x;
    m_textUV.y = m_currentFrame.y * m_frameSize.y;
    m_intRect = sf::IntRect(m_textUV , (sf::Vector2i)m_frameSize);
    CaculateNextFrame();
    return m_intRect;
}

void JumpState::update(float deltaTime)
{
    
}

void JumpState::setStateAtTheEndFrame()
{
    m_character->setState(State::IDLE);
}

void JumpState::reset()
{
    m_currentFrame = sf::Vector2i(0 , 0);

}

void JumpState::CaculateNextFrame()
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

sf::Texture& JumpState::getTexture()
{
    return m_texture;
}
