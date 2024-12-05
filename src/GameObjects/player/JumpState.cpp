#include "JumpState.h"
#include "Character.h"

JumpState::JumpState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

JumpState::~JumpState()
{
    IPlayerState::~IPlayerState();
}


void JumpState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void JumpState::setStateAtTheEndFrame()
{
    reset();
    m_character->setState(STATE::IDLE);
}

void JumpState::handlingEvent(sf::Event &event)
{
}
