#ifndef IMAP_H
#define IMAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <list>

class Character;
class TileMapBase;


class IMap
{
public:
	IMap();
	~IMap();
	virtual void init();
	virtual void update(float deltaTime);
	virtual void render(sf::RenderWindow& window);
	virtual sf::Vector2f getViewPosition();

protected:
	sf::View* m_view;
	sf::Sprite* m_background;
	Character* m_character;

	std::vector<int> m_mapMatrix;
	TileMapBase* m_map;
	std::vector<int> m_decorMap;
	TileMapBase* m_decorMap;
};

#endif