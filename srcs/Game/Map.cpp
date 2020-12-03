#include "Map.hpp"

Map::Map(std::string path)
{
	if (!mDirtTexture.loadFromFile("assets/Textures/dirt400x400.png"))
	{
		/* code */
	}
	if (!mGrassTexture.loadFromFile("assets/Textures/green400x400.png"))
	{
		/* code */
	}
	if (!mSkyTexture.loadFromFile("assets/Textures/blue400x400.png"))
	{
		/* code */
	}

	mDirtSprite.setTexture(mDirtTexture);
	mGrassSprite.setTexture(mGrassTexture);
	mSkySprite.setTexture(mSkyTexture);

	std::fstream				map;
	std::string					tmp;
	map.open(path);

	mDirtSprite.setScale(sf::Vector2f(1, 1));
	mGrassSprite.setScale(sf::Vector2f(1, 1));
	mSkySprite.setScale(sf::Vector2f(1, 1));

	while (!map.eof())
	{
		std::getline(map, tmp);
		mMapLines.push_back(tmp);
	}
	
	
}

Map::~Map()
{
}

	void Map::draw(sf::RenderWindow &window)
	{
		int y = 0;
		for (auto &&i : mMapLines)
		{
			for (size_t x = 0; x < i.length(); x++)
			{
				if (i[x] == '0')
				{
					mSkySprite.setPosition(x * 100, y * 100);
					window.draw(mSkySprite);
				}
				if (i[x] == '1')
				{
					mGrassSprite.setPosition(x * 100, y * 100);
					window.draw(mGrassSprite);
				}
				if (i[x] == '2')
				{
					mDirtSprite.setPosition(x * 100, y * 100);
					window.draw(mDirtSprite);
				}
			}
		}
		y++;
	}

