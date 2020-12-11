#include "ParticleEffect.hpp"


ParticleEffect::ParticleEffect(sf::Vector2f tPos, float tForce, float tRadius, int tCount, float tDirection, float tSpread)
{
	mForce = tForce;
	mCircle.setRadius(tRadius);
	for (int i = 0; i < tCount; i++)
	{
		Particle particle;
		particle.mColor = sf::Color::Red;
		particle.mPos = tPos;
		mParticles.push_back(particle);
	}
	InitSpray(tDirection, tSpread);
}

ParticleEffect::ParticleEffect(sf::Vector2f tPos, float tForce, float tRadius, int tCount)
{
	mForce = tForce;
	mCircle.setRadius(tRadius);
	for (int i = 0; i < tCount; i++)
	{
		Particle particle;
		particle.mColor = sf::Color::Red;
		particle.mPos = tPos;
		mParticles.push_back(particle);
	}
	InitExplosion();
}

ParticleEffect::~ParticleEffect()
{
}

void		ParticleEffect::InitSpray(float tDirection, float tSpread)
{
	srand(time(0));
	for (auto &particle : mParticles)
	{
		float	angle = tDirection + ((1.f/1000.f) * tSpread) * (float)(random() % 1000) - (tSpread / 2.0f);
		float	forceVariation = ((1.f/1000.f) * mForce) * (float)(random() % 1000);
		particle.mVelocity = sf::Vector2f(cos(angle) * (forceVariation), sin(angle) * (forceVariation));
	}
}

void		ParticleEffect::InitExplosion()
{
	srand(time(0));
	for (auto &particle : mParticles)
	{
		float	angle = random();
		float	forceVariation = ((1.f/1000.f) * mForce) * (float)(random() % 1000);
		particle.mVelocity = sf::Vector2f(cos(angle) * (forceVariation), sin(angle) * (forceVariation));
	}
}

void		ParticleEffect::SetParticleColor(sf::Color	tColor)
{
	mCircle.setFillColor(tColor);
}				


void		ParticleEffect::Update()
{
	for (auto &particle : mParticles)
	{
		if (!particle.mIsHit)
		{
			particle.mVelocity.y += mGravity;
			particle.mPos += particle.mVelocity;
		}
		if (mLifeTimeClock.getElapsedTime().asSeconds() > mLifeTime.asSeconds())
		{
			particle.mColor = sf::Color(particle.mColor.r, particle.mColor.g, particle.mColor.b, (255.f / (((mLifeTimeClock.getElapsedTime().asSeconds() - mLifeTime.asSeconds()) * 4.f) + 1.f)));
			if (particle.mColor.a < 5.f)
				mIsActive = false;
		}
	}
}

void		ParticleEffect::Render(Window *tWindow)
{
	for (auto &particle : mParticles)
	{
		mCircle.setPosition(particle.mPos);
		mCircle.setFillColor(particle.mColor);
		tWindow->Draw(mCircle);
	}
}