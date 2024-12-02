#include "Character.h"
#include "IdleState.h"

IdleState::IdleState(Character* character, const char *texturePath, 
                sf::Vector2i frameCount, 
                float frameTime) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

IdleState::~IdleState()
{
    IPlayerState::~IPlayerState();
}


void IdleState::update(float deltaTime)
{
    
}

void IdleState::setStateAtTheEndFrame()
{
    reset();
    m_character->setState(State::IDLE);
}

void IdleState::handleEvent(sf::Event &event)
{
}
