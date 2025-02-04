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

#include "Enemy.h"
#include "../Hitbox.h"

Enemy::Enemy(sf::Texture *texture, sf::Vector2f position) :
                m_sprite(nullptr),
                m_texture(texture),
                m_position(position)
{
    init();
}

Enemy::~Enemy()
{
    if (m_sprite != nullptr)
        delete m_sprite;
    if (m_hitbox != nullptr)
        delete m_hitbox;
    return;
}

void Enemy::init()
{
    //m_sprite = new sf::Sprite(m_texture);
    //m_hitbox = new Hitbox()
}

void Enemy::update(float deltaTime)
{
}

void Enemy::render(sf::RenderWindow &window)
{
    window.draw(*m_sprite);
    return;
}

void Enemy::handleEvent(sf::Event &event)
{
}
