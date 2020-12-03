#include "Player.hpp"

Player::Player(/* args */)
{
	mCharacter = std::unique_ptr<Entity>(new Hero());
}

Player::~Player()
{
}


void	Player::Update()
{
	mCharacter->Update();
	if (InputManager::IsActive(InputAction::JUMP))
		std::cout << "JUMPING" << std::endl;
	if (InputManager::IsActive(InputAction::MOVE_RIGHT))
		mCharacter->MoveRight();
	if (InputManager::IsActive(InputAction::MOVE_LEFT))
		mCharacter->MoveLeft();

}


void	Player::Render(Window	*tWindow)
{
	mCharacter->Render(tWindow);
}