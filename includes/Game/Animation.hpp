#pragma once
#include "ResourceManager.hpp"

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
private:
	std::vector<sf::IntRect>		mFrames;

public:
	Animation();
	~Animation();

	void							AddFrame(sf::IntRect	tRect);

	sf::IntRect						GetTextureRect();
};

