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
	if (mDirection == Direction::LEFT)
		mAction = EntityAction::ATTACK_LEFT;
	else
		mAction = EntityAction::ATTACK_RIGHT;
	if (mAnimations[mAction].IsDone())
	{
		mAnimations[mAction].ResetAnimation();
		for (auto &entity : tEntities)
		{

			if ((mDirection == Direction::LEFT && (entity->GetPosition().x + entity->GetSize().x > mPosition.x - (mSize.x / 2.f) && entity->GetPosition().x < mPosition.x + (mSize.x / 2.f))) ||
				(mDirection == Direction::RIGHT && (entity->GetPosition().x + entity->GetSize().x > mPosition.x + (mSize.x / 2.f) && entity->GetPosition().x < mPosition.x + (1.5 * mSize.x))))
			{
				entity->mHealth -= mAttackDamage;
				entity->mDeathClock.restart();
				sf::Vector2f	particlePos = entity->GetPosition() + (mSize / 2.f);
				if (entity->GetPosition().x + (entity->mSize.x / 2.f) < mPosition.x + (mSize.x / 2.f))
				{
					entity->mVelocity += sf::Vector2f(-5, -1);
					particlePos.x -= 20;
				}
				else
				{
					entity->mVelocity += sf::Vector2f(5, -1);
					particlePos.x += 20;
				}
				float angle = std::atan2(mPosition.y - entity->GetPosition().y, mPosition.x - entity->GetPosition().x) + M_PI;
				ParticleEffect effect(particlePos, 3.f, 0.8f, 300, angle, M_PI / 3.5f);
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
	if (mDirection == Direction::LEFT)
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
			sf::Vector2f	particlePos = tEntity->GetPosition() + (mSize / 2.f);
			if (tEntity->GetPosition().x + (tEntity->mSize.x / 2.f) < mPosition.x + (mSize.x / 2.f))
			{
				tEntity->mVelocity += sf::Vector2f(-5, -1);
				particlePos.x -= 20;
			}
			else
			{
				tEntity->mVelocity += sf::Vector2f(5, -1);
				particlePos.x += 20;

			}
			float angle = std::atan2(mPosition.y - tEntity->GetPosition().y, mPosition.x - tEntity->GetPosition().x) + M_PI;
			ParticleEffect effect(particlePos, 3.f, 0.8f, 300, angle, M_PI / 3.5f);
			effect.SetParticleColor(sf::Color::Red);
			tParticleEffects->push_back(effect);
		}
	}	
}

void				Entity::Reset()
{
	mHealth = 30;
	mIsAlive = true;
	mVelocity = sf::Vector2f(0, 0);
}


void				Entity::MoveLeft()
{
	mVelocity.x -= mSpeed;
	mAction = EntityAction::WALK_LEFT;
	mDirection = Direction::LEFT;
}

void				Entity::MoveRight()
{
	mVelocity.x += mSpeed;
	mAction = EntityAction::WALK_RIGHT;
	mDirection = Direction::RIGHT;
}

void				Entity::Jump()
{
	if (mOnGround)
	{
		if (mVelocity.y > 0 && (mCollisionDirection == Entity::CollisionDirection::LEFT || mCollisionDirection == Entity::CollisionDirection::RIGHT))
		{
			if (mCollisionDirection == Entity::CollisionDirection::LEFT)
				mVelocity.x += 15.f;
			else
				mVelocity.x -= 15.f;
			mVelocity.y -= mJumpForce / 1.5f;
		}
		else
			mVelocity.y -= mJumpForce;
	}
	
}