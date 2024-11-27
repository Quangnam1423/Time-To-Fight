#include "Character.h"

Character::Character(float x, float y)
{
}

Character::~Character()
{
    if (m_sprite != nullptr)
        delete m_sprite;
    if (m_state != nullptr)
        delete m_state;
}

void Character::update()
{
}

void Character::render(sf::RenderWindow &gl_window)
{
    // update IntRect for m_sprite
    gl_window.draw(*m_sprite);
}

void Character::callbackEndingAnimation()
{
}

void Character::handlingEvent(sf::Event &event)
{
}

void Character::setState(State nextState)
{
}
