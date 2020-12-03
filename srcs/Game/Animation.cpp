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

void			Animation::SetLength(float tLength)
{
	mLength = tLength;
}

void			Animation::ResetAnimation()
{
	mClock.restart();
}


sf::IntRect		Animation::GetTextureRect()
{
	int size = mFrames.size();
	sf::IntRect	frame = mFrames.at((int)(((1.0 / mLength) * mClock.getElapsedTime().asSeconds())) % size);
	return (frame);
}