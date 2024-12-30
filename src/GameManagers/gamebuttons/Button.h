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

#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

enum class BUTTON_STATE{
    IDLE,
    HOVER,
    ACTIVE
};

class Button
{
public:
    Button(std::string name, 
            sf::Vector2f position,
            sf::Vector2f size);
    ~Button();
    void init(std::string name);
    void render(sf::RenderWindow& window);
    void update(float deltaTime);

    bool isClicked() const;

private:
    void (*m_buttonClickedFunction)();
    sf::RectangleShape m_shape;
    sf::Font m_font;
    sf::Text m_text;
    sf::Vector2f m_posiiton;
    sf::Vector2f m_size;
    
    // sf::Color m_idleColor;
    // sf::Color m_hoverColor;
    // sf::Color m_activeColor;
    enum BUTTON_STATE m_ButtonState;
};

#endif