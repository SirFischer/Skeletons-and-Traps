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


void				Entity::Attack(std::list<Entity *> tEntities, std::list<ParticleEffect> *tParticleEffects)
{
	if (mAttackClock.getElapsedTime().asSeconds() < mAttackCooldown)
		return ;
	mAttackClock.restart();
	(void)tParticleEffects;
	if (mVelocity.x < 0)
		mAction = EntityAction::ATTACK_LEFT;
	else
		mAction = EntityAction::ATTACK_RIGHT;
	if (mAnimations[mAction].IsDone())
	{
		mAnimations[mAction].ResetAnimation();
		for (auto &entity : tEntities)
		{
			if (entity->mSprite.getGlobalBounds().intersects(mSprite.getGlobalBounds() ))
			{
				entity->mHealth -= mAttackDamage;
				entity->mDeathClock.restart();
				if (entity->GetPosition().x + (entity->mSize.x / 2.f) < mPosition.x + (mSize.x / 2.f))
				{
					entity->mVelocity += sf::Vector2f(-5, -1);	
				}
				else
				{
					entity->mVelocity += sf::Vector2f(5, -1);
				}
				float angle = std::atan2(mPosition.y - entity->GetPosition().y, mPosition.x - entity->GetPosition().x) + (M_PI);
				ParticleEffect effect(entity->GetPosition() + (mSize / 2.f), 5.f, 3.f, 200, angle, 0.5f);
				effect.SetParticleColor(sf::Color::Red);
				tParticleEffects->push_back(effect);
			}
		}
	}	
}


void				Entity::Attack(Entity *tEntity, std::list<ParticleEffect> *tParticleEffects)
{
	(void)tParticleEffects;
	if (mAttackClock.getElapsedTime().asSeconds() < mAttackCooldown)
		return ;
	mAttackClock.restart();
	if (mVelocity.x < 0)
		mAction = EntityAction::ATTACK_LEFT;
	else
		mAction = EntityAction::ATTACK_RIGHT;
	if (mAnimations[mAction].IsDone())
	{
		mAnimations[mAction].ResetAnimation();
	
		if (tEntity->mSprite.getGlobalBounds().intersects(mSprite.getGlobalBounds()))
		{
			tEntity->mHealth -= mAttackDamage;
			tEntity->mDeathClock.restart();
			if (tEntity->GetPosition().x + (tEntity->mSize.x / 2.f) < mPosition.x + (mSize.x / 2.f))
			{
				tEntity->mVelocity += sf::Vector2f(-5, -1);	
			}
			else
			{
				tEntity->mVelocity += sf::Vector2f(5, -1);
			}
			float angle = std::atan2(mPosition.y - tEntity->GetPosition().y, mPosition.x - tEntity->GetPosition().x) + M_PI;
			ParticleEffect effect(tEntity->GetPosition() + (mSize / 2.f), 5.f, 3.f, 200, angle, 0.5f);
			effect.SetParticleColor(sf::Color::Red);
			tParticleEffects->push_back(effect);
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