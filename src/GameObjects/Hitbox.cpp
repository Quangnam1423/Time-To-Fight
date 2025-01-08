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

#include "Hitbox.h"

Hitbox::Hitbox(sf::Vector2f &size, HITBOX_TYPE type)
    :   sf::RectangleShape(size), 
        m_type(type),
        m_isAlive(true),
        m_isOnPlatform(true)
        
{
    std::cout << "create hitbox" << std::endl;
}

Hitbox::~Hitbox()
{
}

bool Hitbox::isColliding(Hitbox &other) const
{
    return getGlobalBounds().intersects(other.getGlobalBounds());
}

bool Hitbox::isColliding(Hitbox &first, Hitbox &second) const
{
    return first.getGlobalBounds().intersects(second.getGlobalBounds());
}

HITBOX_TYPE Hitbox::getType()
{
    return m_type;
}
