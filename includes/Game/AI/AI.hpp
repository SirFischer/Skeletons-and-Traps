#pragma once

#include "Entities/Entities.hpp"
#include "Player.hpp"

#include "AIMode.hpp"

#include <math.h>

#define SIGHT_RANGE 50.f

class AI
{
private:
	AI();

	static bool		IsWidthinSight(Player *tPlayer, Entity *tEntity);

	static void		EntityPatrol(Entity *tEntity);
	static void		EntityAttack(Player *tPlayer, Entity *tEntity);
	
public:
	~AI();
	static void		ProcessEntity(Player *tPlayer, Entity *tEntity);
};
