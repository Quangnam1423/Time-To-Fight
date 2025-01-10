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

#include "Camera.h"
#include "../GameManagers/GameManager.h"
#include "../GameObjects/player/Character.h"

#include <iostream>

Camera::Camera()
{
    std::cout << "create camera for player" << std::endl;
    init();
}

Camera::Camera(sf::Vector2f size, sf::Vector2f center) :
            m_cameraPosition(center), 
            m_size(size),
            m_durationTime(0.0f),
            m_elapsedTime(0.0f)
{
    std::cout << "create camera for player" << std::endl;
    init();
}

Camera::~Camera()
{
    if (m_view != nullptr)
        delete m_view;
    return;
}

void Camera::init()
{
    m_gameManager = nullptr;
    m_character = nullptr;
    m_view = nullptr;
}

void Camera::update(float deltaTime)
{
    m_elapsedTime += deltaTime;

    return;
}

void Camera::handleEvent(sf::Event &event)
{
    // check if character is alive
    //bool isAlive = m_character->


    // handle character turn right
    if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {

    }
    // handle character turn left
    if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

    }
    // handle character jump
    if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {

    }
    return;
}

sf::View* Camera::getView()
{
    if (m_view == nullptr)
        return nullptr;
    // calculate new view if had changed on event queue
    // check if character is alive
    
    return m_view;
}

void Camera::setCharater(Character *character)
{
    m_character = character;
    return;
}

void Camera::setGameManager(GameManager *gameManager)
{
    m_gameManager = gameManager;
    return;
}

Character *Camera::getCharacter()
{
    return m_character;
}

GameManager *Camera::getGameManager()
{
    return m_gameManager;
}

void Camera::setAspect(sf::Vector2u windowSize)
{
    m_aspect = (float)windowSize.x / (float)windowSize.y;
    return;
}
