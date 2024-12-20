
#include "AttackThreeState.h"
#include "Character.h"

AttackThreeState::AttackThreeState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

AttackThreeState::~AttackThreeState()
{
    IPlayerState::~IPlayerState();
}


void AttackThreeState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void AttackThreeState::setStateAtTheEndFrame()
{
    reset();
    m_character->setState(STATE::IDLE);
}

void AttackThreeState::handlingEvent(sf::Event &event)
{
}