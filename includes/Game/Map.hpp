#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>

#include "Window.hpp"
#include "Entities.hpp"
#include "Player.hpp"
#include "ParticleEffect.hpp"
#include "Projectile.hpp"
#include "PowerUp.hpp"
#include "SoundPlayer.hpp"

#define		BLOCK_SIZE 64.f

class Map
{
private:
	sf::Texture					mSkyTexture;
	sf::Texture					mDirtTexture;
	sf::Texture					mDirt2Texture;
	sf::Texture					mDirt3Texture;
	sf::Texture					mDirt4Texture;
	sf::Texture					mGrassTexture;
	sf::Texture					mSpikeTexture;
	sf::Texture					mSpikeOnDirtTexture;
	sf::Texture					mGoalTexture;
	sf::Texture					mDeathTexture;
	sf::Texture					mSignTexture;
	sf::Texture					mBushTexture;
	sf::Texture					mWallTexture;
	sf::Texture					mWall4Texture;
	sf::Texture					mWalltopTexture;
	sf::Texture					mWall3Texture;
	sf::Texture					mDoorTexture;
	sf::Texture					mDoor2Texture;
	sf::Texture					mFloorTexture;
	sf::Texture					mWall2Texture;
	sf::Texture					mSign2Texture;
	sf::Texture					mDoor3Texture;
	sf::Texture					mWindowTexture;
	sf::Texture					mInvisbleTexture;
	sf::Texture					mForestBTexture;
	sf::Texture					mForestTTexture;
	sf::Texture					mTreeBTexture;
	sf::Texture					mTreeTTexture;
	sf::Texture					mShroomsTexture;
	sf::Texture					mShrooms2Texture;
	sf::Texture					mShroomforestTexture;
	sf::Texture					mWallbloodyTexture;
	sf::Texture					mWallskeletonTexture;
	sf::Texture					mSkeletonTexture;
	sf::Texture					mRoofRTexture;
	sf::Texture					mRoofLTexture;





	sf::Sprite					mInvisbleSprite;
	sf::Sprite					mForestBSprite;
	sf::Sprite					mForestTSprite;
	sf::Sprite					mTreeBSprite;
	sf::Sprite					mTreeTSprite;
	sf::Sprite					mShroomsSprite;
	sf::Sprite					mShrooms2Sprite;
	sf::Sprite					mShroomforestSprite;
	sf::Sprite					mWallbloodySprite;
	sf::Sprite					mWallskeletonSprite;
	sf::Sprite					mSkeletonSprite;
	sf::Sprite					mRoofRSprite;
	sf::Sprite					mRoofLSprite;
	sf::Sprite					mWall2Sprite;
	sf::Sprite					mWindowSprite;
	sf::Sprite					mSign2Sprite;
	sf::Sprite					mDoor3Sprite;
	sf::Sprite					mWallSprite;
	sf::Sprite					mWall4Sprite;
	sf::Sprite					mWall3Sprite;
	sf::Sprite					mWalltopSprite;
	sf::Sprite					mDoorSprite;
	sf::Sprite					mDoor2Sprite;
	sf::Sprite					mFloorSprite;
	sf::Texture					mSwordTexture;

	sf::Sprite					mDeathSprite;
	sf::Sprite					mGoalSprite;
	sf::Sprite					mSpikeSprite;
	sf::Sprite					mSpikeOnDirtSprite;
	sf::Sprite					mSkySprite;
	sf::Sprite					mDirtSprite;
	sf::Sprite					mDirt2Sprite;
	sf::Sprite					mDirt3Sprite;
	sf::Sprite					mDirt4Sprite;
	sf::Sprite					mGrassSprite;
	sf::Sprite					mSignSprite;
	sf::Sprite					mBushSprite;
	sf::Sprite					mSwordSprite;

	sf::Sound					mSound;

	sf::Vector2f				mGoalPos;

	std::vector<std::string>	mMapLines;

public:
	Map(std::string path);
	~Map();

	sf::Sprite				GetSprite(){return (mSpikeSprite);}

	bool					GetGoalStatus(Entity *tEntity);

	sf::Vector2f			GetGoalPosition(){return (mGoalPos);}

	void					HandleCollisions(Entity	*tEntity, std::list<ParticleEffect> *tParticleEffects);

	void					HandleParticleCollisions(ParticleEffect	*tEffect);
	void					HandleProjectileCollision(Projectile *tProjectile);

	void					SpawnEntities(std::list<Entity *> *tEntities);

	void					SpawnPowerUps(std::list<PowerUp> *tPowerUps);

	void					SpawnPlayer(Player *tPlayer);

	void					Draw(Window *tWindow);
};