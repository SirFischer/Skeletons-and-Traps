#include "Map.hpp"

Map::Map(std::string path)
{
	if (!mDirtTexture.loadFromFile("assets/Textures/dirt400x400.png"))
	{
	}
	if (!mDirt2Texture.loadFromFile("assets/Textures/dirt_w_grass.png"))
	{
	}
	if (!mDirt3Texture.loadFromFile("assets/Textures/dirt_w_vines.png"))
	{
	}
	if (!mDirt4Texture.loadFromFile("assets/Textures/BackgroundDirt.png"))
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
	if (!mSpikeOnDirtTexture.loadFromFile("assets/Textures/SpikeOnDirt.png"))
	{
	}
	if (!mGoalTexture.loadFromFile("assets/Textures/flag.png"))
	{
	}
	if (!mDeathTexture.loadFromFile("assets/Textures/spike.png"))
	{
	}
	if (!mSignTexture.loadFromFile("assets/Textures/Sign.png"))
	{
	}
	if (!mBushTexture.loadFromFile("assets/Textures/Bush.png"))
	{
	}
	if (!mWallTexture.loadFromFile("assets/Textures/wall.png"))
	{
	}
	if (!mWall4Texture.loadFromFile("assets/Textures/wall-background.png"))
	{
	}
	if (!mWalltopTexture.loadFromFile("assets/Textures/wall-top.png"))
	{
	}
	if (!mFloorTexture.loadFromFile("assets/Textures/floor.png"))
	{
	}
	if (!mDoor2Texture.loadFromFile("assets/Textures/door-open.png"))
	{
	}
	if (!mDoorTexture.loadFromFile("assets/Textures/door.png"))
	{
	}
	if (!mWall3Texture.loadFromFile("assets/Textures/wall-inside-door.png"))
	{
	}
	if (!mSwordTexture.loadFromFile("assets/Textures/BloodySword.png"))
	{
	}
	if (!mWall2Texture.loadFromFile("assets/Textures/wall-inside.png"))
	{
	}
	if (!mSign2Texture.loadFromFile("assets/Textures/danger-sign.png"))
	{
	}
	if (!mDoor3Texture.loadFromFile("assets/Textures/door-open-exit.png"))
	{
	}
	if (!mWindowTexture.loadFromFile("assets/Textures/window.png"))
	{
	}

	//Textures/sprites
	mDirtSprite.setTexture(mDirtTexture);
	mWindowSprite.setTexture(mWindowTexture);
	mWall2Sprite.setTexture(mWall2Texture);
	mSign2Sprite.setTexture(mSign2Texture);
	mDoor3Sprite.setTexture(mDoor3Texture);
	mDirt2Sprite.setTexture(mDirt2Texture);
	mDirt3Sprite.setTexture(mDirt3Texture);
	mDirt4Sprite.setTexture(mDirt4Texture);
	mDeathSprite.setTexture(mDeathTexture);
	mGrassSprite.setTexture(mGrassTexture);
	mSkySprite.setTexture(mSkyTexture);
	mSpikeSprite.setTexture(mSpikeTexture);
	mSpikeOnDirtSprite.setTexture(mSpikeOnDirtTexture);
	mGoalSprite.setTexture(mGoalTexture);
	mSignSprite.setTexture(mSignTexture);
	mBushSprite.setTexture(mBushTexture);
	mWallSprite.setTexture(mWallTexture);
	mWall4Sprite.setTexture(mWall4Texture);
	mWall3Sprite.setTexture(mWall3Texture);
	mWalltopSprite.setTexture(mWalltopTexture);
	mDoorSprite.setTexture(mDoorTexture);
	mDoor2Sprite.setTexture(mDoor2Texture);
	mFloorSprite.setTexture(mFloorTexture);
	mSwordSprite.setTexture(mSwordTexture);

	mWallSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mWall2Sprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mWall3Sprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mDoorSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mDoor2Sprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mFloorSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mWalltopSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mSpikeSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mDeathSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mGoalSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mDirtSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mGrassSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mSkySprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mSignSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mBushSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));
	mSwordSprite.setTextureRect(sf::IntRect(0, 0, BLOCK_SIZE, BLOCK_SIZE));

	std::fstream				map;
	std::string					tmp;
	map.open(path);

	//Read trough map file lines
	while (!map.eof())
	{
		std::getline(map, tmp);
		mMapLines.push_back(tmp);
	}
	
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == 'g')
			{
				mGoalPos = sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
			}
		}
		y++;
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

			if(mMapLines[y][x] == 'k' || mMapLines[y][x] == 'c')
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
			if (mMapLines[y][x] == '.' || mMapLines[y][x] == '_' || mMapLines[y][x] == 'y' || mMapLines[y][x] == '-' || mMapLines[y][x] == 'v' || mMapLines[y][x] == 'o' || mMapLines[y][x] == 'j' || mMapLines[y][x] == 'l'/* || mMapLines[y][x] == 'k'*/)
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
		if (particle.mIsHit)
			continue ;
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
				if (mMapLines[y][x] == '.' || mMapLines[y][x] == '_' || mMapLines[y][x] == '-' || mMapLines[y][x] == 'v' || mMapLines[y][x] == 'o' || mMapLines[y][x] == 'l' || mMapLines[y][x] == 'j' || mMapLines[y][x] == 'y')
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


