#ifndef MAP1_H
#define MAP1_H
#include "MapBase.h"

class PhysicManager;

class Map1 : public MapBase
{
public:
	Map1();
	~Map1();
	void init() override;
	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) override;
	void handleEvent(sf::Event& event) override;
	sf::View getView() override;

private:
	PhysicManager* m_physicControll;
};

#endif