#include "IdleState.h"
#include "../Character.h"

#include <iostream>


IdleState::IdleState(Character* character, 
                    const char *texturePath, 
                    sf::Vector2i frameCount, 
                    float frameTime

                    ) : IPlayerState(character, 
                                    texturePath,
                                    frameCount, 
                                    frameTime
                                    )
{
    std::cout << "create idle state" << std::endl;
}

IdleState::~IdleState()
{
    IPlayerState::~IPlayerState();
}


void IdleState::update(float deltaTime)
{
    m_durationTime += deltaTime;
    if (m_durationTime >= m_timeFrame)
    {
        if (!checkEndFrame())
        {
            CalculateNextFrame();
        }
        else
        {
            reset();
        }
        resetDurationTime();
    }
    return;
}

void IdleState::setStateAtTheEndFrame()
{
    m_character->setState(STATE::IDLE, m_durationTime);
    reset();
    resetDurationTime();
}

void IdleState::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        m_character->setState(STATE::WALK, m_durationTime);
        reset();
        resetDurationTime();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
    {
        m_character->setState(STATE::WALK, m_durationTime);
        reset();
        resetDurationTime();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
    {
        m_character->setState(STATE::JUMP, m_durationTime);
        reset();
        resetDurationTime();
    }
    else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
    {
        m_character->setState(STATE::SHIELD, m_durationTime);
        reset();
        resetDurationTime();
    }

    // handle attack skill....

    return;
}
