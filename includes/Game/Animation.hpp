#pragma once
#include "ResourceManager.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
private:
	std::vector<sf::IntRect>		mFrames;
	sf::Clock						mClock;
	float							mLength = 2.0f;

public:
	Animation();
	~Animation();

	void							AddFrame(sf::IntRect	tRect);
	void							SetLength(float tLength);
	void							ResetAnimation();

	bool							IsDone();

	sf::IntRect						GetTextureRect();
};

