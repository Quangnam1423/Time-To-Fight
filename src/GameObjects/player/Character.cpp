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

#include "Character.h"

#include "playerstates/IPlayerState.h"
#include "playerstates/WalkState.h"
#include "playerstates/JumpState.h"
#include "playerstates/IdleState.h"
#include "playerstates/RunState.h"
#include "playerstates/ShieldState.h"
#include "playerstates/AttackOneState.h"
#include "playerstates/AttackTwoState.h"
#include "playerstates/AttackThreeState.h"
#include "../Hitbox.h"

#include <iostream>



Character::Character()

{
    m_sprite = nullptr;
    m_hitbox = nullptr;
    m_state = nullptr;

    m_elapsedTime = 0.0f;
    m_durationTime = 0.0f;

    
    m_deadMode = false;
    m_isOnPlatform = false;
    m_velocity = { 0.f, 0.f };
    m_direction = DIRECTION::DOWN;
}

Character::~Character()
{
    if (m_sprite != nullptr)
    {
        delete m_sprite;
        m_sprite = nullptr;
    }
    for (auto& pair : m_stateMap)
    {
        if (pair.second != nullptr)
        {
            delete pair.second;
            pair.second = nullptr;
        }
    }
    m_stateMap.clear();

    if (m_hitbox != nullptr)
    {
        delete m_hitbox;
        m_hitbox = nullptr;
    }
}

void Character::init()
{

}

void Character::update(float deltaTime)
{
    // update player state
    {
        m_state->update(deltaTime);
    }

    // update sprite rect and hitbox of player
    {
        m_sprite->setTextureRect(m_state->getCurrentFrame());
        sf::FloatRect playerBound = m_sprite->getGlobalBounds();
        m_sprite->setOrigin(playerBound.width / 2, playerBound.height / 2);
        m_hitbox->setSize(getSize());
        m_hitbox->setOrigin(m_hitbox->getHaftSize());
    }

    // update velocity
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            m_velocity.x = 200.f;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_velocity.x = -200.f;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            m_velocity.y = -200.f;
        }

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
            !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            m_velocity.x = 0.f;
            setDirection(DIRECTION::DNULL);
        }
    }

    // move for character
    {
        if (m_state->getState() == PLAYER_STATE::SHIELD)
            return;
        move(deltaTime * m_velocity.x, 0.f);
        move(0.f, deltaTime * m_velocity.y);
    }
}

void Character::render(sf::RenderWindow &gl_window)
{
    gl_window.draw(*m_sprite);
    gl_window.draw(*m_hitbox);
}

void Character::handleEvent(sf::Event &event)
{

}

void Character::setState(PLAYER_STATE nextState, float durationTime)
{
    m_state = m_stateMap[nextState];
    m_sprite->setTexture(m_state->getTexture());
    m_state->update(durationTime);
    m_durationTime = 0.0f;
    return;
}

void Character::move(float x, float y)
{
    m_sprite->move(x, y);
    m_hitbox->move(x, y);
}

void Character::setVelocity(sf::Vector2f velocity)
{
    m_velocity = velocity;
}

sf::Vector2f Character::getVelocity() const
{
    return m_velocity;
}

void Character::setHitbox(Hitbox* hitbox)
{
    m_hitbox = hitbox;
}

Hitbox* Character::getHitbox()
{
    return m_hitbox;
}

void Character::setDirection(DIRECTION direction)
{
    m_direction = direction;
}

DIRECTION Character::getDirection() const
{
    return m_direction;
}

void Character::isOnPlatform(bool value)
{
    m_isOnPlatform = value;
}

sf::Vector2f Character::getPosition()
{
    return m_sprite->getPosition();
}

sf::Vector2f Character::getSize()
{
    sf::FloatRect playerBound = m_sprite->getGlobalBounds();
    return sf::Vector2f(playerBound.width, playerBound.height);
}
