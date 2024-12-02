#include "Application.h"
#include <iostream>

Application::Application()
{
    m_window = new sf::RenderWindow(sf::VideoMode(_WIDTH, _HEIGHT),_GAME_NAME);

    m_character = new Character(100.0f, 100.0f);
    std::cout << "check in here" << std::endl;
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
    m_clock.restart();
    sf::Event event;
    while (m_window->isOpen())
    {
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();

            
        }
        update();
        m_window->clear();
        render();
        m_window->display();
    }
}

void Application::init()
{
}

void Application::update()
{
    m_character->update();
}

void Application::render()
{
    m_character->render(*m_window);
}
