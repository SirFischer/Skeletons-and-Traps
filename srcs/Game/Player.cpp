#include "Player.hpp"

Player::Player(/* args */)
{
	mCharacter = std::unique_ptr<Entity>(new Hero());
}

Player::~Player()
{
}


void	Player::Update(std::list<Entity *> tEntities, std::list<ParticleEffect> *tParticleEffects)
{
	mCharacter->Update();
	if (mCharacter->GetHealth() > 0)
	{
		if (InputManager::IsActive(InputAction::JUMP))
			mCharacter->Jump();
		if (InputManager::IsActive(InputAction::MOVE_RIGHT))
			mCharacter->MoveRight();
		if (InputManager::IsActive(InputAction::MOVE_LEFT))
			mCharacter->MoveLeft();
		if (InputManager::IsActive(InputAction::ATTACK))
			mCharacter->Attack(tEntities, tParticleEffects);
	}
}


void	Player::Render(Window	*tWindow)
{
	mCharacter->Render(tWindow);
}