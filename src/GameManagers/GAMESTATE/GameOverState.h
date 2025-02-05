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

#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H

#include "IGameState.h"
#include <list>

class Button;

class GameOverState : public IGameState
{
public:
	GameOverState();
	~GameOverState();

	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;
	void exit() override;
	
	// handle state loop

	void handleEvent(sf::Event& event) override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;

	// check state if complete
	bool isFinished() const override;
private:
	sf::Sprite* m_background;
	std::list<Button*> m_buttons;
};


#endif