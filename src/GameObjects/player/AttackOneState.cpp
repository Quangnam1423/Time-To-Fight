#include "AttackOneState.h"
#include "Character.h"

AttackOneState::AttackOneState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

AttackOneState::~AttackOneState()
{
    IPlayerState::~IPlayerState();
}


void AttackOneState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void AttackOneState::setStateAtTheEndFrame()
{
    reset();
    m_character->setState(STATE::IDLE);
}

void AttackOneState::handlingEvent(sf::Event &event)
{

}