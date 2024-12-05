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
    m_durationTime += deltaTime;
    if (m_durationTime > m_timeFrame)
    {
        CalculateNextFrame();
        m_durationTime = 0.0f;
    }
}

void IdleState::setStateAtTheEndFrame()
{
    reset();
    m_character->setState(STATE::IDLE);
}

void IdleState::handlingEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        std::cout << "runing ont the right direction" << std::endl;
        m_character->setState(STATE::WALK);
        reset();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
    {
        std::cout << "running on the left direction" << std::endl;
        m_character->setState(STATE::WALK);
        reset();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
    {
        std::cout << "jumping" << std::endl;
        m_character->setState(STATE::JUMP);
        reset();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
    {
        std::cout << "shielding" << std::endl;
        m_character->setState(STATE::SHIELD);
        reset();
    }
}
