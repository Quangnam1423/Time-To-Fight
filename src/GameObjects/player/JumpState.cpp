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
    m_character->setState(State::IDLE);
}

void JumpState::handleEvent(sf::Event &event)
{
}
