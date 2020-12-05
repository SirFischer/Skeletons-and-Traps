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

size_t			Animation::GetAnimationStep()
{
	return ((int)(((1.0 / mLength) * mClock.getElapsedTime().asSeconds())) % mFrames.size());
}

bool			Animation::IsDone()
{
	return ((mClock.getElapsedTime().asSeconds() > (mLength * mFrames.size())) ? true : false);
}


sf::IntRect		Animation::GetTextureRect()
{
	sf::IntRect	frame = mFrames.at(GetAnimationStep());
	return (frame);
}