void				Map::HandleProjectileCollision(Projectile *tProjectile)
{
	if (tProjectile->mIsHit)
		return ;
	sf::Vector2f	position = sf::Vector2f(tProjectile->mSprite.getGlobalBounds().left, tProjectile->mSprite.getGlobalBounds().top);
	sf::Vector2f	size = sf::Vector2f(tProjectile->mSprite.getGlobalBounds().width, tProjectile->mSprite.getGlobalBounds().height);
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
			if (mMapLines[y][x] == '.' || mMapLines[y][x] == '_' || mMapLines[y][x] == '-' || mMapLines[y][x] == 'v')
			{
				int mx = x * BLOCK_SIZE;
				int my = y * BLOCK_SIZE;
				//AABB collision?
				if ((position.x < (mx + BLOCK_SIZE) && position.x + size.x > mx) && (position.y < (my + BLOCK_SIZE) && position.y > my))
				{
					tProjectile->mIsHit = true;
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
			if (i[x] == '4')
			{
				tEntities->push_front(new DarkArcher());
				tEntities->front()->mPosition = sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
			}
			if (i[x] == '2')
			{
				tEntities->push_front(new Orc());
				tEntities->front()->mPosition = sf::Vector2f(x * BLOCK_SIZE, y * BLOCK_SIZE);
			}
		}
		y++;
	}
}

void			Map::SpawnPowerUps(std::list<PowerUp> *tPowerUps)
{
	int y = 0;
	for (auto &&i : mMapLines)
	{
		for (size_t x = 0; x < i.length(); x++)
		{
			if (i[x] == '+')
			{
				PowerUp powerUp(sf::Vector2f((x * BLOCK_SIZE) + 16, (y * BLOCK_SIZE + 16)));
				tPowerUps->push_front(powerUp);
				tPowerUps->front().SetEffect([](Entity *tEntity){
					tEntity->AddHealth(50.f);
					tEntity->PickUp();
				});
				tPowerUps->front().SetTexture("assets/Textures/healthPowerUp.png");
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
	sf::Vector2f	pos = tWindow->mView.getCenter();
	int				drawSize = 13;
	pos.x /= BLOCK_SIZE;
	pos.y /= BLOCK_SIZE;
	if (pos.y - drawSize < 0)
		pos.y = drawSize;
	if (pos.x - drawSize < 0)
		pos.x = drawSize;
	for (size_t y = pos.y - drawSize; y < pos.y + drawSize; y++)
	{
		if (y >= mMapLines.size())
			break;
		std::string &i = mMapLines[y];
		for (size_t x = pos.x - drawSize; x < pos.x + drawSize; x++)
		{
			if (x >= i.length())
				break;
			if (i[x] == '.')
			{
				mGrassSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mGrassSprite);
			}
			if ((i[x] == '3' || i[x] == '4' || i[x] == '2' || i[x] == 'n' || i[x] == '+' || i[x] == 'i' || i[x] == 'k') && mMapLines[y - 1][x] == ',')
			{
				mDirt4Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDirt4Sprite);
			}
			if ((i[x] == '3' || i[x] == '4' || i[x] == '2' || i[x] == 'n' || i[x] == '+' || i[x] == 'i' || i[x] == 'k') && mMapLines[y - 1][x] == 'h')
			{
				mWall4Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mWall4Sprite);
			}
			if (i[x] == 'i')
			{
				mSignSprite.setPosition(x * BLOCK_SIZE, (y * BLOCK_SIZE) + 5);
				tWindow->Draw(mSignSprite);
			}
			if (i[x] == 'b')
			{
				mBushSprite.setPosition(x * BLOCK_SIZE, (y * BLOCK_SIZE) + 5);
				tWindow->Draw(mBushSprite);
			}
			if (i[x] == 'n')
			{
				mSwordSprite.setPosition(x * BLOCK_SIZE, (y * BLOCK_SIZE) + 5);
				tWindow->Draw(mSwordSprite);
			}
			if (i[x] == '_')
			{
				mDirtSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDirtSprite);
			}
			if (i[x] == ',')
			{
				mDirt4Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDirt4Sprite);
			}
			if (i[x] == 'v')
			{
				mDirt3Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDirt3Sprite);
			}
			if (i[x] == '-')
			{
				mDirt2Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDirt2Sprite);
			}
			if (i[x] == 'k')
			{
				mSpikeSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mSpikeSprite);
			}
			if (i[x] == 'c')
			{
				mSpikeOnDirtSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mSpikeOnDirtSprite);
			}
			if (i[x] == 'g')
			{
				mGoalSprite.setPosition(x * BLOCK_SIZE, (y * BLOCK_SIZE) + 5);
				tWindow->Draw(mGoalSprite);
			}
			if (i[x] == 'z')
			{
				mDeathSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				//tWindow->Draw(mDeathSprite);
			}
			if (i[x] == 'o')
			{
				mWallSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mWallSprite);
			}
			if (i[x] == 'h')
			{
				mWall4Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mWall4Sprite);
			}
			if (i[x] == 'q')
			{
				mWall3Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mWall3Sprite);
			}
			if (i[x] == 'j')
			{
				mWalltopSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mWalltopSprite);
			}
			if (i[x] == 'l')
			{
				mFloorSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mFloorSprite);
			}
			if (i[x] == 'd')
			{
				mDoorSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDoorSprite);
			}
			if (i[x] == 'f')
			{
				mDoor2Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDoor2Sprite);
			}
			if (i[x] == '<')
			{
				mDoor3Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mDoor3Sprite);
			}
			if (i[x] == 'a')
			{
				mSign2Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mSign2Sprite);
			}
			if (i[x] == 'y')
			{
				mWall2Sprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mWall2Sprite);
			}
			if (i[x] == '!')
			{
				mWindowSprite.setPosition(x * BLOCK_SIZE, y * BLOCK_SIZE);
				tWindow->Draw(mWindowSprite);
			}
			
		}
	}
}
