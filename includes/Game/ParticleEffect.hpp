#pragma once

#include "Window.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <random>

struct Particle {
	sf::Vector2f	mPos;
	sf::Vector2f	mVelocity;
	sf::Color		mColor;
	bool			mIsHit = false;
};

class ParticleEffect
{
private:
	std::vector<Particle>	mParticles;

	sf::CircleShape			mCircle;

	float					mGravity = 0.1f;
	float					mForce = 0.1f;

	sf::Clock				mLifeTimeClock;
	sf::Time				mLifeTime = sf::seconds(3);

	bool					mIsActive = true;

	void					InitSpray(float tDirection, float tSpread);
	void					InitExplosion();
public:
	friend class Map;

	ParticleEffect(sf::Vector2f tPos, float tForce, float tRadius, int tCount, float tDirection, float tSpread);
	ParticleEffect(sf::Vector2f tPos, float tForce, float tRadius, int tCount);
	~ParticleEffect();

	bool operator == (const ParticleEffect& s) const { return mLifeTimeClock.getElapsedTime().asSeconds() == s.mLifeTimeClock.getElapsedTime().asSeconds(); }

	void					SetParticleColor(sf::Color	tColor);				

	void					Update();
	void					Render(Window *tWindow);

	bool					IsActive(){return (mIsActive);}
	
};

