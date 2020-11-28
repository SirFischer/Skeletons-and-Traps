#include "Animation.hpp"


Animation::Animation()
{

}

Animation::~Animation()
{
}

void			Animation::AddFrame(sf::IntRect	tRect)
{
	mFrames.push_back(tRect);
}


sf::IntRect		Animation::GetTextureRect()
{
	return (sf::IntRect(0, 0, 100, 100));
}