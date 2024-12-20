#include "ShieldState.h"
#include "Character.h"

ShieldState::ShieldState(Character* character, const char* texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

ShieldState::~ShieldState()
{
    IPlayerState::~IPlayerState();
}


void ShieldState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void ShieldState::setStateAtTheEndFrame()
{
    reset();
    m_character->setState(STATE::IDLE);
}

void ShieldState::handlingEvent(sf::Event &event)
{
}