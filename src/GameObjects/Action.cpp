#include "Action.h"

Action::Action(const char* filePath ,const int frameCount , float frameDuration , void (*animationCallback)())
    :m_frameCount(frameCount) , m_frameDuration(frameDuration) , mFunPtr_animationCallback(animationCallback)
{
    if(!m_texture.loadFromFile(filePath))
    {
        throw std::runtime_error("Unable to load texture!");
    }
    m_frameWidth = m_texture.getSize().x / m_frameCount;
    m_frameHeight = m_texture.getSize().y;

}

const sf::Texture& Action::getTexture() const{
    return m_texture;
}

sf::IntRect Action::getCurrentFrameRect(){
    if (m_currentFrame >= m_frameCount)
    {
        reset();
        (*mFunPtr_animationCallback)();
    }
    return sf::IntRect(m_currentFrame * m_frameWidth , 0 , m_frameWidth , m_frameHeight);
    m_currentFrame++;
}

void Action::reset()
{
    m_currentFrame = 0;
}