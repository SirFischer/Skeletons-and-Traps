#include "State.hpp"

StateAction			State::Run()
{
	sf::Time		mElapsedTime = sf::seconds(0);
	sf::Clock		mClock;

	while (mIsActive)
	{
		while (mElapsedTime.asSeconds() > mDeltaTime.asSeconds())
		{
			HandleEvents();
			Update();
			mElapsedTime -= mDeltaTime;
		}
		Render();
		mElapsedTime += mClock.restart();
	}
	return (mStateReturnAction);
}