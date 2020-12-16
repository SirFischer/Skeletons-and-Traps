#include "DarkArcher.hpp"

DarkArcher::DarkArcher(/* args */)
{
	mPosition = sf::Vector2f(400, 100);
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/Textures/DarkArcher.png"));
	for (size_t i = 0; i < 9; i++)
		mAnimations[EntityAction::WALK_LEFT].AddFrame(sf::IntRect(64 * i, 64 * 9, 64, 64));
	mAnimations[EntityAction::WALK_LEFT].SetLength(0.1);
	for (size_t i = 0; i < 9; i++)
		mAnimations[EntityAction::WALK_RIGHT].AddFrame(sf::IntRect(64 * i, 64 * 11, 64, 64));
	mAnimations[EntityAction::WALK_RIGHT].SetLength(0.1);
	for (size_t i = 0; i < 1; i++)
		mAnimations[EntityAction::IDLE].AddFrame(sf::IntRect(64 * i, 64 * 10, 64, 64));
	mAnimations[EntityAction::IDLE].SetLength(0.08);
	for (size_t i = 0; i < 6; i++)
		mAnimations[EntityAction::JUMP].AddFrame(sf::IntRect(64 * i, 64 * 15, 64, 64));
	mAnimations[EntityAction::JUMP].SetLength(0.08);
	for (size_t i = 0; i < 6; i++)
		mAnimations[EntityAction::DIE].AddFrame(sf::IntRect(64 * i, 64 * 20, 64, 64));
	for (size_t i = 0; i < 13; i++)
		mAnimations[EntityAction::ATTACK_RIGHT].AddFrame(sf::IntRect(64 * i, 64 * 19, 64, 64));
	mAnimations[EntityAction::ATTACK_RIGHT].SetLength(0.03);
	for (size_t i = 0; i < 13; i++)
		mAnimations[EntityAction::ATTACK_LEFT].AddFrame(sf::IntRect(64 * i, 64 * 17, 64, 64));
	mAnimations[EntityAction::ATTACK_LEFT].SetLength(0.03);
	mAnimations[EntityAction::DIE].SetLength(0.1);
	mAnimations[EntityAction::DIE].SetLoop(false);
	if (mAnimations.count(mAction))
		mSprite.setTextureRect(mAnimations[mAction].GetTextureRect());
	mSprite.setOrigin(16, 8);

	mSpeed = 0.17f;
	mJumpForce = 4.f;
}

DarkArcher::~DarkArcher()
{
}

void	DarkArcher::Attack(Entity *tEntity, std::list<ParticleEffect> *tParticleEffects)
{
	(void)tEntity;
	(void)tParticleEffects;
	std::cout << "attacked" << std::endl;
}

void	DarkArcher::Update()
{
	mIsBlocked = false;
	if (!mAnimations[EntityAction::ATTACK_LEFT].IsDone())
		mAction = EntityAction::ATTACK_LEFT;
	if (!mAnimations[EntityAction::ATTACK_RIGHT].IsDone())
		mAction = EntityAction::ATTACK_RIGHT;
	mSprite.setPosition(mPosition);
	mPosition += mVelocity;
	mVelocity.x *= 0.90;
	ApplyAnimation();
	if (!mOnGround)
		mVelocity.y += 0.1;
	if (mHealth > 0)
	{
		mDeathClock.restart();
		mAnimations[EntityAction::DIE].ResetAnimation();
	}
	if (mHealth <= 0)
	{
		mAction = EntityAction::DIE;
		if (mDeathClock.getElapsedTime().asSeconds() > 6.0)
			mIsAlive = false;
	}
}


void	DarkArcher::Render(Window	*tWindow)
{
	tWindow->Draw(mSprite);
}