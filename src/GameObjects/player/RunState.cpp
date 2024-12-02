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
    
}

void RunState::setStateAtTheEndFrame()
{
    m_character->setState(State::IDLE);
}

void RunState::handleEvent(sf::Event &event)
{
}