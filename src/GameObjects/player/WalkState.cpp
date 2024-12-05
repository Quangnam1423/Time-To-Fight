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
    reset();
    m_character->setState(STATE::IDLE);
}

void WalkState::handlingEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::A)
            setStateAtTheEndFrame();
    }
}
