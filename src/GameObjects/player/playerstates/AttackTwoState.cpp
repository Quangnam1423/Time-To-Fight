#include "AttackTwoState.h"
#include "Character.h"

AttackTwoState::AttackTwoState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

AttackTwoState::~AttackTwoState()
{
    IPlayerState::~IPlayerState();
}


void AttackTwoState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void AttackTwoState::setStateAtTheEndFrame()
{
    reset();
    m_character->setState(STATE::IDLE);
}

void AttackTwoState::handlingEvent(sf::Event &event)
{
}