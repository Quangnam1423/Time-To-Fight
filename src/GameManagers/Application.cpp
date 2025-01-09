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

#include "Application.h"

#include "../GameObjects/player/Character.h"
#include "../GameObjects/player/Samurai.h"

#include <iostream>

Application::Application()
{
    init();
}

Application::~Application()
{
    if (m_window != nullptr)
        delete m_window;
    if (m_character != nullptr)
        delete m_character;
}

void Application::run()
{
    m_clock->restart();
    while (m_window->isOpen())
    {
        update();
        render();
    }
}

void Application::init()
{
    m_window = new sf::RenderWindow(sf::VideoMode(_WIDTH, _HEIGHT),_GAME_NAME);
    m_character = new Samurai(sf::Vector2f(100.0f, 100.0f));
    m_clock = new sf::Clock();

    m_window->setFramerateLimit(60);
    m_window->setVerticalSyncEnabled(false);

    m_timer = 0.0f;
    m_deltaTime = 0.0f;
}

void Application::update()
{
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window->close(); 
        m_character->handlingEvent(event); 
    }

    m_deltaTime = m_clock->restart().asSeconds();
    m_timer += m_deltaTime;
    m_character->update(m_deltaTime);
}

void Application::render()
{
    m_window->clear();

    m_character->render(*m_window);

    m_window->display();
}
