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

#include "PauseState.h"
#include "../Resource.h"
#include "../Button.h"
#include "../FunctionManagers/FunctionCallBack.h"
#include "../WindowManager.h"

PauseState::PauseState()
{
	m_logo = nullptr;
	init();
}

PauseState::~PauseState()
{
}

void PauseState::init()
{
	// overlay layer
	{
		sf::RenderWindow* window = _MAIN_WINDOW->getWindow();
		m_overlay = sf::RectangleShape((sf::Vector2f)window->getSize());
		m_overlay.setFillColor(sf::Color(0, 0, 0, 128));
	}
	// Home button
	{
		Button* homeButton = new Button(this,
			_RM->getTexture("Home Icon", TEXTURE_TYPE::BUTTON),
			_HOME_ICON_CB,
			sf::Vector2f(100.0f, 10.0f),
			"Home Icon",
			BUTTON_TYPE::HOME_ICON_BUTTON
		);
		m_buttons.push_back(homeButton);
	}
	// continue button
	{
		Button* continueButton = new Button(this,
			_RM->getTexture("Continue", TEXTURE_TYPE::BUTTON),
			_CONTINUE_CB,
			"Continue",
			BUTTON_TYPE::CONTINUE_BUTTON
		);
		m_buttons.push_back(continueButton);
	}
	// logo
	{
		m_logo = new sf::Sprite(*_RM->getTexture("Logo", TEXTURE_TYPE::LOGO));
	}
	return;
}

void PauseState::cleanup()
{
}

void PauseState::handleEvent(sf::Event& event)
{
}

void PauseState::update(float deltaTime)
{
}

void PauseState::render(sf::RenderWindow& window)
{
	window.draw(m_overlay);
	window.draw(*m_logo);
	for (Button* button : m_buttons)
	{
		button->render(window);
	}
	return;
}

void PauseState::pause()
{
}

void PauseState::resume()
{
}

bool PauseState::isFinished() const
{
	return false;
}
