#ifndef GAMEONSTATE_H
#define GAMEONSTATE_H

#include "IGameState.h"
#include <list>

class MapBase;

class GameOnState : public IGameState
{
public:
	GameOnState();
	~GameOnState();

	void init() override;
	void cleanup() override;

	// handle state loop
	void handleEvent(sf::Event& event) override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;

	// manager state
	void pause() override;
	void resume() override;
	void exit() override;

	// check state if complete
	bool isFinished() const override;
private:
	MapBase* m_map;
};

#endif