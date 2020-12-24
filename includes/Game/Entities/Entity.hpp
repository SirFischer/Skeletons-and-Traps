#pragma once
#include "Window.hpp"
#include "Animation.hpp"
#include "EntityAction.hpp"
#include "AIMode.hpp"
#include "ParticleEffect.hpp"
#include "Projectile.hpp"

#include <map>

class Entity
{
protected:
	enum class	Type {
		MELEE,
		ARCHER
	}							mType = Type::MELEE;
	enum class	Direction {
		RIGHT,
		LEFT
	}							mDirection;
	enum class	CollisionDirection {
		NONE,
		RIGHT,
		LEFT,
		BOTTOM,
		TOP
	}							mCollisionDirection;

	sf::Vector2f				mSize = sf::Vector2f(32, 48);
	sf::Vector2f				mPosition = sf::Vector2f(0, 0);
	sf::Vector2f				mVelocity = sf::Vector2f(0, 0);
	float						mHealth = 100.f;
	float						mAttackDamage = 30.f;
	float						mSpeed = 0.35f;
	float						mRunSpeed = 0.30f;
	float						mJumpForce = 6.5f;
	float						mViewDistance = 300.f;
	float						mVerticalViewDistance = 200.f;
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

	virtual void				Shoot(std::list<Projectile> *tProjectiles);

	void						Reset();

	void						HandleCollisions(std::list<Entity *> tEntities);

	void						MoveLeft();
	void						MoveRight();
	void						RunLeft();
	void						RunRight();
	void						Jump();

	sf::Sprite					GetSprite(){return (mSprite);}
	sf::Vector2f				GetPosition(){return (mPosition);}
	sf::Vector2f				GetVelocity(){return (mVelocity);}
	//sf::Vector2f				GetSize(){return (sf::Vector2f(mSprite.getGlobalBounds().width, mSprite.getGlobalBounds().height));}
	sf::Vector2f				GetSize(){return (mSize);}
	float						GetHealth(){return (mHealth);}
	bool						IsAlive(){return (mIsAlive);}
	friend class				Map;
	friend class				AI;
};

