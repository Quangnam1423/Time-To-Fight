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

#ifndef HITBOX_H
#define HITBOX_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define _CHECk_COLLISION(x, y) Hitbox::isColliding(x, y)

enum class HITBOX_TYPE
{
    CHARACTER,
    MONSTER,
    MAP,
    SAW,
    SAND,
    WIND,
    FLOOR
};



class Hitbox : public sf::RectangleShape
{
public:
    Hitbox(sf::Vector2f& size, HITBOX_TYPE type);
    ~Hitbox();

    bool isColliding(Hitbox& other) const;
    static bool isColliding(Hitbox& first, Hitbox& second) const;
    HITBOX_TYPE getType();
private:
    sf::Vector2f m_velocity;
    enum HITBOX_TYPE m_type;
    bool m_isAlive;
    bool m_isOnPlatform;
    sf::Vector2f m_offset;
};

#endif