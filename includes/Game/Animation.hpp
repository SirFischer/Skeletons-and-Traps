#pragma once
#include "ResourceManager.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
private:
	std::vector<sf::IntRect>		mFrames;
	sf::Clock						mClock;
	sf::Time						mElapsedTime = sf::seconds(10.f);
	float							mLength = 2.0f;
	bool							mLoop = true;

public:
	Animation();
	~Animation();

	void							AddFrame(sf::IntRect	tRect);
	void							SetLength(float tLength);
	void							SetLoop(bool tLoop);
	void							ResetAnimation();

	bool							IsDone();

	sf::IntRect						GetTextureRect();
	size_t							GetAnimationStep();
};

