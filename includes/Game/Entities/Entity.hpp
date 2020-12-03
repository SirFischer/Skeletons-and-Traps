#pragma once
#include "Window.hpp"
#include "Animation.hpp"
#include "EntityAction.hpp"

#include <map>

class Entity
{
protected:
	sf::Vector2f				mPosition = sf::Vector2f(0, 0);
	sf::Vector2f				mVelocity = sf::Vector2f(0, 0);
	float						mSpeed = 0.2f;
	float						mJumpForce = 2.f;

	sf::Sprite					mSprite;

	EntityAction				mAction = EntityAction::IDLE;

	std::map<EntityAction, Animation>	mAnimations = std::map<EntityAction, Animation>();

public:
	Entity(/* args */);
	~Entity();

	virtual void				Update() = 0;
	virtual void				Render(Window *tWindow) = 0;

	void						MoveLeft();
	void						MoveRight();
	void						Jump();

	sf::Vector2f				GetPosition(){return (mPosition);}
	sf::Vector2f				GetSize(){return (sf::Vector2f(mSprite.getGlobalBounds().width, mSprite.getGlobalBounds().height));}
	friend class				Map;
};

