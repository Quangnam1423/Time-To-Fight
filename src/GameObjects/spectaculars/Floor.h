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
#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define _FLOOR_LEVEL 100.0f

class Hitbox;

class Floor
{
public:
	Floor();
	~Floor();
	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
	Hitbox* getHitbox();
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	void setStatus(bool drawable);
private:
	sf::Sprite* m_sprite;
	Hitbox* m_hitbox;
	sf::Vector2f m_position;
	sf::vector2f m_size;

	float m_elapsedTime;
	float m_durationTime;
	float deltaTime;
	bool m_drawable;
};

#endif