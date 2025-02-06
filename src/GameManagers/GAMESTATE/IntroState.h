#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "IGameState.h"

#include <SFML/Graphics.hpp>
#include <iostream>
class IntroState : public IGameState
{
public:
	IntroState();
	~IntroState();

	void init() override;
	void cleanup() override;

	// handle state loop

	void handleEvent(sf::Event& event) override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;

	//manager state
	void pause() override;
	void resume() override;
	void exit() override;

	// check state if complete
	bool isFinished() const override;
private:
	sf::Sprite* m_logo;
	sf::Sprite* m_background;
	float m_elapsedTime;
};

#endif