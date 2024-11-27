#include "WalkState.h"
#include "Character.h"

WalkState::WalkState(Character* character, const std::string *texturePath, 
                sf::Vector2i frameCount, 
                float frameTime = 0.1f) : IPlayerState(character, texturePath, frameCount, frameTime)
{

}

WalkState::~WalkState()
{
    IPlayerState::~IPlayerState();
}


void WalkState::update(float deltaTime)
{
    
}

void WalkState::setStateAtTheEndFrame()
{
    m_character->setState(State::IDLE);
}

void WalkState::handleEvent(sf::Event &event)
{
}
