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

#include "Button.h"
#include <iostream>


Button::Button(sf::Texture* texture, sf::Vector2f position, BUTTON_TYPE type) 
{
    init(texture, position, type);
}

Button::~Button()
{
    if (m_sprite != nullptr)
        delete m_sprite;
    m_callbackFunction = nullptr;
    return;
}

void Button::init(sf::Texture* texture, sf::Vector2f position, BUTTON_TYPE type)
{
    // button type and button state
    m_buttonType = type;
    m_buttonState = BUTTON_STATE::DEFAULT;

    //button sprite and texture config
    m_sprite = new sf::Sprite(*texture);
    m_sprite->setPosition(position);
    m_sprite->setColor(ButtonDefaultColor);
    m_sprite->setScale(ButtonDefaultSize);
    sf::FloatRect bounds = m_sprite->getGlobalBounds();
    m_sprite->setOrigin(bounds.width / 2 , bounds.height / 2);
    return;
}

void Button::render(sf::RenderWindow& window)
{
    window.draw(*m_sprite);
    return;
}

void Button::update(float deltaTime, sf::RenderWindow& window)
{
    if (checkHover(window))
    {
        if (checkIsClicked(window))
        {
            m_sprite->setColor(ButtonActiveColor);
            m_sprite->setScale(ButtonActiveSize);
        }
        else
        {
            m_sprite->setColor(ButtonHoverColor);
            m_sprite->setScale(ButtonHoverSize);
        }
    }
    else
    {
        m_sprite->setColor(ButtonDefaultColor);
        m_sprite->setScale(ButtonDefaultSize);
    }
    return;
}

bool Button::checkIsClicked(sf::RenderWindow& window)
{
    bool check = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    if (check)
    {
        std::cout << "clicked button" << std::endl;
    }
    return check;
}

void Button::setCallBack(void(*callbackfunction)())
{
    m_callbackFunction = callbackfunction;
    return;
}


bool Button::checkHover(sf::RenderWindow& window)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    float x_mousePos = static_cast<float>(mousePosition.x);
    float y_mousePos = static_cast<float>(mousePosition.y);

    sf::FloatRect bounds = m_sprite->getGlobalBounds();
    if (bounds.contains(x_mousePos, y_mousePos))
    {
        return true;
    }
    return false;
}