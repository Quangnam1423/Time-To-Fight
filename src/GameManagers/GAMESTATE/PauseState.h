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

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include <SFML/Graphics.hpp>
#include <list>
#include "IGameState.h"

class Button;

class PauseState : public IGameState
{
public:
	PauseState();
	~PauseState();

	void init() override;
	void cleanup() override;
	void handleEvent(sf::Event& event) override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;
	void pause() override;
	void resume() override;
	void exit() override;
	bool isFinished() const override;
private:
	//sf::Sprite* m_background;
	sf::Sprite* m_logo;
	std::list<Button*> m_buttons;
	sf::RectangleShape m_overlay;
};

#endif