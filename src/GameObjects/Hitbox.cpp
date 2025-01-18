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

Hitbox::Hitbox(sf::Vector2f size, sf::Vector2f position)
			:
	sf::RectangleShape(size)
{
	
	setPosition(position);
}

Hitbox::~Hitbox()
{
}

void Hitbox::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
	return;
}

bool Hitbox::checkCollison(const Hitbox& other) const
{
	return this->getGlobalBounds().intersects(other.getGlobalBounds());
}

void Hitbox::setStatus(Status status)
{
	m_status = status;
	return;
}

Status Hitbox::getStatus()
{
	return m_status;
}
