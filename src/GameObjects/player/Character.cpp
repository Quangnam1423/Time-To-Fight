#include "Character.h"
#include "WalkState.h"
#include "JumpState.h"
#include "IdleState.h"
#include "RunState.h"

#include <iostream>



Character::Character()
{
}

Character::~Character()
{
    if (m_sprite != nullptr)
        delete m_sprite;


    for (auto& pair : m_stateMap)
    {
        if (pair.second != nullptr)
            delete pair.second;
    }
}

void Character::init()
{

}

void Character::update(float deltaTime)
{
    m_state->update(deltaTime);
    m_sprite->setTextureRect(m_state->getCurrentFrame());
}

void Character::render(sf::RenderWindow &gl_window)
{
    m_sprite->setTextureRect(m_state->getCurrentFrame());
    gl_window.draw(*m_sprite);
}


void Character::handlingEvent(sf::Event &event, float deltaTime)
{
}

void Character::setState(State nextState)
{
    m_state = m_stateMap[nextState];
    m_sprite->setTexture(m_state->getTexture());
}
