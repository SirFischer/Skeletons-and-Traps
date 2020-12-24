#include "Projectile.hpp"

Projectile::Projectile(sf::Vector2f	tPosition, float tAngle, float tForce)
{
	mSprite.setTexture(*ResourceManager::LoadTexture("assets/Textures/arrow.png"));
	mSprite.setOrigin(mSprite.getTextureRect().width / 2.f, mSprite.getTextureRect().height / 2.f);
	mSprite.setRotation((tAngle * 180.f) / M_PI);
	mSprite.setScale(0.1f, 0.1f);
	mPosition = tPosition;
	mVelocity.x = std::cos(tAngle) * tForce;
	mVelocity.y = std::sin(tAngle) * tForce;
}

Projectile::~Projectile()
{
}

void		Projectile::Update()
{
	if (!mIsHit)
	{
		mPosition += mVelocity;
		mVelocity.y += 0.03f;
	}
	if (mClock.getElapsedTime().asSeconds() > mHitLifeTime)
	{
		mSprite.setColor(sf::Color(mSprite.getColor().r, mSprite.getColor().g, mSprite.getColor().b, (255.f / (((mClock.getElapsedTime().asSeconds() - mHitLifeTime * 4.f) + 1.f)))));
		if (mSprite.getColor().a < 5.f)
			mActive = false;
	}
	mSprite.setPosition(mPosition);
}

void		Projectile::Render(Window *tWindow)
{
	tWindow->Draw(mSprite);
}
