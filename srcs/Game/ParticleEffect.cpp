#include "ParticleEffect.hpp"


ParticleEffect::ParticleEffect(sf::Vector2f tPos, float tRadius, int tCount, float tDirection, float tSpread)
{
	ParticleEffect(tPos, tRadius, tCount);
	InitSpray(tDirection, tSpread);
}

ParticleEffect::ParticleEffect(sf::Vector2f tPos, float tRadius, int tCount)
{
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

}

void		ParticleEffect::InitExplosion()
{
		
}

void		ParticleEffect::Update()
{
	for (auto &particle : mParticles)
	{
		particle.mVelocity.y += mGravity;
		particle.mPos += particle.mVelocity;
	}
}

void		ParticleEffect::Render(Window *tWindow)
{
	for (auto &particle : mParticles)
	{
		mCircle.setPosition(particle.mPos);
		tWindow->Draw(mCircle);
	}
}