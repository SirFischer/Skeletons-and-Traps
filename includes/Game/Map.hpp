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

#define		BLOCK_SIZE 64.f

class Map
{
private:
	sf::Texture					mSkyTexture;
	sf::Texture					mDirtTexture;
	sf::Texture					mGrassTexture;
	sf::Texture					mSpikeTexture;
	sf::Texture					mGoalTexture;

	sf::Sprite					mGoalSprite;
	sf::Sprite					mSpikeSprite;
	sf::Sprite					mSkySprite;
	sf::Sprite					mDirtSprite;
	sf::Sprite					mGrassSprite;

	sf::Vector2f				mGoalPos;

	std::vector<std::string>	mMapLines;

public:
	Map(std::string path);
	~Map();

	sf::Sprite				GetSprite(){return (mSpikeSprite);}

	bool					GetGoalStatus(Entity *tEntity);

	void					HandleCollisions(Entity	*tEntity, std::list<ParticleEffect> *tParticleEffects);

	void					HandleParticleCollisions(ParticleEffect	*tEffect);

	void					SpawnEntities(std::list<Entity *> *tEntities);

	void					SpawnPlayer(Player *tPlayer);

	void					Draw(Window *tWindow);
};