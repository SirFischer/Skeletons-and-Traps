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
	if (!mSkyTexture.loadFromFile("assets/Textures/blue400x400.jpg"))
	{
		/* code */
	}

	mDirtSprite.setTexture(mDirtTexture);
	mGrassSprite.setTexture(mGrassTexture);
	mSkySprite.setTexture(mSkyTexture);

	mDirtSprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
	mGrassSprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
	mSkySprite.setTextureRect(sf::IntRect(0, 0, 100, 100));

	std::fstream				map;
	std::string					tmp;
	map.open(path);

	while (!map.eof())
	{
		std::getline(map, tmp);
		mMapLines.push_back(tmp);
	}
	
	
}

Map::~Map()
{
}

void Map::Draw(Window *tWindow)
{
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == '0')
			{
				mSkySprite.setPosition(x * 100, y * 100);
				tWindow->Draw(mSkySprite);
			}
			if (i[x] == '1')
			{
				mGrassSprite.setPosition(x * 100, y * 100);
				tWindow->Draw(mGrassSprite);
			}
			if (i[x] == '2')
			{
				mDirtSprite.setPosition(x * 100, y * 100);
				tWindow->Draw(mDirtSprite);
			}
		}
		y++;
	}
}

