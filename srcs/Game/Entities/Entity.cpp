#include "Entity.hpp"

Entity::Entity(/* args */)
{
}

Entity::~Entity()
{
}

void				Entity::ApplyAnimation()
{
	if (mAnimations.count(mAction))
		mSprite.setTextureRect(mAnimations[mAction].GetTextureRect());
	mAction = EntityAction::IDLE;
}


void				Entity::Attack(std::list<Entity *> tEntities)
{
	if (mVelocity.x < 0)
		mAction = EntityAction::ATTACK_LEFT;
	else
		mAction = EntityAction::ATTACK_RIGHT;
	if (mAnimations[mAction].IsDone())
	{
		mAnimations[mAction].ResetAnimation();
		for (auto &entity : tEntities)
		{
			if (entity->mSprite.getGlobalBounds().intersects(mSprite.getGlobalBounds()))
			{
				entity->mHealth -= mAttackDamage;
				entity->mDeathClock.restart();
				if (entity->GetPosition().x + (entity->mSize.x / 2.f) < mPosition.x + (mSize.x / 2.f))
					entity->mVelocity += sf::Vector2f(-5, -1);
				else
					entity->mVelocity += sf::Vector2f(5, -1);
			}
		}
	}	
}


void				Entity::MoveLeft()
{
	mVelocity.x -= mSpeed;
	mAction = EntityAction::WALK_LEFT;
}

void				Entity::MoveRight()
{
	mVelocity.x += mSpeed;
	mAction = EntityAction::WALK_RIGHT;
}

void				Entity::Jump()
{
	if (mOnGround)
		mVelocity.y -= mJumpForce;
}