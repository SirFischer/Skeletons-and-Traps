#include "Knight.hpp"

Knight::Knight(/* args */)
{
	mPosition = sf::Vector2f(400, 100);
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/Textures/Knight.png"));
	for (size_t i = 0; i < 9; i++)
		mAnimations[EntityAction::WALK_LEFT].AddFrame(sf::IntRect(64 * i, 64 * 9, 64, 64));
	mAnimations[EntityAction::WALK_LEFT].SetLength(0.1);
	for (size_t i = 0; i < 9; i++)
		mAnimations[EntityAction::WALK_RIGHT].AddFrame(sf::IntRect(64 * i, 64 * 11, 64, 64));
	mAnimations[EntityAction::WALK_RIGHT].SetLength(0.1);
	mAnimations[EntityAction::IDLE_RIGHT].AddFrame(sf::IntRect(64, 64 * 3, 64, 64));
	mAnimations[EntityAction::IDLE_LEFT].AddFrame(sf::IntRect(64, 64 * 1, 64, 64));
	for (size_t i = 0; i < 6; i++)
		mAnimations[EntityAction::JUMP].AddFrame(sf::IntRect(64 * i, 64 * 15, 64, 64));
	mAnimations[EntityAction::JUMP].SetLength(0.08);
	for (size_t i = 0; i < 6; i++)
		mAnimations[EntityAction::DIE].AddFrame(sf::IntRect(64 * i, 64 * 20, 64, 64));
	for (size_t i = 0; i < 6; i++)
		mAnimations[EntityAction::ATTACK_RIGHT].AddFrame(sf::IntRect(64 * i, 64 * 15, 64, 64));
	mAnimations[EntityAction::ATTACK_RIGHT].SetLength(0.05);
	for (size_t i = 0; i < 6; i++)
		mAnimations[EntityAction::ATTACK_LEFT].AddFrame(sf::IntRect(64 * i, 64 * 13, 64, 64));
	mAnimations[EntityAction::ATTACK_LEFT].SetLength(0.05);
	mAnimations[EntityAction::DIE].SetLength(0.1);
	mAnimations[EntityAction::DIE].SetLoop(false);
	if (mAnimations.count(mAction))
		mSprite.setTextureRect(mAnimations[mAction].GetTextureRect());
	mSprite.setOrigin(16, 8);
	mRunSpeed = 0.18f;
	mSpeed = 0.13f;
	mViewDistance = 200.f;
	mVerticalViewDistance = 100.f;
	mAttackDamage = 5;
	mJumpForce = 2.5f;
	mKnockBack = 8.f;
	mScoreValue = 75;
	mHealth = 200.f;

	mSound.SetVolume(SoundEffect::EnemyAttack, 0.5);
}

Knight::~Knight()
{
}

void	Knight::Update()
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
		mKilledClock.restart();
		mDeathClock.restart();
		mAnimations[EntityAction::DIE].ResetAnimation();
	}
	if (mHealth <= 0)
	{
		mAction = EntityAction::DIE;
		mSize.y = mSprite.getGlobalBounds().height / 1.8;
		if (mDeathClock.getElapsedTime().asSeconds() > 6.0)
			mIsAlive = false;
	}
	if (mHealth <= 0 && mKilledClock.getElapsedTime().asSeconds() < 0.1)
	{
		mSound.Play(SoundEffect::EnemyDeath);
	}
}


void	Knight::Render(Window	*tWindow)
{
	tWindow->Draw(mSprite);
}