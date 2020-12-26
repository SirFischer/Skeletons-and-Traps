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
	sf::Texture					mGrassTexture;
	sf::Texture					mSpikeTexture;
	sf::Texture					mGoalTexture;
	sf::Texture					mDeathTexture;

	sf::Sprite					mDeathSprite;
	sf::Sprite					mGoalSprite;
	sf::Sprite					mSpikeSprite;
	sf::Sprite					mSkySprite;
	sf::Sprite					mDirtSprite;
	sf::Sprite					mDirt2Sprite;
	sf::Sprite					mDirt3Sprite;
	sf::Sprite					mGrassSprite;

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