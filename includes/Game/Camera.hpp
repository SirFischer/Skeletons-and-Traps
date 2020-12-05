#pragma once

#include "Hero.hpp"

#include <SFML/Graphics.hpp>



class Camera
{
private:
	Hero				mCenter;
	sf::View			mView;
	sf::Sprite			mSprite;
	sf::Vector2f		mPosition;

public:
	Camera();
	~Camera();

	void	Update();
	void	Draw(Window *tWindow);
};