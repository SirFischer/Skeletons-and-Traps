#pragma once

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "State.hpp"
#include "ResourceManager.hpp"
#include "Window.hpp"



#define		BLOCK_SIZE 64.f

class Goal
{
private:
	sf::Texture			mTexture;
	sf::Sprite			mSprite;
	Player				mPlayer;
	sf::Vector2f		mGoalPosition = sf::Vector2f(0, 0);
	



public:
	Goal();
	~Goal();

	sf::Vector2f				GetPosition(){return (mGoalPosition);}

	void		GoalTrigger();
	void		Draw(Window *tWindow);
};