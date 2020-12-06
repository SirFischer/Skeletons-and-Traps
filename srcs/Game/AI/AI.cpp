#include "AI.hpp"

AI::AI(/* args */)
{
}

AI::~AI()
{
}

bool		AI::IsWidthinSight(Player *tPlayer, Entity *tEntity)
{
	(void)tPlayer;
	(void)tEntity;
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
		/* code */
		break;
	
	default:
		break;
	}
}
