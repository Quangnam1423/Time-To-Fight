#include "Character.h"

#include "IPlayerState.h"
#include "WalkState.h"
#include "JumpState.h"
#include "IdleState.h"
#include "RunState.h"
#include "ShieldState.h"
#include "AttackOneState.h"
#include "AttackTwoState.h"
#include "AttackThreeState.h"

// #include "../logics/Physics.h"
// #include "../logics/Collision.h"

#include <iostream>



Character::Character(sf::Vector2f position) : m_position(position)

{
    this->m_onLeft = false;
    this->m_onRight = true;
    this->m_deadMode = false;

    m_healthPoint = 100.0f;
    m_manaPoint = 20.0f;
    m_strength = 5.0f;
    m_dexterity = 1.0f;
    m_constitution = 1.0f;

    m_movementSpeed = 200.0f;
    m_healing = 2.5f;
    m_physicalDamage = 2.5f;
    m_magicDamage = 2.0f;
    m_armor = 1.0f;
    m_magicResistance = 0.5f;
    m_evasion = 0.1f;
    m_block = 2.0f;

    m_healthRegen = 100.0f;
    m_manaRegen = 100.0f;
    m_energyRegen = 50.0f;
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement(deltaTime, DIRECTION::RIGHT_DIRECTION);
        std::cout << "move right" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement(deltaTime, DIRECTION::LEFT_DIRECTION);
        std::cout << "move left" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        jump(deltaTime, DIRECTION::JUMP_DIRECTION);
        std::cout << "jump" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement(deltaTime, DIRECTION::SHIELD_DIRECTION);
        std::cout << "shield" << std::endl;
    }
}

void Character::render(sf::RenderWindow &gl_window)
{
    m_sprite->setTextureRect(m_state->getCurrentFrame());
    if (m_onLeft)
    {
        m_sprite->setScale(-1.0f, 1.0f);
        m_sprite->setOrigin(m_sprite->getGlobalBounds().width, 0);
        //m_sprite->setPosition(m_position);
    }
    else{
        m_sprite->setScale(1.0f, 1.0f);
        m_sprite->setOrigin(0, 0);
        //m_sprite->setPosition(m_position);
    }
    // draw the sprite
    gl_window.draw(*m_sprite);

    return;
}

// virtual 
void Character::handlingEvent(sf::Event &event)
{
}

void Character::setState(STATE nextState)
{
    m_state = m_stateMap[nextState];
    m_sprite->setTexture(m_state->getTexture());
}

void Character::movement(float deltaTime, DIRECTION direction)
{
    std::cout << "call movement" << std::endl;
    if (direction == DIRECTION::LEFT_DIRECTION)
    {
        m_onLeft = true;
        m_onRight = false;
        m_position.x -= deltaTime * m_movementSpeed;
        float distance = deltaTime * m_movementSpeed;
        m_sprite->move(-distance, 0.0f);
    }
    else if (direction == DIRECTION::RIGHT_DIRECTION)
    {
        m_onLeft = false;
        m_onRight = true;
        m_position.x += deltaTime * m_movementSpeed;
        float distance = deltaTime * m_movementSpeed;
        m_sprite->move(distance, 0.0f);
    }
    //m_sprite->setPosition(m_position);
    //m_sprite.move()

    return;
}

void Character::jump(float deltaTime, DIRECTION direction)
{

}

void Character::shield(float deltaTime, DIRECTION direction)
{
    std::cout <<"shield mode on display" << std::endl;
}
