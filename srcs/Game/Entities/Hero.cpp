#include "Hero.hpp"

Hero::Hero(/* args */)
{
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/textures/Hero.png"));
	for (size_t i = 0; i < 9; i++)
		mAnimations[EntityAction::IDLE].AddFrame(sf::IntRect(64 * i, 64 * 11, 64, 64));
	mAnimations[EntityAction::IDLE].SetLength(0.1);
}

Hero::~Hero()
{
}

void	Hero::Update()
{
	mSprite.setTextureRect(mAnimations[mAction].GetTextureRect());
}


void	Hero::Render(Window	*tWindow)
{
	tWindow->Draw(mSprite);
}