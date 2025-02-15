#include "InformationState.h"
#include "../../GameObjects/Button.h"
#include "../WindowManager.h"
#include "../GameManager.h"
#include "../../Application.h"
#include "../ResourceManager.h"

#include <iostream>

const char* introduce = "Time To Fight Game \n developed by Quangnam1423.";

InformationState::InformationState()
{
}

InformationState::~InformationState()
{
	cleanup();
}

void InformationState::init()
{
	m_font = nullptr;
	// MEMBER CLASS
	m_index = 0;
	m_lineIndex = 0;

	m_elapsedTime = 0.0f;
	m_displayText = "";

	// FONT CONFIG
	m_font = DATA->getFont("gameFont6");

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
	Button* homeButton = new Button(DATA->getTexture("Buttons/Home Icon Button"),
		sf::Vector2f(750.0f, 550.0f),
		BUTTON_TYPE::HOME_ICON_BUTTON);
	homeButton->setCallBack(
		[]() {
			_GM->popState();
			std::cout << "homeButton" << std::endl;
		}
	);
	m_buttons.push_back(homeButton);

	// MAIN BACKGROUND............................................................................
	m_background = new sf::Sprite(*DATA->getTexture("Main BackGround"));
	m_background->setScale(sf::Vector2f(1.4f, 1.4f));
	m_background->setOrigin((sf::Vector2f)m_background->getTexture()->getSize() / 2.f);
	m_background->setPosition(400, 300);
}

void InformationState::cleanup()
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

void InformationState::handleEvent(sf::Event& event)
{
	for (Button* button : m_buttons)
		button->handleEvent(event);
}

void InformationState::update(float deltaTime)
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

void InformationState::render(sf::RenderWindow& window)
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

void InformationState::pause()
{
}

void InformationState::resume()
{
}

void InformationState::exit()
{
	// _GM->popState();
}

bool InformationState::isFinished() const
{
	return false;
}