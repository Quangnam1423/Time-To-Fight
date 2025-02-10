#ifndef MAP01_H
#define MAP01_h

#include "IMap.h"
class Map01 : public IMap
{
public:
	void init() override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;
	virtual sf::Vector2f getViewPosition();
	bool IsWin();
	bool IsLose();
private:
	bool m_isWin;
	bool m_isLose;
};

#endif