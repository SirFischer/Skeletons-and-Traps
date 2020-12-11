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

	bool						mGoalReached = false;

	std::vector<std::string>	mMapLines;

public:
	Map(std::string path);
	~Map();

	sf::Sprite				GetSprite(){return (mSpikeSprite);}

	bool					GetGoalStatus(){return (mGoalReached);}


	void					HandleCollisions(Entity	*tEntity);

	void					HandleParticleCollisions(ParticleEffect	*tEffect);

	void					SpawnEntities(std::list<Entity *> *tEntities);

	void					SpawnPlayer(Player *tPlayer);

	void					Draw(Window *tWindow);
};