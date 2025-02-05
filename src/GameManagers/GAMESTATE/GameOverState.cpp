#include "GameOverState.h"
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
#include "GameOverState.h"
#include "../../GameObjects/Button.h"

#include <iostream>

GameOverState::GameOverState()
{
	std::cout << "game over state" << std::endl;
	m_background = nullptr;
}

GameOverState::~GameOverState()
{
	if (m_background != nullptr)
		delete m_background;
	for (Button* button : m_buttons)
	{
		if (button != nullptr)
			delete button;
		button = nullptr;
	}
}

void GameOverState::init()
{
}

void GameOverState::cleanup()
{
}

void GameOverState::pause()
{
}

void GameOverState::resume()
{
}

void GameOverState::exit()
{
}

void GameOverState::handleEvent(sf::Event& event)
{
}

void GameOverState::update(float deltaTime)
{
}

void GameOverState::render(sf::RenderWindow& window)
{
}

bool GameOverState::isFinished() const
{
	return false;
}
