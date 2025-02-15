#ifndef MAPBASE_H
#define MAPBASE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

class Character;
class TileMapBase;
class Hitbox;

class MapBase
{
public:
	virtual ~MapBase() = default;

	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void handleEvent(sf::Event& event) = 0;
	virtual sf::View getView() = 0;
protected:
	sf::Sprite* m_background;
	Character* m_character;

	// decor
	std::vector<int> m_decorMatrix;
	TileMapBase* m_decorMap;
	// map 
	std::vector<int> m_mapMatrix;
	TileMapBase* m_map;

	std::list<Hitbox*> m_mapHitbox;
};

#endif