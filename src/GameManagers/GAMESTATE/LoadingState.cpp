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

#include "LoadingState.h"
#include "../Resource.h"
#include "../../GameObjects/Button.h"
#include "../FunctionManagers/FunctionCallBack.h"

LoadingState::LoadingState()
{
}

LoadingState::~LoadingState()
{
	cleanup();
	return;
}

void LoadingState::init()
{
}

void LoadingState::cleanup()
{
	if (m_logo != nullptr)
		delete m_logo;
	if (m_background != nullptr)
		delete m_background;
	return;
}

void LoadingState::handleEvent(sf::Event& event)
{
}

void LoadingState::update(float deltaTime)
{
	m_durationTime += deltaTime;
	if (m_durationTime >= _UPDATE_TIME)
	{
		m_durationTime = 0.0f;
		m_dotCount = (m_dotCount + 1) % 5;
	}
	m_textLoading.setString(_TEXT_LOAD + std::string(m_dotCount, '.'));
}

void LoadingState::render(sf::RenderWindow& window)
{
	window.draw(*m_background);
	window.draw(m_textLoading);
	window.draw(*m_logo);
	return;
}

void LoadingState::pause()
{
}

void LoadingState::resume()
{
}

void LoadingState::exit()
{
}

bool LoadingState::isFinished() const
{
	return false;
}

void LoadingState::resetState()
{
	m_durationTime = 0.0f;
}
