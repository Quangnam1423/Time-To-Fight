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
    m_character->setState(State::IDLE);
}

void AttackOneState::handleEvent(sf::Event &event)
{
}