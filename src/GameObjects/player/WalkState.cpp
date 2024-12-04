#include "WalkState.h"
#include "Character.h"

WalkState::WalkState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

WalkState::~WalkState()
{
    IPlayerState::~IPlayerState();
}


void WalkState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void WalkState::setStateAtTheEndFrame()
{
    m_character->setState(State::IDLE);
}

void WalkState::handleEvent(sf::Event &event)
{
}
