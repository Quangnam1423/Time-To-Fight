#include "TileMapBase.h"

std::list<TileInformation> TileMapBase::getMapCollider(sf::Vector2i baseSize, std::vector<int> tile, int width, int height)
{
	std::list<TileInformation> mapCollider;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			int tileNumber = tile[i + j * width];
			if (tileNumber == -1)
				continue;
			// above
			{
				int x = i;
				int y = j - 1;
				if (y < 0)
				{
					mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::DOWN });
				}
				if (x >= 0 && x < width && y >= 0 && y < height)
				{
					int aboveTile = tile[x + y * width];
					if (aboveTile == -1)
					{
						mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::DOWN });
					}
				}
			}
			// right
			{
				int x = i + 1;
				int y = j;
				if (x >= width)
				{
					mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::LEFT });
				}
				if (x >= 0 && x < width && y >= 0 && y < height)
				{
					int rightTile = tile[x + y * width];
					if (rightTile == -1)
					{
						mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::LEFT });
					}
				}
			}
			// below
			{
				int x = i;
				int y = j + 1;
				if (y >= height)
				{
					mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::UP });
				}
				if (x >= 0 && x < width && y >= 0 && y < height)
				{
					int belowTile = tile[x + y * width];
					if (belowTile == -1)
					{
						mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::UP });
					}
				}
			}
			// left
			{
				int x = i - 1;
				int y = j;
				if (x < 0)
				{
					mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::RIGHT });
				}
				if (x >= 0 && x < width && y >= 0 && y < height)
				{
					int leftTile = tile[x + y * width];
					if (leftTile == -1)
					{
						mapCollider.push_back({ {i * baseSize.x, j * baseSize.y}, DIRECTION::RIGHT });
					}
				}
			}// end for height
		}// end for width
	}
	return mapCollider;
}

bool TileMapBase::loadBase(sf::Texture* texture, sf::Vector2i baseSize, std::vector<int> tile, int width, int height)
{
    m_tileMapBase = texture;
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
			int tileNumber = tile[i + j * width];
			if (tileNumber == -1)
				continue;
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
