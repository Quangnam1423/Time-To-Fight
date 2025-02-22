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
#include "GameManagers/GAMESTATE/GameState.h"
#include "GameManagers/GameManager.h"
#include "GameManagers/WindowManager.h"
#include "GameManagers/ResourceManager.h"

#include <iostream>

/*
* _MAIN_WINDOW get instance of WindowManager which is single object
* _GM get instance of GameManager which is single object
* DATA get instance of ResourceManager which is single object
* CAMERA get instance of CameraManager which is single object
* references : "GameManager.h", "ResourceManager.h", "WindowManager.h", "CameraManager.h"
*/

Application::Application() :
    m_elapsedTime(0.0f),
    m_deltaTime(0.0f)
{
    init();
}

Application::~Application()
{
    delete _GM;
    delete _MAIN_WINDOW;
    delete DATA;
}

void Application::run()
{
    m_clock->restart();
    while (_MAIN_WINDOW->isOpen())
    {
        update();
        render();
    }
}

void Application::init()
{
    _MAIN_WINDOW->setWindow(new sf::RenderWindow(sf::VideoMode(_WIDTH, _HEIGHT), _GAME_NAME));
    _MAIN_WINDOW->windowConfig(60, false);
    //m_window = new sf::RenderWindow(sf::VideoMode(_WIDTH, _HEIGHT),_GAME_NAME);
    m_clock = new sf::Clock();
    _GM->changeState(GAMESTATE::INTRODUCE_STATE);
}

void Application::update()
{
    sf::Event event;
    while (_MAIN_WINDOW->getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _MAIN_WINDOW->close();
        }
        if (_GM->currentState() != nullptr)
            _GM->currentState()->handleEvent(event);
    }
    m_deltaTime = m_clock->restart().asSeconds();
    m_elapsedTime += m_deltaTime;

    // UPDATE GAME CONTROLL
    if (_GM->needToChangeState())
    {
        _GM->performStateChange();
    }
    _GM->currentState()->update(m_deltaTime);
}

void Application::render()
{
    _MAIN_WINDOW->readyToDraw();
    _GM->currentState()->render(*_MAIN_WINDOW->getWindow());
    _MAIN_WINDOW->display();
}
