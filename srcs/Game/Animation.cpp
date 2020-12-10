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

void			Animation::SetLoop(bool tLoop)
{
	mLoop = tLoop;
}


void			Animation::ResetAnimation()
{
	mElapsedTime = sf::seconds(0);
	mClock.restart();
}

size_t			Animation::GetAnimationStep()
{
	mElapsedTime += mClock.restart();
	if (!mLoop && mElapsedTime.asSeconds() > mLength * mFrames.size())
		return (mFrames.size() - 1);
	return ((int)(((1.0 / mLength) * mElapsedTime.asSeconds())) % mFrames.size());
}

bool			Animation::IsDone()
{
	return ((mElapsedTime.asSeconds() > (mLength * mFrames.size())) ? true : false);
}


sf::IntRect		Animation::GetTextureRect()
{
	sf::IntRect	frame = mFrames.at(GetAnimationStep());
	return (frame);
}