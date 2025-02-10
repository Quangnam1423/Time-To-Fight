#include "TileMapBase.h"

bool TileMapBase::loadBase(sf::Texture* texture, sf::Vector2i baseSize, std::vector<int> tile, int width, int height)
{
    m_tileMapBase = texture;
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
			int tileNumber = tile[i + j * width] - 1;
			int tu = tileNumber % (m_tileMapBase->getSize().x / baseSize.x);
			int tv = tileNumber / (m_tileMapBase->getSize().x / baseSize.x);

			sf::Vertex* square = &m_vertices[(i + j * width) * 4];

			square[0].position = sf::Vector2f(i * baseSize.x, j * baseSize.y);
			square[1].position = sf::Vector2f((i + 1) * baseSize.x, j * baseSize.y);
			square[2].position = sf::Vector2f((i + 1) * baseSize.x, (j + 1) * baseSize.y);
			square[3].position = sf::Vector2f(i * baseSize.x, (j + 1) * baseSize.y);

			square[0].texCoords = sf::Vector2f(tu * baseSize.x, tv * baseSize.y);
			square[1].texCoords = sf::Vector2f((tu + 1) * baseSize.x, tv * baseSize.y);
			square[2].texCoords = sf::Vector2f((tu + 1) * baseSize.x, (tv + 1) * baseSize.y);
			square[3].texCoords = sf::Vector2f(tu * baseSize.x, (tv + 1) * baseSize.y);
        }
    }
	return true;
}
