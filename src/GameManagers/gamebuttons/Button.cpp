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

Button::Button(IGameState* gameState, 
                sf::Texture* texture, 
                void(*buttonClickedFunction)(), 
                sf::Vector2f position, 
                std::string name, 
                BUTTON_TYPE type) :
        m_gameState(gameState),
        m_texture(texture),
        m_buttonClickedFunction(buttonClickedFunction),
        m_position(position),
        m_name(name),
        m_buttonType(type),
        m_buttonState(BUTTON_STATE::IDLE),
        m_elapsedTime(0.0f),
        m_animationTime(0.0f),
        m_animationActiveTime(0.0f)
{
    m_sprite = nullptr;
    init();
}

Button::~Button()
{
    if (m_sprite != nullptr)
        delete m_sprite;
    if (m_texture != nullptr)
        delete m_texture;
    return;
}

void Button::init()
{
    m_sprite = new sf::Sprite(*m_texture);
    m_sprite->setOrigin(m_position);
    m_sprite->setScale(_IDLE_SCALE);

    sf::Vector2u textureSize = m_texture->getSize();
    m_hoverShape = sf::RectangleShape((sf::Vector2f)textureSize);
    m_hoverShape.setOrigin(m_position);
    m_hoverShape.setScale(_IDLE_SCALE);
    m_hoverShape.setFillColor(_HOVERSHAPE_COLOR);
    return;
}

void Button::render(sf::RenderWindow &window)
{
    if (m_buttonState == BUTTON_STATE::HOVER)
    {
        m_hoverShape.setScale(_HOVER_SCALE);
        m_sprite->setScale(_IDLE_SCALE);
        window.draw(m_hoverShape);

    }
    else if (m_buttonState == BUTTON_STATE::ACTIVE)
    {
        m_hoverShape.setScale(_IDLE_SCALE);
        m_sprite->setScale(_ACTIVE_SCALE);
        window.draw(m_hoverShape);
    }
    else 
    {
        m_hoverShape.setScale(_IDLE_SCALE);
        m_sprite->setScale(_IDLE_SCALE);
    }
    window.draw(m_hoverShape);
    return;
}

void Button::update(float deltaTime)
{   
    m_elapsedTime += deltaTime;
}

bool Button::isClicked(sf::RenderWindow& window)
{ 
    if (checkHover(window) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
         return true;
    }
    return false;
}

std::string Button::getName()
{
    return m_name;
}

void Button::setCallbackFunction(void (*buttonClickedFunction)())
{
    m_buttonClickedFunction = buttonClickedFunction;
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

void Button::setGameState(IGameState* gameState)
{
    m_gameState = gameState;
    return;
}

void Button::setPosition(sf::Vector2f position)
{
    m_position = position;
    m_sprite->setPosition(m_position);
    m_hoverShape.setPosition(m_position);
    return;
}

