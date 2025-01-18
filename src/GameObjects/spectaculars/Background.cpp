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

#include "Background.h"
#include "../../GameManagers/Resource.h"

Background::Background()
{
	init();
}

Background::~Background()
{
	if (m_sprite != nullptr)
		delete m_sprite;
	return;
}

void Background::init()
{
	std::string backgroundPath = "";
	m_texture = _RM->getTexture(backgroundPath, TEXTURE_TYPE::ENVIROMENT);
	m_sprite->setTexture(*m_texture);
	m_sprite->setScale(_SCALE_BG, _SCALE_BG);

	return;
}

void Background::update(float deltaTime)
{

}

void Background::render(sf::RenderWindow& window)
{
	window.draw(*m_sprite);
	return;
}