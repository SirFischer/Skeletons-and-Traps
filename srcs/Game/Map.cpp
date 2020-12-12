#include "Map.hpp"

Map::Map(std::string path)
{
	if (!mDirtTexture.loadFromFile("assets/Textures/dirt400x400.png"))
	{
	}
	if (!mGrassTexture.loadFromFile("assets/Textures/green400x400.png"))
	{
	}
	if (!mSkyTexture.loadFromFile("assets/Textures/blue400x400.jpg"))
	{
	}
	if (!mSpikeTexture.loadFromFile("assets/Textures/spike.png"))
	{
	}
	if (!mGoalTexture.loadFromFile("assets/Textures/flag.png"))
	{
	}
	if (!mDeathTexture.loadFromFile("assets/Textures/spike.png"))
	{
	}

	//Textures/sprites
	mDirtSprite.setTexture(mDirtTexture);
	mDeathSprite.setTexture(mDeathTexture);
	mGrassSprite.setTexture(mGrassTexture);
	mSkySprite.setTexture(mSkyTexture);
	mSpikeSprite.setTexture(mSpikeTexture);
	mGoalSprite.setTexture(mGoalTexture);


	mSpikeSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mDeathSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mGoalSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mDirtSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mGrassSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mSkySprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));

	std::fstream				map;
	std::string					tmp;
	map.open(path);

	//Read trough map file lines
	while (!map.eof())
	{
		std::getline(map, tmp);
		mMapLines.push_back(tmp);
	}
	
	
}

Map::~Map()
{
}

void				Map::HandleCollisions(Entity	*tEntity, std::list<ParticleEffect> *tParticleEffects)
{

	sf::Vector2f	size = tEntity->GetSize();
	sf::Vector2f	position = tEntity->GetPosition() + tEntity->mVelocity;
	sf::Vector2f	prevposition = tEntity->GetPosition();
	sf::Vector2i	index = sf::Vector2i((position.x - BLOCK_SIZE) / BLOCK_SIZE, (position.y - BLOCK_SIZE) / BLOCK_SIZE);

	tEntity->mCollisionDirection = Entity::CollisionDirection::NONE;
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

			if(mMapLines[y][x] == 'k')
			{
				int my = y * BLOCK_SIZE;
				int mx = x * BLOCK_SIZE;
				if((position.x < (mx + BLOCK_SIZE) && (position.x + size.x) > mx) && (position.y < (my + BLOCK_SIZE) && (position.y + size.y) > my + (BLOCK_SIZE / 4.f)) && tEntity->mHealth > 0)
				{
					//std::cout<<"Hit"<<std::endl;
					
					tEntity->mVelocity.y = 0.f;
					tEntity->mHealth -= 30.f;
					tEntity->mVelocity.y -= 3.f;
					tEntity->mVelocity.x += ((position.x + (size.x / 2.f)) - (mx + (BLOCK_SIZE / 2.f))) * 0.2f;
					ParticleEffect effect(sf::Vector2f((x * BLOCK_SIZE) + (BLOCK_SIZE / 2.f), y * BLOCK_SIZE), 3.f, 0.8f, 300);
					effect.SetParticleColor(sf::Color::Red);
					tParticleEffects->push_back(effect);
				}
			}
			if(mMapLines[y][x] == 'z')
			{
				int my = y * BLOCK_SIZE;
				int mx = x * BLOCK_SIZE;
				if((position.x < (mx + BLOCK_SIZE) && (position.x + size.x) > mx) && (position.y < (my + BLOCK_SIZE) && (position.y + size.y) > my) < my && tEntity->mHealth > 0)
				{
					//std::cout<<"Hit"<<std::endl;
					
					tEntity->mVelocity.y = 0.f;
					tEntity->mHealth -= 100.f;
					ParticleEffect effect(sf::Vector2f((x * BLOCK_SIZE) + (BLOCK_SIZE / 2.f), y * BLOCK_SIZE), 3.f, 0.8f, 600);
					effect.SetParticleColor(sf::Color::Red);
					tParticleEffects->push_back(effect);
					break ;
				}
			}

			//if block is solid
			if (mMapLines[y][x] == '.' || mMapLines[y][x] == '_'/* || mMapLines[y][x] == 'k'*/)
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
						tEntity->mCollisionDirection = Entity::CollisionDirection::BOTTOM;
						tEntity->mPosition = sf::Vector2f(prevposition.x, my - size.y);
						
					} else if ((angle < 45 || angle > 315) && tEntity->mVelocity.x > 0)
					{
						tEntity->mVelocity.x = 0;
						tEntity->mPosition = sf::Vector2f(mx - size.x, prevposition.y);
						tEntity->mCollisionDirection = Entity::CollisionDirection::RIGHT;
						tEntity->mIsBlocked = true;
					} else if ((angle > 135 && angle < 225) && tEntity->mVelocity.x < 0)
					{
						tEntity->mVelocity.x = 0;
						tEntity->mCollisionDirection = Entity::CollisionDirection::LEFT;
						tEntity->mPosition = sf::Vector2f(mx + BLOCK_SIZE, prevposition.y);
						tEntity->mIsBlocked = true;
					} else if ((angle > 235  && angle < 305) && tEntity->mVelocity.y < 0)
					{
						tEntity->mVelocity.y = 0;
						tEntity->mCollisionDirection = Entity::CollisionDirection::TOP;
						tEntity->mPosition = sf::Vector2f(prevposition.x, my + BLOCK_SIZE);
					}
					position = tEntity->GetPosition() + tEntity->mVelocity;
					prevposition = tEntity->GetPosition();
				}
			}
		}
	}
}

