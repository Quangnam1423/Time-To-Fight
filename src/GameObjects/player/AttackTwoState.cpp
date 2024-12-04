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
    m_character->setState(State::IDLE);
}

void AttackTwoState::handleEvent(sf::Event &event)
{
}