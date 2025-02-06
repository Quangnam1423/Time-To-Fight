#ifndef INFORMATION_STATE_H
#define INFORMATION_STATE_H

#include "IGameState.h"
#include <list>
#include <vector>



class Button;

class InformationState : public IGameState
{
public:
	InformationState();
	~InformationState();

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
	float m_elapsedTime;

	std::vector<std::string> m_lines;
	std::vector<sf::Text> m_textLines;
	sf::Font* m_font;
	std::string m_displayText;
	int m_index;
	int m_lineIndex;

	sf::Sprite* m_background;
	std::list<Button*> m_buttons;
};

#endif

