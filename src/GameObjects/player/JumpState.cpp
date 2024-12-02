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
    
}

void JumpState::setStateAtTheEndFrame()
{
    m_character->setState(State::IDLE);
}

void JumpState::handleEvent(sf::Event &event)
{
}
