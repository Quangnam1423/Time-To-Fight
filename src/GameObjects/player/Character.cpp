#include "Character.h"
#include "WalkState.h"
#include "JumpState.h"
#include "IdleState.h"
#include "RunState.h"

#include <iostream>


// path of action
const char* const_idlePath = "resource/Samurai/Idle.png";
const char* const_runPath = "resource/Samurai/Run.png";
const char* const_jumpPath = "resource/Samurai/Jump.png";
const char* const_walkPath = "resource/Samurai/Walk.png";
const char* const_attack_1Path = "resource/Samurai/Attack_3.png";
const char* const_attack_2Path = "resource/Samurai/Attack_2.png";
const char* const_attack_3Path = "resource/Samurai/Attack_1.png";
const char* const_hurtPath = "resource/Samurai/Hurt.png";
const char* const_deadPath = "resource/Samurai/Dead.png";


// number of action frame
const int const_idleFrame = 6;
const int const_runFrame = 8;
const int const_jumpFrame = 12;
const int const_walkFrame = 8;
const int const_attack_3 = 3;
const int const_attack_2 = 4;
const int const_attack_1 = 6;
const int const_hurt = 2;
const int const_dead = 3;

Character::Character(float x, float y)
{
    init();
    
    m_sprite = new sf::Sprite(m_state->getTexture());
    std::cout << "check character init" << std::endl;
    m_sprite->setPosition(x , y);
 
    m_sprite->setTextureRect(m_state->getCurrentFrame());
  

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
    IdleState* idleState = new IdleState(this, const_idlePath, 
                                        sf::Vector2i(const_idleFrame - 1, 0), 30.0f);
    m_stateMap[State::IDLE] = idleState;

    JumpState* jumpState = new JumpState(this, const_jumpPath, 
                                        sf::Vector2i(const_jumpFrame - 1, 0) , 0.1f);
    m_stateMap[State::JUMP] = jumpState;

    WalkState* walkState = new WalkState(this, const_walkPath,
                                        sf::Vector2i(const_walkFrame - 1, 0) , 0.05f);
    m_stateMap[State::WALK] = walkState;

    RunState* runState = new RunState(this, const_runPath, 
                                        sf::Vector2i(const_runFrame - 1, 0), 0.05f);
    m_stateMap[State::RUN] = runState;

    m_state = m_stateMap[State::IDLE];
    //setState(State::IDLE);
    return;
}

void Character::update()
{
    m_sprite->setTextureRect(m_state->getCurrentFrame());
}

void Character::render(sf::RenderWindow &gl_window)
{
    m_sprite->setTextureRect(m_state->getCurrentFrame());
    gl_window.draw(*m_sprite);
}


void Character::handlingEvent(sf::Event &event)
{
}

void Character::setState(State nextState)
{
    m_state = m_stateMap[nextState];
    m_sprite->setTexture(m_state->getTexture());
}
