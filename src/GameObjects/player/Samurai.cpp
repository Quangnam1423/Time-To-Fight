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

#include "Samurai.h"
#include "playerstates/WalkState.h"
#include "playerstates/JumpState.h"
#include "playerstates/IdleState.h"
#include "playerstates/RunState.h"
#include "playerstates/ShieldState.h"
#include "playerstates/AttackOneState.h"
#include "playerstates/AttackTwoState.h"
#include "playerstates/AttackThreeState.h"

//path of action
const char* const_idlePath = "characters/Samurai/Idle";
const char* const_runPath = "characters/Samurai/Run";
const char* const_jumpPath = "characters/Samurai/Jump";
const char* const_walkPath = "characters/Samurai/Walk";
const char* const_attack_1Path = "characters/Samurai/Attack_3";
const char* const_attack_2Path = "characters/Samurai/Attack_2";
const char* const_attack_3Path = "characters/Samurai/Attack_1";
const char* const_hurtPath = "characters/Samurai/Hurt";
const char* const_deadPath = "characters/Samurai/Dead";
const char* const_shieldPath = "characters/Samurai/Shield";


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

std::vector<sf::IntRect> idleHitboxes = {
    {46, 46, 40, 82},
    {174, 46, 40, 82},
    {302, 46, 40, 82},
    {430, 46, 40, 82},
    {558, 46, 40, 82},
    {686, 46, 40, 82}
};

std::vector<sf::IntRect> runHitboxes = {
    {20, 48, 40, 80},
    {148, 48, 40, 80},
    {276, 48, 40, 80},
    {404, 48, 40, 80},
    {532, 48, 40, 80},
    {660, 48, 40, 80},
    {788, 48, 40, 80},
    {916, 48, 40, 80}
};

std::vector<sf::IntRect> jumpHitboxes = {
    {46, 48, 40, 80},
    {174, 50, 40, 78},
    {302, 52, 40, 76},
    {430, 48, 40, 80},
    {558, 44, 40, 84},
    {686, 46, 40, 82},
    {814, 48, 40, 80},
    {942, 50, 40, 78},
    {1070, 54, 40, 74},
    {1198, 56, 40, 72},
    {1326, 58, 40, 70},
    {1454, 64, 40, 64}
};

std::vector<sf::IntRect> walkHitboxes = {
    {36, 46, 38, 82},
    {164, 46, 38, 82},
    {292, 46, 38, 82},
    {420, 46, 38, 82},
    {548, 46, 38, 82},
    {676, 46, 38, 82},
    {804, 46, 38, 82},
    {932, 46, 38, 82}
};

std::vector<sf::IntRect> attack1Hitboxes = {
    {34, 54, 43, 74},
    {162, 54, 42, 74},
    {290, 54, 46, 74},
    {418, 54, 54, 74},
    {546, 54, 92, 74},
    {674, 54, 44, 74}
};

std::vector<sf::IntRect> attack2Hitboxes = {
    {28, 54, 56, 74},
    {152, 54, 62, 74},
    {286, 56, 100, 72},
    {412, 56, 66, 72}
};

std::vector<sf::IntRect> attack3Hitboxes = {
    {34, 54, 68, 74},
    {162, 54, 92, 74},
    {290, 54, 92, 74}
};

std::vector<sf::IntRect> hurtHitboxes = {
    {48, 48, 40, 80},
    {176, 50, 40, 78}
};

std::vector<sf::IntRect> deadHitboxes = {
    {28, 52, 48, 76},
    {152, 68, 52, 60},
    {284, 118, 76, 10}
};

std::vector<sf::IntRect> shieldHitboxes = {
    {34, 50, 64, 78},
    {162, 50, 60, 78}
};


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

void Samurai::handleEvent(sf::Event &event)
{
    m_state->handleEvent(event);
}

void Samurai::init()
{
    // IDLE STATE
    {
        IdleState* idleState = new IdleState(this, const_idlePath, { const_idleFrame - 1, 0 }, 0.05f);
        idleState->setFrameHitboxes(idleHitboxes);
        idleState->setState(STATE::IDLE);
        m_stateMap[STATE::IDLE] = idleState;
    }
    // JUMP STATE
    {
        JumpState* jumpState = new JumpState(this, const_jumpPath, { const_jumpFrame - 1, 0 }, 0.1f);
        jumpState->setFrameHitboxes(jumpHitboxes);
        jumpState->setState(STATE::JUMP);
        m_stateMap[STATE::JUMP] = jumpState;
    }
    // WALK STATE
    {
        WalkState* walkState = new WalkState(this, const_walkPath, { const_walkFrame - 1, 0 }, 0.1f);
        walkState->setFrameHitboxes(walkHitboxes);
        walkState->setState(STATE::WALK);
        m_stateMap[STATE::WALK] = walkState;
    }
    // RUN STATE
    {
        RunState* runState = new RunState(this, const_runPath, { const_runFrame - 1, 0 }, 0.05f);
        runState->setFrameHitboxes(runHitboxes);
        runState->setState(STATE::RUN);
        m_stateMap[STATE::RUN] = runState;
    }
    // ATTACK ONE STATE
    {
        AttackOneState* attackOneState = new AttackOneState(this, const_attack_1Path, { const_attack_1 - 1, 0 }, 0.05f);
        attackOneState->setFrameHitboxes(attack1Hitboxes);
        attackOneState->setState(STATE::ATTACK_1);
        m_stateMap[STATE::ATTACK_1] = attackOneState;
    }
    // ATTACK TWO STATE
    {
        AttackTwoState* attackTwoState = new AttackTwoState(this, const_attack_2Path, {const_attack_2 - 1, 0}, 0.05f);
        attackTwoState->setFrameHitboxes(attack2Hitboxes);
        attackTwoState->setState(STATE::ATTACK_2);
        m_stateMap[STATE::ATTACK_2] = attackTwoState;
    } 
    // ATTACK THREE STATE                     
    {
        AttackThreeState* attackThreeState = new AttackThreeState(this, const_attack_3Path,{const_attack_3 - 1, 0}, 0.05f);
        attackThreeState->setFrameHitboxes(attack3Hitboxes);
        attackThreeState->setState(STATE::ATTACK_3);
        m_stateMap[STATE::ATTACK_3] = attackThreeState;
    }
    // SHIELD STATE
    {
        ShieldState* shieldState = new ShieldState(this, const_shieldPath, { const_shield - 1, 0 }, 0.05f);
        shieldState->setFrameHitboxes(shieldHitboxes);
        shieldState->setState(STATE::SHIELD);
        m_stateMap[STATE::SHIELD] = shieldState;
    }
    // set player state
    m_state = m_stateMap[STATE::IDLE];
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
