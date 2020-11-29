#include "Hero.hpp"

Hero::Hero(/* args */)
{
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/textures/Hero.png"));
	int animation_line = 2 * 64;
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(0, animation_line, 64, 64));
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(64, animation_line, 64, 64));
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(64 * 2, animation_line, 64, 64));
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(64 * 3, animation_line, 64, 64));
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(64 * 4, animation_line, 64, 64));
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(64 * 5, animation_line, 64, 64));
	mAnimations[Action::IDLE].AddFrame(sf::IntRect(64 * 6, animation_line, 64, 64));
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