#pragma once

#include "Window.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

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

public:
	friend class Map;

	ParticleEffect(sf::Vector2f tPos, float tRadius, int tCount, float tDirection, float tSpread);
	ParticleEffect(sf::Vector2f tPos, float tRadius, int tCount);
	~ParticleEffect();

	void					InitSpray(float tDirection, float tSpread);
	void					InitExplosion();

	void					Update();
	void					Render(Window *tWindow);

	
};

