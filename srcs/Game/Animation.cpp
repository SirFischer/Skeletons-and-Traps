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

bool			Animation::IsDone()
{
	return ((mClock.getElapsedTime().asSeconds() > (mLength * mFrames.size())) ? true : false);
}


sf::IntRect		Animation::GetTextureRect()
{
	sf::IntRect	frame = mFrames.at((int)(((1.0 / mLength) * mClock.getElapsedTime().asSeconds())) % mFrames.size());
	return (frame);
}