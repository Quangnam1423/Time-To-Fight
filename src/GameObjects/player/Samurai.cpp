#include "Samurai.h"
#include "WalkState.h"
#include "JumpState.h"
#include "IdleState.h"
#include "RunState.h"
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

Samurai::Samurai(sf::Vector2f position) : Character(), m_position(position)                                  
{
    init();
    m_sprite = new sf::Sprite(m_state->getTexture());
    m_sprite->setPosition(m_position);
    m_sprite->setTextureRect(m_state->getCurrentFrame());


    this->m_onLeft = true;
    this->m_onRight = false;
    this->m_deadMode = false;

    m_healthPoint = 100.0f;
    m_manaPoint = 20.0f;
    m_strength = 5.0f;
    m_dexterity = 1.0f;
    m_constitution = 1.0f;

    m_movementSpeed = 3.0f;
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

Samurai::~Samurai()
{

}

void Samurai::handlingEvent(sf::Event &event, float deltaTime)
{
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

    m_state = m_stateMap[State::IDLE];
    //setState(State::IDLE);
    return;
}
