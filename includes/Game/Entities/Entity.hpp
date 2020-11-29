#pragma once
#include "Window.hpp"
#include "Animation.hpp"
#include "EntityAction.hpp"

#include <map>

class Entity
{
protected:

	sf::Sprite					mSprite;

	EntityAction				mAction = EntityAction::IDLE;

	std::map<EntityAction, Animation>	mAnimations = std::map<EntityAction, Animation>();

public:
	Entity(/* args */);
	~Entity();

	virtual void				Update() = 0;
	virtual void				Render(Window *tWindow) = 0;
};

