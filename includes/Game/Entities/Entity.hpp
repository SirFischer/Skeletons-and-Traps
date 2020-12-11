#pragma once
#include "Window.hpp"
#include "Animation.hpp"
#include "EntityAction.hpp"
#include "AIMode.hpp"
#include "ParticleEffect.hpp"

#include <map>

class Entity
{
protected:
	sf::Vector2f				mSize = sf::Vector2f(32, 48);
	sf::Vector2f				mPosition = sf::Vector2f(0, 0);
	sf::Vector2f				mVelocity = sf::Vector2f(0, 0);
	float						mHealth = 100.f;
	float						mAttackDamage = 30.f;
	float						mSpeed = 0.35f;
	float						mJumpForce = 6.f;
	float						mViewDistance = 300.f;
	bool						mOnGround = false;
	bool						mIsAlive = true;
	bool						mIsBlocked = false;
	float						mAttackCooldown = 0.55f;

	AIMode						mAIMode = AIMode::PATROL;
	EntityAction				mAIAction = EntityAction::WALK_RIGHT;

	sf::Clock					mDeathClock;
	sf::Clock					mAttackClock;

	sf::Sprite					mSprite;

	EntityAction				mAction = EntityAction::IDLE;

	std::map<EntityAction, Animation>	mAnimations = std::map<EntityAction, Animation>();

	virtual void				ApplyAnimation();

public:
	Entity(/* args */);
	virtual ~Entity();

	virtual void				Update() = 0;
	virtual void				Render(Window *tWindow) = 0;

	virtual void				Attack(std::list<Entity *> tEntities, std::list<ParticleEffect> *tParticleEffects);
	virtual void				Attack(Entity *tEntity, std::list<ParticleEffect> *tParticleEffects);


	void						MoveLeft();
	void						MoveRight();
	void						Jump();

	sf::Vector2f				GetPosition(){return (mPosition);}
	//sf::Vector2f				GetSize(){return (sf::Vector2f(mSprite.getGlobalBounds().width, mSprite.getGlobalBounds().height));}
	sf::Vector2f				GetSize(){return (mSize);}
	float						GetHealth(){return (mHealth);}
	bool						IsAlive(){return (mIsAlive);}
	friend class				Map;
	friend class				AI;
};

