#include "Character.h"

Character::Character(float x , float y)
{
    if (!m_idleTexture.loadFromFile(const_idlePath) ||
        !m_runTexture.loadFromFile(const_runPath) ||
        !m_jumpTexture.loadFromFile(const_jumpPath) ||
        !m_attackFirstTexture.loadFromFile(const_attackFirstPath) ||
        !m_attackSecondTexture.loadFromFile(const_attackSecondPath) ||
        !m_attackThirdTexture.loadFromFile(const_attackThirdPath) ||
        !m_walkTexture.loadFromFile(const_walkPath) ||
        !m_hurtTexture.loadFromFile(const_hurtPath) ||
        !m_deadTexture.loadFromFile(const_deadPath)
    ) { 
        throw std::runtime_error("Unable to load textures!");
    }

    //m_sprite.setPosition(x , y);
    m_statusAction = Idle;

    setTextureForFirsttime(x , y);

    m_frameHeight = 128;
    m_frameWidth = 128;
    m_animationClock = sf::Clock();
    m_deltaTime = m_animationClock.getElapsedTime();
}

void Character::render(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}


void Character::setTextureForCurrentState()
{
    //m_sprite = sf::Sprite(m_idleTexture);
    //m_sprite.setPosition()
}

void Character::setTextureForFirsttime(float x , float y)
{
    m_sprite = sf::Sprite(m_idleTexture);
    m_sprite.setTextureRect(sf::IntRect(0  , 0 , m_frameWidth , m_frameHeight));
    m_sprite.setPosition(x , y);
}