bool				Map::GetGoalStatus(Entity *tEntity)
{
	return ((tEntity->GetPosition().x < (mGoalPos.x + BLOCK_SIZE) && (tEntity->GetPosition().x + tEntity->GetSize().x) > mGoalPos.x) && (tEntity->GetPosition().y < (mGoalPos.y + BLOCK_SIZE) && (tEntity->GetPosition().y + tEntity->GetSize().y) > mGoalPos.y));
}

void				Map::HandleParticleCollisions(ParticleEffect	*tEffect)
{
	for (auto &particle : tEffect->mParticles)
	{
		sf::Vector2f	position = particle.mPos;
		sf::Vector2i	index = sf::Vector2i((position.x - BLOCK_SIZE) / BLOCK_SIZE, (position.y - BLOCK_SIZE) / BLOCK_SIZE);
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
				if (mMapLines[y][x] == '.' || mMapLines[y][x] == '_')
				{
					int mx = x * BLOCK_SIZE;
					int my = y * BLOCK_SIZE;
					//AABB collision?
					if ((position.x < (mx + BLOCK_SIZE) && position.x > mx) && (position.y < (my + BLOCK_SIZE) && position.y > my))
					{
						particle.mIsHit = true;
					}
				}
			}
		}
	}
}


//function to spawn enemy on map
void		Map::SpawnEntities(std::list<Entity *> *tEntities)
{
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == '3')
			{
				tEntities->push_front(new Skeleton());
				tEntities->front()->mPosition = sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
			}
		}
		y++;
	}
}

void		Map::SpawnPlayer(Player *tPlayer)
{
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == 's')
			{
				tPlayer->GetEntity()->mPosition = sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
			}
		}
		y++;
	}
}



//drawing sprites on map->screen
void		Map::Draw(Window *tWindow)
{
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == '.')
			{
				mGrassSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mGrassSprite);
			}
			if (i[x] == '_')
			{
				mDirtSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDirtSprite);
			}
			if (i[x] == 'k')
			{
				mSpikeSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mSpikeSprite);
			}
			if (i[x] == 'g')
			{
				mGoalSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				mGoalPos = sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mGoalSprite);
			}
			if (i[x] == 'z')
			{
				mDeathSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				//tWindow->Draw(mDeathSprite);
			}
		}
		y++;
	}
}
