#include "Hero.hpp"

Hero::Hero(/* args */)
{
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/textures/Hero.png"));
	for (size_t i = 0; i < 7; i++)
		mAnimations[Action::IDLE].AddFrame(sf::IntRect(64 * i, 128, 64, 64));
	mAnimations[Action::IDLE].SetLength(0.1);
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