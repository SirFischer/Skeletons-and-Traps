#include "Hero.hpp"

Hero::Hero(/* args */)
{
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/textures/Hero.png"));
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(1, 10, 100, 100));
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