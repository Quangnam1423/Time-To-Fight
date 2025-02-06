#include "IntroState.h"
#include "../ResourceManager.h"
#include "../../GameObjects//Button.h"
#include "../WindowManager.h"
#include "../GameManager.h"
#include "../../Application.h"

#include <iostream>

IntroState::IntroState()
{
}

IntroState::~IntroState()
{
}

void IntroState::init()
{
    m_elapsedTime = 0.f;
    // BACKGROUND................................................................................
    m_background = new sf::Sprite(*DATA->getTexture("Main BackGround"));
    m_background->setScale(sf::Vector2f(1.4f, 1.4f));
    m_background->setOrigin((sf::Vector2f)m_background->getTexture()->getSize() / 2.0f);
    m_background->setPosition(400, 300);

    m_logo = new sf::Sprite(*DATA->getTexture("Logo"));
    m_logo->setOrigin((sf::Vector2f)m_logo->getTexture()->getSize() / 2.f);
    m_logo->setPosition(400, 300);
}

void IntroState::cleanup()
{
}

void IntroState::handleEvent(sf::Event& event)
{
}

void IntroState::update(float deltaTime)
{
    m_elapsedTime += deltaTime;
    if (m_elapsedTime >= 2.0f)
    {
        _GM->changeState(GAMESTATE::MENU_STATE);
    }
}

void IntroState::render(sf::RenderWindow& window)
{
    window.draw(*m_background);
    window.draw(*m_logo);
}

void IntroState::pause()
{
}

void IntroState::resume()
{
}

void IntroState::exit()
{
}

bool IntroState::isFinished() const
{
	return false;
}
