#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>

#include "Window.hpp"
#include "Entities.hpp"
#include "Player.hpp"

#define		BLOCK_SIZE 64.f

class Map
{
private:
	sf::Texture				mSkyTexture;
	sf::Texture				mDirtTexture;
	sf::Texture				mGrassTexture;

	sf::Sprite				mSkySprite;
	sf::Sprite				mDirtSprite;
	sf::Sprite				mGrassSprite;

	std::vector<std::string>	mMapLines;

public:
	Map(std::string path);
	~Map();

	void					HandleCollisions(Entity	*tEntity);

	void					SpawnEntities(std::list<Entity *> *tEntities);

	void					SpawnPlayer(Player *tPlayer);

	void					Draw(Window *tWindow);
};