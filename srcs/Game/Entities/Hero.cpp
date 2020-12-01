#include "Hero.hpp"

Hero::Hero(/* args */)
{
	mPosition = sf::Vector2f(400, 300);
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/textures/Hero.png"));
	mSprite.setOrigin(32, 0);
	for (size_t i = 0; i < 9; i++)
		mAnimations[EntityAction::WALK].AddFrame(sf::IntRect(64 * i, 64 * 11, 64, 64));
	mAnimations[EntityAction::WALK].SetLength(0.08);
	for (size_t i = 0; i < 1; i++)
		mAnimations[EntityAction::IDLE].AddFrame(sf::IntRect(64 * i, 64 * 10, 64, 64));
	mAnimations[EntityAction::IDLE].SetLength(0.08);
	
}

Hero::~Hero()
{
}

void	Hero::Update()
{
	mSprite.setPosition(mPosition);
	if (mVelocity.x >= 0)
		mSprite.setScale(1, 1);
	else
		mSprite.setScale(-1, 1);
	mPosition += mVelocity;
	mVelocity.x *= 0.95;
	if (std::abs(mVelocity.x) < 1)
		mAction = EntityAction::IDLE;
	if (mAnimations.count(mAction))
		mSprite.setTextureRect(mAnimations[mAction].GetTextureRect());
}


void	Hero::Render(Window	*tWindow)
{
	tWindow->Draw(mSprite);
}