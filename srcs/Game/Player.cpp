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

}


void	Player::Render(Window	*tWindow)
{
	mCharacter->Render(tWindow);
}