#include "Entity.hpp"

Entity::Entity(/* args */)
{
}

Entity::~Entity()
{
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