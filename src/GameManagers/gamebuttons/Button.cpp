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

Button::Button(std::string name, 
                sf::Vector2f position, 
                sf::Vector2f size) :
                m_position(position), m_size(size)
{
    init(name);
}

Button::~Button()
{
}

void Button::init(std::string name)
{
    m_name = name;
    m_pathTexture = "resource/menubuttons/" + name + "button.png";
    sf::Texture texture;
    if (!texture.loadFromFile(m_name))
    {
        throw std::runtime_error("can't load texture from" + m_name);
    }
    m_shape = sf::RectangleShape(m_position);
    m_shape.setSize(m_size);
    
    m_text.setString
}

void Button::render(sf::RenderWindow &window)
{
    window.draw(m_shape);
    window.draw(m_text);
}

void Button::update(float deltaTime)
{
}

bool Button::isClicked() const
{
    return false;
}
