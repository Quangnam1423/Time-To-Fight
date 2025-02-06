/*
MIT License

Copyright (c) 2024 Quangnam1423

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include "PlayinGameState.h"
#include "../GameManager.h"
#include "../WindowManager.h"
#include "../InputLockManager.h"
#include "../ResourceManager.h"
#include "../../GameObjects/Button.h"

#include <iostream>

PlayInState::PlayInState()
{
	m_background = nullptr;
}

PlayInState::~PlayInState()
{
	cleanup();
}

void PlayInState::init()
{
	// MAIN BACKGROUND............................
	m_background = new sf::Sprite(*DATA->getTexture("Main BackGround"));
	m_background->setScale(sf::Vector2f(1.4f, 1.4f));
	m_background->setOrigin((sf::Vector2f)m_background->getTexture()->getSize() / 2.f);
	m_background->setPosition(400, 300);

	// BUTTON CONFIG
	Button* newGameButton = new Button(DATA->getTexture("Buttons/New Game Button"),
										sf::Vector2f(400.f, 250.f),
										BUTTON_TYPE::NEW_GAME_BUTTON);
	newGameButton->setCallBack(
		[]() {
			std::cout << "newgame Callback" << std::endl;
		}
	);
	m_buttons.push_back(newGameButton);

	Button* continueButton = new Button(DATA->getTexture("Buttons/Continue Button"),
									sf::Vector2f(400.f, 350.f),
									BUTTON_TYPE::RESUME_BUTTON);
	continueButton->setCallBack(
		[](){
			std::cout << "continue callback Button" << std::endl;
		}
	);
	m_buttons.push_back(continueButton);

	Button* settingButton = new Button(DATA->getTexture("Buttons/Settings Button"),
		sf::Vector2f(400.0f, 450.0f),
		BUTTON_TYPE::HOME_ICON_BUTTON);
	settingButton->setCallBack(
		[]() {
			std::cout << "setting callback" << std::endl;
		}
	);
	m_buttons.push_back(settingButton);

	Button* homeButton = new Button(DATA->getTexture("Buttons/Home Icon Button"),
		sf::Vector2f(750.0f, 550.0f),
		BUTTON_TYPE::HOME_ICON_BUTTON);
	homeButton->setCallBack(
		[]() {
			_GM->popState();
		}
	);
	m_buttons.push_back(homeButton);

	//Button* homeButton = new Button
}

void PlayInState::cleanup()
{
	if (m_background != nullptr)
	{
		delete m_background;
		m_background = nullptr;
	}

	for (Button* button : m_buttons)
	{
		if (button != nullptr)
		{
			delete button;
			button = nullptr;
		}
	}
	m_buttons.clear();
}

void PlayInState::handleEvent(sf::Event& event)
{
	for (Button* button : m_buttons)
	{
		button->handleEvent(event);
	}
}

void PlayInState::update(float deltaTime)
{
	for (Button* button : m_buttons)
	{
		button->update(deltaTime, *_MAIN_WINDOW->getWindow());
	}
}

void PlayInState::render(sf::RenderWindow& window)
{
	window.draw(*m_background);
	for (Button* button : m_buttons)
	{
		button->render(window);
	}
}

void PlayInState::pause()
{
}

void PlayInState::resume()
{
}

void PlayInState::exit()
{
}

bool PlayInState::isFinished() const
{
	return false;
}
