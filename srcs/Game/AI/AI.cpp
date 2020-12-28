#include "AI.hpp"

AI::AI(/* args */)
{
}

AI::~AI()
{
}

bool		AI::IsWidthinSight(Player *tPlayer, Entity *tEntity)
{
	sf::Vector2f	diff = (tEntity->mPosition - tPlayer->GetEntity()->GetPosition());
	float distance = std::sqrt((diff.x * diff.x) + (diff.y * diff.y));
	if (distance < tEntity->mViewDistance && std::abs(tEntity->mPosition.y - tPlayer->GetEntity()->mPosition.y) < tEntity->mVerticalViewDistance)
		return (true);
	return (false);
}

void		AI::EntityPatrol(Entity *tEntity)
{
	if (tEntity->mAIAction == EntityAction::WALK_LEFT && tEntity->mVelocity.x == 0)
	{
		tEntity->MoveRight();
		tEntity->mAIAction = EntityAction::WALK_RIGHT;
	}
		
	if (tEntity->mAIAction == EntityAction::WALK_RIGHT && tEntity->mVelocity.x == 0)
	{
		tEntity->MoveLeft();
		tEntity->mAIAction = EntityAction::WALK_LEFT;
	}

	if (tEntity->mAIAction == EntityAction::WALK_LEFT)
		tEntity->MoveLeft();
	if (tEntity->mAIAction == EntityAction::WALK_RIGHT)
		tEntity->MoveRight();
	
}


void		AI::EntityAttack(Player *tPlayer, Entity *tEntity, std::list<ParticleEffect> *tParticleEffects)
{
	sf::Vector2f	diff = (tEntity->mPosition - tPlayer->GetEntity()->GetPosition());
	float distance = std::sqrt((diff.x * diff.x) + (diff.y * diff.y));
	
	if (tEntity->mIsBlocked)
		tEntity->Jump();
	if (distance < 15.f)
		tEntity->Attack(tPlayer->GetEntity(), tParticleEffects);
	else if (tEntity->GetPosition().x < tPlayer->GetEntity()->GetPosition().x - 20)
		tEntity->RunRight();
	else if (tEntity->GetPosition().x > tPlayer->GetEntity()->GetPosition().x + 20)
		tEntity->RunLeft();
	
}

void		AI::EntityRangeAttack(Player *tPlayer, Entity *tEntity, std::list<ParticleEffect> *tParticleEffects, std::list<Projectile> *tProjectiles)
{
	// sf::Vector2f	diff = (tEntity->mPosition - tPlayer->GetEntity()->GetPosition());
	// float distance = std::sqrt((diff.x * diff.x) + (diff.y * diff.y));
	if (tEntity->mAction != EntityAction::SHOOT_LEFT && tEntity->mAction != EntityAction::SHOOT_RIGHT)
	{
		if (tEntity->GetPosition().x < tPlayer->GetEntity()->GetPosition().x)
			tEntity->mDirection = Entity::Direction::RIGHT;
		else if (tEntity->GetPosition().x > tPlayer->GetEntity()->GetPosition().x)
			tEntity->mDirection = Entity::Direction::LEFT;
		tEntity->Shoot(tProjectiles);
	}
	
	(void)tPlayer;

	(void)tParticleEffects;
	
}



void		AI::ProcessEntity(Player *tPlayer, Entity *tEntity, std::list<ParticleEffect> *tParticleEffects, std::list<Projectile> *tProjectiles)
{
	if (IsWidthinSight(tPlayer, tEntity))
		tEntity->mAIMode = AIMode::ATTACK;
	else
		tEntity->mAIMode = AIMode::PATROL;

	switch (tEntity->mAIMode)
	{
	case AIMode::PATROL:
		EntityPatrol(tEntity);
		break;

	case AIMode::ATTACK:
		if (tEntity->mType == Entity::Type::MELEE)
			EntityAttack(tPlayer, tEntity, tParticleEffects);
		else
			EntityRangeAttack(tPlayer, tEntity, tParticleEffects, tProjectiles);
		break;
	
	default:
		break;
	}
}
