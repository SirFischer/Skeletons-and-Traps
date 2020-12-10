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
	if (distance < tEntity->mViewDistance)
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


void		AI::EntityAttack(Player *tPlayer, Entity *tEntity)
{
	sf::Vector2f	diff = (tEntity->mPosition - tPlayer->GetEntity()->GetPosition());
	float distance = std::sqrt((diff.x * diff.x) + (diff.y * diff.y));
	
	if (std::abs(tEntity->mVelocity.x) < 0.1f && tPlayer->GetEntity()->GetPosition().y < tEntity->GetPosition().y - tEntity->mSize.y && tEntity->mIsBlocked)
		tEntity->Jump();
	if (distance < 30.f)
		tEntity->Attack(tPlayer->GetEntity());
	else if (tEntity->GetPosition().x < tPlayer->GetEntity()->GetPosition().x)
		tEntity->MoveRight();
	else if (tEntity->GetPosition().x > tPlayer->GetEntity()->GetPosition().x)
		tEntity->MoveLeft();
	
}



void		AI::ProcessEntity(Player *tPlayer, Entity *tEntity)
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
		EntityAttack(tPlayer, tEntity);
		break;
	
	default:
		break;
	}
}
