#pragma once
#include "Window.hpp"
#include "Animation.hpp"
#include "Action.hpp"

#include <map>

class Entity
{
protected:

	sf::Sprite					mSprite;

	Action						mAction = Action::IDLE;

	std::map<Action, Animation>	mAnimations = std::map<Action, Animation>();

public:
	Entity(/* args */);
	~Entity();

	virtual void				Update() = 0;
	virtual void				Render(Window *tWindow) = 0;
};

