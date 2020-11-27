#pragma once
#include "Window.hpp"

class Entity
{
protected:
	sf::Texture		mTexture;
	sf::Sprite		mSprite;

public:
	Entity(/* args */);
	~Entity();

	virtual void	Update() = 0;
	virtual void	Render(Window *tWindow) = 0;
};

