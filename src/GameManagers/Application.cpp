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
    m_timer = 0.0f;
    m_deltaTime = 0.0f;
}

void Application::update()
{
    m_deltaTime = m_clock->restart().asSeconds();
    m_timer += m_deltaTime;
    sf::Event event;
    while (m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window->close(); 
        m_character->handlingEvent(event, m_deltaTime); 
    }
    m_character->update(m_deltaTime);
}

void Application::render()
{
    m_window->clear();

    m_character->render(*m_window);

    m_window->display();
}
