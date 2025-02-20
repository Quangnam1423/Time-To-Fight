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

#include "WindowManager.h"

WindowManager::WindowManager()
{
	m_window = nullptr;
}

WindowManager::~WindowManager()
{
}

void WindowManager::setWindow(sf::RenderWindow* window)
{
	m_window = window;
	m_defaultView = window->getDefaultView();
	return;
}

void WindowManager::windowConfig(int frameRateLimit, bool verticalSync)
{
	m_window->setFramerateLimit(frameRateLimit);
	m_window->setVerticalSyncEnabled(verticalSync);
}

sf::RenderWindow* WindowManager::getWindow()
{
	return m_window;
}

bool WindowManager::isOpen()
{
	return m_window->isOpen();
}

void WindowManager::readyToDraw()
{
	//m_defaultView.setViewport(sf::FloatRect(0.f, 0.f, 0.5f, 1.f));
	m_window->setView(m_defaultView);
	m_window->clear(sf::Color::White);
	return;
}

void WindowManager::close()
{
	m_window->close();
}

void WindowManager::display()
{
	m_window->display();
}
