#pragma once
#ifndef TILE_MAP_BASE_H
#define TILE_MAP_BASE_H

#include <SFML/Graphics.hpp>
#include <list>

class TileMapBase : public sf::Drawable, public sf::Transformable
{
public:
	std::list<sf::Vector2i> getMapCollider(sf::Vector2i baseSize, std::vector<int> tile, int width, int height);
	bool loadBase(sf::Texture* texture, sf::Vector2i baseSize, std::vector<int> tile, int width, int height);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = m_tileMapBase;
		target.draw(m_vertices, states);

	}
private:
	sf::VertexArray m_vertices;
	sf::Texture* m_tileMapBase;
};

#endif