#include "RunState.h"
#include "Character.h"

RunState::RunState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

RunState::~RunState()
{
    IPlayerState::~IPlayerState();
}


void RunState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void RunState::setStateAtTheEndFrame()
{
    m_character->setState(State::IDLE);
}

void RunState::handleEvent(sf::Event &event)
{
}