#include "Samurai.h"

#include "WalkState.h"
#include "JumpState.h"
#include "IdleState.h"
#include "RunState.h"
#include "ShieldState.h"
#include "AttackOneState.h"
#include "AttackTwoState.h"
#include "AttackThreeState.h"

//path of action
const char* const_idlePath = "resource/Samurai/Idle.png";
const char* const_runPath = "resource/Samurai/Run.png";
const char* const_jumpPath = "resource/Samurai/Jump.png";
const char* const_walkPath = "resource/Samurai/Walk.png";
const char* const_attack_1Path = "resource/Samurai/Attack_3.png";
const char* const_attack_2Path = "resource/Samurai/Attack_2.png";
const char* const_attack_3Path = "resource/Samurai/Attack_1.png";
const char* const_hurtPath = "resource/Samurai/Hurt.png";
const char* const_deadPath = "resource/Samurai/Dead.png";
const char* const_shieldPath = "resource/Samurai/Shield.png";


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
const int const_shield = 2;

Samurai::Samurai(sf::Vector2f position) : Character(position)                                
{
    init();
    m_sprite = new sf::Sprite(m_state->getTexture());
    m_sprite->setPosition(m_position);
    m_sprite->setTextureRect(m_state->getCurrentFrame());
    m_sprite->setScale(1.f, 1.f);
    m_sprite->setOrigin(0, 0);
}

Samurai::~Samurai()
{

}

void Samurai::handlingEvent(sf::Event &event, float deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //movement(deltaTime, DIRECTION::RIGHT_DIRECTION);
        std::cout << "move right" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //movement(deltaTime, DIRECTION::LEFT_DIRECTION);
        std::cout << "move left" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //jump(deltaTime, DIRECTION::JUMP_DIRECTION);
        std::cout << "jump" << std::endl;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //movement(deltaTime, DIRECTION::SHIELD_DIRECTION);
        std::cout << "shield" << std::endl;
    }
    // state handle event from keyboard..
    m_state->handleEvent(event);
}

void Samurai::init()
{
    IdleState* idleState = new IdleState(this, const_idlePath, 
                                        sf::Vector2i(const_idleFrame - 1, 0), 0.05f);
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

    AttackOneState* attackOneState = new AttackOneState(this, const_attack_1Path,
                                        sf::Vector2i(const_attack_1 - 1, 0), 0.05f);
    m_stateMap[State::ATTACK_1] = attackOneState;    

    AttackTwoState* attackTwoState = new AttackTwoState(this, const_attack_2Path,
                                        sf::Vector2i(const_attack_2 - 1, 0), 0.05f);
    m_stateMap[State::ATTACK_2] = attackTwoState;

    AttackThreeState* attackThreeState = new AttackThreeState(this, const_attack_3Path,
                                        sf::Vector2i(const_attack_3 - 1, 0), 0.05f);
    m_stateMap[State::ATTACK_3] = attackThreeState;   

    ShieldState* shieldState = new ShieldState(this, const_shieldPath,
                                        sf::Vector2i(const_shield - 1, 0), 0.05f);   
    m_stateMap[State::SHIELD] = shieldState;                         

    m_state = m_stateMap[State::IDLE];
    //setState(State::IDLE);
    return;
}

void Samurai::attack()
{
}

void Samurai::combo_1()
{
}

void Samurai::combo_2()
{
}
