#include "IntroduceGameState.h"
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

#include "IntroduceGameState.h"
#include "../Resource.h"
#include "../../GameObjects//Button.h"
#include "../WindowManager.h"
#include "../GameManager.h"
#include "../../Application.h"

#include <iostream>

const char* introduce = "Time To Fight Game \n developed by Quangnam1423.";

IntroduceState::IntroduceState()
{
}

IntroduceState::~IntroduceState()
{
	cleanup();
}

void IntroduceState::init()
{
	m_font = nullptr;
	// MEMBER CLASS
	m_index = 0;
	m_lineIndex = 0;

	m_elapsedTime = 0.0f;
	m_displayText = "";

	// FONT CONFIG
	m_font = _RM->getFont("gameFont6");

	// HANDLE TEXT LINE
	std::string tempLine = "";
	for (int i = 0; introduce[i] != '\0'; i++)
	{
		if (introduce[i] == '\n')
		{
			m_lines.push_back(tempLine);
			tempLine = "";
		}
		else
		{
			tempLine += introduce[i];
		}
	}
	if (!tempLine.empty())
		m_lines.push_back(tempLine);

	m_textLines = std::vector<sf::Text>(m_lines.size());
	for (size_t i = 0; i < m_textLines.size(); i++) {
		m_textLines[i].setFont(*m_font);
		m_textLines[i].setCharacterSize(40);
		m_textLines[i].setFillColor(sf::Color::White);
	}
	// BUTTON CONFIG
	Button* homeButton = new Button(_RM->getTexture("Home Icon Button", TEXTURE_TYPE::BUTTON),
									sf::Vector2f(750.0f, 550.0f),
									BUTTON_TYPE::HOME_ICON_BUTTON);
	homeButton->setCallBack(
		[]() {
			_GM->popState();
		}
	);
	m_buttons.push_back(homeButton);

	// MAIN BACKGROUND............................................................................
	m_background = new sf::Sprite(*_RM->getTexture("Main BackGround", TEXTURE_TYPE::ENVIROMENT));
	m_background->setScale(sf::Vector2f(1.4f, 1.4f));
	m_background->setOrigin((sf::Vector2f)m_background->getTexture()->getSize() / 2.f);
	m_background->setPosition(400, 300);
}

void IntroduceState::cleanup()
{
	m_font = nullptr;
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
}

void IntroduceState::handleEvent(sf::Event& event)
{
	for (Button* button : m_buttons)
		button->handleEvent(event);
}

void IntroduceState::update(float deltaTime)
{
	m_elapsedTime += deltaTime;
	if (m_elapsedTime >= 0.05f && introduce[m_index] != '\0')
	{
		if (introduce[m_index] == '\n')
		{
			m_lineIndex++;
			m_displayText = "";
		}
		else
		{
			m_displayText += introduce[m_index];
			m_textLines[m_lineIndex].setString(m_displayText);
		}
		m_index++;
		m_elapsedTime = 0.f;
	}
	for (Button* button : m_buttons)
	{
		button->update(deltaTime, *_MAIN_WINDOW->getWindow());
	}
}

void IntroduceState::render(sf::RenderWindow& window)
{
	for (size_t i = 0; i < m_textLines.size(); i++) {
		sf::FloatRect textBounds = m_textLines[i].getLocalBounds();
		m_textLines[i].setOrigin(textBounds.width / 2, textBounds.height / 2);
		m_textLines[i].setPosition(400, 300 + i * 50);
	}
	window.draw(*m_background);
	for (Button* button : m_buttons)
	{
		button->render(window);
	}
	for (auto& text : m_textLines) {
		window.draw(text);
		//std::cout << "Text: " << text.getString().toAnsiString() << "\n";
	}
}

void IntroduceState::pause()
{
}

void IntroduceState::resume()
{
}

void IntroduceState::exit()
{
	// _GM->popState();
}

bool IntroduceState::isFinished() const
{
	return false;
}
