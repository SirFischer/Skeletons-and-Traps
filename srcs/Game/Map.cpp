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

	mDirtSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mGrassSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mSkySprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));

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

void				Map::HandleCollisions(Entity	*tEntity)
{
	sf::Vector2f	size = tEntity->GetSize();
	sf::Vector2f	position = tEntity->GetPosition() + tEntity->mVelocity;
	sf::Vector2f	prevposition = tEntity->GetPosition();
	sf::Vector2i	index = sf::Vector2i((position.x - BLOCK_SIZE) / BLOCK_SIZE, (position.y - BLOCK_SIZE) / BLOCK_SIZE);
	tEntity->mOnGround = false;
	index.x = (index.x < 0) ? 0 : index.x;
	index.y = (index.y < 0) ? 0 : index.y;
	for (int y = index.y; y < index.y + 3; y++)
	{
		if (y >= (int)mMapLines.size())
				break;
		for ( int x = index.x; x < index.x + 3; x++)
		{
			if (x >= (int)mMapLines[y].length())
				break;
			//if block is solid
			if (mMapLines[y][x] == '1')
			{
				int mx = x * BLOCK_SIZE;
				int my = y * BLOCK_SIZE;
				//AABB collision?
				if ((position.x < (mx + BLOCK_SIZE) && (position.x + size.x) > mx) && (position.y < (my + BLOCK_SIZE) && (position.y + size.y) > my))
				{
					float middleX =  (position.x + (size.x / 2.0)) - (mx + (BLOCK_SIZE / 2.0));
					float middleY = (position.y + (size.y / 2.0)) - (my + (BLOCK_SIZE / 2.0));
					float angle = std::atan2(middleY, middleX) + M_PI;
					angle = ((angle / 3.1416) * 180.0);
					if ((angle > 45 && angle < 135) && tEntity->mVelocity.y > 0)
					{
						tEntity->mVelocity.y = 0;
						tEntity->mOnGround = true;
						tEntity->mPosition = sf::Vector2f(prevposition.x, my - size.y);
						
					} else if ((angle < 45 || angle > 315) && tEntity->mVelocity.x > 0)
					{
						tEntity->mVelocity.x = 0;
						tEntity->mPosition = sf::Vector2f(mx - size.x, prevposition.y);
					} else if ((angle > 225  && angle < 315) && tEntity->mVelocity.y < 0)
					{
						tEntity->mVelocity.y = 0;
						tEntity->mPosition = sf::Vector2f(prevposition.x, my + BLOCK_SIZE);
					} else if ((angle > 135 && angle < 225) && tEntity->mVelocity.x < 0)
					{
						tEntity->mVelocity.x = 0;
						tEntity->mPosition = sf::Vector2f(mx + BLOCK_SIZE, prevposition.y);
					}
					position = tEntity->GetPosition() + tEntity->mVelocity;
					prevposition = tEntity->GetPosition();
				}
			}
			
		}
	}
}

void		Map::SpawnEntities(std::list<Entity *> *tEntities)
{
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == '3')
			{
				Hero *entity = new Hero();
				entity->mPosition = sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tEntities->push_front(entity);
			}
		}
		y++;
	}
}

void		Map::Draw(Window *tWindow)
{
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == '0')
			{
				mSkySprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mSkySprite);
			}
			if (i[x] == '1')
			{
				mGrassSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mGrassSprite);
			}
			if (i[x] == '2')
			{
				mDirtSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDirtSprite);
			}
		}
		y++;
	}
}

